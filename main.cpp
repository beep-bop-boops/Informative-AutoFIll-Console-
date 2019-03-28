#include <iostream>
#include <string>
#include <Windows.h>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <time.h>
#define _WIN32_WINNT 0 * 0502
using namespace std;

string TxtInput;
bool cmdfound = false;
string LibArray[10][10][10][10][10];
int arrayIndexAmount = 5;
int LocAmount = 10;
int usLoc[10];
bool usLocB[5];
bool exitDir = false;
int Loc[5];
string title,t;

void printdir();
void initializeDictionary();
void TxtInputin();
void TxtInputout();
void cmd2in();
void cmd2out();

void loadanimin();
void loadanimout();
void Subidirectory();
void randcolour();
void remove_scrollbar();

int main()
{
    for (int x = 0; x < LocAmount; x++)
    {
        usLoc[x] = 0;
    }
    srand(time(NULL));
    initializeDictionary();
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
    cout << "|   view information on how to use |" << endl;
    cout << "|                 IAC              |" << endl;
    cout << "------------------------------------" << endl;

    // iac 3.40 = iac 3= Libarray size 40 = usloc size.  dd
    //finding location . can tpye loc3.4.5 at any time to go into locus[1]=3 usloc[2]=4...
    // cant find current location loc = 4.5.6.7

    /*
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r); //stores the console's current dimensions
    MoveWindow(console, r.left, r.top, 338, 900, TRUE); // 800 width, 100 height.left, rect.bottom-rect.top, rect.right-rect.left, TRUE);  
    */

    printdir();

    system("pause");

    return 0;
}

void printdir()
{
    cmdfound = false;
    exitDir = false;

    cout << "IAC:\\";

    if (usLocB[1] == true)
    {
        usLocB[0] = true;
    }
    else
    {
        usLocB[0] = false;
    }

    if (usLoc[1] > 0)
    {

        usLoc[0] = 1;
    }
    else
    {
        usLoc[0] = 0;
    }

    /*
    for (int x = 0; x < 5; x++)
    {

        cout << "usLocB[" << x << "] = " << usLocB[x] << endl;
    }

    for (int x = 0; x < 5; x++)
    {

        cout << "usLoc[" << x << "] = " << usLoc[x] << endl;
    }
    */

    for (int n = 0; n < LocAmount; n++)
    {
        if (usLoc[n] > 0)
        {
            usLocB[n] = true;
        }
        else
        {
            usLocB[n] = false;
        }
    }

    /*
    for (int x = 0; x < 10; x++)
    {

        cout << "usLocB[" << x << "] = " << usLocB[x] << endl;
    }

    for (int x = 0; x < 10; x++)
    {

        cout << "usLoc[" << x << "] = " << usLoc[x] << endl;
    }

*/
    if (usLocB[1] == true)
    {
        t = LibArray[usLoc[1]][0][0][0][0];
        title = t.substr(0, t.find(" "));
        cout << title << "\\";
    
    }
    if (usLocB[2] == true)
    {
       
         t = LibArray[usLoc[1]][usLoc[2]][0][0][0];
        title = t.substr(0, t.find(" "));
        cout << title << "\\";
    }
    if (usLocB[3] == true)
    {
        
         t = LibArray[usLoc[1]][usLoc[2]][usLoc[3]][0][0];
        title = t.substr(0, t.find(" "));
        cout << title << "\\";
    }
    if (usLocB[4] == true)
    {
       
         t = LibArray[usLoc[1]][usLoc[2]][usLoc[3]][usLoc[4]][0];
        title = t.substr(0, t.find(" "));
        cout << title << "\\";
    }
    if (usLocB[5] == true)
    {
        
        t = LibArray[usLoc[1]][usLoc[2]][usLoc[3]][usLoc[4]][usLoc[5]];
        title = t.substr(0, t.find(" "));
        cout << title << "\\";
    }

    TxtInputin();
}
void TxtInputin()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    cmdfound = false;

    getline(cin, TxtInput);

    if (TxtInput == "exit")
    {
        int o = 0;

        for (int a = 1; a < LocAmount; a++)
        {

            if (exitDir == false)
            {

                if (usLoc[a] > 0)

                {
                    
                    if(o == 0)
                    {

                    loadanimin();
                    SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);

                    t = LibArray[usLoc[1]][usLoc[2]][usLoc[3]][usLoc[4]][usLoc[5]];
                    title = t.substr(0, t.find(" "));
                    cout << title << " directory left";
                    
                    SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
                    loadanimout();
                    SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
                    }
                    int d;
                    d = a + 1;

                    if (usLoc[d] == 0)
                    {
                        usLoc[a] = 0;
                       

                        exitDir = true;
                    }
                }
            }

            o = 1;
            
        }

        printdir();
    }

    else if (TxtInput == "subd")
    {
        Subidirectory();
        printdir();
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
        cout << "| exit -- will exit any subdirectory|" << endl;
        cout << "|         you are currently in      |" << endl;
        cout << "------------------------------------" << endl;
        cout << "| Files listed in the subd search   |" << endl;
        cout << "------------------------------------" << endl;
        cout << "| .fo  = folder                     |" << endl;
        cout << "------------------------------------" << endl;
        cout << "| .in  = informative text           |" << endl;
        cout << "------------------------------------" << endl;
        cout << "| .tu  = is a step by step tutorial |" << endl;
        cout << "------------------------------------" << endl;
        cout << "| .bu  = is a bug found in any      |" << endl;
        cout << "|        real world programe/website|" << endl;
        cout << "|        .bu files will end with a  |" << endl;
        cout << "|         number representing the   |" << endl;
        cout << "|         severity of the bug.      |" << endl;
        cout << "------------------------------------" << endl;

        printdir();
    }
    else if (TxtInput == " " || TxtInput == ""  )
    {
        loadanimin();
                    SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
                    
                    cout << "No Command Entered";
                    SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                    loadanimout();
        
        printdir();
    }

    else
    {
        for (int p = 1; p < 5; p++)
        {
            if (usLocB[p] == false)
            {
                int r;
                for (r = 1; r < arrayIndexAmount; r++)
                {
                    usLoc[p] = r;
                    string firstWord, temp;
                    temp = LibArray[usLoc[1]][usLoc[2]][usLoc[3]][usLoc[4]][usLoc[5]];
                    firstWord = temp.substr(0, temp.find(" "));

                    if (TxtInput == firstWord)
                    {
                        usLoc[p] = r;

                        r = arrayIndexAmount + 1;

                        usLocB[p] = true;

                        cmdfound = true;
                        loadanimin();
                        cout << "Accesed to " << TxtInput << " directory granted";
                        loadanimout();

                        if(firstWord.substr( firstWord.length() - 3 ) == ".in")
{
    cout << temp << endl;
}
                       
                    }
                }

                if (cmdfound == false)
                {

                    loadanimin();
                    SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
                    
                    cout << "Command Not Found";
                    SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                    loadanimout();
                    usLoc[p] = 0;

                    printdir();
                }
                else
                {
                    printdir();
                }
            }
        }
    }
}

