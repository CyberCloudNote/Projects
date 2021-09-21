#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void printMenu();
void printSpecRooms();
void printExamRooms();
void printRoomChoice();
void updateSpecRoom(int choiceSpec);
void updateExamRoom(int choiceExam);
void deleteDoctor(string wholeName);
void matchDoc(string patientName);
void patientCheckOut(string nameOut);

int main() 
{
  int menu;
  int typeRoom;
  int roomNum;
  int specialOrExam;
  int sRoom;
  int eRoom;
  int age;
  bool veryHurt;
  string firstName;
  string lastName;
  string fullName;
  vector <int> roomData;
  queue<string> waitList;
  queue<string> specRoom1;
  ofstream doctorData;

  do
  {
    printMenu();
    cin >> menu;
    switch(menu)
    {
       case 1:
       cout << "Doctor Check-Ins" << endl << endl;
       cout << "Doctor what is you first name?" << endl;
       cin >> firstName;
       cout << "Doctor what is you last name?" << endl;
       cin >> lastName;
       cout << endl;
       fullName = firstName + "_" + lastName;
       //puts name of in list of present doctors
       doctorData.open("DoctorIn.txt", std::ios_base::app);
       doctorData << fullName << endl;
       //ask for room
        cout << "What type of room would you like?" << endl;
        printRoomChoice();
        cin >> specialOrExam;
        if(specialOrExam == 1)
        {
          printSpecRooms();
          cin >> sRoom;
          //exception handling: break if slecting room over the parameters
          if (sRoom < 1 || sRoom > 13)
          {
          cout << "Invalid Room Number" << endl;
          break;
          }
          sRoom = sRoom - 1;
          updateSpecRoom(sRoom);
        }
        else if (specialOrExam == 2)
        {
          printExamRooms();
          cin >> eRoom;
          //exception handling: break if slecting room over the parameters
          if (eRoom < 1 || eRoom > 21)
          {
            cout << "Invalid Room Number" << endl;
            break;
          }
          eRoom = eRoom - 1;
          updateExamRoom(eRoom);
        }
        break;
      case 2:
        cout << "Doctor Check-Out" << endl << endl;
        cout << "What is your first name?" << endl;
        cin >> firstName;
        cout << "What is your last name?" << endl;
        cin >> lastName;
        fullName = firstName + "_" + lastName;
        deleteDoctor(fullName);
        cout << "What type of room did you check-out from?" << endl;
        cout << "1. Special Room" << endl;
        cout << "2. Examination Room" << endl;
        cin >> typeRoom;
        if(typeRoom == 1)
        {
          cout << "Special Room Number: ";
          cin >> roomNum;
        }
        else if (typeRoom == 2)
        {
          cout << "Examination Room Number: ";
          cin >> roomNum;
        }
        break;
       case 3:
        cout << "Patient Check-In" << endl << endl;
        cout << "What is your first name?" << endl;
        cin >> firstName;
        cout << "What is your last name?" << endl;
        cin >> lastName;
        fullName = firstName + "_" + lastName;
        cout << "What is the age of the patients?" << endl;
        cin >> age;
        cout << "Is your visit an emergancy?" << endl;
        cout << "1, Yes" << endl;
        cout << "2. No" << endl;
        cin >> veryHurt;

        if(veryHurt == true)
        {
          string first = waitList.front();
          waitList.front() = fullName.back();
          waitList.pop();
          waitList.push(first);
        }
        else if(age < 16)
        {
          specRoom1.push(fullName);
        }
        else
        {
          waitList.push(fullName);
        }
        matchDoc(waitList.front());

        break;
       case 4:
        cout << "Patient Check-Out" << endl << endl;
        cout << "Patient Check-In" << endl << endl;
        cout << "What is your first name?" << endl;
        cin >> firstName;
        cout << "What is your last name?" << endl;
        cin >> lastName;
        fullName = firstName + "_" + lastName;
        patientCheckOut(fullName);
        break;
       case 5:
          //exit
          cout << "Exiting Menu" << endl;
          return 0;
          break;
    }
  } while (true);
}
void printMenu()
{
  cout << "Hospitol Menu" << endl;
  cout << "1. Doctor Check-In" << endl;
  cout << "2. Doctor Check-Out" << endl;
  cout << "3. Patient Check-In" << endl;
  cout << "4. Patient Check-Out" << endl;
  cout << "5. QUIT" << endl;
}
void printSpecRooms()
{
  cout << "List of all Special Rooms" << endl << endl;
  cout << "1.Pediatrics " << endl;
  cout << "2.General practice " << endl;
  cout << "3.Internal medicine " << endl;
  cout << "4.Cardiology " << endl;
  cout << "5.Surgeon " << endl;
  cout << "6.Obstetrics " << endl;
  cout << "7.Psychiatry " << endl;
  cout << "8.Neurology " << endl;
  cout << "9.Orthopedics " << endl;
  cout << "10.Dermatology " << endl;
  cout << "11.Ophthalmology " << endl;
  cout << "12.Ear, Nose, and Throat " << endl;
}
void printExamRooms()
{
  cout << "List of all Examination Rooms" << endl;
  cout << "1.  Examination Room #1" << endl;
  cout << "2.  Examination Room #2" << endl;
  cout << "3.  Examination Room #3" << endl;
  cout << "4.  Examination Room #4" << endl;
  cout << "5.  Examination Room #5" << endl;
  cout << "6.  Examination Room #6" << endl;
  cout << "7.  Examination Room #7" << endl;
  cout << "8.  Examination Room #8" << endl;
  cout << "9.  Examination Room #9" << endl;
  cout << "10. Examination Room #10" << endl;
  cout << "11. Examination Room #11" << endl;
  cout << "12. Examination Room #12" << endl;
  cout << "13. Examination Room #13" << endl;
  cout << "14. Examination Room #14" << endl;
  cout << "15. Examination Room #15" << endl;
  cout << "16. Examination Room #16" << endl;
  cout << "17. Examination Room #17" << endl;
  cout << "18. Examination Room #18" << endl;
  cout << "19. Examination Room #19" << endl;
  cout << "20. Examination Room #20" << endl;
}
void printRoomChoice()
{
  cout << "1. Special Room" << endl;
  cout << "2. Examination Room" << endl;
}

