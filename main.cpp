#include <iostream>
#include <string>
#include <Windows.h>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <time.h>
#define _WIN32_WINNT 0*0502
using namespace std;

string TxtInput;
bool cmdfound = false;
string LibArray[10][10][10][10][10];
int arrayIndexAmount = 10;
int LocAmount = 5;
int usLoc[5];
bool usLocB[5];
bool exitDir = false;
int Loc[5];




void printdir();
void initializeDictionary();
void TxtInputin();
void TxtInputout();
void cmd2in();
void cmd2out();
void opendi();
void loadanimin();
void loadanimout();
void Subidirectory();
void randcolour();
void remove_scrollbar();


int main()
{
    for(int x=0; x<LocAmount ; x++)
    {
        usLoc[x] = 0;
        cout << usLoc[x];
        
    }
    srand (time(NULL));
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

    for(int n = 1; n<LocAmount; n++) 
    {
        if(usLoc[n] > 0)
        {
            usLocB[n] = true;
        }
        else 
        {
            usLocB[n] = false;
        }
    }

    for(int x=0; x<LocAmount ; x++)
    {
        
        cout << usLoc[x];
        
    }
   
   if(usLocB[1] == true){ cout << LibArray[usLoc[1]][0][0][0][0] << "\\" ;}
   if(usLocB[2] == true){ cout <<  LibArray[usLoc[1]][usLoc[2]][0][0][0] << "\\";}
   if(usLocB[3] == true){ cout << LibArray[usLoc[1]][usLoc[2]][usLoc[3]][0][0] << "\\";}
   if(usLocB[4] == true){ cout << LibArray[usLoc[1]][usLoc[2]][usLoc[3]][usLoc[4]][0] << "\\";}
   if(usLocB[5] == true){ cout << LibArray[usLoc[1]][usLoc[2]][usLoc[3]][usLoc[4]][usLoc[5]] << "\\";}


   

    
    
   TxtInputin();


} 
void TxtInputin()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    cmdfound = false;
    


    getline(cin, TxtInput);


//cout << endl << exitDir << endl;
//cout << TxtInput << endl;



 if (TxtInput == "exit")
    {
       
        
        for(int a= 1; a<LocAmount; a++) 
    {
        
        if(exitDir == false)
        {
       // cout << endl << "a = " << a << endl;
        //cout << "locamount  =" << LocAmount ;
        
       // cout << "exit is fuck";
        if(usLoc[a] > 0)

        //cout << "usloc = " << usLoc[a] << endl;
        {

           // cout << "if main accepted" << endl;

            int d;
            d = a + 1;

            //cout << "usloc d =" << usLoc[d] << endl;

           // cout << "d = " << d;  
            if(usLoc[d] == 0)
            {
                usLoc[a] = 0;
               // cout << "loc =" << a << "has been butt fucked";
                //cout << usLoc[1];

                exitDir = true;
              
                
            }
          
            
        }
        }

       
    }
   
    printdir();

    }


















else {
    for (int p=1;p<5;p++)
    {
     //   cout << "its has been run" << endl;




        
        if (usLocB[p] == false)
cout << "we are in this bitch ";
        
         {
             
             int r;
             //cout <<  LibArray[usLoc[1]][usLoc[2]][usLoc[3]][usLoc[4]][usLoc[5]];   
                                
              for (r = 1; r<arrayIndexAmount; r++)
             {
                 //fucked used to be Usloc[p] = r
                 
                 Loc[p] = r ;
                 if(usLoc[p] > 0) 
                 {

                 }
                 
                
                 if(TxtInput == LibArray[usLoc[1]][usLoc[2]][usLoc[3]][usLoc[4]][usLoc[5]])
                 {
                    
                    usLoc[p] = r; 
                    r = arrayIndexAmount + 1;
                    p = 5;
                    cmdfound = true;       
                    
                                          
                 }
                 cout << "ntohing fouydn";
              
               
                 
                 
        
             }
             
         }

    }


}
    
     
    
    if (cmdfound)
    {

        loadanimin();
        cout << "Accesed to " << TxtInput << " directory granted";
        loadanimout();

        //opendi();

    
      
        printdir();
 



    }
     
    
    



    

    else
    
/*
        if (usLoc1 > 0 && usLoc2 == 0 && usLoc3 == 0)
        {
            usLoc1 = 0;
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
        cout << "| Files listed in the subd search   |" << endl;
        cout << "------------------------------------" << endl;
        cout << "| .fo  = folder                     |" << endl;
        cout << "------------------------------------" << endl;
        cout << "| .in  = informative text           |" << endl;
        cout << "------------------------------------" << endl;
        cout << "| .tu  = is a step by step tutorial |" << endl;
        cout << "------------------------------------" << endl;
        cout << "| .bu  = is a bu is a bug found in a|" << endl;
        cout << "|        real world programe/website|" << endl;
        cout << "|        .bu files will end with a  |" << endl;
        cout << "|         number representing the   |" << endl;
        cout << "|         severity of the bug.      |" << endl;
        cout << "------------------------------------" << endl;

        input();
    }
    */
    
   
    {
        SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "Command Not Found" << endl;
        SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        printdir();
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

    LibArray[2][1][0][0][0] = "lterminal.fo";
    LibArray[2][2][0][0][0] = "lapplications.fo";
    LibArray[2][3][0][0][0] = "luserstuff.fo";




}

void Subidirectory()
{
    /*
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


void remove_scrollbar()
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(handle, &info);
    COORD new_size = 
    {
        info.srWindow.Right - info.srWindow.Left + 1,
        info.srWindow.Bottom - info.srWindow.Top + 1
    };
    SetConsoleScreenBufferSize(handle, new_size);
}
 
