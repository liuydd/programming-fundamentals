#include<iostream>
using namespace std;
struct meal{
    int A,B,C,D;
};
int main(){
    meal m[5];
    m[0]={2,1,0,2};
    m[1]={1,1,1,1};
    m[2]={0,0,2,1};
    m[3]={0,3,0,0};
    m[4]={1,0,0,1};
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int count[5]={};
    for(int i=0;i<5;i++)
        count[i]=0;
    for(int i=0;i<5;i++){
        while(a>=m[i].A&&b>=m[i].B&&c>=m[i].C&&d>=m[i].D){
            count[i]++;
            a-=m[i].A;
            b-=m[i].B;
            c-=m[i].C;
            d-=m[i].D;
        }
    }
    for(int i=0;i<5;i++)
        cout<<count[i]<<endl;
    return 0;
}