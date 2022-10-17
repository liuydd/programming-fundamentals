#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int day,hour,min;
    day=n/1440;
    hour=(n-day*1440)/60;
    min=n-day*1440-hour*60;
    cout<<day<<" "<<hour<<" "<<min<<endl;
    return 0;
}
