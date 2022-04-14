#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <fstream>
#include <sstream>
using namespace std;

struct Vertex {
	set<string> authorsInSet;
	set<string> genresInSet;
	int pages;
	int rating;
	string title;

	Vertex() {

	}

	Vertex(set<string> _author, set<string> _genresInSet, int _pages, int _rating, string _title) {
		authorsInSet = _author;
		genresInSet = _genresInSet;
		pages = _pages;
		rating = _rating;
		title = _title;
	}
};

class AdjacencyList {

private:
	//unordered_map<string, Vertex> dataContainer;
	unordered_map<string, vector<pair<string, int>>> titles;
	unordered_map<string, set<string>> authorsGraph;
	map<string, set<string>> genresGraph;
	set<string> genres;
	unordered_map<string, int> pageGraph;
	unordered_map<string, int> ratingGraph;

	void RefineAuthors(string &authors, set<string> &authorsInVector);
	void RefineGenres(string& genres, set<string>& genresInVector);
	void AddBook(string title, int rating, int pages, set<string>& genresInVector, set<string>& authorsInVector);
	
public:

	AdjacencyList(vector<Vertex> &container);

	AdjacencyList();

	void Connect(string x, string y);

	int WeightCalc(string x, string y);

	set<string>& GetAllGenres();

};