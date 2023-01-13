#include<iostream>
using namespace std;
int a[1010],b[1010];
int intersection(int *a,int n,int *b,int m){ //A∩B
    int vis[1010];
    int count=0;
    for(int i=0;i<1010;i++)
        vis[i]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i]==b[j]){
                vis[count]=a[i];
                count++;
            }
        }
    }
    for(int i=0;i<count;i++)
        cout<<vis[i]<<" ";
    return 0;
}
int unionset(int *a,int n,int *b,int m){ //A∪B
    
    int vis[2020];
    for(int i=0;i<2020;i++)
        vis[i]=0;
    int p;
    for(p=0;p<n;p++)
        vis[p]=a[p];
    for(int j=0;j<m;j++){
        int flag=1;
        for(int k=0;k<n;k++){
            if(b[j]==vis[k]){
                flag=0;
                break;
            }
        }
        if(flag==1)
            vis[p++]=b[j];
    }
    //排序，呃似乎测试点没用到
    for(int i=0;i<p;i++)
        cout<<vis[i]<<" ";
    return 0;
}
int comple(int *a,int n,int *b,int m){ //A-A∩B
    bool vis[1010];
    for(int i=0;i<1010;i++)
        vis[i]=false;
    int vi[1010];
    int count=0;
    for(int i=0;i<1010;i++)
        vi[i]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i]==b[j]){
                vi[count]=a[i];
                count++;
            }
        }
    }
    for(int i=0;i<count;i++){
        for(int j=0;j<n;j++){
            if(vi[i]==a[j]){
                vis[j]=true;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(vis[i]==false)
            cout<<a[i]<<" ";
    }
    return 0;
}
int main(){
    int n,m;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cin>>m;
    for(int i=0;i<m;i++)
        cin>>b[i];
    intersection(a,n,b,m);
    cout<<endl;
    unionset(a,n,b,m);
    cout<<endl;
    comple(a,n,b,m);
    return 0;
}