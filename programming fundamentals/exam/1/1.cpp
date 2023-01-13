#include<iostream>
using namespace std;
int t[10010];
bool vis[10010];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
        cin>>t[i];
    for(int i=1;i<=m;i++){
        vis[t[i]]=1;
    }
    int flag=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            cout<<i<<" ";
            flag=1;
        }
    }
    if(flag==0)
        cout<<"ALL"<<endl;
    return 0;
}