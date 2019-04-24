//in cmd input "chcp 437"  // https://en.wikipedia.org/wiki/Code_page_437

#include <iostream>
#include <string>
#include <Windows.h>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <time.h>
#include <fstream>
#include <ctime>

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
bool cmdEnt = false;
int Loc[5];
string title, t, strStar, decodes;
string filename;
string password;

ofstream file;
ifstream importfile;

bool debug = false;

string cP0 = " ";     //0  space
const char cP1 = 196; //1  ─
const char cP2 = 195; //2  ├
const char cP3 = 218; //3  ┌
const char cP4 = 191; //4  ┐
const char cP5 = 192; //5  └
const char cP6 = 217; //6  ┘
const char cP7 = 175; //7  »
const char cP8 = 179; //8  |
const char cP9 = 242; //9  _
const char cP10 = 47; //10  /
const char cP11 = 92; //11  \/
const char cP12 = 92; //12  \/

void printdir();
void initializeDictionary();
void TxtInputin();
void TxtInputout();
void cmd2in();
void cmd2out();
void exportdata();
void decode();

void loadanimin();
void loadanimout();
void Subidirectory();
void randcolour();
void remove_scrollbar();
void fillcontent();

void print(int id, int amount)
{

    for (int i = 0; i < amount; i++)
    {

        switch (id)
        {
        case 0:
            cout << cP0;
            break;
        case 1:
            cout << cP1;
            break;
        case 2:
            cout << cP2;
            break;
        case 3:
            cout << cP3;
            break;
        case 4:
            cout << cP4;
            break;
        case 5:
            cout << cP5;
            break;
        case 6:
            cout << cP6;
            break;
        case 7:
            cout << cP7;
            break;
        case 8:
            cout << cP8;
            break;
        case 9:
            cout << cP9;
            break;
        case 10:
            cout << cP10;
            break;
        case 11:
            cout << cP11;
            break;
        }
    }
}

int EnCr(int q, int w, int e, int r, int t)
{

    string code;
    code = LibArray[q][w][e][r][t];

    char c[code.size() + 1];
    strcpy(c, code.c_str());

    int encrId;
    encrId = rand() % 4 + 1;

    char te;

    if (encrId == 1)
    {
        int print;
        print = rand() % 10 + 1;
        switch (print)
        {
        case 0:
            te = 178;
            break;
        case 1:
            te = 167;         
            break;
        case 2:
            te = 235;
            break;
        case 3:
            te = 43;
            break;
        case 4:
            te = 62;
            break;
        case 5:
            te = 41;
            break;
        case 6:
            te = 180;
            break;
        case 7:
            te = 236;
            break;
        case 8:
            te = 244;
            break;
        case 9:
            te = 173;
            break;
        }
        file << te;
    }
    if (encrId == 2)
    {
        int print;
        print = rand() % 10 + 1;
        switch (print)
        {
        case 0:
            te = 223;
            break;
        case 1:
            te = 237;
            break;
        case 2:
            te = 243;
            break;
        case 3:
            te = 180;
            break;
        case 4:
            te = 124;
            break;
        case 5:
            te = 138;
            break;
        case 6:
            te = 178;
            break;
        case 7:
            te = 91;
            break;
        case 8:
            te = 184;
            break;
        case 9:
            te = 299;
            break;
        }
        file << te;
    }
    if (encrId == 3)
    {
        int print;
        print = rand() % 10 + 1;
        switch (print)
        {
        case 0:
            te = 176;
            break;
        case 1:
            te = 197;
            break;
        case 2:
            te = 170;
            break;
        case 3:
            te = 126;
            break;
        case 4:
            te = 61;
            break;
        case 5:
            te = 62;
            break;
        case 6:
            te = 112;
            break;
        case 7:
            te = 142;
            break;
        case 8:
            te = 159;
            break;
        case 9:
            te = 209;
            break;
        }
        file << te;
    }
    if (encrId == 4)
    {
        int print;
        print = rand() % 10 + 1;
        switch (print)
        {
        case 0:
            te = 206;

            break;
        case 1:
            te = 210;
            break;
        case 2:
            te = 211;
            break;
        case 3:
            te = 201;
            break;
        case 4:
            te = 221;
            break;
        case 5:
            te = 241;
            break;
        case 6:
            te = 251;
            break;
        case 7:
            te = 169;
            break;
        case 8:
            te = 145;
            break;
        case 9:
            te = 129;
            break;
        }
        file << te;
    }

    int encr;

    for (int y = 0; y < code.size(); y++)
    {
        encr = y;

        if (encrId == 0)
        {
            switch (y)
            {
            case 0:
                c[y] = c[y] + 1;
                break;
            default:
                c[y] = c[y] + 1;
                break;
            }
        }
        else if (encrId == 1)
        {
            switch (y)
            {
            case 0:
                c[y] = c[y] + 1;
                break;
            default:
                c[y] = c[y] + 1;
                break;
            }
        }
        else if (encrId == 2)
        {
            switch (y)
            {
            case 0:
                c[y] = c[y] + 1;
                break;
            default:
                c[y] = c[y] + 1;
                break;
            }
        }
        else if (encrId == 3)
        {
            switch (y)
            {
            case 0:
                c[y] = c[y] + 1;
                break;
            default:
                c[y] = c[y] + 1;
                break;
            }
        }
        else
        {
            switch (y)
            {
            case 0:
                c[y] = c[y] + 1;
                break;
            default:
                c[y] = c[y] + 1;
                break;
            }
        }

        file << c[y];
    }

    file << ",";
    return 0;
}

