#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <time.h>

using namespace std;

int ID;
string Pname[100] = {};
int Pid[100] = {};
string Pprice[100] = {};
string Punit[100] = {};

struct Product
{
    int id;
    string name;
    string price;
    string unit;
    string check;
};

void Addproduct()
{
    Product pd;
    cout << "Enter product name : ";
    cin.get();
    getline(cin, pd.name);
    cout << "Enter product Price : ";
    cin >> pd.price;
    ID++;

    ofstream write;
    write.open("product.txt", ios_base::app);
    write << "\n"
          << ID;
    write << "\n"
          << pd.name;
    write << "\n"
          << pd.price;
    write << "\n"
          << pd.unit;
    write.close();
    // write.open("id.txt");
    // write << ID;
    // write.close();
    cout << "Data save to file" << endl;
}

void print(Product s)
{
    cout << "ID is : " << s.id << endl;
    cout << "Name is : " << s.name << endl;
    cout << "Price is : " << s.price << endl;
    cout << "Unit is : " << s.unit << endl
         << endl;
}

void Readdata()
{
    Product pd;
    ifstream read;
    read.open("product.txt");
    while (!read.eof())
    {
        read >> pd.id;
        read.ignore();
        getline(read, pd.name);
        read >> pd.price >> pd.unit;
        print(pd);
    }
    read.close();
}

void Productlist()
{
    Product pd;
    ifstream read;
    read.open("product.txt");
    int x = 0;
    cout << "===================== Menu ===================" << endl;
    while (!read.eof())
    {
        read >> pd.id;
        read.ignore();
        getline(read, pd.name);
        read >> pd.price >> pd.unit;

        Pid[x] = pd.id;
        Pname[x] = pd.name;
        Pprice[x] = pd.price;
        Punit[x] = pd.unit;

        cout << "ID : " << Pid[x] << " " << Pname[x] << " " << Pprice[x] << " Bath " << Punit[x] << " Spoon" << endl;
        x++;
    }
    cout << "==============================================" << endl;
    read.close();
}

int searchData()
{
    int id;
    cout << "Enter toping id to search : ";
    cin >> id;
    Product pd;
    ifstream read;
    read.open("product.txt");
    while (!read.eof())
    {
        read >> pd.id;
        read.ignore();
        getline(read, pd.name);
        read >> pd.price >> pd.unit;
        if (pd.id == id)
        {
            print(pd);
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
        cout << "Enter product name : ";
        cin.get();
        getline(cin, newData.name);
        cout << "Enter product price : ";
        cin >> newData.price;
        Product pd;
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("product.txt");
        while (!read.eof())
        {
            read >> pd.id;
            read.ignore();
            getline(read, pd.name);
            read >> pd.price >> pd.unit;
            if (pd.id != id)
            {
                tempFile << "\n"
                         << pd.id;
                tempFile << "\n"
                         << pd.name;
                tempFile << "\n"
                         << pd.price;
            }
            else
            {
                tempFile << "\n"
                         << pd.id;
                tempFile << "\n"
                         << newData.name;
                tempFile << "\n"
                         << newData.price;
            }
        }
        read.close();
        tempFile.close();
        remove("product.txt");
        rename("temp.txt", "product.txt");
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
        tempFile.open("temp.txt");
        ifstream read;
        read.open("product.txt");
        while (!read.eof())
        {
            read >> pd.id;
            read.ignore();
            getline(read, pd.name);
            read >> pd.price >> pd.unit;
            if (pd.id != id)
            {
                tempFile << "\n"
                         << pd.id;
                tempFile << "\n"
                         << pd.name;
                tempFile << "\n"
                         << pd.price;
                tempFile << "\n"
                         << pd.unit;
            }
        }
        read.close();
        tempFile.close();
        remove("product.txt");
        rename("temp.txt", "product.txt");
        cout << "Data deleted successfuly" << endl;
    }
    else
    {
        cout << "Record not deleted" << endl;
    }
}

void admin()
{
    bool check = false;
    do
    {
        Productlist();
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
            Addproduct();
            system("CLS");
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
            Productlist();
            Updatedata();
            system("CLS");
            check = false;
        }
        else if (option == 4)
        {
            system("CLS");
            Productlist();
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
}

void select()
{

    bool check = false;
    do
    {
        Productlist();
        cout << "1.Ping" << endl;
        cout << "2.Maiping" << endl;
        cout << "3.Exit" << endl;
        int option;
        cout << "Enter option : ";
        cin >> option;
        if (option == 1)
        {
            system("CLS");
            check = false;
        }
        else if (option == 2)
        {
            system("CLS");
            check = false;
        }
        else if (option == 788)
        {
            system("CLS");
            admin();
            check = false;
        }
        else
        {
            check = true;
        }
    } while (check == false);
}

void ping()
{
    ifstream read;
    ofstream write;
    const string Filename = "product.txt";
    read.open(Filename.c_str());
}

void createpro()
{
   
}

/* void createcheck(){
    Product pd;
    ifstream read;
    ofstream write;
    const string CheckID = "check.txt";
    pd.check = 1;
    write.open("check.txt", ios_base::app);
    write << "\n" << pd.check;
    write.close();

}*/
//------------------------------------------------------------------------------------//

int main()
{
    Product pd;
    ifstream read;
    ofstream write;
    const string Filename = "product.txt";
    ofstream OutFile(Filename.c_str(), ios_base::out | ios_base::app);
    OutFile.close();
    
    select();
}

/*if(!read.fail()){
     read >> ID;
 }else{
     ID = 0;
 }
 read.close();
*/
/* bool check = false;
 do
 {
     Productlist();
     cout << "1.ADD" << endl;
     cout << "2.Read" << endl;
     cout << "3.Update" << endl;
     cout << "4.Delete" << endl;
     cout << "5.Exit" << endl;
     int option;
     cout << "Enter option : ";
     cin >> option;
     if(option == 1){
         Addproduct();
         system("CLS");
         check = false;
     }else if(option == 2){
         system("CLS");
         Readdata();
         check = false;
     }else if(option == 3){
         system("CLS");
         Productlist();
         Updatedata();
         system("CLS");
         check = false;
     }else if(option == 4){
         system("CLS");
         Productlist();
         deleteData();
         system("CLS");
         check = false;
     }else if(option == 5){
         check = true;
     }else{
         system("CLS");
         check = false;
     }
 } while (check == false); */
