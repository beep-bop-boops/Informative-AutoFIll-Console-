#include <iostream>
#include <string>
#include <Windows.h>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <time.h>

using namespace std;

//string cmd1;
string cmd1, cmd2;
string cmd1array[3] = 
{
    "Linux", 
    "Windows", 
    "Help"};
int cmd1arraysize = 3;
bool cmd1store= false;

string cmd2array[2] = {"Help", "More Help"};



void cmd1con();
void cmd2con();


int main ()
{
    cout << "------------------------------------" << endl;
    cout << "|               _        _______   |" << endl;
    cout << "|      |       / \\      |          |" << endl;
    cout << "|      |      /   \\     |          |" << endl;
    cout << "|      |     /     \\    |          |" << endl;
    cout << "|      |    /_______\\   |          |" << endl;
    cout << "|      |   /         \\  |          |" << endl;
    cout << "|      |  /           \\ |_______   |" << endl;
    cout << "|                                  |" << endl;
    cout << "------------------------------------" << endl;
    cout << "|          Welcome To IAC          |" << endl;
    cout << "------------------------------------" << endl;
    cout << "Type Help to view menu. Once inside a menu type help to see futher commands within the menu. To exit chosen menu type exit"<< endl;

 
cmd1con();

system ("pause");
    return 0;

}



void cmd1con()
{
    HANDLE h = GetStdHandle( STD_OUTPUT_HANDLE);


cout << "IAC:\\";

if(cmd1.empty())
{
do{
    getline(cin, cmd1);
    if(cmd1.empty())
    {
        SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "Command Not Found"  << endl;
        SetConsoleTextAttribute(h,FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << "IAC:\\";
    }
    else 
    {
        bool cmdfound = false;
        
        for(int a=0; a<cmd1arraysize; a++)
        {
            
            if(cmd1 == cmd1array[a])
            {
                
                cmdfound= true;
                a = cmd1arraysize;

            }
                        
        }

        if(cmdfound)
        {
            
            cout << "|";
            for(int b=1; b<3; b++)
            {
            cout << ".";
            Sleep(200);
            }
        Sleep(1000);
            SetConsoleTextAttribute(h,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << "Accesed to " << cmd1 << " granted" ;
        SetConsoleTextAttribute(h,FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);

    
            for(int b=1; b<3; b++)
            {
            cout << ".";
            Sleep(200);
            }
            cout << "|";
            cout << endl;
            cmd1store = true;
            
        }
        else 
        {
           SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "Command Not Found"  << endl;
        SetConsoleTextAttribute(h,FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << "IAC:\\";

        }
       
        
    }
}while(cmd1store == false);
}


cmd2con();

}



void cmd2con()
{

if(cmd1 == "Help")
{
    cout << "----------------------" << endl;
    cout << "| Linux |  | Windows |  " << endl;
    cout << "----------------------" << endl;
    cout << "IAC:\\" << cmd1 << "\\";
}

}