#include<iostream>
using namespace std;
void swap(int &a,int &b){
    a=a+b;
    b=a-b;
    a=a-b;
}
void min_heap(int a[],int &k){
    if(k==0)
    cin>>a[0];
    else
    {int tep;cin>>tep;int leaf=k;
    a[k]=tep;
    while(a[leaf]<a[(leaf-1)/2]){
        swap(a[leaf],a[(leaf-1)/2]);
        leaf=(leaf-1)/2;
    }
    }
    k++;

}

int main() {
    int n,i,length=0;
    cin>>n;
    int a[100000]={};
    for(i=0;i<n;i++)
    min_heap(a,length);
    int m;
    cin>>m;
    for(i=0;i<m;i++)
    {
    string s;
    cin>>s;
    if(s[0]=='E')
    {if(length!=0){int bye=0;printf("%d\n",a[0]);
    length-=1;
    a[0]=a[length];
    while(2*bye+1<length){
        if(a[bye]<=a[2*bye+1]&&a[bye]<=a[2*bye+2])
        bye=2*bye+1;
        else
        {if(2*bye+2>=length)
        {if(a[bye]>a[2*bye+1])
        swap(a[bye],a[2*bye+1]);}
        else if(a[2*bye+2]>a[2*bye+1])
        {bye=2*bye+1;
        swap(a[bye],a[(bye-1)/2]);
        }
        else
        {bye=2*bye+2;
        swap(a[bye],a[(bye-1)/2]);
        }}

        
    }
  
        
    }
    else printf("NULL\n");
    }
    
    else 
    min_heap(a,length);
    }


}