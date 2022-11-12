#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <direct.h>
using namespace std;


int ID,Cnum = 0,OrderID,SSumtotal = 0;
string Pid[100] = {};
string Pname[100] = {};
string PpriceS[100] = {};
string Punit[100] = {};

/*int Oid[3] = {};
int Ono[3] = {};
string Osize[3] = {};
int Oquan[3] = {};
int Ofour[3] = {};*/

struct Product
{
    int id;
    string name;
    string priceS;
    string unit;
};

/*struct Orders
{
    int OrderIds;
    int OrderQl;
    int OrderPid;
    int Orderflour;
    string OrderSize;
    int OrderQ;
    int OrderTT;
    int Orderwday;
    int Orderday;
    int Ordermount;
    int Orderyear;
    string Ordertime;
};*/

void Addproduct()
{
    Product pd;
    cout << "Enter toping name : ";
    cin.get();
    getline(cin, pd.name);
    cout << "Enter toping price : ";
    cin >> pd.priceS;
    cout << "Enter toping unit : ";
    cin >> pd.unit;
    ID++;

    ofstream write;
    write.open("C:/Pungping/product.txt", ios::app);
    write << "\n" << ID;
    write << "\n" << pd.name;
    write << "\n" << pd.priceS;
    write << "\n" << pd.unit;
    write.close();
    write.open("C:/Pungping/id.txt");
    write << ID;
    write.close();
    cout << "Data save to file" << endl;
}

void print(Product s)
{
    cout << right << ":" << setw(3) << s.id << " : " << setw(20) << s.name << " : " << setw(5) << s.priceS << " :" << setw(5)<< s.unit << "  :" << endl;
}

void Readdata()
{
    Product pd;
    ifstream read;
    read.open("C:/Pungping/product.txt");
    cout << "+===========================================+" << endl;
    cout << ": ID :         Name         : Price : Unit  :" << endl;
    cout << "+-------------------------------------------+" << endl;
    while (!read.eof())
    {
        read >> pd.id;
        read.ignore();
        getline(read, pd.name);
        read >> pd.priceS;
        read >> pd.unit;
        print(pd);
    }
    cout << "+===========================================+" << endl;
    read.close();
}

void Productlist()
{
    Product pd;
    ifstream read;
    read.open("C:/Pungping/product.txt");
    int x = 0;
    cout << "+==========================================+" << endl;
    cout << ": ID :         Name         : Price : Unit :" << endl;
    cout << "+------------------------------------------+" << endl;

    while (!read.eof())
    {
        string strid;

        read >> pd.id;
        read.ignore();
        getline(read, pd.name);
        read >> pd.priceS;
        read >> pd.unit;
       

        strid = to_string(pd.id);

        Pid[x] = strid;
        Pname[x] = pd.name;
        PpriceS[x] = pd.priceS;
        Punit[x] = pd.unit;
 

       cout << right << ":" << setw(3) << Pid[x] << " : " << setw(20) << Pname[x] << " : " << setw(5) << PpriceS[x] << " :" << setw(5) << " :" << endl;
        x++;
    }
    cout << "+=========================================+" << endl;
    read.close();
}

int searchData()
{
    int id;
    cout << "Enter id you want to search : ";
    cin >> id;
    Product pd;
    ifstream read;
    read.open("C:/Pungping/product.txt");
    while (!read.eof())
    {
        read >> pd.id;
        read.ignore();
        getline(read, pd.name);
        read >> pd.priceS;
        read >> pd.unit;
        if (pd.id == id)
        {
            cout << "+===========================================+" << endl;
            cout << ": ID :         Name         : Price : Unit  :" << endl;
            cout << "+-------------------------------------------+" << endl;
            print(pd);
            cout << "+===========================================+" << endl;
            return id;
        }
    }
}

void Updatedata()
{
    int id = searchData();
    cout << "You want to update record (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y')
    {
        Product newData;
        cout << "Enter new product name : ";
        cin.get();
        getline(cin, newData.name);
        cout << "Enter name : ";
        cin >> newData.name;
        cout << "Enter price : ";
        cin >> newData.priceS;
        cout << "Enter unit : ";
        cin >> newData.unit;
        Product pd;
        ofstream tempFile;
        tempFile.open("C:/Pungping/temp.txt");
        ifstream read;
        read.open("C:/Pungping/product.txt");
        while (!read.eof())
        {
            read >> pd.id;
            read.ignore();
            getline(read, pd.name);
            read >> pd.priceS;
            read >> pd.unit;
            if (pd.id != id)
            {
                tempFile << "\n" << pd.id;
                tempFile << "\n" << pd.name;
                tempFile << "\n" << pd.priceS;
                tempFile << "\n" << pd.unit;
            }
            else
            {
                tempFile << "\n" << pd.id;
                tempFile << "\n" << newData.name;
                tempFile << "\n" << newData.priceS;
                tempFile << "\n" << newData.unit;
            }
        }
        read.close();
        tempFile.close();
        remove("C:/Pungping/product.txt");
        rename("C:/Pungping/temp.txt", "C:/Pungping/product.txt");
        cout << "Data updated successfuly" << endl;
    }
    else
    {
        cout << "Record not deleted" << endl;
    }
}

