#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> getWizard();
vector<string> getHolidays();
void printMenu();
void printMagicians();
void printHolidays();
bool magicianCheck(int choice);
void addMagicians(string magicAgent);
void fireMagicians(string fireAgent);
void deleteBooking(string dName, string dHoliday);
void printStatus(string magicianName, string magicianDay);

int main() 
{
  string signPerson;
  string firePerson;
  string magicName;
  string holiName;
  string cName;
  string nameCustomer;
  string cancelName;
  string cancelHoliday;
  fstream outFile;
  int holiday;
  int givenName;
  bool done;
  bool moveOn = true;
  int menu;
  vector<int> schedual;
  fstream openCheck;
  ofstream outfile ("Magic.txt");

  
  printMenu();

  do
  {
    done = true;
    cin >> menu;
    switch(menu)
    {
       case 1:
        //scheduel
         //promt user for name
        cout << "What is your name? ";
        cin >> nameCustomer;
        cout << endl;

        //promt user for magician name
        cout << "what is the number of the magician you want to schedual? " << endl;
        printMagicians();
        cout << "Please input a number. " << endl;
        cin >> givenName;
      
        //check if magician exists
        if(givenName < 11 && givenName > -1)
        {
          cout << "Magician is found. " << endl << endl;
        }
        else
        {
          cout << "Wrong Input" << endl;
          break;
        }

        //promt user for holiday
         cout << "What is your name of the holiday to be scheduled? " << endl;
         printHolidays();
         cout << "Please input a number. " << endl;
         cin >> holiday;

        //check if holiday exists
        if(holiday < getHolidays().size() && holiday > getHolidays().size() - getHolidays().size())
        {
          cout << "Holiday is found. " << endl << endl;
        }
        else
        {
          cout << "Wrong Input" << endl;
          break;
        }
        //check if their is over lap  in schedual
        openCheck.open("Magic.txt");
        while (!openCheck.eof())
        {
          openCheck >> magicName >> holiName >> cName;
          if(getWizard()[givenName-1] == magicName && 
            getHolidays()[holiday-1] == holiName)
          {
            openCheck.close();
            cout << "The magician is booked on that day. " << endl;
            cout << nameCustomer << " have been put on a waiting list." << endl; 
            moveOn = false;
            break;
          }
        }
        if (moveOn == true)
        {
          openCheck.close();
          outFile.open("Magic.txt", std::ios_base::app);
          outFile << getWizard()[givenName-1] << " " << getHolidays()[holiday-1] << 
          " " << nameCustomer << endl;
          cout << "Booking has Been Made" << endl;
          outFile.close();
        }
        else 
        {
          break;
        }
        
        break;

        case 2:
          //cancel
          cout << "What is your name. ";
          cin >> cancelName;
          cin >> cancelHoliday;
          deleteBooking(cancelName, cancelHoliday);
          break;
        case 3:
          //signUp
          cout << "What magician do you want to sign up? " << endl;
          cin >> signPerson;
          addMagicians(signPerson);
          break;
        case 4:
          //dropout
          cin >> firePerson;
          fireMagicians(firePerson);
          break;
        case 5:
          //status
          break;

        case 6:
          //exit
          done = false;
          return 0;
          break;
    }
  } while (done == true);
  
}

//prints menu
void printMenu()
{
  cout << "Magician Holiday Menu" << endl;
  cout << "1. SCHEDULE" << endl;
  cout << "2. CANCEL" << endl;
  cout << "3. SIGNUP" << endl;
  cout << "4. DROPOUT" << endl;
  cout << "5. STATUS" << endl;
  cout << "6. QUIT" << endl;
}
//prints magician name
void printMagicians()
{
  for(int i = 0; i < getWizard().size(); i++)
  {
    cout<< i + 1 << ", " << getWizard()[i] << endl;
  }
}
//vecot of holidays names
vector<string> getWizard()
{
  vector<string> wizard;
  string wizardName;
  fstream myFile;
  myFile.open("Magician.txt");

  //get names from file line by line into vector until end of file
  while (!myFile.eof())
  {
    getline(myFile, wizardName);
    wizard.push_back(wizardName);
  }
  return wizard;
}
//prints holidays name
void printHolidays()
{
  for(int i = 0; i < getHolidays().size(); i++)
  {
    cout<< i + 1 << ", " << getHolidays()[i] << endl;
  }
}
//vector of holidays
vector<string> getHolidays()
{
  vector<string> holiDay;
  string dayName;

  //open file holidays
  fstream myDays;
  myDays.open("Holidays.txt");

  //get names from file line by line into vector until end of file
  while (!myDays.eof())
  {
    getline(myDays, dayName);
    holiDay.push_back(dayName);
  }
  myDays.close();

  return holiDay;
}
//add magician to roster
void addMagicians(string magicAgent)
{
  try
  {
   ofstream addMagic;
   addMagic.open("Magician.txt", std::ios_base::app);
   addMagic << magicAgent;
   cout << "Magician Add Success" << endl;
   addMagic.close();
  } catch (...)
  {
    throw magicAgent;
    cout << magicAgent << " Is Not A Valid Input. " << endl;
  }
  
}
//rid a magician from the roster
void fireMagicians(string fireAgent)
{
  vector<string> magicPersons;
  string magicName;
  ifstream exitMagic;
  exitMagic.open("Magician.txt");
  while(!exitMagic.eof())
  {
    getline(exitMagic, magicName);
    magicPersons.push_back(magicName);
  }
  exitMagic.close();

  ofstream newList;
  newList.open("Magician.txt");
  for(int i = 0; i < magicPersons.size(); i++)
  {
    newList << magicPersons[i];
  }
  newList.close();
}
void deleteBooking(string dName, string dHoliday)
{
  vector<string> newBooking;
  string magicName;
  string dayName;
  string personName;
  ifstream takeSchedule;
  takeSchedule.open("Magic.txt");
  while(!takeSchedule.eof())
  {
    takeSchedule >> magicName >> dayName >> personName;
    if ((dayName == dHoliday) && (personName == dName))
    {
      newBooking.pop_back();
      newBooking.pop_back();
      newBooking.pop_back();
    }
    newBooking.push_back(magicName);
    newBooking.push_back(dayName);
    newBooking.push_back(personName);
  }
  takeSchedule.close();

  ofstream newList;
  newList.open("Magician.txt");
  for(int i = 0; i < newBooking.size(); i++)
  {
    newList << newBooking[i];
  }
  newList.close();
}
void printStatus(string magicianName, string magicianDay)
{
  vector<string> wholeStatus;
  string magicN;
  string dayN;
  string personN;
  ifstream finalStats;
  finalStats.open("Magic.txt");
  while(!finalStats.eof())
    {
      finalStats >> magicN >> dayN >> personN;
      if ((dayN == magicianName) || (personN == magicianName))
      {
        wholeStatus.push_back(magicN);
        wholeStatus.push_back(dayN);
        wholeStatus.push_back(personN);
      }
    }
    finalStats.close();
    for(int i = 0; i <= wholeStatus.size()/3; i++)
    {
      cout << "Magician: " <<wholeStatus[i] << " Holiday: " << wholeStatus[i+ 1] << " Customer: " << wholeStatus[i+2] << endl;
    }
}
