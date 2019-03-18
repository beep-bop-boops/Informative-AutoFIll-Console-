#include <iostream>
#include <string>
#include <Windows.h>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <time.h>


using namespace std;

int main()
{

srand (time(NULL));
int a;



HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

for(int p=0; p<10; p++)
{
a = rand() % 3 +1;
cout << a;
if(a==0){SetConsoleTextAttribute(h, FOREGROUND_BLUE);}
else if(a==1){SetConsoleTextAttribute(h, FOREGROUND_GREEN);}
else if(a==2){SetConsoleTextAttribute(h, FOREGROUND_BLUE);}


}




    return 0;
}