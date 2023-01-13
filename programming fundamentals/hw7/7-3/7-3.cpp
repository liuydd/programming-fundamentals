#include <iostream>
#include<stdio.h>
using namespace std;
const int p=10000010;
long long int a[p]={};
void quick_sort(long long int l,long long int r){
    long long int i=l;
    long long int j=r;
    long long int mid=a[(l+r)/2];
    do{
    while(a[i]<mid)
        i++;
    while(a[j]>mid)
        j--;
    if(i<=j){
        swap(a[i],a[j]);
        i++;
        j--;
    }
    }while(i<=j);
    if(l<j)
        quick_sort(l,j);
    if(r>i)
        quick_sort(i,r);
}
int main(){
    int n,n1,n2;
    long long int m1=0,m2=0;
    long long int sum=0;
    scanf("%d",&n);
    for(int i=0;i<p;i++)
        a[i]=0;
    for(int i=0;i<n;i++)
        scanf("%lld",&a[i]); //把这两个都改为lld就AC了
    quick_sort(0,n-1);
    
    for(int i=0;i<=n/2-1;i++)
        m1+=a[i];
    for(int i=n/2;i<n;i++)
        m2+=a[i];
    
    sum=abs(m1-m2);
    printf("%lld",sum); //和这个
    return 0;
}
