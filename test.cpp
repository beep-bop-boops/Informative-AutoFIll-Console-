
#include <iostream>
#include <string>
#include <Windows.h>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <time.h>
#include <fstream>
#include <ctime>



using namespace std;

int main()
{

    

ofstream file;
ifstream importfile;


file.open("hello.csv");

char p = 0;

cout << "p =" << p << endl;

int y = 0;
for(int u=0;u<20;u++)
{
    
for(int t=0;t<20;t++)
{
    y = y +1;

    file << "Id = " << y << " Symbol = " << p << ",";
    p = p +1;
    
}
file << endl;
}

p = 178;
cout << " =============" << p;

Sleep(1000);
importfile.open("hello.csv");


string in;

while(importfile.good())
{
    


for(int t=0;t<200;t++)
{
    getline(importfile, in, ',');
     cout << " -------   Id =  " << t << "    Symbol = " << in << "--------" << endl;
    
}


     
     
}

cout << in;

system("pause");
return 0;
}


