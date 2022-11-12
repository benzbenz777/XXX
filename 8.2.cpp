#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
void GetandWrite(ofstream &OutFile);
void ReadandDisplay(ifstream &InFile);
int main()
{
    string Filename;
    ifstream InFile;
    ofstream OutFile;
    cout << "Enter file name : ";
    cin >> Filename;
    cout << endl;
    
    // open output file for write data
    OutFile.open(Filename.c_str());
    cout << "Now open file " << Filename << " for write." << endl;
    GetandWrite(OutFile);
    OutFile.close();
    cout << "Now close file " << Filename << ".\n\n";
    // open input file for read data
    InFile.open(Filename.c_str());
    cout << "Now open file " << Filename << " for read." << endl;
    ReadandDisplay(InFile);
    InFile.close();
    cout << "Now close file " << Filename << ".\n\n";
    return (0);
}

void GetandWrite(ofstream &OutFile)
{
    string Id, Name, SurName;
    int Score;
    // Get data from keyboard
    for (int n = 1; n <= 3; n++)
    {
        cout << "\nStudent No. " << n << endl;
        cout << "Enter Id : ";
        cin >> Id;
        cout << "Enter Name : ";
        cin >> Name;
        cout << "Enter SurName : ";
        cin >> SurName;
        cout << "Enter Score : ";
        cin >> Score;
        // write value( intgeter number ) to output file
        OutFile << Id << " " << Name << " ";
        OutFile << SurName << " " << Score << endl;
    }
    cout << endl;
}

void ReadandDisplay(ifstream &InFile)
{
    string Id, Name, SurName;
    int Score;
    // Read name from input file
    for (int n = 1; n <= 3; n++)
    {
        // read name from inputfile
        InFile >> Id >> Name >> SurName >> Score;
        cout << Id << " " << Name << " " << SurName;
        cout << " " << Score << endl;
    }
    cout << endl;
}