#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int res=0;
    int maxend=0;
    int maxposition=0;
    for(int i=0;i<n-1;i++){
        maxposition=max(maxposition,a[i]+i);
        if(i==maxend){
            res++;
            maxend=maxposition;
        }
    }
    cout<<res<<endl;
    return 0;
}