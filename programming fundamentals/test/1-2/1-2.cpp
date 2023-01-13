#include<iostream>
using namespace std;
bool judge(long long int date){
    if(date%4==0||date%400==0)
        return true;
    return false;
}
bool jm(int month){
    if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
        return true;
    return false;
}
int main(){
    long long int x,y;
    cin>>x>>y;
    int y1,y2;
    int m1,m2;
    int d1,d2;
    d1=x%100; d2=y%100;
    m1=(x/100)%100; m2=(y/100)%100;
    y1=x/10000; y2=y/10000;
    long long int res=0;
    //cout<<y1<<" "<<m1<<" "<<d1<<endl;
    //cout<<y2<<" "<<m2<<" "<<d2<<endl;
    if(y1==y2){
        if(m1==m2)
            res=d2-d1+1;
        else{
            if(d2>=d1){
                res+=d2-d1+1;
                res+=(m2-m1)*30;
                for(int i=m1;i<m2;i++){
                    if(jm(i))
                    res+=1;
                    if(i==2){
                        if(judge(y1))
                            res-=1;
                        else
                            res-=2;
                    }

                }
            }
            else{
                if(jm(m1))
                    res+=32-d1+d2;
                else
                    res+=31-d1+d2;
                res+=(m2-m1-1)*30;
                for(int i=m1+1;i<m2;i++){
                    if(jm(i))
                        res+=1;
                    if(i==2){
                        if(judge(y1))
                            res-=1;
                        else
                            res-=2;
                    }
                }
            }
        }
    }
    else{
        if(m1==m2){
            if(d2>=d1){
                res+=d2-d1+1;
                res+=(y2-y1)*365;
                for(int i=y1;i<y2;i++){
                    if(judge(i)){
                    res+=1;
                }
                }
            }
            else{
                if(jm(m1)){
                    res+=32-d1;
                    res+=d2+(y2-y1)*365-31;
                }
                else{
                    res+=31-d1;
                    res+=d2+(y2-y1)*365-30;
                }
                for(int i=y1;i<y2;i++){
                    if(judge(i)){
                    res+=1;
                }
                }
            }
        }
        else{
           
        if(m2==1)
            res+=d2+1;
        else{
            res+=d2+1;
            res+=(m2-1)*30;
            for(int i=1;i<m2;i++){
            if(jm(i)){
                res+=1;
            }
            if(i==2){
                        if(judge(y1))
                            res-=1;
                        else
                            res-=2;
                    }
        }
        }
        res+=(12-m1)*30;
        for(int i=1;i<m2;i++){
            if(jm(i)){
                res+=1;
            }
            if(i==2){
                        if(judge(y1))
                            res-=1;
                        else
                            res-=2;
                    }
        }
        res+=31-d1;
           
        res+=(y2-1-y1)*365;
        for(int i=y1;i<y2;i++){
            if(judge(i))
                res+=1;
        }
        }
    }
    cout<<res<<endl;
    return 0;
}