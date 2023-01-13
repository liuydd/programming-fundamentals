#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
const  double lg= log(10.0);
bool bp(long long a,long long b){
    long double  r = log(a) / lg * b;
    long double cut = r - int(r);
    if (r < 3)
        return false;
    else
        return true;
}
long long binpow(long long a,long long b){
    long long c=1000;
    a%=c;
    long long res=1;
    while(b>0){
        if(b&1)
            res=res*a%c;
        a=a*a%c;
        b>>=1;
    }
    return res;
}
//这个有两个点过不了，如1100^2
//update 过了
int pow1(int a, int b) {
    long double  r = b*log10(a); //这里，最终发现真正的问题出在这里，不能用log(a)/lg*b，那样不精确
    //cout<<"r="<<r<<endl;
    //long double r=b*log(a)/log(10.0);
    long double cut = r - int(r);
    if (r < 3)
        return int(pow(a, b));
    else{
        return int(pow(10.0, cut + 2.0)); //还有这里的.0
    }
}
/*
//这个都过了
int front(int n,int m){
    double b=m*log10(n);
    double d=1;
    for(int i=1;i<=m;i++){
        d*=n;
        if(d>100)
            return (int)(pow(10.0,b-(int)(b)+2.0));
    }
    return (int)d;
}
*/
int main(){
    int t;
    cin>>t;
    long long n,m;
    for(int i=0;i<t;i++){
        cin>>n>>m;
        long long ans=binpow(n,m);
        int an=pow1(n,m);
        //int an=front(n,m);
        if(!bp(n,m)){
            if(ans<=9)
                cout<<0<<0<<an<<" "<<0<<0<<ans<<endl;
            else if(ans>9&&ans<=99)
                cout<<0<<an<<" "<<0<<ans<<endl;
            else if(ans>99&&ans<=999)
                cout<<an<<" "<<ans<<endl;
        }
        else{
           if(ans<=9)
                cout<<an<<" "<<0<<0<<ans<<endl;
            else if(ans>9&&ans<=99)
                cout<<an<<" "<<0<<ans<<endl;
            else if(ans>99&&ans<=999)
                cout<<an<<" "<<ans<<endl;
        }
    }
    return 0;
}

