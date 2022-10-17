#include<iostream>
using namespace std;
int main(){
    double x,y;
    cin>>x>>y;
    int z;
    double pi=3.14;
    double s=pi*(x*x+y*y)/2.0;
    double _z=s/50.0;
    /*
    if(z==_z*50.0)
        z=_z+1;
    else
        z=_z;
    cout<<z<<endl;
*/
    z=_z+1;
    cout<<z<<endl;
    return 0;
}