#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
int Menu();
void AddStudent(string FN);
void DisplayStudent(string FN);
void ReportGrade(string FN);
int main()
{
    const string Filename = "student.dat";
    ifstream InFile;
    ofstream OutFile;
    int c;
    do
    {
        system("cls");
        // call external command
        c = Menu();
        switch (c)
        {
        case 1:
            AddStudent(Filename);
            break;

        case 2:
            DisplayStudent(Filename);
            break;

        case 3:
            ReportGrade(Filename);
            break;
        }
    } while (c != 0);
    cout << "Exit program." << endl;
    return (0);
}

int Menu()
{
    string line(25, '=');
    int Choose;
    cout << "Program Add-Display Student Data\n";
    cout << line << endl;
    cout << ":      Main Menu       :\n";
    cout << line << endl;
    cout << ":  0 -Exit             :\n";
    cout << ":  1 -Add Student      :\n";
    cout << ":  2 -Display Student  :\n";
    cout << ":  3 -Report Grade     :\n";
    cout << line << endl;
    cout << " Enter choose : ";
    cin >> Choose;
    return (Choose);
}

void AddStudent(string FN)
{
    // open file for write and append
    ofstream OutFile(FN.c_str(), ios_base::out | ios_base::app);
    if (OutFile.is_open())
    {
        string Id, Name, Grade;
        int Score;
        cout << "\n Add Student \n";
        cout << "Enter id : ";
        cin >> Id;
        cout << "Enter name : ";
        cin >> Name;
        cout << "Enter score : ";
        cin >> Score;

        if (Score < 50)
        {
            Grade = "F";
        }
        else if (Score < 55)
        {
            Grade = "D";        
        }
        else if (Score < 60)
        {
            Grade = "D+";       
        }
        else if (Score < 65)
        {
            Grade = "C";
        }
        else if (Score < 70)
        {
            Grade = "C+";
        }
        else if (Score < 75)
        {
            Grade = "B";
        }
        else if (Score < 80)
        {
            Grade = "B+";
        }
        else if (Score >= 80)
        {
            Grade = "A";
        }

        // write data to file student.dat
        OutFile << Id << " " << Name << " "<< Score << " " << Grade << endl;
        OutFile.close();
        char Wait;
        cin.get(Wait);
        cout << "\nSaved already ,Press Enter to continue";
        cin.get(Wait);
    }
    else
        cout << "File could not opened." << endl;
}

void DisplayStudent(string FN)
{
    ifstream InFile(FN.c_str(), ios_base::in);
    // open file for read
    if (InFile.is_open())
    {
        string Id, Name;
        string line(30, '=');
        int n = 0;
        cout << "\nList Student\n";
        cout << line << endl;
        cout << " No.   Id      Name \n";
        cout << line << endl;
        // read data from file student.dat
        InFile >> Id >> Name;

        while (!InFile.eof())
        {
            n = n + 1;
            cout << right << setw(3) << n << " : ";
            cout << left << setw(6) << Id;
            cout << "  " << Name << endl;
            InFile >> Id >> Name;
        }

        InFile.close();
        char Wait;
        cin.get(Wait);
        cout << "\nPress Enter to continue";
        cin.get(Wait);
    }
    else
        cout << "File could not opened." << endl;
}

void ReportGrade(string FN)
{
    ifstream InFile(FN.c_str(), ios_base::in);
    // open file for read
    if (InFile.is_open())
    {
        string Id, Name ,Grade;
        int Score;
        string line(60, '=');
        int n = 0;
        cout << "\nList Student\n";
        cout << line << endl;
        cout << " No.  Id               Name      Score     Grade \n";
        cout << line << endl;

        // read data from file student.dat
        InFile >> Id >> Name >> Score >> Grade;

        while (!InFile.eof())
        {
            n = n + 1;
            cout << right << setw(3) << n << " : ";
            cout << left << setw(6) << Id;
            cout << setw(3) << " " << Name;
            cout << setw(4) << " " << Score;
            cout << setw(9) << " " << Grade << endl;
            InFile >> Id >> Name >> Score >> Grade;
        }

        InFile.close();
        char Wait;
        cin.get(Wait);
        cout << "\nPress Enter to continue";
        cin.get(Wait);
    }
    else
        cout << "File could not opened." << endl;
}


