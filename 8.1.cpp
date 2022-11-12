#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <time.h>
using namespace std;

int main()
{
    string Filename;
    ifstream InFile;
    ofstream OutFile;
    int Value;
    srand(time(0));
    cout << "Enter file name : ";
    cin >> Filename;
    cout << endl;

    // open output file for write data
    OutFile.open(Filename.c_str());
    cout << "Now open file " << Filename << " for write" << endl;

    // Get name from keyboard
    for (int n = 1; n <= 10; n++)
    {
        Value = rand() % 100;
        cout << setw(5) << Value;

        // write value( intgeter number ) to output file
        OutFile << Value << " ";
    }
    cout << endl;
    OutFile.close();

    // close output file
    cout << "Now close file " << Filename << ".\n\n";

    // open input file for read data
    InFile.open(Filename.c_str());
    cout << "Now open file " << Filename << " for read." << endl;

    // Read name from input file
    for (int n = 1; n <= 10; n++)
    {
        InFile >> Value;
        cout << setw(5) << Value;
    }
    cout << endl;
    InFile.close();

    // close input file
    cout << "Now close file " << Filename << ".\n\n";
    return (0);
}