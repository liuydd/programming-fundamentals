#include<iostream>
using namespace std;
struct date{
    int y;
    int m;
    int d;
};
bool judge(long long int year){
    if(year%4==0||year%400==0)
        return true;
    return false;
}
bool jm(int month){
    if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
        return true;
    return false;
}
long long int distance(date d1){
    long long int res=0;

        if(d1.m==1){
            res+=d1.d;
        }
        else{
            res+=d1.d;
            res+=(d1.m-1)*30;
            for(int i=1;i<d1.m;i++){
                if(jm(i))
                    res+=1;
                if(i==2){
                        if(judge(d1.y))
                            res-=1;
                        else
                            res-=2;
                    }
            }
        }
    res+=(d1.y-2021)*365;
    for(int i=2021;i<d1.y;i++){
            if(judge(i))
                res+=1;
        }
    return res;
}
int main(){
    long long int x,y;
    cin>>x>>y;
    date d1,d2;
    d1.d=x%100; d2.d=y%100;
    d1.m=(x/100)%100; d2.m=(y/100)%100;
    d1.y=x/10000; d2.y=y/10000;
    cout<<distance(d2)-distance(d1)+1<<endl;
    return 0;
}