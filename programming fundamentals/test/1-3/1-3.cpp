#include<iostream>
using namespace std;
char s[110][110];
bool vis[110][110];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>s[i][j];
        }
    }
    for(int i=0;i<n;i++){
        int index[n];
        int flag[7]={0,0,0,0,0,0,0};
        for(int j=0;j<n;j++){
        int cnt=0;
        if(flag[0]==0&&s[i][j]=='p'){
            index[cnt]=j;
            cnt++;
            flag[0]=1;
        }
        if(flag[1]==0&&s[i][j]=='r'){
            index[cnt]=j;
            cnt++;
            flag[1]=1;
        }
        if(flag[2]==0&&s[i][j]=='o'){
            index[cnt]=j;
            cnt++;
            flag[2]=1;
        }
        if(flag[3]==0&&s[i][j]=='g'){
            index[cnt]=j;
            cnt++;
            flag[3]=1;
        }
        if(flag[4]==0&&s[i][j]=='r'){
            index[cnt]=j;
            cnt++;
            flag[4]=1;
        }
        if(flag[5]==0&&s[i][j]=='a'){
            index[cnt]=j;
            cnt++;
            flag[5]=1;
        }
        if(flag[6]==0&&s[i][j]=='m'){
            index[cnt]=j;
            cnt++;
            flag[6]=1;
        }
        }
        
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-6;j++){
            if(s[i][j]=='p'&&s[i][j+1]=='r'&&s[i][j+2]=='o'&&s[i][j+3]=='g'&&s[i][j+4]=='r'&&s[i][j+5]=='a'&&s[i][j+6]=='m'){
                vis[i][j]=vis[i][j+1]=vis[i][j+2]=vis[i][j+3]=vis[i][j+4]=vis[i][j+5]=vis[i][j+6]=1;
            }
            else if(s[i][j]=='m'&&s[i][j+1]=='a'&&s[i][j+2]=='r'&&s[i][j+3]=='g'&&s[i][j+4]=='o'&&s[i][j+5]=='r'&&s[i][j+6]=='p'){
                vis[i][j]=vis[i][j+1]=vis[i][j+2]=vis[i][j+3]=vis[i][j+4]=vis[i][j+5]=vis[i][j+6]=1;
            }
        }
    }
    for(int j=0;j<n;j++){
        for(int i=0;i<n-6;i++){
            if(s[i][j]=='p'&&s[i+1][j]=='r'&&s[i+2][j]=='o'&&s[i+3][j]=='g'&&s[i+4][j]=='r'&&s[i+5][j]=='a'&&s[i+6][j]=='m')
                vis[i][j]=vis[i+1][j]=vis[i+2][j]=vis[i+3][j]=vis[i+4][j]=vis[i+5][j]=vis[i+6][j]=1;
            else if(s[i][j]=='m'&&s[i+1][j]=='a'&&s[i+2][j]=='r'&&s[i+3][j]=='g'&&s[i+4][j]=='o'&&s[i+5][j]=='r'&&s[i+6][j]=='p')
                vis[i][j]=vis[i+1][j]=vis[i+2][j]=vis[i+3][j]=vis[i+4][j]=vis[i+5][j]=vis[i+6][j]=1;
        }
    }
    for(int i=0;i<n-6;i++){
        for(int j=0;j<n-6;j++){
            if(s[i][j]=='p'&&s[i+1][j+1]=='r'&&s[i+2][j+2]=='o'&&s[i+3][j+3]=='g'&&s[i+4][j+4]=='r'&&s[i+5][j+5]=='a'&&s[i+6][j+6]=='m')
                vis[i][j]=vis[i+1][j+1]=vis[i+2][j+2]=vis[i+3][j+3]=vis[i+4][j+4]=vis[i+5][j+5]=vis[i+6][j+6]=1;
            else if(s[i][j]=='m'&&s[i+1][j+1]=='a'&&s[i+2][j+2]=='r'&&s[i+3][j+3]=='g'&&s[i+4][j+4]=='o'&&s[i+5][j+5]=='r'&&s[i+6][j+6]=='p')
                vis[i][j]=vis[i+1][j+1]=vis[i+2][j+2]=vis[i+3][j+3]=vis[i+4][j+4]=vis[i+5][j+5]=vis[i+6][j+6]=1;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!vis[i][j])
                cout<<'*';
            else
                cout<<s[i][j];
        }
        cout<<endl;
    }
    return 0;
}