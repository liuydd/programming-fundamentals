#include<iostream>
using namespace std;
struct time{
    string s;
    string e;
    int s_h;
    int s_m;
    int e_h;
    int e_m;
};
//time t[2];
time t1;
time t2;
int main(){
    cin>>t1.s>>t1.e;
    cin>>t2.s>>t2.e;
    //cout<<t1.s[1]<<endl;
    t1.s_h=(t1.s[0]-'0')*10+t1.s[1]-'0';
    t1.s_m=(t1.s[3]-'0')*10+t1.s[4]-'0';
    t1.e_h=(t1.e[0]-'0')*10+t1.e[1]-'0';
    t1.e_m=(t1.e[3]-'0')*10+t1.e[4]-'0';
    t2.s_h=(t2.s[0]-'0')*10+t2.s[1]-'0';
    t2.s_m=(t2.s[3]-'0')*10+t2.s[4]-'0';
    //t2.e_h=(t2.e[0]-'0')*10+t2.e[1]-'0';
    //t2.e_m=(t2.e[3]-'0')*10+t2.e[4]-'0';
    //cout<<t2.s_h<<" "<<t2.s_m<<" "<<t1.e_h<<" "<<t1.e_m<<endl;
    //还需要排个序
    if(t1.s_h>t2.s_h)
        swap(t1,t2);
    else if(t1.s_h==t2.s_h){
        if(t1.s_m>t2.s_m)
            swap(t1,t2);
    }

    int flag=0;
    if(t1.e_h>t2.s_h)
        flag=1;
    else if(t1.e_h==t2.s_h){
        if(t1.e_m>t2.s_m)
            flag=1;
    }
    if(flag==0)
        cout<<-1<<endl;
    else{
        int res=0;
        if(t1.e_h==t2.s_h){
            res=t1.e_m-t2.s_m;
        }
        else{
            //if(t1.e_m>=t2.s_m)
                res=(t1.e_h-t2.s_h)*60+t1.e_m-t2.s_m;
            //else
                //res=(t1.e_h-t2.s_h)*60+t1.e_m-t2.e_m;
        }
        cout<<res<<endl;
    }
    return 0;
}