void updateSpecRoom(int choiceSpec)
{
  vector<int> specStatus;
  int values;
  ifstream specRoom;
  specRoom.open("SpecialRoomStatus.txt");
  do
  {
    specRoom >> values;
    specStatus.push_back(values);
  } while (!specRoom.eof());
  specRoom.close();

  if(specStatus[choiceSpec] == 0)
  {
    specStatus[choiceSpec] = 1;
    ofstream specRoomOccupied;
    specRoomOccupied.open("SpecialRoomStatus.txt");
    for(int i = 0; i < specStatus.size(); i++)
    {
      specRoomOccupied << specStatus[i] << endl;
      i++;
    }
    cout << "Special room " << choiceSpec + 1 << " is assigned to you." << endl << endl;
  }
  else if (specStatus[choiceSpec] == 1)
  {
    cout << "Special room " << choiceSpec + 1 << " is unavalible." << endl;
  }
}

void updateExamRoom(int choiceExam)
{
  vector<int> examStatus;
  int values;
  ifstream examRoom;
  examRoom.open("ExamRoomStatus.txt");
  do
  {
    examRoom >> values;
    examStatus.push_back(values);
  } while (!examRoom.eof());
  examRoom.close();

  if(examStatus[choiceExam] == 0)
  {
    examStatus[choiceExam] = 1;
    ofstream examRoomOccupied;
    examRoomOccupied.open("ExamRoomStatus.txt");
    for(int i = 0; i < examStatus.size(); i++)
    {
      examRoomOccupied << examStatus[i] << endl;
      i++;
    }
    cout << "Examination room " << choiceExam + 1 << " is assigned to you." << endl << endl;
  }
  else if (examStatus[choiceExam] == 1)
  {
    cout << "Examination room " << choiceExam + 1 << " is unavalible." << endl;
  }
}

