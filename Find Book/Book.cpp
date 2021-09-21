#include <iostream>
#include <vector>
#include<algorithm>
#include "book.h"

using namespace std;

Book::Book()
{

}

Book::Book(string t, string a, string c, string p, int d, int m, int y) 
{    
  title = t;
  author = a;
  category = c;
  publisher = p;

  day = d;
  month = m;
  year = y;

}

void Book::printBook(Book b) 
{
  b.title.erase(remove(b.title.begin(), b.title.end(), '{'), b.title.end());
  b.title.erase(remove(b.title.begin(), b.title.end(), '"'), b.title.end());
  b.title.erase(remove(b.title.begin(), b.title.end(), ','), b.title.end());

  b.category.erase(remove(b.category.begin(), b.category.end(), '{'), b.category.end());
  b.category.erase(remove(b.category.begin(), b.category.end(), '"'), b.category.end());
  b.category.erase(remove(b.category.begin(), b.category.end(), ','), b.category.end());
  b.category.erase(remove(b.category.begin(), b.category.end(), '}'), b.category.end());
  b.category.erase(remove(b.category.begin(), b.category.end(), ';'), b.category.end());

  cout << "Book  " << bookNumber << endl;
  cout << "Title: " << b.title << endl;
  cout << "Author: " << b.author << endl;
  cout << "Publisher: " << b.publisher << endl;
  cout << "Date: " << b.day << "/" << b.month << "/" << b.year << endl;
  cout << "Category: " << b.category << endl << endl;;
  bookNumber++;
}


void Book::searchYear(vector<Book> list, int start, int end) 
{
  int counter = 0;
  for (int i = 0; i < list.size(); i++) 
  {
    if (list[i].year >= start && list[i].year <= end) 
    {
      printBook(list[i]);
      counter++;
    }
  }
  
  if (counter == 0) 
  {
    cout << error;
  }
}



void Book::searchAuthor(vector<Book> list, string author) 
{
  int counter = 0;
  
  for (int i = 0; i < list.size(); i++) 
  {
    if(list[i].author == author) 
    { 
      printBook(list[i]);
      counter++;
    }
  }
  
  if (counter == 0) 
  {
    cout << error;
  }
}

void Book::searchCategory(vector<Book> list, string category) 
{
  int counter = 0;
  for (int i = 0; i < list.size(); i++) 
  {
    list[i].category.erase(remove(list[i].category.begin(), list[i].category.end(), '{'), list[i].category.end());
    list[i].category.erase(remove(list[i].category.begin(), list[i].category.end(), '"'), list[i].category.end());
    list[i].category.erase(remove(list[i].category.begin(), list[i].category.end(), ','), list[i].category.end());
    list[i].category.erase(remove(list[i].category.begin(), list[i].category.end(), '}'), list[i].category.end());
    list[i].category.erase(remove(list[i].category.begin(), list[i].category.end(), ';'), list[i].category.end());
    if (list[i].category == category) 
    {
      printBook(list[i]);
      counter++;
    }
  }

  if (counter == 0) 
  {
    cout << error;
  }
}

void Book::printMenu()
{
  cout << "Book finding Menu" << endl;
  cout << "1. Display all books in a year range: " << endl;
  cout << "2. Search for an author:" << endl;
  cout << "3. Display all books for a category:" << endl;
  cout << "4. Exit Menu" << endl;
}
