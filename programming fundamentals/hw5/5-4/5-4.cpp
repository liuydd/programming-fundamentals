#include<iostream>
using namespace std;
struct book{
    string category;
    string name;
    int mean;
};
int main(){
    int T;
    cin>>T;
    string c,n;
    int m;
    string s;
    int count=0;
    book bk[1010];
    for(int t=T;t>0;t--){
        while(cin>>s){
            if(s=="ENLIST"){
//这个和第二个操作均使用数组
                cin>>c>>n>>m;
                bk[count]={c,n,m};
                count++;
                break;
            }
            else if(s=="REMOVE"){
                cin>>n;
                for(int i=0;i<count;i++){
                    if(n==bk[i].name){
                        for(int j=i;j<count-1;j++){
                            bk[j]=bk[j+1];
                        }
                        count--;
                        i--;
                    }
                }
                break;
            }
            else if(s=="REFINE"){
//先将这一类的书交换到书的最上面，并且冒泡排序，然后refine删除除第一本以下的书
//update：此方法不行，应该直接删除，并且在过程中再用一本书来保存有最大期望值的书
                cin>>c;
                /*
                int cc=0;
                for(int i=0;i<count;i++){
                    if(c==bk[i].category){
                        swap(bk[i],bk[count-1-cc]);
                        cc++;
                        //i--;
                    }
                }
                if(cc>0){
                for(int i=(count-cc);i<count;i++){//
                    for(int j=(count-cc);j<(count-1);j++){ //
                        if(bk[j].mean>bk[j+1].mean){
                            swap(bk[j],bk[j+1]);
                        }
                    }
                }
                swap(bk[count-cc],bk[count-1]);
                count=count-cc+1;
                }
                */
                book res={"A","B",0};
                bool flag=false;
                for(int i=0;i<count;i++){
                    if(c==bk[i].category){
                        flag=true;
                        if(res.mean<=bk[i].mean){
                            res=bk[i];
                        }
                        for(int j=i;j<count-1;j++){
                            bk[j]=bk[j+1];
                        }
                        count--;
                        i--; //删除的时候注意这里要让i减1，否则不能判断最前面的那个
                    }
                }
                if(flag==true){
                    count++;
                    bk[count-1]=res;
                }
                break;
            }
            else if(s=="CLEANUP"){
//先冒泡将这一类的书排到最上面，再全删除，再将剩下的书按期望冒泡排序
//update：同上update，不应该将这一类书全交换到上面（这样不好“迭代”），应该直接删除。
                cin>>c;
                for(int i=0;i<count;i++){
                    if(c==bk[i].category){
                        for(int j=i;j<count-1;j++){
                            bk[j]=bk[j+1];
                        }
                        count--;
                        i--;
                    }
                }
                for(int i=0;i<count;i++){//
                    for(int j=0;j<(count-1);j++){ //
                        if(bk[j].mean>bk[j+1].mean){
                            swap(bk[j],bk[j+1]);
                        }
                    }
                }
                break;
            }
            else{
                continue;
            }
        }
}
    if(count>=3){
    for(int i=(count-1);i>=(count-3);i--){
        cout<<bk[i].category<<" "<<bk[i].name<<" "<<bk[i].mean<<endl;
    }
    }
    else if(count>0&&count<3){
        for(int i=(count-1);i>=0;i--){
            cout<<bk[i].category<<" "<<bk[i].name<<" "<<bk[i].mean<<endl;
        }
    }
    else if(count==0){
        cout<<"NULL"<<endl;
    }
    return 0;
}