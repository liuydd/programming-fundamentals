#include<iostream>
#include<algorithm>
using namespace std;
bool zj[5];
char res[1100];
bool c5[5]={0,1,1,1,1};
int num(char x){
    if(x=='A')
        return 1;
    else if(x=='B')
        return 2;
    else if(x=='C')
        return 3;
    else if(x=='D')
        return 4;
    return 0;
}
char zm(int x){
    if(x==1)
        return 'A';
    else if(x==2)
        return 'B';
    else if(x==3)
        return 'C';
    else if(x==4)
        return 'D';
    return 0;
}
int main(){
    char x,y,z,q;
    int cnt=0;
    cin>>x>>y>>z>>q;
    //根据说辞，下面判断谁真谁假
    //case1
    zj[num(x)]=1; zj[num(y)]=0; zj[num(z)]=0; zj[num(q)]=1;
    if(x==q&&x!=y&&x!=z){
        res[cnt]=x;
        cnt++;
    }
    //case2
    zj[num(x)]=1; zj[num(y)]=1; zj[num(z)]=1; zj[num(q)]=1;
    if(x==y&&y==z&&z==q){
        res[cnt]=x;
        cnt++;
    }
    //case3
    zj[num(x)]=1; zj[num(y)]=1; zj[num(z)]=0; zj[num(q)]=0;
    if(x==y&&x!=z&&x!=q){
        res[cnt]=x;
        cnt++;
    }
    //case4
    zj[num(x)]=0; zj[num(y)]=0; zj[num(z)]=1; zj[num(q)]=1;
    if(z==q&&x!=z&&y!=z){
        res[cnt]=z;
        cnt++;
    }
    //case5
    zj[num(x)]=0; zj[num(y)]=0; zj[num(z)]=0; zj[num(q)]=0;
    c5[num(x)]=c5[num(y)]=c5[num(z)]=c5[num(q)]=0;
    for(int i=1;i<=4;i++){
        if(c5[i]){
            res[cnt]=zm(i);
            cnt++;
        }
    }
    //case 6
    zj[num(x)]=0; zj[num(y)]=1; zj[num(z)]=1; zj[num(q)]=0;
    if(y==z&&x!=y&&q!=y){
        res[cnt]=y;
        cnt++;
    }
    sort(&res[0],&res[cnt-1]);
    for(int i=0;i<cnt;i++)
        cout<<res[i];
    
    return 0;
}