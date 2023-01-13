#include<iostream>
using namespace std;
int count(int h){
    if(h==1)
        return 1;
    if(h==2)
        return 2;
    if(h==3)
        return 4;
    return count(h-1)+count(h-2)+count(h-3);
}
int main(){
    int h;
    cin>>h;
    if(h<4||h>20)
        cout<<0;
    else
        cout<<count(h);
    return 0;
}