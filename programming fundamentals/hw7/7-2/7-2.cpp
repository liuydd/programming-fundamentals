#include<iostream>
using namespace std;
const int p=100000;
int a[p]={},b[p]={};
void quick_sort(int l,int r){
    int i=l;
    int j=r;
    int mid=a[(l+r)/2];
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
    int n;
    cin>>n;
    int temp=n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    quick_sort(0,n-1);
    /*
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
*/
    int k=0;
    for(int i=0;i<n;i++){
        if(a[i]!=a[k])
            a[++k]=a[i];
    }
    n=k+1;
    cout<<n<<endl;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}
