#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int res=0;
    int flag=0;
    for(int i=1;i<n;i++){
        int profit=a[i]-a[i-1];
        if(profit>0)
            res+=profit;
    }
    cout<<res<<endl;
    return 0;
}