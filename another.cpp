#include<iostream>
using namespace std;
//交换 
void swap(int &a,int &b)
{
 int temp;
 temp=a;
 a=b;
 b=temp;
}
//全排列递归算法 
void perm(int list[],int k,int m)
{
 //list 数组存放排列的数，k表示层，代表第几个数，m表示数组的长度
 int i;
 if(k==m)
 {
  //k=m表示到达最后一个数，不能再交换，最终的排列数需要输出
  for(i=0;i<m;i++){
   printf("%d ",list[i]);
  }
  printf("\n");
 }
 else{
  for(i=k;i<m;i++){
   swap(list[i],list[k]);//枚举该层子序列第一个位置可以取的值 
   perm(list,k+1,m);//该层递归的子序列第一个位置已经确定了，所以又可以往下再分 
   swap(list[i],list[k]);//把第该层子序列第一个位置的值换成另外一个值，所以要交换回来 
  }
 }
}
int main(){
 int i,n,a[100];
 printf("请输入需要全排列的元素个数：");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {printf("输入第%d个元素大小\n",i+1);
  scanf("%d",&a[i]);}
 perm(a,0,n);
 return 0;
} 
