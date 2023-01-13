#include <iostream>
using namespace std;
int main() {
    int a=2;
 cout << "\e[92;100;1m"<<a << endl;
 cout << "\e[92;104;1m2\e[0m" << endl;
 cout << "\e[92;100;1m1\e[92;100;1m1\e[92;104;1m1\e[0m" << endl;
 return 0;
}