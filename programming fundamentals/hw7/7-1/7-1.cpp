#include<iostream>
using namespace std;
long long int a[1000010];
long long int n,m; //我不理解，为啥n和m都要改成long long...
bool judge(long long int x){
    long long int sum=0;
    long long int k=0; //还有k...
    for(int i=0;i<n;i++){
        if(sum+a[i]>x){
            sum=0;
            k++;
        }
        if(k>m-1){
            sum=0;
            return false; //说明x太小
        }
        sum+=a[i];
    }
    return true; //说明x太大
}
int ef(long long int l,long long int r){
    long long int mid;
    while(l<r){  //别忘了这个循环！这是判断条件
    //cout<<"l="<<l<<" "<<"r="<<r<<endl;
    mid=(l+r)/2; //别忘记更新mid...
    if(judge(mid)){
        r=mid;
    }
    else{
        l=mid+1;
    }
    }
    return l;
}
int main(){
    long long int max=-1;
    long long int sum=0;
    cin>>n>>m;
    for(int i=0;i<1000010;i++)
        a[i]=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>max)
            max=a[i];
        sum+=a[i];
    }
    //cout<<max<<" "<<sum<<endl;
    //cout<<ef(max,sum)<<endl;
    printf("%lld",ef(max,sum));  //还有这个输出...
    return 0;
}