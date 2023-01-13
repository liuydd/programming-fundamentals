#include<iostream>
#include<string.h>
using namespace std;
struct thing{
    char color[40];
    char x[40];
};
thing t[1050];
int main(){
    int n;
    cin>>n;
    int cnt=1;
    for(int i=0;i<n;i++){
        char s[40];
        cin>>s;
        if(s=="CREATE"){
            cin>>t[cnt].color>>t[cnt].x;
            cnt++;
        }
        else if(s=="DUP"){
            int temp;
            char c1[40];
            cin>>temp>>c1;
            strcpy(t[cnt].x,t[temp].x);
            strcpy(t[cnt].color,c1);
            cnt++;
        }
        else if(s=="CRASH"){
            int index;
            cin>>index;
            for(int i=index;i<cnt-1;i++){
                t[i]=t[i+1];
            }
            cnt-=1;
        }
        else if(s=="ORDER"){
            for(int i=1;i<cnt-1;i++){
                for(int j=i+1;j<cnt;j++){
                    if(strcmp(t[i].color,t[j].color)>0){
                        char te[40];
                        strcpy(te,t[i].color);
                        strcpy(t[i].color,t[j].color);
                        strcpy(t[j].color,te);
                    }
                    else if(t[i].color==t[j].color){
                        if(strcmp(t[i].x,t[j].x)>0){
                        char tem[40];
                        strcpy(tem,t[i].x);
                        strcpy(t[i].x,t[j].x);
                        strcpy(t[j].x,tem);
                    }
                    }
                }
            }
        }
    }
    for(int i=1;i<cnt;i++){
        cout<<t[i].color<<" "<<t[i].x<<endl;
    }
    return 0;
}