void initializeDictionary()
{
    //IAC:/
    LibArray[0][0][0][0][0] = "";
    LibArray[1][0][0][0][0] = "windows.fo";
    LibArray[2][0][0][0][0] = "linux.fo";
    LibArray[3][0][0][0][0] = "macos.fo";
    LibArray[4][0][0][0][0] = "andriod.fo";
    //windows

    LibArray[1][1][0][0][0] = "terminal.fo";
    LibArray[1][2][0][0][0] = "applications.fo";
    LibArray[1][3][0][0][0] = "userstuff.fo";
    LibArray[1][4][0][0][0] = "windowsHelp.in \n This is a windows help tutorial \n Windows is an operating system designed by Microsoft. The operating system is what allows you to use a computer. Windows comes preloaded on most new personal computers (PCs), which helps to make it the most popular operating system in the world.Windows makes it possible to complete all types of everyday tasks on your computer. For example, you can use Windows to browse the Internet, check your email, edit digital photos, listen to music, play games, and do much more.";

     //windows - terminal

    LibArray[1][1][1][0][0] = "terminal.fo";
    LibArray[1][1][2][0][0] = "applications.fo";
    LibArray[1][1][3][0][0] = "userstuff.fo";

      //windows - terminal - terminal

    LibArray[1][1][1][1][0] = "terminal.fo";
    LibArray[1][1][1][2][0] = "applications.fo";
    LibArray[1][1][3][3][0] = "userstuff.fo";

    LibArray[2][1][0][0][0] = "Network";
    LibArray[2][2][0][0][0] = "lapplications.fo";
    LibArray[2][3][0][0][0] = "luserstuff.fo";


    LibArray[2][1][1][0][0] = "bruteForce.in";
}

void Subidirectory()
{

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    for (int p = 1; p < arrayIndexAmount; p++)
    {
        if (usLocB[p] == false)
        {
            SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

            t = LibArray[usLoc[1]][usLoc[2]][usLoc[3]][usLoc[4]][usLoc[5]];
                 title = t.substr(0, t.find(" "));
                  

            cout << title << "Subdirectorys found & listed :";

            int r;
            for (r = 1; r < arrayIndexAmount; r++)
            {

                usLoc[p] = r;
                SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
                cout << "---";
                randcolour();
                Sleep(200);
             


                t = LibArray[usLoc[1]][usLoc[2]][usLoc[3]][usLoc[4]][usLoc[5]];
                 title = t.substr(0, t.find(" "));
                  cout << title ;

            }

            usLoc[p] = 0;
            p = arrayIndexAmount + 1;
            SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
            cout << endl;
        }
    }

    /*
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
    */
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
    a = rand() % 14 + 1;
    if (a == 0)
    {
        SetConsoleTextAttribute(h, FOREGROUND_BLUE);
    }
    else if (a == 1)
    {
        SetConsoleTextAttribute(h, FOREGROUND_GREEN);
    }
    else if (a == 2)
    {
        SetConsoleTextAttribute(h, FOREGROUND_BLUE);
    }
    else if (a == 3)
    {
        SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_BLUE);
    }
    else if (a == 4)
    {
        SetConsoleTextAttribute(h, FOREGROUND_RED);
    }
    else if (a == 5)
    {
        SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_BLUE);
    }
    else if (a == 6)
    {
        SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN);
    }
    else if (a == 7)
    {
        SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }
    else if (a == 8)
    {
        SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_BLUE);
    }
    else if (a == 9)
    {
        SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
    }
    else if (a == 10)
    {
        SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }
    else if (a == 11)
    {
        SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_RED);
    }
    else if (a == 12)
    {
        SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
    }
    else if (a == 13)
    {
        SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    }
    else if (a == 14)
    {
        SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }
    else
    {
        SetConsoleTextAttribute(h, FOREGROUND_GREEN);
    }
}

void remove_scrollbar()
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(handle, &info);
    COORD new_size =
        {
            info.srWindow.Right - info.srWindow.Left + 1,
            info.srWindow.Bottom - info.srWindow.Top + 1};
    SetConsoleScreenBufferSize(handle, new_size);
}
