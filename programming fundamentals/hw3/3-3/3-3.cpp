#include<iostream>
#include<cstring>
//注意有进位的！！！
using namespace std;
int main(){
    string m,n;
    string max,min;
    cin>>m>>n;
    //cout<<m.size()<<" "<<n.size()<<endl;
    if(m.size()>=n.size()){
        max=m;
        min=n;
    }
    else{
        max=n;
        min=m;
    }

    for(int i=min.size()-1,j=max.size()-1;i>=0;i--,j--){
        max[j]=max[j]+min[i]-'0';
        //m[i]=m[i]+n[i]-'0';  //这里数字就要减去0，而不是减a
            //cout<<m[i]<<endl;
            /*
            if(m[i]>=10){
                if(i==0){
                    m[0]=m[0]-10;
                    m='1'+m;
                }
                else{
                    m[i]=m[i]-10;
                    m[i-1]=m[i-1]+1;
                }
            }
            */
    }
    for(int i=max.size()-1;i>0;i--){
        if(max[i]>'9'){ //string类的每一位为字符类型
            max[i]-=10;
            max[i-1]++;
        }
    }
    if(max[0]>'9'){
        max[0]=max[0]-10;
        max='1'+max;
    }
    cout<<max<<endl;

    
    return 0;
}