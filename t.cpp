#include <iostream>
#include <string>
using namespace std;
int main() 
{
string test;
getline(cin, test, '<');
cout << "Read input:\n\n '"<< test << "'";
}