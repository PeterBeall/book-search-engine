#include "InputWindow.h"
#include "AdjacencyList.h"
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <fstream>
#include <sstream>
using namespace std;
using namespace System;
using namespace System::Windows::Forms;
[STAThread]

void RefineAuthors(string& authors, set<string>& authorsInSet);
void RefineGenres(string& genres, set<string>& genresInSet);

void main()
{

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	COP3530Project3::InputWindow form;
	Application::Run(% form);

	//cout << "Done" << endl;

	/*
	string nextTitle;
	string nextRating;
	string nextPages;
	string nextGenre;
	string nextAuthor;

	while (true) {
		cout << "Enter title, rating, pages, genre\n";

		getline(cin, nextTitle, '\n');
		getline(cin, nextRating, '\n');
		getline(cin, nextPages, '\n');
		getline(cin, nextGenre, '\n');

		unsigned char nextRatingChar = nextRating[0];

		if (nextRating == "") {
			nextRatingChar = -1;
		}
		if (nextPages == "") {
			nextPages = "-1";
		}

		string foundTitle = container.Find(true, nextTitle, nextRatingChar, stoi(nextPages), vector<string>{nextGenre});

		cout << foundTitle << "\n";

		for (auto similarTitle : container.getSimilar(foundTitle)) {
			cout << similarTitle << "\n";
		}
	}
	*/

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

void COP3530Project3::InputWindow::searchFunc(std::string title, std::string rating, int pages, std::vector<std::string> genre)
{
	AdjacencyList container;

	unsigned char rate = rating[0];

	if (rating == "") {
		rate = -1;
	}
	if (pages == NULL) {
		pages = -1;
	}

	std::string foundTitle = container.Find(true, title, rate, pages, genre);

	ResultWindow^ result = gcnew ResultWindow;
	result->Show();

	for (auto similarTitle : container.getSimilar(foundTitle)) {
		String^ simTitle = gcnew String(similarTitle.c_str());;
		result->listBox1->Items->Add(simTitle);
	}
}
