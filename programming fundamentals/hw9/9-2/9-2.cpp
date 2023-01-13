#include<iostream>
#include<cstring>
using namespace std;
int b[1005];
int cnt=1;
struct things{
	float cost;
	int off;
	int num;
};
things a[1005];
int main()
{
 	for(int i=0;i<1005;i++)
        b[i]=0;
 	float s,n;
 	cin>>s>>n;
 	for(int i=1;i<=n;i++)
 	{
  		a[i].num=i;
  		cin>>a[i].cost>>a[i].off;
 	}
 	for(int i=1;i<n;i++)
 	    for(int j=i+1;j<=n;j++)
 	    {
  		if(a[i].cost*a[i].off/2<a[j].cost*a[j].off/2)//判断条件1
  		{
   			things temp;
   			temp=a[i];
  		 	a[i]=a[j];
   			a[j]=temp;
  		} 
  		else if(a[i].cost*a[i].off/2==a[j].cost*a[j].off/2)
  		{
   			if(a[i].cost>a[j].cost)//判断条件2
  			{
    				things temp;
    				temp=a[i];
    				a[i]=a[j];
    				a[j]=temp;
   			}
   			else if(a[i].cost==a[j].cost) 
   			{
    				if(a[i].num>a[j].num)//判断条件3
    				{
     					things temp;
     					temp=a[i];
     					a[i]=a[j];
     					a[j]=temp;
    				}
   			} 
  		}
 	}
 	for(int i=1;i<=n;i++)//按照排序依次将买得起的物品买入，将买的物品的num存入数组b
 	{
  		if(a[i].off==0&&a[i].cost<=s)
  		{
   			s-=a[i].cost;
   			b[cnt++]=a[i].num;
  		}
  		else if(a[i].off==1&&a[i].cost/2<=s)
  		{
   			s-=a[i].cost/2;
   			b[cnt++]=a[i].num;
  		}
 	}
 	if(cnt==1)//一样都买不起输出0
 	cout<<0<<endl;
 	//sort(b,b+cnt);
    for(int i=cnt-1;i>=1;i--){
        for(int j=1;j<i;j++){
            if(b[j]>b[j+1]){
                int temp=b[j+1];
                b[j+1]=b[j];
                b[j]=temp;
            }
        }
    }
 	for(int i=1;i<cnt;i++)
  		cout<<b[i]<<" ";
    return 0;
}

