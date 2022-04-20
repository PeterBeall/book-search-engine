#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include "AdjacencyList.h"
using namespace std;


void AdjacencyList::RefineAuthors(string& authors, vector<string>& authorsInVector) {
	authorsInVector.clear();
	stringstream a(authors);
	while (a.good()) {
		string author;
		getline(a, author, ':');
		authorsInVector.push_back(author);
	}
	sort(authorsInVector.begin(), authorsInVector.end());
}

//Refines the genres string into a vector string. O(n) time complexity.
void AdjacencyList::RefineGenres(string& genres, vector<string>* genresInVector) {
	genresInVector->clear();
	stringstream g(genres);
	while (g.good()) {
		string genre;
		getline(g, genre, ':');
		genresInVector->push_back(genre);
	}
	sort(genresInVector->begin(), genresInVector->end());
}

//Using Vertexes. Go through the file and add connections as it goes through. O(n^2) time complexity.
AdjacencyList::AdjacencyList() {
	int p = 1;
	string line;
	string genres;
	string pages;
	string rating;
	string title;
	Vertex book;

	vector<string>* intersect = new vector<string>;

	ifstream inFile;

	//inFile.open("test.csv");
	inFile.open("book_dataset.csv");
	getline(inFile, line);
	//while(getline(inFile, line)){
	for (int p = 0; p < 1000; p++) {
		/*p++;
		if (p % 1000 == 0) {
			cout << p << "\n";
		}*/

		getline(inFile, line);
		vector<string>* genresInVector = new vector<string>;
		istringstream stream(line);
		getline(stream, genres, ',');//skip author column
		getline(stream, genres, ',');
		RefineGenres(genres, genresInVector);
		getline(stream, pages, ',');
		getline(stream, rating, ',');
		rating = rating.at(0);
		getline(stream, title);
		dataContainer[title] = Vertex(genresInVector, stoi(pages), stoi(rating), title);

		for (unordered_map<string, Vertex>::iterator it = dataContainer.begin(); it != dataContainer.end(); ++it) {

			set_intersection(it->second.genresInSet->begin(), it->second.genresInSet->end(), genresInVector->begin(), genresInVector->end(), back_inserter(*intersect));

			if (it->first != title && intersect->size() >= 3) {
				dataContainer[title].connections->push_back(make_pair(it->first, abs(dataContainer[title].rating - it->second.rating) + abs(dataContainer[title].pages - it->second.pages)));
				dataContainer[it->first].connections->push_back(make_pair(title, abs(dataContainer[title].rating - it->second.rating) + abs(dataContainer[title].pages - it->second.pages)));
				if (dataContainer[title].connections->size() > 5) {
					vector<pair<string, unsigned int>>::iterator largest = dataContainer[title].connections->begin();
					for (vector<pair<string, unsigned int>>::iterator obj = dataContainer[title].connections->begin(); obj != dataContainer[title].connections->end(); ++obj) {
						if (largest->second > obj->second) {
							largest = obj;
						}
					}
					dataContainer[title].connections->erase(largest);
				}
				if (dataContainer[it->first].connections->size() > 5) {
					vector<pair<string, unsigned int>>::iterator largest = dataContainer[it->first].connections->begin();
					for (vector<pair<string, unsigned int>>::iterator obj = dataContainer[it->first].connections->begin(); obj != dataContainer[it->first].connections->end(); ++obj) {
						if (largest->second > obj->second) {
							largest = obj;
						}
					}
					dataContainer[it->first].connections->erase(largest);
				}
			}
			intersect->clear();
		}
	}

	//the graph might be disconnected. create a set containing exactly one title from each connected portion.

	unordered_map<string, string> unionFind;//a union-find aka disjoint-set aka merge-find structure

	//assuming no book will have the empty string as a title. so a title mapping to the empty string indicates that title is the representative of its group.

	//first, put every title in its own group
	for (auto vertex : dataContainer) {
		unionFind[vertex.first] = "";
	}

	//next, for each title not yet in a group, merge everything connected to it
	for (auto representative : unionFind) {
		if (representative.second != "") {
			continue;
		}

		unordered_set<string> visited;
		queue<string> next;

		next.push(representative.first);

		while (!next.empty()) {
			string current = next.front();
			next.pop();
			visited.insert(current);

			//here, we are guaranteed that current.second == ""

			unionFind[current] = representative.first;

			for (auto toAdd : *dataContainer[current].connections) {
				if (visited.count(toAdd.first) == 0) {
					next.push(toAdd.first);
					visited.insert(toAdd.first);
				}
			}
		}

		representative.second = "";
	}

	//finally, add one representative from each group to the set
	for (auto element : unionFind) {
		minimumTitles.insert(element.second);
	}
	minimumTitles.erase("");

	cout << minimumTitles.size() << endl;
}

