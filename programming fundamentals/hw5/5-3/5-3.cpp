#include<iostream>
using namespace std;
struct file{
    string filename;
    int filetype;
    string fileinfo;
};
int main(){
    string s,name,info;
    int type;
    file f[1000];
    int count=0;
    while(cin>>s){
        int flag=0;
        int repo=0;
        if(s=="exit")
            break;
        else if(s=="create"){
            cin>>name>>type>>info;
            for(int i=0;i<count;i++){
                if(name==f[i].filename){
                    f[i].filetype=type;
                    f[i].fileinfo=info;
                    flag=1;
                    repo=i;
                    break;
                }
            }
            if(type==0){
                f[count]={name,type,info};
                count++;
                if(flag==1)
                    count--;
                
            }
            else{
                for(int i=0;i<count;i++){
                    if(info==f[i].filename){
                        if(flag==0){
                        file *p=&f[i];
                        f[count]={name,type,(*p).fileinfo};
                        count++;
                        break;
                        }
                        else{
                        file *p1=&f[i];
                        f[repo]={name,type,(*p1).fileinfo};
                        break;
                        }
                    }
                }
            }
            
        }
        else if(s=="open"){
            cin>>name;
            for(int i=0;i<count;i++){
                if(name==f[i].filename){
                    cout<<f[i].fileinfo<<endl;
                    break;
                }
            }

        }
        else{
            continue;
        }
    }
    return 0;
}