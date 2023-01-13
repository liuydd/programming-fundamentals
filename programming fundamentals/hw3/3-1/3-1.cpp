#include<iostream>
using namespace std;
const int p=100;
const int m=12;
const int d=31;
struct student{
    string name;
    int month;
    int day;
};



int main(){
    int n;
    cin>>n;
    student stu[p];
    for(int i=0;i<n;i++){
        cin>>stu[i].name>>stu[i].month>>stu[i].day;
    }
    
   //按日期排序
   for(int i=0;i<n;i++){
    for(int j=0;j<n-1;j++){
        if(stu[j+1].month<stu[j].month||(stu[j+1].month==stu[j].month&&stu[j+1].day<stu[j].day)){
            student st=stu[j+1];    //结构体的交换！我果然不会结构体
            stu[j+1]=stu[j];
            stu[j]=st;
        }
    }
   }
    /*
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<stu[i].name<<" "<<stu[i].month<<" "<<stu[i].day<<endl;
    }
    cout<<endl;
*/

    int flag=0;
    int s=0;
   //找到生日相同的学生输出
   for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
        if(stu[j].day==stu[j-1].day&&stu[j].month==stu[j-1].month){
            if(flag==0){
                cout<<stu[j].month<<" "<<stu[j].day<<" "<<stu[j-1].name;
                flag=1;
                //i=j+1;
            }
            cout<<" "<<stu[j].name;
            if(j==n-1)
                goto a;   
                //太不优雅了，但我也想不到直接跳出两层循环的方式了。最后三个点的错误在于排完序后如果最后几个日期相同，则else会不起作用，此时i每加1，程序就会输出一次
        }       //故需要判断后跳出循环
        else{
            i=j;
            if(flag==1){
            //&&i!=n-1)
                for(int k=i;k<n;k++){
                    if(stu[k].day==stu[k-1].day&&stu[k].month==stu[k-1].month){
                        s=1;
                    }
                }
                if(s==1){
                    cout<<endl;  //s是用来解决换行问题的
                }
            }
            flag=0;
            s=0;
            //break;
        }
    }
   }
  a:
   return 0;
}