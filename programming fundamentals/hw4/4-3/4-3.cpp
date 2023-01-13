#include<iostream>
#include<cmath>
using namespace std; 
/*
const int p=1000000;
void judge(int n,int r){
    //筛法筛出质数
    bool isPrime[p]={};
    for(int i=0;i<p;i++)
        isPrime[i]=true;
    int flag=0;
    isPrime[n]=false;
    for(int i=2;i<=sqrt(n+r);i++){
        //cout<<isPrime[i]<<endl;
            if(isPrime[i]){
                for(int j=i*i;j<=(n+r);j+=i){
                    isPrime[j]=false;
                }
            }
        }
    if(n>r){
        for(int i=n-r;i<=(n+r);i++){ //相当于人为地多加了一层复杂度
            if(isPrime[i]){  
                flag=1;
                break;
            }
        }
    }
    else{
        for(int i=1;i<=sqrt(n+r);i++){
            if(isPrime[i]){
                flag=1;
                break;
            }
        }
    }
    
    if(flag==1)
        cout<<"T"<<endl;
    else
        cout<<"F"<<endl;
        
}
*/

bool prime(int i) {
 for (int j = 2; j * j <= i; j++) {
  if (i % j == 0)
   return false;
 }
 return true;
}
bool judge(int n, int r) {
if (n <= r) {
  for (int i = 1; i < n - 1; i++) {
    if (prime(i + 1))
        return true;
  }
 }
else {
  for (int i = n - r; i <= n - 1; i++) {
    if (prime(i))
        return true;
  }
 }
    
for (int i = n + 1; i <= n + r; i++) {
    if (prime(i))
        return true;
 }
    return false;
}


int main(){
    
    int t,r;
    int n[10000];
    cin>>t>>r;
    for(int i=0;i<t;i++){
        cin>>n[i];
    }
    for(int i=0;i<t;i++){
        if(judge(n[i],r))
            cout<<"T"<<endl;
        else
            cout<<"F"<<endl;
    }
    
   //judge(10,1);
    return 0;
}
