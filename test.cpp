#include <iostream>
 
using namespace std;
 
const char Line = 196;
const char WHITE = 32;
const int SIZE = 8;
const int BLOCK = 3;
 
 int print(int amount)
 {
     for(int i=0;i<amount; i++)
     {
         cout << Line;
     }

 }
int main()
{


print(5);



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