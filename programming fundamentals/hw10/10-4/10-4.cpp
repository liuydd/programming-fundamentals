#include<iostream>
using namespace std;
struct ca{
    int n;
    int a[2020];
};
int gcd(int a,int b){
    int remainer=a%b;
    while(remainer!=0){
        a=b;
        b=remainer;
        remainer=a%b;
    }
    return b;
}
int main(){
    int t;
    cin>>t;
    ca c[t];
    for(int i=0;i<t;i++){
        cin>>c[i].n;
        for(int j=0;j<c[i].n;j++)
            cin>>c[i].a[j];
    }
    for(int i=0;i<t;i++){
        int max=0;
        for(int j=0;j<c[i].n;j++){
            for(int k=j+1;k<c[i].n;k++){
                if(max<gcd(c[i].a[j],c[i].a[k]))
                    max=gcd(c[i].a[j],c[i].a[k]);
            }
        }
        cout<<max<<endl;
    }
    return 0;
}