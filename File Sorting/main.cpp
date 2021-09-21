#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;

void printMenu();
void test();
bool cleanFile(char remPunc);
void readData();
void readNum();
void sortData();
void sortNum();
void modNums();
void writeFile();
void writeFileNum();
void writeSortedNum();
void yearRange(int yearOne, int yearTwo);
void disasterYears(string typeDis);
void makeReport(string myYear);
void chainReport();
bool ridCom(char remCom);
vector<string> storeLine;
vector<string> storeName; //Name of disaster
vector<string> storeDate; //Type of disaster
vector<string> storeNum;
vector<string> storeSortNum;
vector<string> storeYear; //Year of disaster
vector<string> storeProp; //Property damage of disaster (millions)
vector<string> storeDeath; //Number of death of disaster
vector<string> summaryData; //summary file data

int main() 
{
  int menu, startYear, endYear;
  string disName;
  string nameFile;

  //store data
  readData();

  //writeData
  writeFile();

  //solrt data
  sortData();

  // write numbers
  writeFileNum();

  //read numbers
  readNum();

  //sort nums in vectors
  sortNum();
 do
 {
    printMenu();
    cout << endl;
    cout <<"select a option: ";
    cin >> menu;
    cout << endl;
    if(menu > 0 && menu < 4)
    {
      switch(menu)
      {
        case 1:
        cout << "Enter beginning year: ";
        cin >> startYear; 
        cout << "Enter ending year: ";
        cin >> endYear;
        cout << endl;
        yearRange(startYear, endYear);
        cout << endl;
          break;
        case 2:
        cout << "Enter an Disaster name: " << endl;
        cin >> disName;
        cout << endl;
        disasterYears(disName);
        cout << endl;
          break;
        case 3: 
        cout << "Enter output file name: ";
        cin >> nameFile;
        ofstream makeFile;
        makeFile.open(nameFile);
        chainReport();
        makeFile << "Year; Disasters; Total deaths" << endl;
        cout << "Year; Disasters; Total deaths" << endl;
        for(int i = 0; i < summaryData.size(); i++)
        {
          makeFile << summaryData[i] << endl;
          cout << summaryData[i] << endl;
        }
        cout << "NOTE: Sample data of Disasters_summary.txt for 2012 to 2019 is shown here." << endl;
          return 0;
      }
    }
    else
    {
      cout << "Invalid Input!" << endl;
      cout << "Please Input 1, 2, or 3 form the menu options." << endl;
    }

  }
  while(true);
}

void printMenu()
{
  cout << "What would you like to do?" << endl;
  cout << "1: Look up year range" << endl;
  cout << "2: Look up disaster" << endl;
  cout << "3: Generate summary report" << endl;
}

bool cleanFile(char remPunc)
{
   if(remPunc== '"')
   {
     return true;
   }
   else
   {
     return false;
   }
}

bool ridCom(char remCom)
{
   if(remCom == ',')
   {
     return true;
   }
   else
   {
     return false;
   }
}

void readData()
{
  string temp;
  ifstream inFile;
	inFile.open("catastrophe.txt");
  if (!inFile)
	{
		cout << "The File Failed to Open!" << endl;
		cout << "Exiting!" << endl;
	}
  else
  {
     while(!inFile.eof())
     {
        getline(inFile, temp);
        storeLine.push_back(temp);
      }
      
      inFile.close();
        
      for(int i = 0; i <= storeLine.size(); i++)
      {
        string myWord = storeLine[i];
        for(int j = 0; j <= myWord.size(); j++)
        {
          if (cleanFile(myWord[j]))
          {
            myWord[j] = '\n';
            storeLine[i] = myWord;
          }
        }
      }
  }
}

void sortData()
{
  string temp, empty;
  string wordA, wordB, wordC, wordD;
  ifstream inFile;
	inFile.open("HandleWords.txt");
  if (!inFile)
	{
		cout << "The File Failed to Open!" << endl;
		cout << "Exiting!" << endl;
	}
  else
  {
    getline(inFile, empty);
     while(!inFile.eof())
     {
        getline(inFile, wordA);
        storeName.push_back(wordA);
        getline(inFile, wordB);
        getline(inFile, wordC);
        storeDate.push_back(wordC);
        getline(inFile, wordD);
        storeNum.push_back(wordD);
      }
      
      inFile.close();
        
      //for(int i = 0; i <= storeName.size()-1; i++)
      //{
        //cout << storeName[i] << endl;
        //cout << storeDate[i] << endl;
        //cout << storeNum[i] << endl;
      //}
  }
}
void modNums()
{
  string temp;
  ifstream inFile;
	inFile.open("catastrophe.txt");
  if (!inFile)
	{
		cout << "The File Failed to Open!" << endl;
		cout << "Exiting!" << endl;
	}
  else
  {
     while(!inFile.eof())
     {
        getline(inFile, temp);
        storeSortNum.push_back(temp);
      }
      
      inFile.close();
        
      for(int i = 0; i <= storeSortNum.size(); i++)
      {
        string myWord = storeLine[i];
        for(int j = 0; j <= myWord.size(); j++)
        {
          if (ridCom(myWord[j]))
          {
            myWord[j] = '\n';
            storeSortNum[i] = myWord;
          }
        }
      }
  }
}
void writeFile()
{
  ofstream outFile;
  outFile.open("HandleWords.txt");
  for(int i = 0; i <= storeLine.size()-1 ; i++)
  {
    outFile << storeLine[i] ;
  }
  outFile.close();
}

