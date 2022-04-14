#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <fstream>
#include <sstream>
#include "AdjacencyList.h"
using namespace std;


void RefineAuthors(string& authors, set<string>& authorsInSet);
void RefineGenres(string &genres, set<string> &genresInSet);


int main() {
	/*int i = 1;
	string line;
	string authors;
	set<string> authorsInSet;
	string genres;
	set<string> genresInSet;
	string pages;
	string rating;
	string title;
	vector<Vertex> storage;

	string trash;

	ifstream inFile;

	inFile.open("book_dataset.csv");
	getline(inFile, line);
	cout << "Begin" << endl;
	while (getline(inFile, line)) {
		cout << i++ << endl;
		istringstream stream(line);
		getline(stream, authors, ',');
		RefineAuthors(authors, authorsInSet);
		getline(stream, genres, ',');
		RefineGenres(genres, genresInSet);
		getline(stream, pages, ',');
		getline(stream, rating, ',');
		rating = rating.at(0);
		getline(stream, title, ',');
		Vertex temp(authorsInSet, genresInSet, stoi(pages), stoi(rating), title);
		storage.push_back(temp);
	}*/

	AdjacencyList container;

	cout << "Done" << endl;
}


void RefineAuthors(string& authors, set<string>& authorsInSet) {
	authorsInSet.clear();
	stringstream a(authors);
	while (a.good()) {
		string author;
		getline(a, author, ':');
		authorsInSet.insert(author);
	}
}

void RefineGenres(string& genres, set<string>& genresInSet) {
	genresInSet.clear();
	stringstream g(genres);
	while (g.good()) {
		string genre;
		getline(g, genre, ':');
		genresInSet.insert(genre);
	}
}