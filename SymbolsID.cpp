#include <iostream>
#include <windows.h>
 
using namespace std;
 


int main()
{

int num = 0 ;

     for(int i=0;i<254; i++)
     {

         num = num + 1;
         const char test = num;
         cout << "ID = " << num << " Symbol = " << test << "     ";

         if(i%5 == 0)
         {
             cout << endl << endl;
         }
         
        // Sleep(500);
        //system("CLS");
         
     }





system("pause");
return 0;
}








/*
    for (int i = 0; i < SIZE; i ++) {
        for (int u = 0; u < BLOCK; u ++) {
            for (int j = 0; j < SIZE; j ++) {
                int c = (i + j) & 1;
                for (int k = 0; k < BLOCK; k ++) {
                    if (c == 1) {
                        cout << BLACK;
                    } else {
                        cout << WHITE;
                    }
                }
            }
            cout << endl;
        }
    }
    return 0;
*/