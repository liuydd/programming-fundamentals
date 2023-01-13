/*
#include<iostream>
using namespace std;
struct line{
    int begin;
    int end;
};
int main(){
    int n,m;
    line l[25010];
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>l[i].begin>>l[i].end;
    for(int j=n-1;j>=0;j--){
    for(int i=0;i<j;i++){
        if(l[i].begin>l[i+1].begin){
            swap(l[i],l[i+1]);
        }
    }
    }
    for(int j=n-1;j>=0;j--){
        for(int i=0;i<j;i++){
            if(l[i].begin==l[i+1].begin){
            if(l[i].end>l[i+1].end)
                swap(l[i],l[i+1]);
        }
        }
    }
    if(l[0].begin>1)
        cout<<-1<<endl;
    int now=1,pos=0,ans=0;
    while(pos<n&&now<=m){
        int mx=0;
        while(pos<n&&l[pos].begin<=now){
            mx=max(mx,l[pos].end);
            pos++;
        }
        if(mx<=now-1) break;
        now=mx+1;
        ans++;
    }
    if(now>=m) cout<<ans<<endl;
    else cout<<-1<<endl;
    return 0;
    }
    */
#include <iostream>
using namespace std;
struct Line{
    int x,y;
}A[25000 + 100];

int main(){
    ios::sync_with_stdio(false);
    int N, T;
    cin >> N >> T;
    for(int i = 0; i < N; i++)
        cin >> A[i].x >> A[i].y;
        for(int j=N-1;j>=0;j--){
    for(int i=0;i<j;i++){
        if(A[i].x>A[i+1].x){
            swap(A[i],A[i+1]);
        }
    }
    }
    for(int j=N-1;j>=0;j--){
        for(int i=0;i<j;i++){
            if(A[i].x==A[i+1].x){
            if(A[i].y<A[i+1].y)
                swap(A[i],A[i+1]);
        }
        }
    }
        int i = 0, cnt = 1, ok = 1;
        if(A[i].x > 1)ok = 0;
        else while(i < N -1 && A[i].y < T){
            int t = i;
            for(int j = i + 1; j < N &&A[j].x <= A[i].y+1; j++)
                if(A[j].y > A[t].y) t = j;
            if(t == i){
                ok = 0;
                break;
            }
            else i = t, cnt++;
        }
        if(A[i].y < T) ok = 0;
        if(ok)cout << cnt << endl;
        else cout << -1 << endl;
    
    return 0;
}