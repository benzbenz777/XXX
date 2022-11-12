#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <time.h>

using namespace std;

int main(){
    select();
}
    
void ping(){
    
}


void select(){

        bool check = false; 
        do{
        cout << "1.Ping" << endl;
        cout << "2.Maiping" << endl;
        cout << "3.Exit" << endl;
        int option;
        cout << "Enter option : ";
        cin >> option;
        if(option == 1){
            check = false;
        }else if(option == 2){
            check = false;
        }else if(option == 788){
            check = false;
        }else{
            check = true;
        }    
    } while (check == false);
    
}