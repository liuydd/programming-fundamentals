#include<iostream>
#include<cctype>
using namespace std;
int main(){
    string s1,s2;
    cin>>s1;
    cin>>s2;
    int flag=0;
    if(s1.size()!=s2.size())
        flag=1;
    else{
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i])
                break;
            if(i==s1.size()-1&&s1[i]==s2[i])
                flag=2;   //这里不能先判断相等时令flag=2，否则就进不去下面的对类型3和4的判断中
        }
    }
    if(flag==0){
        for(int i=0;i<s1.size();i++){
            s1[i]=tolower(s1[i]);
            s2[i]=tolower(s2[i]);
        }
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                flag=4;
                break;
            }
            else
                flag=3;
        }
    }

    if(flag==1)
        cout<<"1";
    else if(flag==2)
        cout<<"2";
    else if(flag==3)
        cout<<"3";
    else if(flag==4)
        cout<<"4";
        
    return 0;
}