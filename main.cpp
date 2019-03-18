#include <iostream>
#include <string>
#include <Windows.h>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <time.h>

using namespace std;

string TxtInput;

bool cmdfound = false;
string LibArray[4][4][4];
int usLoc1, usLoc2, usLoc3;

int TxtInputArSize = 4;

int TxtInputArLoc, cmd2ArLoc, cmd3ArLoc;

bool TxtInputstore = false;

string cmd2array[2] = {"Subidirectory", "More Subidirectory"};

void input();
void settingvaribles();
void TxtInputin();
void TxtInputout();
void cmd2in();
void cmd2out();
void opendi();
void loadanimin();
void loadanimout();
void Subidirectory();
void randcolour();
int main()


{
    settingvaribles();
    usLoc1 = 0;
    usLoc2 = 0;
    usLoc3 = 0;

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
    cout << "|   Enter help in any directory to |" << endl;
    cout << "|   virw information on how to use |" << endl;
    cout << "|                 IAC              |" << endl;
    cout << "------------------------------------" << endl;


    srand (time(NULL));
    input();

    system("pause");

    return 0;
}

void input()
{

    cout << "IAC:\\";

    if (usLoc1 > 0 && usLoc2 == 0 && usLoc3 == 0)
    {
        cout << LibArray[usLoc1][0][0] << "\\";
    }

    else if (usLoc2 > 0 && usLoc1 > 0 && usLoc3 == 0)
    {
        cout << "\\";
        cout << LibArray[usLoc1][0][0] << "\\";
        cout << LibArray[usLoc1][usLoc2][0] << "\\";
    }
    else if (usLoc3 > 0 && usLoc1 > 0 && usLoc2 > 0)
    {
        cout << "\\";
        cout << LibArray[usLoc1][0][0] << "\\";
        cout << LibArray[usLoc1][usLoc2][0] << "\\";
        cout << LibArray[usLoc1][usLoc2][usLoc3] << "\\";
    }

    else
    {
    }

    TxtInputin();
}

void TxtInputin()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    cmdfound = false;

    getline(cin, TxtInput);
    // TxtInput.erase( TxtInput.end()-3); // erase 3 chars from end of string
    // TxtInput.append ("fuck");  // add to the end of the string

    if (usLoc1 == 0)
    {

        for (int a = 0; a < 5; a++)
        {

            if (TxtInput == LibArray[a][0][0])
            {

                usLoc1 = a;

                cmdfound = true;
            }
        }
    }
    else if (usLoc2 == 0)
    {
        for (int a = 0; a < 5; a++)
        {

            if (TxtInput == LibArray[usLoc1][a][0])
            {

                usLoc2 = a;

                cmdfound = true;
            }
        }
    }
    else if (usLoc3 == 0)
    {
        for (int a = 0; a < 5; a++)
        {

            if (TxtInput == LibArray[usLoc1][usLoc2][a])
            {

                usLoc2 = a;

                cmdfound = true;
            }
        }
    }

    if (cmdfound)
    {

        loadanimin();
        cout << "Accesed to " << TxtInput << " directory granted";
        loadanimout();

        opendi();
        input();
    }

    else if (TxtInput == "exit")
    {

        if (usLoc1 > 0 && usLoc2 == 0 && usLoc3 == 0)
        {
            usLoc1 = 0;
            loadanimin();
            cout << LibArray[usLoc1][usLoc2][usLoc3] << " directory left";
            loadanimout();
            input();
        }

        else if (usLoc1 > 0 && usLoc2 > 0 && usLoc3 == 0)
        {
            usLoc2 = 0;
            loadanimin();
            cout << LibArray[usLoc1][usLoc2][usLoc3] << " directory left";
            loadanimout();
            input();
        }
        else if (usLoc1 > 0 && usLoc2 > 0 && usLoc3 > 0)
        {
            usLoc3 = 0;
            loadanimin();
            cout << LibArray[usLoc1][usLoc2][usLoc3] << " directory left";
            loadanimout();
            input();
        }

        else
        {
             SetConsoleTextAttribute(h, FOREGROUND_RED );
            cout << "No directory to leave" << endl;
            SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
            input();
        }
    }

    else if (TxtInput == "subd")
    {
        Subidirectory();
        input();
    }

    else if (TxtInput == "help")
    {
        loadanimin();
        cout << "Accesed to " << TxtInput << " directory granted";
        loadanimout();
        cout << "------------------------------------" << endl;
        cout << "|          Help Information         |" << endl;
        cout << "------------------------------------" << endl;
        cout << "| subd -- will reveal all           |" << endl;
        cout << "|         subdirectorys             |" << endl;
        cout << "| exit -- will exit and subdirectory|" << endl;
        cout << "|         you are currently in      |" << endl;
        cout << "------------------------------------" << endl;
        cout << "| files listed in the subd search.. |" << endl;
        cout << "| .fo  = folder                     |" << endl;
        cout << "| .inf = information text           |" << endl;
        cout << "------------------------------------" << endl;

        input();
    }
    else
    {
        SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "Command Not Found" << endl;
        SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        input();
    }
}

