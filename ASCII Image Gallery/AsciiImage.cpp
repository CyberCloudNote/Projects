#include "AsciiImage.h"
#include "string"
#include <iomanip>

using namespace std;

AsciiImage::AsciiImage()
{
	// Add defaults here
	title = "";
	id = "";
	catagory = "";
	name = "";
	url = "";
  x = 0;
}

bool AsciiImage::LoadImage(ifstream &file)
{
  string lineSS;
  while (getline(file, lineSS))
  {
  string a;
  stringstream ss(lineSS);
    if (!(ss >> a)) 
    { 
      break; 
    } 
  }
  // Load title
  getline(file,title);

  // Get ID
  getline (file, id);

	// Read image
  string line;
  do
	{
		getline(file, line);
    picFull.push_back(line);
	} while (line.compare("====="));
 
	//Read Catagory
  getline(file, url);

	// Read URL
  getline(file, catagory);

	// Maybe read a name
  getline(file, name);

	return true;
}

void AsciiImage::PrintImage(bool showTitle, bool showName, bool showID, bool showCateg, bool showURL)
{
	// Print the image with the board and options
  if (showTitle == 1)
  {
    cout << title << endl;
  }

  for(int boarder = 0; boarder < picFull.size() - 1; boarder++)
  {
    if(x < picFull[boarder].length())
    {
      x = picFull[boarder].length();
    }
  }
  PrintHorizontalBorder();

  for(int i = 0; i < picFull.size() - 1; i++)
  {
    string imageInsert = picFull[i];
    PrintWithVerticalBorders(imageInsert);
  }

  PrintHorizontalBorder();

  if(showName == 1)
  {
    //4thlane
    cout << name << endl;
  }
  if(showID == 1)
  {
    cout << id << endl;
  }
  if(showCateg == 1)
  {
    cout << catagory << endl;
  }
  if(showURL == 1)
  {
    cout << url << endl;
  }
}

void AsciiImage::PrintHorizontalBorder()
{
	// Print the horizontal border
   for (int i = 0; i < x + 5; i++)
   {
     cout << "=";
   }
   cout << endl;
}

void AsciiImage::PrintWithVerticalBorders(string s)
{
	// Print the string s with "|" on both sides
  cout << "|" << setw(2) << s << setw(x+4 - s.length()) << "|" << endl;
}