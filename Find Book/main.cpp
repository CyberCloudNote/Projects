#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include "book.h"

using namespace std;

void printMenu();

int main() 
{
  int menu;
  int startYear;
  int endYear;
  string authorName;
  string bookType;
  string fullName;
  Book searchRange;

  string bookTitle;
  string bookAuthor;
  string bookPublisher;
  string bookDate;
  string bookCategory;

  fstream myFile;
  myFile.open("booklist.txt"); // bring in the text file
  vector<Book> bookList;
  string line;

  getline(myFile, line);
  while(getline(myFile, line)) 
  {
    int titleLength = 0;
    int authorLength = 0;
    int publisherLength = 0;
    int dateLength = 0;

    while(line[titleLength] != ',')
    {
      titleLength++;
    }

    authorLength = titleLength + 1;
    while (line[authorLength] != ',')
    {
      authorLength++;
    }

    publisherLength = authorLength + 1;
    while (line[publisherLength] != ',')
    {
      publisherLength++;
    }

    dateLength = publisherLength + 1;
    while (line[dateLength] != ',')
    {
      dateLength++;
    }

    bookTitle = line.substr(1, titleLength);
    bookAuthor = line.substr(titleLength + 2, authorLength - titleLength - 3); 
    bookPublisher = line.substr(authorLength + 2, publisherLength - authorLength - 3);
    bookDate = line.substr(publisherLength + 2, dateLength - publisherLength - 3); 
    bookCategory = line.substr(dateLength + 2);

    int delim1 = 0;
    int delim2 = 0;

    while(bookDate[delim1] != '/')
    {
      delim1++;
    }

    delim2 = delim1 + 1;
    while (bookDate[delim2] != '/')
    {
      delim2++;
    }

    int month = stoi(bookDate.substr(0, delim1));
    int day = stoi(bookDate.substr(delim1 + 1, delim2 - delim1 - 1));
    int year = stoi(bookDate.substr(delim2 + 1));
      
    Book myBook(bookTitle, bookAuthor, bookCategory, bookPublisher, day, month, year);
    bookList.push_back(myBook);

  }

 do
 {
   searchRange.printMenu();
   while (!(cin >> menu) && (menu < 1 || menu > 5)) 
   {
     cout << "Invalid Input!" << endl;
     cout << "Please Input 1, 2, or 3 from the menu options." << endl << endl;
     cin.clear();
     cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
  if(menu < 1 || menu > 5)
  {
    cout << "Invalid Input!" << endl;
    cout << "Please Input 1, 2, or 3 from the menu options." << endl << endl;
  }
    switch(menu)
     {
      case 1:
      cout << "Please input the begining year: ";
      cin >> startYear;
      cout << "Please input the ending year: ";
      cin >> endYear;
          
      searchRange.searchYear(bookList, startYear, endYear);
        break;
      case 2:
      cin.ignore();
      cout << "Please input the author's name: ";
      getline(cin, authorName);

      searchRange.searchAuthor(bookList, authorName);
        break;
      case 3:
      cin.ignore();
      cout << "Please input a category: ";
      getline(cin, bookType);

      searchRange.searchCategory(bookList, bookType);
        break;
      case 4:
      cout << "Thank for using our Menu." << endl;
      return 0;
        break;
      }
 }while(true);
}