void writeFileNum()
{
  ofstream outFile;
  outFile.open("HandleNumbers.txt");
  for(int i = 0; i <= storeLine.size()-1 ; i++)
  {
    outFile <<  storeNum[i] << endl;
  }
  outFile.close();
}

void writeSortedNum()
{
  ofstream outFile;
  outFile.open("HandleNumbers.txt");
  for(int i = 0; i <= storeLine.size()-1 ; i++)
  {
    outFile << storeLine[i];
  }
  outFile.close();
}

void readNum()
{
  string temp;
  ifstream inFile;
	inFile.open("HandleNumbers.txt");
  vector<string> storeLine;

  if (!inFile)
	{
		cout << "The File Failed to Open!" << endl;
		cout << "Exiting!" << endl;
	}
  else
  {
     while(!inFile.eof())
     {
        getline(inFile, temp);
        storeLine.push_back(temp);
      }
      
      inFile.close();
        
      for(int i = 0; i <= storeLine.size(); i++)
      {
        string myWord = storeLine[i];
        for(int j = 0; j <= myWord.size(); j++)
        {
          if (ridCom(myWord[j]))
          {
            myWord[j] = '\n';
            storeLine[i] = myWord;
          }
        }
      }
  }
  ofstream outFile;
  outFile.open("HandleNumbers.txt");
  for(int i = 0; i <= storeLine.size()-1 ; i++)
  {
    outFile << storeLine[i];
  }
  outFile.close();
}

void sortNum()
{
  string temp, empty;
  string wordA, wordB, wordC;
  ifstream inFile;
	inFile.open("HandleNumbers.txt");
  if (!inFile)
	{
		cout << "The File Failed to Open!" << endl;
		cout << "Exiting!" << endl;
	}
  else
  {
    getline(inFile, empty);
     while(!inFile.eof())
     {
        getline(inFile, wordA);
        storeYear.push_back(wordA);
        getline(inFile, wordB);
        storeProp.push_back(wordB);
        getline(inFile, wordC);
        storeDeath.push_back(wordC);
      }
      
      inFile.close();
        
      for(int i = 0; i <= storeYear.size()-1; i++)
      {
        //cout << storeYear[i] << endl;
        //cout << storeProp[i] << endl;
        //cout << storeDeath[i] << endl;
      }
  }
}
void yearRange(int yearOne, int yearTwo)
{
  for(int i = yearOne; i <= yearTwo; i++)
  {
    for(int j = 0; j < storeYear.size(); j++)
    {
      if(i == stoi(storeYear[j]))
      {
        cout << storeName[j] << endl;
      }
    }
  }
}
void disasterYears(string typeDis)
{
  vector<string> disYear; 
  for(int i = 0; i <= storeDate.size(); i++)
  {
    if(typeDis == storeDate[i])
    {
      disYear.push_back(storeYear[i]);
    }
  }
  disYear.erase(unique(disYear.begin(), disYear.end() ), disYear.end());

  cout << "Years when disaster happened are: ";
  for(int i = 0; i < disYear.size(); i++)
  {
    if(i < disYear.size()-1)
    {
      cout << disYear[i] << ", ";
    }
    else
    {
      cout << disYear[i];
    }
  }
  cout << endl;
}

void makeReport(string myYear)
{
  string arr[7] = {"Severe Storm", "Tropical Cyclone","Wildfire","Drought","Flooding","Winter Storm","Freeze"};
  string allData, disCombine;
  vector<string> typeDis;
  vector<string> printDis;
  int countA = 0;
  int countB = 0;
  int countC = 0;
  int countD = 0;
  int countE = 0;
  int countF = 0;
  int countG = 0;
  int totalDeath = 0;
  ofstream outFile;
  outFile.open("Disasters_summary.txt");
  outFile << "Year; Disasters; Total deaths"; 

  for(int i = 0; i <= storeDate.size()-1; i++)
  {
    if(storeYear[i] == myYear)
    {
      totalDeath = totalDeath + stoi(storeDeath[i]);
      typeDis.push_back(storeDate[i]);
    }
  }

  for(int i = 0; i < typeDis.size()-1; i++)
  {
    if(typeDis[i] == arr[0])
    {
      countA++;
      if(countA == 1)
      {
        printDis.push_back(arr[0]);
      }
    }
    else if(typeDis[i] == arr[1])
    {
      countB++;
      if(countB == 1)
      {
        printDis.push_back(arr[1]);
      }
    }
    else if(typeDis[i] == arr[2])
    {
      countC++;
      if(countC == 1)
      {
        printDis.push_back(arr[2]);
      }
    }
    else if(typeDis[i] == arr[3])
    {
      countD++;
      if(countD == 1)
      {
        printDis.push_back(arr[3]);
      }
    }
    else if(typeDis[i] == arr[4])
    {
      countE++;
      if(countE == 1)
      {
        printDis.push_back(arr[4]);
      }
    }
    else if(typeDis[i] == arr[5])
    {
      countF++;
      if(countF == 1)
      {
        printDis.push_back(arr[5]);
      }
    }
    else if(typeDis[i] == arr[6])
    {
      countG++;
      if(countG == 1)
      {
        printDis.push_back(arr[6]);
      }
    }
  }

  for(int i = 0; i < printDis.size(); ++i)
  {
    disCombine = disCombine + printDis[i];
    if(i < printDis.size()-1)
    {
      disCombine = disCombine + ", ";
    }
  }

  allData = myYear +"; "+ disCombine + "; " + to_string(totalDeath);

  summaryData.push_back(allData);
}

void chainReport()
{
  for(int i = 2012; i <= 2019; i++)
  {
    makeReport(to_string(i));
  }
}
