#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

vector <string> myData(string myData);
vector <string> uniqueWords(string dataFile);
vector <string> fourLetters(string uData);
vector <string> specialData(string specFile);
vector <int> specialWords(string mainData, string sFile);
void printToFile(string mainFile, string specialFile);
int allCount(string mainData);
int uniqueCount(string mainData);
int unique4Count(string mainData);



int main() 
{
  ///*
  string fileName;
  string specialName;

  cout <<  "Please input the name of the file to be analyzed. " << endl;
  cin >> fileName;

  cout<< "Please input the name of the file with special words. " << endl;
  cin >> specialName;
  //*/

  //string fileName = "Rats.txt";
  //string specialName = "special_words.txt";

  uniqueWords(fileName);
  fourLetters(fileName);
  fourLetters(fileName);
  specialWords(fileName, specialName);
  printToFile(fileName, specialName);
  
  return 0;
}

//string vector holding the whole file I want to analyze
vector <string> myData(string myData)
{
  vector <string> wholeFile;
  string word;
  fstream inFile;

  inFile.open(myData);

  while( inFile >> word)
  {
    wholeFile.push_back(word);
  }
  inFile.close();

  return wholeFile;
}

//string vector holding all the unique words in the file
vector <string> uniqueWords(string dataFile)
{
  vector <string> uList;
  string words;
  int uCount = 0;
  int notU = 0;

  ifstream myList;
  myList.open(dataFile);

  while (myList >> words)
  {
    if(find(uList.begin(), uList.end(), words) != uList.end()) 
    {
      notU++;
    } 
    else 
    {
      uList.push_back(words);
      uCount++;
    }
  }

  myList.close();

  return uList;
}

//string vector holding all the unique words with 4 or more letters
vector <string> fourLetters(string uData)
{
  vector <string> fourList;
  string wordLength;
  int sizeWord;

  for(int i = 0; i < uniqueWords(uData).size(); i++)
  {
    wordLength = uniqueWords(uData)[i];
    sizeWord = wordLength.length();
    if(sizeWord >= 4)
    {
      fourList.push_back(uniqueWords(uData)[i]);
    }
  }

  return fourList;
}

//string vector holding all the words in special words file
vector <string> specialData(string specialData)
{
  vector <string> specList;
  string sWord;
  string data;

  ifstream specialFile;
  specialFile.open(specialData);

  while (specialFile >> data)
  {
    specList.push_back(data);
  }

  return specList;
}

//int vector holding the number of uses the special words occured
vector <int> specialWords(string mainData, string sFile)
{
  vector <int> numUses;
  int counter = 0;

  for (int i = 0; i < specialData(sFile).size(); i++)
  {
    for(int j = 0; j < myData(mainData).size(); j++)
    {
      if(specialData(sFile)[i] == myData(mainData)[j])
      {
        counter++;
      }
    }
    numUses.push_back(counter);
    counter = 0;
  }

  return numUses;
}

//count of whole file
int allCount(string mainData)
{
  return myData(mainData).size();
}

//count of unique words
int uniqueCount(string mainData)
{
  return uniqueWords(mainData).size();
}

//count of unqiue words with 4 or more letters
int unique4Count(string mainData)
{
  return fourLetters(mainData).size();
}

void printToFile(string mainFile, string specialFile)
{
  ofstream outFile;
  outFile.open("OutPutData.txt");
  outFile << "The name of the file is " << mainFile << "." << endl;
  outFile << "The name of the special file is " << specialFile << "." << endl << endl;
  outFile << "The total number of words are " << allCount(mainFile) << "." << endl;
  outFile << "The total number of unique words are " << uniqueCount(mainFile) << "." << endl;
  outFile << "The total number of unique words with 4 or more letters are " << unique4Count(mainFile)<< "." << endl;
  outFile << "The total number of reaccuring special words" << endl;
  for(int i = 0; i < specialData(specialFile).size(); i++)
  {
    outFile << specialData(specialFile)[i] << " " << specialWords(mainFile, specialFile)[i] << endl;
  }
  outFile.close();
}
