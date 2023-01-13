#include<iostream>
using namespace std;
struct line{
    int begin;
    int end;
};
int main(){
    int n;
    int cnt=0;
    cin>>n;
    line l[n];
    for(int i=0;i<n;i++){
        cin>>l[i].begin>>l[i].end;
    }
    for(int j=n-1;j>=0;j--){
    for(int i=0;i<j;i++){
        if(l[i].begin>l[i+1].begin){
            swap(l[i],l[i+1]);
        }
    }
/*
for(int i=0;i<n;i++)
    cout<<l[i].begin<<" "<<l[i].end<<endl;
*/
    }
    for(int i=1;i<n;i++){
        if(l[i].begin>=l[i-1].end){
            cnt=cnt+l[i-1].end-l[i-1].begin;
        }
        else{
            l[i].begin=min(l[i-1].begin,l[i].begin); //最后的错误在这里，要用min，还要用max
            l[i].end=max(l[i-1].end,l[i].end);
        }
        if(i==n-1){
            cnt=cnt+l[i].end-l[i].begin;
        }
    }
    cout<<cnt<<endl;
    return 0;
}