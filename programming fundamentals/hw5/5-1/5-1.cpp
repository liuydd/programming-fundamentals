#include<iostream>
using namespace std;
int main(){
    int p1,p2,p3;
    cin>>p1>>p2>>p3;
    string s;
    cin>>s;
    int count=0;
    for(int i=0;i<s.length();i++){//直接帮判断边输出，不需要另存一份后再判断输出
        char a=s[i-1],b=s[i+1];
        if(s[i]=='-'){
            if((a>='a'&&b<='z'||a>='0'&&b<='9')&&a<b){
                if(p1==2&&(a>='a'&&b<='z')){
                    a-=32;
                    b-=32;
                }
                if(p3==2)
                    swap(a,b);
                while(a!=b){
                    if(p3==1)
                        a++;
                    else
                        a--;
                    if(a==b)
                        break;
                    for(int j=1;j<=p2;j++){
                        if(p1==3)
                            cout<<"*";
                        else
                            cout<<a;
                    }
                }
            }
            else
                cout<<s[i];
        }
        else
            cout<<s[i];
    }
    cout<<endl;
    return 0;
}