void opendi()
{
    /*
 if(usLoc1 == 1)
    {   
         cout << "----------------------" << endl;
        cout << "| Linux |  | Windows |  " << endl;
        cout << "----------------------" << endl;

    }
*/
}

void settingvaribles()
{

    LibArray[0][0][0] = "";
    LibArray[1][0][0] = "windows.fo";
    LibArray[2][0][0] = "linux.fo";
    LibArray[3][0][0] = "macos.fo";
    LibArray[4][0][0] = "andriod.fo";

    LibArray[1][1][0] = "terminal.fo";
    LibArray[1][2][0] = "applications.fo";
    LibArray[1][3][0] = "userstuff.fo";

    LibArray[2][1][0] = "terminal.fo";
    LibArray[2][2][0] = "applications.fo";
    LibArray[2][3][0] = "userstuff.fo";

    LibArray[3][1][0] = "terminal.fo";
    LibArray[3][2][0] = "applications.fo";
    LibArray[3][3][0] = "userstuff.fo";
}

void Subidirectory()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    if (usLoc1 == 0)
    {
        SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << "IAC Subdirectorys found & listed :";

        for (int p = 0; p < 4; p++)
        {
            SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
            cout << "---";
            randcolour();
            Sleep(200);
            cout <<  LibArray[p + 1][0][0];
        }
        cout << endl;
        SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    }

    else if (usLoc2 == 0 && usLoc1 > 0)
    {
        SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << LibArray[usLoc1][0][0] << " Subdirectorys found & listed :" ;

        for (int p = 0; p < 4; p++)
        {

            SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
            cout << "---";
            randcolour();
            Sleep(200);
            cout <<  LibArray[usLoc1][p+1][0];
        }
        cout << endl;
        SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    }

    else if (usLoc3 == 0 && usLoc1 > 0 && usLoc2 > 0)
    {
        SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << LibArray[usLoc1][usLoc2][0] << " Subdirectorys found & listed :";

        for (int p = 0; p < 4; p++)
        {

             SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
            cout << "---";
            randcolour();
            Sleep(200);
            cout <<  LibArray[usLoc1][usLoc2][p+1];
        }
        SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
        cout << endl;
    }

    else
    {
        SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "No Subdirectory Found";
        SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
        cout << endl;
    }
}

void loadanimin()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    for (int b = 1; b < 3; b++)
    {
        cout << ".";
        Sleep(200);
    }
    Sleep(400);
    SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
}

void loadanimout()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);

    for (int b = 1; b < 3; b++)
    {
        cout << ".";
        Sleep(200);
    }
    cout << endl;
}

void randcolour()
{
    int a;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
a = rand() % 14 +1;
if(a==0){SetConsoleTextAttribute(h, FOREGROUND_BLUE);}
else if(a==1){SetConsoleTextAttribute(h, FOREGROUND_GREEN);}
else if(a==2){SetConsoleTextAttribute(h, FOREGROUND_BLUE);}
else if(a==3){SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_BLUE);}
else if(a==4){SetConsoleTextAttribute(h, FOREGROUND_RED);}
else if(a==5){SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_BLUE);}
else if(a==6){SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN);}
else if(a==7){SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);}
else if(a==8){SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_BLUE);}
else if(a==9){SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_GREEN);}
else if(a==10){SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);}
else if(a==11){SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_RED);}
else if(a==12){SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);}
else if(a==13){SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);}
else if(a==14){SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);}
else {SetConsoleTextAttribute(h, FOREGROUND_GREEN);}
}
