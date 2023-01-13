#include<iostream>
#include<algorithm>
using namespace std;
struct stu{
    int h;
    string n;
};
stu st[1010];
bool cmp(stu s1,stu s2){
    if(s1.h!=s2.h) return s1.h<s2.h;
    else return (s1.n+s2.n)<(s2.n+s1.n);
}
int ind(string s1,string s2){
    int len=min(s1.length(),s2.length());
    int res=0;
    for(int i=0;i<len;i++){
        if(s1[i]!=s2[i])
            res=i;
    }
    return res;
}
int main(){
    int n;
    cin>>n;
    int cnt=0;
    for(int t=0;t<n;t++){
    string s;
    cin>>s;
    if(s=="ADD"){
        cin>>st[cnt].n>>st[cnt].h;
        cnt++;
    }
    else if(s=="SELECT"){
        stu s2;
        cin>>s2.n;
        int in;
        for(int i=0;i<cnt;i++){
            if(st[i].n==s2.n){
                s2.h=st[i].h;
                in=i;
            }
        }
        for(int i=in;i>=1;i--){
            st[i]=st[i-1];
        }
        st[0]=s2;
    }
    else if(s=="LEAVE"){
        stu s1;
        cin>>s1.n;
        int index;
        for(int i=0;i<cnt;i++){
            if(st[i].n==s1.n){
                index=i;
            }
        }
        for(int i=index;i<cnt-1;i++){
            st[i]=st[i+1];
        }
        cnt--;
    }
    else if(s=="ORDER"){
        //sort(&st[0],&st[cnt-1],cmp);
        
        for(int i=0;i<cnt-1;i++){
            for(int j=i+1;j<cnt;j++){
                if(st[i].h>st[j].h)
                    swap(st[i],st[j]);
                else if(st[i].h==st[j].h){
                    int in=ind(st[i].n,st[j].n);
                    if(st[i].n[in]>st[j].n[in])
                        swap(st[i],st[j]);
                }
            }
        }
        
    }
    }
    for(int i=0;i<cnt;i++)
        cout<<st[i].n<<" "<<st[i].h<<endl;
    return 0;
}