void deleteDoctor(string wholeName)
{
  vector<string> allDoctors;
  ifstream doctorList;
  doctorList.open("DoctorIn.txt", std::ios_base::app);
  string nameData;
  do
  {
    doctorList >> nameData;
    //push back all data except the doctor that wants to check-out
    if(nameData != wholeName)
    {
      allDoctors.push_back(nameData);
    }
    else if (nameData == wholeName)
    {
      cout << "Name found. " << endl;
      replace( nameData.begin(), nameData.end(), '_', ' ');
      cout << "Doctor " << nameData << " has been Chacked-Out" << endl << endl;
    }
  }while(!doctorList.eof());
  doctorList.close();

  ofstream doctorRemoved;
  doctorRemoved.open("DoctorIn.txt", std::ios_base::app);
  string newData;
  for(int i = 0; i < allDoctors.size(); i++)
  {
    doctorRemoved << allDoctors[i];
    i++;
  }
  doctorRemoved.close();
}

void docSpecRoomOut(int roomNum)
{
  vector<int> roomSpecData;
  int values;
  ifstream specRoomOut;
  specRoomOut.open("SpecRoomStatus.txt");
  do
  {
    specRoomOut >> values;
    roomSpecData.push_back(values);
  } while (!specRoomOut.eof());
  specRoomOut.close();

  roomSpecData[roomNum] = 0;
  ofstream specRoomClear;
  specRoomClear.open("SpecRoomStatus.txt");
  for(int i = 0; i < roomSpecData.size(); i++)
  {
    specRoomClear << roomSpecData[i] << endl;
    i++;
  }
}

void docExamRoomOut(int roomNum)
{
  vector<int> roomExamData;
  int values;
  ifstream examRoomOut;
  examRoomOut.open("ExamRoomStatus.txt");
  do
  {
    examRoomOut >> values;
    roomExamData.push_back(values);
  } while (!examRoomOut.eof());
  examRoomOut.close();

  roomExamData[roomNum] = 0;
  ofstream examRoomClear;
  examRoomClear.open("ExamRoomStatus.txt");
  for(int i = 0; i < roomExamData.size(); i++)
  {
    examRoomClear << roomExamData[i] << endl;
    i++;
  }
}

void matchDoc(string patientName)
{
  //get list of doctors that checked in
  ifstream avalibleDoc;
  int choice;
  avalibleDoc.open("DoctorIn.txt");
  vector<string> allDocs;
  string docName;
  do
  {
    avalibleDoc >> docName;
    allDocs.push_back(docName);
  } while (!avalibleDoc.eof());
  avalibleDoc.close();

  cout << "Avalible Doctors" << endl << endl;
  for(int i = 0; i < allDocs.size(); i++)
  {
    replace( allDocs[i].begin(), allDocs[i].end(), '_', ' ');
    cout<< i + 1 << ", " << allDocs[i] << endl;
  }
  cout << "What doctor do you want? " << endl;
  cin >> choice;

  ofstream pairClient;
  pairClient.open("InTreatment.txt", std::ios_base::app);
  pairClient << docName[choice] << patientName;
  pairClient.close();

  ofstream doctorRemoved;
  doctorRemoved.open("DoctorIn.txt", std::ios_base::app);
  string newData;
  for(int i = 0; i < allDocs.size(); i++)
  {
    doctorRemoved << allDocs[i];
    i++;
  }
  doctorRemoved.close();
}

void patientCheckOut(string nameOut)
{
  ifstream patientOut;
  patientOut.open("InTreatment.txt");
  vector<string> allDoc;
  vector<string> allPatients;
  string docName;
  string patientName;
  string finishedDoctor;
  do
  {
    patientOut >> docName >> patientName;
    allDoc.push_back(docName);
    allPatients.push_back(patientName);
  } while (!patientOut.eof());
  patientOut.close();

  ofstream updatedPairs;
  updatedPairs.open("InTreatment.txt", std::ios_base::app);
  for(int i = 0; i < allDoc.size(); i++)
  {
    if(nameOut != patientName)
    {
      updatedPairs << allDoc[i] << allPatients[i];
      i++;
    }
    else if (nameOut == patientName)
    {
      finishedDoctor = allDoc[i];
      replace( allDoc[i].begin(), allDoc[i].end(), '_', ' ');
      cout  << "Doctor " << allDoc[i] << "has finished treating this patient." << endl;
      replace( allPatients[i].begin(), allPatients[i].end(), '_', ' ');
      cout << allPatients[i] << " has been released." << endl;
      i++;
    }

    ofstream freeDoc;
    freeDoc.open("DoctorIn.txt", std::ios_base::app);
    freeDoc << finishedDoctor;
  }
}
