#include <iostream>
#include <string>
#include <Windows.h>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <time.h>

using namespace std;

string cmd1, cmd2, cmd3;
int cmd1ArLoc, cmd2ArLoc, cmd3ArLoc;
string cmd1array[3];
//new cmd1array[2] = {"Linux"};



int cmd1arraysize = 3;
bool cmd1store= false;

string cmd2array[2] = {"Help", "More Help"};

void cmd1in();
void cmd1out();
void cmd2in();
void cmd2out();

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

    cmd1in();

    system ("pause");

    return 0;
}

void cmd1in()
 {
    HANDLE h = GetStdHandle( STD_OUTPUT_HANDLE);

    cout << "IAC:\\";

    if(cmd1.empty())
    {
        do
        {
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
                        cmd1ArLoc = a;
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

    cmd1out();

}


void cmd1out()
{
    if(cmd1ArLoc == 3)
    {
        cout << "----------------------" << endl;
        cout << "| Linux |  | Windows |  " << endl;
        cout << "----------------------" << endl;
    }

cmd2in();
}






void cmd2in()
{
cout << "IAC:\\" << cmd1 << "\\";
getline(cin, cmd2);

}




