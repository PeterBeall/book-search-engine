#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <fstream>
#include <sstream>
#include "Quack.h"
using namespace std;

struct Vertex {
	vector<string>* genresInSet;
	int pages;
	unsigned char rating;
	string title;
	vector<pair<string, unsigned int>>* connections;

	Vertex() {

	}

	Vertex(vector<string>* _genresInSet, int _pages, unsigned char _rating, string _title) {
		genresInSet = _genresInSet;
		pages = _pages;
		rating = _rating;
		title = _title;
		connections = new vector<pair<string, unsigned int>>;
	}
};

class AdjacencyList {

private:
	unordered_map<string, Vertex> dataContainer;

	void RefineAuthors(string& authors, vector<string>& authorsInVector);
	void RefineGenres(string& genres, vector<string>* genresInVector);

	unordered_set<string> minimumTitles;
	unordered_set<string> breakIntoWords(string toBreak);
	int Sameness(string title1, string title2, unsigned char rating, int pages, vector<string> genresInSet);
public:
	AdjacencyList();

	string Find(bool BFS, string title, unsigned char rating, int pages, vector<string> genresInSet);
	vector<string> getSimilar(string title, int n = 10);
};

