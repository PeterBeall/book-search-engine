#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <fstream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include "AdjacencyList.h"
using namespace std;

void AdjacencyList::RefineAuthors(string& authors, set<string>& authorsInVector) {
	authorsInVector.clear();
	stringstream a(authors);
	while (a.good()) {
		string author;
		getline(a, author, ':');
		authorsInVector.insert(author);
	}
}

void AdjacencyList::RefineGenres(string& genres, set<string>& genresInVector) {
	genresInVector.clear();
	stringstream g(genres);
	while (g.good()) {
		string genre;
		getline(g, genre, ':');
		genresInVector.insert(genre);
	}
}

void AdjacencyList::AddBook(string title, int rating, int pages, set<string> &genresInVector, set<string> &authorsInVector) {
	titles[title] = {};
	ratingGraph[title] = rating;
	pageGraph[title] = pages;
	genresGraph[title] = genresInVector;
	authorsGraph[title] = authorsInVector;
}

/*AdjacencyList::AdjacencyList(vector<Vertex> &container) {
	for (unsigned int i = 0; i < container.size(); i++) {
		titles[container.at(i).title] = {};
		for (set<string>::iterator it = container.at(i).authorsInSet.begin(); it != container.at(i).authorsInSet.end(); ++it) {
			authorsGraph[container.at(i).title].push_back(*it);
		}
		for (set<string>::iterator it = container.at(i).genresInSet.begin(); it != container.at(i).genresInSet.end(); ++it) {
			genresGraph[container.at(i).title].push_back(*it);
			genres.insert(*it);
		}
		pageGraph[container.at(i).title] = container.at(i).pages;
		ratingGraph[container.at(i).title] = container.at(i).rating;
	}
	for (map<string, vector<string>>::iterator it = genresGraph.begin(); it != genresGraph.end(); ++it) {
		for (map<string, vector<string>>::iterator ti = next(it); ti != genresGraph.end(); ++ti) {
			for (int i = 0; i < it->second.size(); i++) {
				for (int j = 0; j < ti->second.size(); j++) {
					if (ti->second.at(i).compare(ti->second.at(j)) == 0) {
						Connect(it->first, ti->first);
					}
				}
			}
		}
	}
}*/

AdjacencyList::AdjacencyList() {
	int f = 1;
	string line;
	string authors;
	set<string> authorsInVector;
	string genres;
	set<string> genresInVector;
	string pages;
	string rating;
	string title;
	
	set<string> intersect;

	ifstream inFile;

	inFile.open("book_dataset.csv");
	getline(inFile, line);
	cout << "Begin" << endl;
	for (int p = 0; p < 10000; p++) {
		getline(inFile, line);
		cout << f++ << endl;
		istringstream stream(line);
		getline(stream, authors, ',');
		RefineAuthors(authors, authorsInVector);
		getline(stream, genres, ',');
		RefineGenres(genres, genresInVector);
		getline(stream, pages, ',');
		getline(stream, rating, ',');
		rating = rating.at(0);
		getline(stream, title);
		AddBook(title, stoi(rating), stoi(pages), genresInVector, authorsInVector);
		for (map<string, set<string>>::iterator it = genresGraph.begin(); it != genresGraph.end(); ++it) {
			set_intersection(it->second.begin(), it->second.end(), genresInVector.begin(), genresInVector.end(), inserter(intersect, intersect.begin()));
			if (it->first != title && intersect.size() != 0) {
				Connect(it->first, title);
			}
		}
		intersect.clear();
	}
	/*while (getline(inFile, line)) {
		cout << f++ << endl;
		istringstream stream(line);
		getline(stream, authors, ',');
		RefineAuthors(authors, authorsInVector);
		getline(stream, genres, ',');
		RefineGenres(genres, genresInVector);
		getline(stream, pages, ',');
		getline(stream, rating, ',');
		rating = rating.at(0);
		getline(stream, title);
		AddBook(title, stoi(rating), stoi(pages), genresInVector, authorsInVector);
	}*/




	/*set<string> intersect;
	bool temp;
	for (map<string, set<string>>::iterator it = genresGraph.begin(); it != genresGraph.end(); ++it) {
		for (map<string, set<string>>::iterator ti = next(it); ti != genresGraph.end(); ++ti) {
			intersect.clear();
			set_intersection(it->second.begin(), it->second.end(), ti->second.begin(), ti->second.end(), inserter(intersect, intersect.begin()));
			if (intersect.size() != 0) {
				Connect(it->first, ti->first);
			}
		}
	}*/

	/*
	for (map<string, vector<string>>::iterator it = genresGraph.begin(); it != genresGraph.end(); ++it) {
		for (map<string, vector<string>>::iterator ti = next(it); ti != genresGraph.end(); ++ti) {
			for (int i = 0; i < it->second.size(); i++) {
				for (int j = 0; j < ti->second.size(); j++) {
					if (it->second.at(i).compare(ti->second.at(j)) == 0) {
						Connect(it->first, ti->first);
					}
				}
			}
		}
	}*/
}

void AdjacencyList::Connect(string x, string y) {
	int weight = WeightCalc(x, y);
	titles[x].push_back(make_pair(y, weight));
	titles[y].push_back(make_pair(x, weight));
}

int AdjacencyList::WeightCalc(string x, string y) {
	int weight = 1;
	weight += abs(ratingGraph[x] - ratingGraph[y]);
	weight += abs(pageGraph[x] - pageGraph[y]);
	return weight;
}

set<string> &AdjacencyList::GetAllGenres()
{
	return genres;
}