void home()
{
    print(3, 1);
    print(1, 40);
    print(4, 1);
    cout << endl;

    print(8, 1);
    print(0, 15);
    print(9, 2);
    print(0, 9);
    print(3, 1);
    print(1, 10);
    print(0, 3);

    print(8, 1);
    cout << endl;

    print(8, 1);
    print(0, 6);
    print(8, 1);
    print(0, 7);
    print(10, 1);
    print(0, 2);
    print(11, 1);
    print(0, 8);
    print(8, 1);
    print(0, 13);
    print(8, 1);

    cout << endl;

    print(8, 1);
    print(0, 6);
    print(8, 1);
    print(0, 6); //-
    print(10, 1);
    print(0, 4); //+
    print(11, 1);
    print(0, 7); //-
    print(8, 1);
    print(0, 13);
    print(8, 1);

    cout << endl;

    print(8, 1);
    print(0, 6);
    print(8, 1);
    print(0, 5); //-
    print(10, 1);
    print(0, 6);
    print(11, 1);
    print(0, 6); //-
    print(8, 1);
    print(0, 13);
    print(8, 1);

    cout << endl;

    print(8, 1);
    print(0, 6);
    print(8, 1);
    print(0, 4); //-
    print(10, 1);
    print(1, 8);
    print(11, 1);
    print(0, 5); //-
    print(8, 1);
    print(0, 13);
    print(8, 1);

    cout << endl;

    print(8, 1);
    print(0, 6);
    print(8, 1);
    print(0, 3); //-
    print(10, 1);
    print(0, 10); //++
    print(11, 1);
    print(0, 4); //-
    print(8, 1);
    print(0, 13);
    print(8, 1);

    cout << endl;

    print(8, 1);
    print(0, 6);
    print(8, 1);
    print(0, 2); //-
    print(10, 1);
    print(0, 12); //++
    print(11, 1);
    print(0, 3); //-
    print(8, 1);
    print(0, 13);
    print(8, 1);

    cout << endl;

    print(8, 1);
    print(0, 6);
    print(8, 1);
    print(0, 1); //-
    print(10, 1);
    print(0, 14); //++
    print(11, 1);
    print(0, 2); //-
    print(5, 1);
    print(1, 10);
    print(0, 3);
    print(8, 1);
    cout << endl;

    print(5, 1);
    print(1, 40);
    print(6, 1);
    cout << endl;

    /////////////////////////
    print(3, 1);
    print(1, 40);
    print(4, 1);
    cout << endl;

    print(8, 1);
    print(0, 13);
    cout << "Welcome To IAC";
    print(0, 13);
    print(8, 1);
    cout << endl;

    print(5, 1);
    print(1, 40);
    print(6, 1);
    cout << endl;
    ///////////////////////////////
    print(3, 1);
    print(1, 40);
    print(4, 1);
    cout << endl;

    print(8, 1);
    print(0, 5);
    cout << "Enter help in any directory to";
    print(0, 5);
    print(8, 1);
    cout << endl;

    print(8, 1);
    print(0, 5);
    cout << "view information on how to use.";
    print(0, 4);
    print(8, 1);
    cout << endl;

    print(5, 1);
    print(1, 40);
    print(6, 1);
    cout << endl;
}
int main()
{
    srand(time(0));
    for (int x = 0; x < LocAmount; x++)
    {
        usLoc[x] = 0;
    }
    srand(time(NULL));
    initializeDictionary();

    home();

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

    if (debug == true)
    {
        cout << usLoc[1] << endl;
        cout << usLoc[2] << endl;
        cout << usLoc[3] << endl;
        cout << usLoc[4] << endl;

        cout << usLocB[1] << endl;
        cout << usLocB[2] << endl;
        cout << usLocB[3] << endl;
        cout << usLocB[4] << endl;
    }

    cmdfound = false;
    exitDir = false;

    print(1, 42);

    cout << endl;

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

    cin >> TxtInput;
    print(1, 42);
    cout << endl;

    //getline(cin, TxtInput);

    strStar = TxtInput.substr(0, 6);

    if (TxtInput == "exit")
    {
        int o = 0;

        for (int a = 1; a < LocAmount; a++)
        {

            if (exitDir == false)
            {

                if (usLoc[a] > 0)

                {

                    if (o == 0)
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

    else if (TxtInput == "d")
    {
        debug = true;
        printdir();
    }

    else if (TxtInput == "export")
    {

        string yn;
        cout << "Please enter file name : ";
        cin >> filename;
        filename = filename + ".csv";

        cout << "Would you like to set a password for the file (Y/N):";
        cin >> yn;

        while (true)
        {
            if (yn == "y")
            {
                cout << "Password :";
                cin >> password;

                break;
            }
            else if (yn == "n")
            {

                break;
            }
            else
            {
                cout << "Input must be y or n." << endl;
                cout << "Would you like to set a password for the file (Y/N):";
                cin >> yn;
            }
        }

        loadanimin();
        SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << "File exported";
        SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        loadanimout();

        file.open(filename);

        exportdata();
        cmdEnt = true;
        printdir();
    }

    else if(TxtInput == "import")
    {
        string filename;
        cout << "Please Place csv file in same folder as IAC.exe folder" << endl ;
        cout << "Please enter csv file name (Case Sensative/No Extension):";
        cin >> filename;
        filename = filename + ".csv";

        importfile.open(filename);

        string importText;
        int perc = 0;
        cout << "Please Wait till 1000 reached";

    string decS;


        string che1;
        string che2;
        string che3;
        string che4;
        string che5;
        string che6 ;
        string che7;
        string che8;
        string che9;
        string che10;
        char che1c = 178;
        char che2c = 178;
        char che3c = 178;
        char che4c = 178;
        char che5c = 178;
        char che6c = 178;
        char che7c = 178;
        char che8c = 178;
        char che9c = 178;
        char che10c = 178;
        che1 = che1c;
        che2 = che2c;
        che3 = che3c;
        che4 = che4c;
        che5 = che5c;
        che6 = che6c;
        che7 = che7c;
        che8 = che8c;
        che9 = che9c;
        che10 = che10c;

        
        int importedAmount = 0;
        
        while(importfile.good())
        {

 for (int q = 0; q < LocAmount; q++)
    {
        for (int w = 0; w < LocAmount; w++)
        {
            for (int e = 0; e < LocAmount; e++)
            {
                for (int r = 0; r < LocAmount; r++)
                {
                    for (int t = 0; t < LocAmount; t++)
                    {
                        

                        getline(importfile, importText, ',');
                        cout << perc << importText << endl;
                      
                        if(importText.substr(1,1) == che1 || importText.substr(1,1) == che2 || importText.substr(1,1) == che3 || importText.substr(1,1) == che4 || importText.substr(1,1) == che5 || importText.substr(1,1) == che6 || importText.substr(1,1) == che7 || importText.substr(1,1) == che8 || importText.substr(1,1) == che9 || importText.substr(1,1) == che10)
                        {
                            cout << "Sub found!" << endl;

                            for(int g=0; g<importText.length(); g++)
                            {
                                decS = importText.substr(g,g);
                                char decC[decS.size() + 1];
                                strcpy(decC, decS.c_str());

                                cout << "Old Char = " << decC[0]; 

                               char u = decC[0];

                                LibArray[t][r][e][w][q].substr(g,g) = importText.substr(g,g);
                                    
                               

                            }

                            cout << "impoerted" << endl;
                            importedAmount = importedAmount +1;

                        }
                        
                        
                       // cout << "Location = " << t << r << e << w << q << " = " << LibArray[t][r][e][w][q] << endl ;
                        
                        cout << perc << " / 9999 : complete" << endl;
                        perc = perc + 1;
                        cout << "Directory Imported : " << importedAmount;

                        Sleep(9000);
                        
                        system("CLS");

                    }
                }
                file << endl;
            }
            file << endl;
        }
        file << endl;
    }
    file << endl;
        }



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
        cout << "|         Create and delete         |" << endl;
        cout << "------------------------------------" << endl;
        cout << "| +subd\\Name --  Will create       |" << endl;
        cout << "|         a new subdirectory        |" << endl;
        cout << "| -subd\\Name --  Will delete       |" << endl;
        cout << "|         the subdirectory and any  |" << endl;
        cout << "|         subdirectory within the   |" << endl;
        cout << "|         folder                    |" << endl;
        cout << "------------------------------------" << endl;
        cout << "| Files listed in the subd search   |" << endl;
        cout << "------------------------------------" << endl;
        cout << "| .fo  = folder                     |" << endl;
        cout << "------------------------------------" << endl;
        cout << "| .in  = informative text           |" << endl;
        cout << "------------------------------------" << endl;
        cout << "| .bu  = is a bug found in any      |" << endl;
        cout << "|        real world programe/website|" << endl;
        cout << "|        .bu files will end with a  |" << endl;
        cout << "|         number representing the   |" << endl;
        cout << "|         severity of the bug.      |" << endl;
        cout << "------------------------------------" << endl;
        cout << "|           Import / Export         |" << endl;
        cout << "------------------------------------" << endl;
        cout << "| export = will export all          |" << endl;
        cout << "|          directorys to a csv file |" << endl;
        cout << "| import = will clear all curent    |" << endl;
        cout << "|          directorys & import ones |" << endl;
        cout << "|          in the csv file          |" << endl;
        cout << "------------------------------------" << endl;
        cout << "|                Tools              |" << endl;
        cout << "------------------------------------" << endl;
        cout << "| clear -- will clear screen        |" << endl;
        cout << "| 5563  -- will delete all          |" << endl;
        cout << "|          directorys and restart   |" << endl;
        cout << "|          the exe !!               |" << endl;
        cout << "------------------------------------" << endl;
        printdir();
    }

    else if (strStar == "+subd\\")
    {

        //  cout << TxtInput.substr(TxtInput.length() - 3;

        int start, end, sett;
        string ser;

        if (TxtInput.substr(TxtInput.length() - 3) == ".fo" || TxtInput.substr(TxtInput.length() - 3) == ".in")
        {
            for (int b = 1; b < arrayIndexAmount; b++)
            {
                if (usLocB[b] == false)
                {
                    for (int y = 1; y < LocAmount; y++)
                    {
                        usLoc[b] = y;
                        ser = LibArray[usLoc[1]][usLoc[2]][usLoc[3]][usLoc[4]][usLoc[5]];
                        if (ser.length() == 0)
                        {

                            start = 6;
                            end = TxtInput.length();
                            LibArray[usLoc[1]][usLoc[2]][usLoc[3]][usLoc[4]][usLoc[5]] = TxtInput.substr(start, end) + " ";
                            fillcontent();
                            usLoc[b] = 0;
                            sett = y;

                            y = LocAmount + 1;
                            b = arrayIndexAmount + 1;
                        }
                    }
                }
            }

            loadanimin();
            cout << TxtInput.substr(start, end) << " Directory Created";
            loadanimout();
            printdir();
        }
        else
        {

            loadanimin();
            SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
            cout << "Subdirectory Could Not Be Created";
            SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            loadanimout();

            loadanimin();
            SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
            cout << TxtInput.substr(TxtInput.length() - 3) << " Extension Invalid";
            SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            loadanimout();
            printdir();
        }
    }

    else if (strStar == "-subd\\")
    {
        int save[5];
        for (int h = 0; h < LocAmount; h++)
        {
            save[h] = usLoc[h];
        }
        bool found = false;

        for (int p = 1; p < 5; p++)
        {
            if (usLocB[p] == false)
            {
                int r, hold;

                //loc amount
                for (r = 1; r < LocAmount; r++)
                {
                    usLoc[p] = r;

                    if (LibArray[usLoc[1]][usLoc[2]][usLoc[3]][usLoc[4]][usLoc[5]] == TxtInput.substr(6, TxtInput.length()))
                    {

                        LibArray[usLoc[1]][usLoc[2]][usLoc[3]][usLoc[4]][usLoc[5]] = "";

                        r = LocAmount + 1;
                        p = 6;
                        found = true;
                        break;
                    }
                    else
                    {
                    }
                }
            }
        }
        if (found == false)
        {
            loadanimin();
            SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);

            cout << "Could Not Find Directory";
            SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            loadanimout();
        }
        for (int h = 0; h < LocAmount; h++)
        {
            usLoc[h] = save[h];
        }
        printdir();
    }

    else if (TxtInput == "clear")
    {

        system("CLS");

        home();
        printdir();
    }

    else if (TxtInput == "5563")
    {
        string yesno;

        cout << "Are you sure you want to clear all data? (y/n) :";
        cin >> yesno;

        while (true)
        {

            if (yesno == "y")
            {
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);

                for (int q = 0; q < LocAmount; q++)
                {
                    for (int w = 0; w < LocAmount; w++)
                    {
                        for (int e = 0; e < LocAmount; e++)
                        {
                            for (int r = 0; r < LocAmount; r++)
                            {
                                for (int t = 0; t < LocAmount; t++)
                                {
                                    LibArray[t][r][e][w][q] = "";

                                    int x;
                                    string a;

                                    x = rand() % 5 + 1;

                                    if (x == 1)
                                    {
                                        a = "£";
                                    }
                                    else if (x == 2)
                                    {
                                        a = "&";
                                    }
                                    else if (x == 3)
                                    {
                                        a = "(";
                                    }
                                    else if (x == 4)
                                    {
                                        a = "#";
                                    }
                                    else if (x == 5)
                                    {
                                        a = "(";
                                    }

                                    cout << a;
                                    //Sleep(5);
                                }
                            }
                        }
                    }
                }

                system("color 4F");
                Sleep(200);
                system("color 7C");
                Sleep(200);
                system("color 4F");
                Sleep(200);
                system("color 7C");
                Sleep(200);

                SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                system("CLS");

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
                break;
            }
            else if (yesno == "n")
            {
                break;
            }
            else
            {
                cout << "Input must be y or n." << endl;
                cout << "Are you sure you want to clear all data? (y/n) :";
                cin >> yesno;
            }
        }

        cmdEnt = true;

        printdir();
    }

    else if (TxtInput == " " || TxtInput == "")
    {

        if (cmdEnt)
        {
        }
        else
        {

            cout << "enterd" << endl;
            loadanimin();
            SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);

            cout << "No Command Entered";
            SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            loadanimout();
            cmdEnt = true;
            printdir();
        }
    }

    else
    {

        for (int p = 1; p < 5; p++)
        {
            if (usLocB[p] == false)
            {
                int r;
                //loc amount
                for (r = 1; r < LocAmount; r++)
                {
                    usLoc[p] = r;
                    string firstWord, temp;
                    temp = LibArray[usLoc[1]][usLoc[2]][usLoc[3]][usLoc[4]][usLoc[5]];
                    firstWord = temp.substr(0, temp.find(" "));

                    if (TxtInput == firstWord)
                    {
                        usLoc[p] = r;
                        //locacmount
                        r = LocAmount + 1;

                        usLocB[p] = true;

                        cmdfound = true;
                        loadanimin();
                        cout << "Accesed to " << TxtInput << " directory granted";
                        loadanimout();

                        if (firstWord.substr(firstWord.length() - 3) == ".in")
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

    int line = 0;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    for (int p = 1; p < arrayIndexAmount; p++)
    {
        if (usLocB[p] == false)
        {
            SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

            t = LibArray[usLoc[1]][usLoc[2]][usLoc[3]][usLoc[4]][usLoc[5]];
            title = t.substr(0, t.find(" "));

            cout << title << "Subdirectorys found & listed :" << endl;

            int r;
            for (r = 1; r < LocAmount; r++)
            {

                usLoc[p] = r;
                t = LibArray[usLoc[1]][usLoc[2]][usLoc[3]][usLoc[4]][usLoc[5]];
                title = t.substr(0, t.find(" "));

                if (debug == true)
                {
                    cout << endl
                         << t << endl
                         << t.length();
                }

                if (t.length() != 0)
                {

                    randcolour();
                    cout << "[";
                    cout << title;
                    cout << "]";
                    // SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
                    cout << "    ";

                    Sleep(200);

                    line = line + 1;
                    if (line == 3)
                    {
                        cout << endl;
                        line = 0;
                    }
                }
            }

            usLoc[p] = 0;
            p = arrayIndexAmount + 1;
            SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
            cout << endl;
        }
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

void fillcontent()
{
    string cont;

    if (TxtInput.substr(TxtInput.length() - 3) == ".in")
    {
        cout << endl
             << "Please Fill in content of .in File :" << endl;
        //getline(cin, cont);
        cin >> cont;
        LibArray[usLoc[1]][usLoc[2]][usLoc[3]][usLoc[4]][usLoc[5]] = LibArray[usLoc[1]][usLoc[2]][usLoc[3]][usLoc[4]][usLoc[5]] + cont;
    }
    else if (TxtInput.substr(TxtInput.length() - 3) == ".tu")
    {
    }
}

void exportdata()
{

    for (int q = 0; q < LocAmount; q++)
    {
        for (int w = 0; w < LocAmount; w++)
        {
            for (int e = 0; e < LocAmount; e++)
            {
                for (int r = 0; r < LocAmount; r++)
                {
                    for (int t = 0; t < LocAmount; t++)
                    {
                        if (LibArray[t][r][e][w][q].length() == 0)
                        {
                            decode();
                            //file << decodes << "," ;
                        }
                        else
                        {

                            EnCr(t, r, e, w, q);

                            //file << LibArray[t][r][e][w][q] << ",";
                            //file << LibArray[t][r][e][w][q] << t << r << e << w << q << ",";
                        }
                    }
                }
                file << endl;
            }
            file << endl;
        }
        file << endl;
    }
    file << endl;
}

// file << endl = one down
// file << "," = to the right

void decode()
{

    int x;
    char y;

    for (int u = 0; u < rand() % (30 - 10) + 10; u++)
    {
        x = rand() % (250 - 50) + 50;
        y = x;
        file << y;
    }
    file << ",";
}
