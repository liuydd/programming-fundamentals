#include<iostream>
using namespace std;
int sum(int a,int b){
    int s=0;
    s=(a+b)*(b-a+1)/2;    //这里不用for循环一项一项加后，就过了（原来的超时了
    return s;
}
int main(){
    int n;
    cin>>n;
    for (int i=1;i<n;i++){
        for (int j=i+1;j<n;j++){
            if(n==sum(i,j))
                cout<<i<<" "<<j<<endl;
        }
    }
    return 0;
}