// AsciiArtGallery.cpp : Defines the entry point for the console application.

#include <iostream>
#include "AsciiImage.h"
#include "string"
#include "fstream"
using namespace std;

/*
 * This function has already been completed for you.
 */

int GetUserChoice(bool options[], int maxSz);

int main()
{
	vector<AsciiImage*> images;
	ifstream file;

	string filename;
	cout << "Enter Gallery File: ";
	cin >> filename;
	filename = "ascii_data.txt";
	file.open(filename);
	// Code to load each image entry goes here...
	while (!file.eof()) {
		AsciiImage *imgEntry = new AsciiImage;
		if(imgEntry->LoadImage(file))
			images.push_back(imgEntry);
	}

	bool options[5];
	cout << endl;
	cout << "Please enter your image choice and display options (0 or 1)." << endl;
	cout << "> ImageIndex ShowTitle ShowName ShowID ShowCategory ShowURL" << endl;
	cout << endl;
	cout << "ExampleUsage:" << endl;
	cout << "> 0 1 1 1 1 1		Shows image 0 with title, artist name, image id, category, url" << endl;
	cout << "> 0 1 1 0 0 0		Shows image 0 with title and artist name" << endl;
	cout << endl << endl;
	while (true) {
		int choice = GetUserChoice(options, images.size());
		if (choice < 0)
			break;
		images[choice]->PrintImage(options[0], options[1], options[2], options[3], options[4]);
	}

    return 0;
}

int GetUserChoice(bool options[], int maxSz) {
	int choice = -1;

	while (true) {
		cout << "> ";
		cin >> choice;
		for (int i = 0; i < 5; i++) {
			cin >> options[i];
		}
		if (choice < maxSz)
			break;
		else {
			cout << "Please enter an image number between 0 and " << (maxSz - 1) << "." << endl;
		}
	}

	return choice;
}