unordered_set<string> AdjacencyList::breakIntoWords(string toBreak) {
	unordered_set<string> words;

	stringstream asStream(toBreak);
	while (asStream.good()) {
		string word;
		getline(asStream, word, ' ');

		//remove any special symbols and make the word lowercase, for less strict comparison
		word.erase(std::remove_if(word.begin(), word.end(), [](char character) {
			return (character == ':' || character == '-' || character == ',' || character == '\'');
			}), word.end());

		transform(word.begin(), word.end(), word.begin(), [](char character) {
			return tolower(character);
			});

		words.insert(word);
	}

	return words;
}

//return an integer, with greater integers indicating the book in the graph with title1 is more similar to the book represented by the rest of the parameters
int AdjacencyList::Sameness(string title1, string title2, unsigned char rating, int pages, vector<string> genresInSet) {
	//get a set containing the words in each of the titles
	unordered_set<string> words1 = breakIntoWords(title1);
	unordered_set<string> words2 = breakIntoWords(title2);

	int same = 0;

	//increment same for each common word
	for (auto word1 : words1) {
		for (auto word2 : words2) {
			if (word1 == word2) {
				same += 3;
			}
		}
	}

	//increment same if ratings match
	if (dataContainer[title1].rating == rating) {
		same++;
	}

	//increment same if pages are close
	if (pages != -1 && -100 <= pages - dataContainer[title1].pages && pages - dataContainer[title1].pages <= 100) {
		same++;
	}

	//increment same for each common genre:
	for (auto genre1 : *dataContainer[title1].genresInSet) {
		for (auto genre2 : genresInSet) {
			if (genre1 == genre2) {
				same++;
			}
		}
	}

	return same;
}

//returns the title of the book in the graph which most closely matches the given parameters. but returns "" if no match found.
/*the book parameters represent a book outside of the graph. These parameters are optional:
	if the title is not available, provide title2 = ""
	if the rating is not available, provide rating = '0'
	if the pages is not available, provide pages = -1
	if genres not available, provide an empty string set
	if authors not available, provide an empty string set.
*/
string AdjacencyList::Find(bool BFS, string title, unsigned char rating, int pages, vector<string> genresInSet) {
	Quack<string> next(BFS); //queue for BFS, stack for DFS
	unordered_set<string> visited;

	//add each title from minimumTitles into next
	for (auto startingTitle : minimumTitles) {
		next.push(startingTitle);
		visited.insert(startingTitle);
	}

	string best = ""; //the best match that has been found so far
	int bestSimilarity = 0; //how good this match is

	while (!next.empty()) {
		string current = next.pop();

		int currentSimilarity = Sameness(current, title, rating, pages, genresInSet);

		if (currentSimilarity > bestSimilarity) {
			best = current;
			bestSimilarity = currentSimilarity;
		}

		//add each adjacents to next
		for (auto toAdd : *dataContainer[current].connections) {
			if (visited.count(toAdd.first) == 0) {
				next.push(toAdd.first);
				visited.insert(toAdd.first);
			}
		}
	}

	return best;
}

//returns a list of up to size n of the titles of the books adjacent to the one with the given title
//the given title must exactly match one in the graph
vector<string> AdjacencyList::getSimilar(string title, int n) {
	vector<pair<string, unsigned int>> adjacentBooksPairs;

	for (auto adjacent : *dataContainer[title].connections) {
		//insert adjacent while maintaining order based on weight
		int i = 0;
		while (i < adjacentBooksPairs.size() && adjacentBooksPairs.at(i).second > adjacent.second) {
			i++;
		}

		adjacentBooksPairs.insert(adjacentBooksPairs.begin() + i, adjacent);

		if (adjacentBooksPairs.size() >= n) {
			//do not insert too many
			adjacentBooksPairs.pop_back();
		}
	}

	//create vector without weights
	vector<string> adjacentBooks;
	for (int i = 0; i < adjacentBooksPairs.size(); i++) {
		adjacentBooks.push_back(adjacentBooksPairs.at(i).first);
	}

	return adjacentBooks;
}