#include <iostream>

using namespace std;

class Book 
{
public:
  string title;
  string author;
  string category;
  string publisher;
  string authorSearch;
  string categorySearch;
  string error = "No results found"; 

  int day;
  int month;
  int year;
  int bookNumber = 1;

  Book();
  Book(string t, string a, string c, string p, int d, int m, int y);
  void searchYear(vector<Book> list, int start, int end);
  void searchAuthor(vector<Book> list, string author);
  void searchCategory(vector<Book> list, string category);
  void printBook(Book b);
  void printMenu();
};
