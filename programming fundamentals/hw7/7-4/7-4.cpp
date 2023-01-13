#include <iostream>
using namespace std;
int x, y;
int Col[20];
int sum,n;
int vis[3][100]; 
bool attack(int i,int t){
    if(!vis[0][i] && !vis[1][t + i] && !vis[2][t - i + n])
        return false;
    
    return true;
}
void queen(int t)
{
    if (t == n)
        sum++;
    else
        for (int i = 0; i < n; i++)
        {
            if (x - 1 == t && y - 1 == i)
                continue;
            if (!attack(i,t))
            {                                                        
                vis[0][i] = vis[1][t + i] = vis[2][t - i + n] = 1;
                queen(t + 1);
                vis[0][i] = vis[1][t + i] = vis[2][t - i + n] = 0;
            }
        }
}
int main()
{
    cin >> n >> x >> y;
    queen(0);
    cout << sum << endl;
    return 0;
}


//这个超时了两个点...
/*
#include<iostream>
using namespace std;
int n;
int x[15];
int sum;
int p,q;
bool place(int t)
{
    for (int i=1; i<t; i++)
        if ((abs(t-i) == abs(x[i]-x[t])) || (x[i] == x[t]))
            return false;
    return true;
}

void queen(int t)
{
    if (t>n){
        if(x[p]!=q){
            sum++;
        }
    }
    else
        for (int i=1; i<=n; i++)
        {
            x[t] = i;
            if (place(t))
                queen(t+1);
        }
}

int main()
{
    cin>>n>>p>>q;
    sum = 0;
    queen(1);
    cout<<sum<<endl;
    
    return 0;
}
*/