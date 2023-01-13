//不知道哪里错了怎样输出都是1...
#include<iostream>
using namespace std;
int n;
int count;
int col[15]; //数组表示列，下标表示行
bool attack(int k){
    for(int i=1;i<k;i++){
        if((abs(k-i)==abs(col[k]-col[i]))||(col[k]==col[i]))
            return false;
    }
    return true;
}
void queen(int t){
    if(t>=n)
        count++;
    else{
    for(int i=1;i<=n;i++){ //i表示列
        col[t]=i;
        /*
        if(t==p&&col[t]==q)
            continue;
            */
        if(attack(t)){
            queen(t+1);
        }
    }
    }
}
int main(){
    int n,x,y;
    count=0;
    cin>>n;
    queen(1);
    cout<<count<<endl;
    return 0;
}