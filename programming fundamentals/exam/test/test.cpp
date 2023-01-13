#include<iostream>
using namespace std;
int main(){
    string s1,e1,s2,e2;
    cin>>s1>>e1;
    cin>>s2>>e2;
    int s1_h,s1_m,s2_h,s2_m;
    int e1_h,e1_m,e2_h,e2_m;
    //cout<<t1.s[1]<<endl;
    s1_h=(s1[0]-'0')*10+s1[1]-'0';
    s1_m=(s1[3]-'0')*10+s1[4]-'0';
    e1_h=(e1[0]-'0')*10+e1[1]-'0';
    e1_m=(e1[3]-'0')*10+e1[4]-'0';
    s2_h=(s2[0]-'0')*10+s2[1]-'0';
    s2_m=(s2[3]-'0')*10+s2[4]-'0';
    e2_h=(e2[0]-'0')*10+e2[1]-'0';
    e2_m=(e2[3]-'0')*10+e2[4]-'0';
    //cout<<t2.s_h<<" "<<t2.s_m<<" "<<t1.e_h<<" "<<t1.e_m<<endl;
    //还需要排个序
    if(s1_h>s2_h){
        swap(s1_h,s2_h);
        swap(s1_m,s2_m);
    }
    else if(s1_h==s2_h){
        if(s1_m>s2_m){
            swap(s1_h,s2_h);
            swap(s1_m,s2_m);
            swap(e1_h,e2_h);
            swap(e1_m,e2_m);
        }
    }

    int flag=0;
    if(e1_h>s2_h)
        flag=1;
    else if(e1_h==s2_h){
        if(e1_m>s2_m)
            flag=1;
    }
    if(flag==0)
        cout<<-1<<endl;
    else{
        int res=0;
        if(e1_h==s2_h){
            res=e1_m-s2_m;
        }
        else{
            //if(t1.e_m>=t2.s_m)
                res=(e1_h-s2_h)*60+e1_m-s2_m;
            //else
                //res=(t1.e_h-t2.s_h)*60+t1.e_m-t2.e_m;
        }
        cout<<res<<endl;
    }
    return 0;
}