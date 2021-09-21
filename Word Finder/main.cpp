// Andy Chu
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int getRow(string nameFile);
int getCol(string nameFile);
void editString(string input);
vector<string> myKey;
vector<int> keyLoc;
vector<int> tempKey;
vector<int> finalKey;

int main() 
{
  string fileName = "quotes.txt";
  string line;
  int myRow = 0;
  int myCol = 0;
  int checkKey = 0;
  int count = 0;
  int countRow;
  int countCol;
  int resizeVal;
  string findKey;

  ifstream myFile;

  cout << "Enter a file name: "<< endl;
  //cin >> fileName;
  
  countRow = getRow(fileName);
  countCol = getCol(fileName);
  
  string **arr = new string*[countRow];
  for(int i = 0; i < countRow; ++i)
  {
    arr[i] = new string[countCol];
  }

  myFile.open(fileName);
  while(!myFile.eof())
  {
    getline(myFile, line);
    istringstream ss(line);
    do 
    { 
      string word; 
      ss >> word; 

      reverse(word.begin(), word.end());
      transform(word.begin(), word.end(), word.begin(), ::tolower);

      arr[myRow][myCol] = word;
      myCol++;
    } while (ss);
    myRow++;
  }
  myFile.close();
  
  while(true)
  {
  cout << "Enter space-separated words: ";

  getline(cin,findKey);

  if(findKey == "quit")
  {
    return 0;
  }

  editString(findKey);

  cout << "The co-occurance for: " << findKey;
  cout << endl;
  cout << "Lines: ";
  for(int x = 0; x < myKey.size()-1; x++)
  {
    for (int i = 0; i < countRow; ++i)
    {
      for (int j = 0; j < countCol; ++j)
      {
        if(arr[i][j] == myKey[x])
        {
          keyLoc.push_back(i);
          checkKey++;
        }
      }
    }
  }

  keyLoc.erase(unique(keyLoc.begin(), keyLoc.end()), keyLoc.end());

  if(myKey.size() == 2)
  {
    if(checkKey == 0)
    {
      cout << "None" << endl;
    }
    else
    {
      for(int i = 0; i < keyLoc.size(); i++)
      {
        cout << keyLoc[i] + 1;
        if(i < keyLoc.size()-1)
        {
          cout << ", ";
        }
      }
    }
  }
  else
  {
    int maxCount = 1;
    int mostRepeat = keyLoc[0];
    int tempCount = 1; 

    sort(keyLoc.begin(), keyLoc.end()); 

    for (int i = 1; i < keyLoc.size(); i++)
    { 
      if (keyLoc[i] == keyLoc[i - 1]) 
      {
        tempCount++; 
      }
      else 
      { 
        if (tempCount > maxCount) 
        { 
          maxCount = tempCount; 
          mostRepeat = keyLoc[i - 1]; 
        } 
        tempCount = 1; 
      } 
    } 

    if (tempCount > maxCount) 
    { 
      maxCount = tempCount; 
      mostRepeat = keyLoc[keyLoc.size() - 1]; 
    } 
    
    if(maxCount == 1)
    {
      cout << "None" << endl;
    }
    else
    {
      cout << mostRepeat + 1 << endl;
    } 
  }
    cout << endl;
    myKey.clear();
    keyLoc.clear();
    tempKey.clear();
    finalKey.clear();
  }
}

int getRow(string nameFile)
{
  ifstream myFile;
  string line;
  int rowCount = 0;
  myFile.open(nameFile);
  while(!myFile.eof())
  {
    getline(myFile, line);
    rowCount++;
  }
  myFile.close();
  return rowCount;
}

int getCol(string nameFile)
{
  ifstream myFile;
  string line;
  int colCount = 0;
  int temp = 0;

  myFile.open(nameFile);
  while(!myFile.eof())
  {
    getline(myFile, line);
    istringstream ss(line);
    do 
    { 
      string word; 
      ss >> word;
      temp++;

      if(temp > colCount)
      {
        colCount = temp;
      }
    } while (ss);
  }
  myFile.close();
  return colCount;
}

void editString(string input)
{
  istringstream ss(input); 
  do 
  { 
    string word; 
    ss >> word; 

    myKey.push_back(word);
  } while (ss); 
}
