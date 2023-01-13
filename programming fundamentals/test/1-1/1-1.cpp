#include<iostream>
using namespace std;
struct pos{
    int x;
    int y;
};
struct circle{
  pos p;
  int r;  
};
int main(){
    int n,m;
    cin>>n;
    pos p[510];
    for(int i=0;i<n;i++)
        cin>>p[i].x>>p[i].y;
    cin>>m;
    circle c[510];
    for(int i=0;i<m;i++)
        cin>>c[i].p.x>>c[i].p.y>>c[i].r;
    int sum[510];
    for(int j=0;j<m;j++){
        sum[j]=0;
    for(int i=0;i<n;i++){
        int l=(p[i].x-c[j].p.x)*(p[i].x-c[j].p.x)+(p[i].y-c[j].p.y)*(p[i].y-c[j].p.y);
        if(l<=(c[j].r*c[j].r))
            sum[j]++;
    }
    }
    for(int i=0;i<m;i++)
        cout<<sum[i]<<" ";
    return 0;
}