void deleteData()
{
    int id = searchData();
    cout << "You want to delete record (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y')
    {
        Product pd;
        ofstream tempFile;
       tempFile.open("C:/Pungping/temp.txt");
        ifstream read;
        read.open("C:/Pungping/product.txt");
        while (!read.eof())
        {
            read >> pd.id;
            read.ignore();
            getline(read, pd.name);
            read >> pd.priceS;
            read >> pd.unit;
            if (pd.id != id)
            {
                tempFile << "\n" << pd.id;
                tempFile << "\n" << pd.name;
                tempFile << "\n" << pd.priceS;
                tempFile << "\n" << pd.unit;
            }
        }
        read.close();
        tempFile.close();
        remove("C:/Pungping/product.txt");
        rename("C:/Pungping/temp.txt", "C:/Pungping/product.txt");
        cout << "Data deleted successfuly" << endl;
    }
    else
    {
        cout << "Record not deleted" << endl;
    }
}

/*void datetime()
{
    time_t nows;
    struct tm datelc;
    nows = time(NULL);
    datelc = *localtime(&nows);
    cout << datelc.tm_mday << "/" << datelc.tm_mon + 1 << "/" << datelc.tm_year + 1900 << endl;
    cout << datelc.tm_hour << ":" << datelc.tm_min << ":" << datelc.tm_sec;
}*/

void Checkfile()
{
    ifstream read;
    read.open("C:/Pungping/id.txt");
    if (!read.fail())
    {
        read >> ID;
    }
    else
    {
        ID = 0;
    }
    read.close();
}

void admin(){
    Checkfile();
    bool check = false;
    do
    {
        cout << "1.ADD" << endl;
        cout << "2.Read" << endl;
        cout << "3.Update" << endl;
        cout << "4.Delete" << endl;
        cout << "5.Exit" << endl;
        int option;
        cout << "Enter option : ";
        cin >> option;
        if (option == 1)
        {
            system("CLS");
            Addproduct();
            check = false;
        }
        else if (option == 2)
        {
            system("CLS");
            Readdata();
            check = false;
        }
        else if (option == 3)
        {
            system("CLS");
            Updatedata();
            system("CLS");
            check = false;
        }
        else if (option == 4)
        {
            system("CLS");
            deleteData();
            system("CLS");
            check = false;
        }
        else if (option == 5)
        {
            check = true;
        }
        else
        {
            system("CLS");
            check = false;
        }
    } while (check == false);
    system("CLS");
}

void Creatfile(){
    mkdir("C:/Pungping");
    ofstream pidfile("C:/Pungping/id.txt");
    pidfile << "6";
    pidfile.close();
    /*ofstream oidfile("C:/Pungping/orderid.txt");
    oidfile << "0";
    oidfile.close();*/
    ofstream productfile("C:/Pungping/product.txt");
    productfile << "\n" << "1";
    productfile << "\n" << "Sugar";
    productfile << "\n" << "5";
    productfile << "\n" << "100";

    productfile << "\n" << "2";
    productfile << "\n" << "Chocolate";
    productfile << "\n" << "5";
    productfile << "\n" << "100";

    productfile << "\n" << "3";
    productfile << "\n" << "";
    productfile << "\n" << "5";
    productfile << "\n" << "100";

    productfile << "\n" << "4";
    productfile << "\n" << "";
    productfile << "\n" << "5";
    productfile << "\n" << "100";

    productfile << "\n" << "5";
    productfile << "\n" << "";
    productfile << "\n" << "5";
    productfile << "\n" << "100";

    productfile << "\n" << "6";
    productfile << "\n" << "";
    productfile << "\n" << "5";
    productfile << "\n" << "100";
    productfile.close();
    /*ofstream orderfile("C:/Pungping/order.txt");
    orderfile.close();*/
    /*ofstream openfile("C:/Pungping/open.txt");
    openfile.close();*/
}


void select()
{
    bool check = false;
    do
    {
        cout << "1.Buy" << endl;
        cout << "2.For employee" << endl;
        cout << "3.Exit" << endl;
        int option;
        string ad_pass;
        cout << "Enter option : ";
        cin >> option;
        if (option == 1)
        {
            system("CLS");
            Readdata();
            check = false;
        }
        else if (option == 2)
        {
            system("CLS");
            cout << "Enter password: ";
            cin >> ad_pass;
            if (ad_pass == "admin1234")
            {
                system("CLS");
                admin();
            }else{
                system("CLS");
                cout << "Wrong password!" << endl;
            }
            check = false;
        }
        else if (option == 3)
        {
            check = true;
        }else{
            check = false;
        }
    } while (check == false);
}

int main(){
    ofstream myfile;
    myfile.open("C:/Pungping/open.txt");
    if(myfile){
        select();
    }else{
        Creatfile();
        select();
    }
}