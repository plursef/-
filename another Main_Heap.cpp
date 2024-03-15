#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void swap(int *p,int *q){
    int t= *p;
    *p=*q;
    *q=t;
}
void born_Heap(vector<int> &a,int &k){
    if(k==0){
        int s;cin>>s;a[0]=s;
    }
    else{int tem;cin>>tem;int l=k;a[l]=tem;
    while(l>0)
    {int dad=(l-1)/2;

    if(a[l]<a[dad]||a[dad]==-1)
    {swap(a[l],a[dad]);
    l=dad;}
    else
    break;}

    }
    k++;

}
void Extract(vector<int> &a){
    int idx=0;
    while(a[2*idx+1]!=-1||a[2*idx+2]!=-1)
   {int indx;
    if(a[2*idx+1]==-1||a[2*idx+2]==-1){
    indx=max_element(a.begin()+2*idx+1,a.begin()+2*idx+3)-a.begin();
   } 
    else
    indx=min_element(a.begin()+2*idx+1,a.begin()+2*idx+3)-a.begin();
    a[idx]=a[indx];idx=indx;}
    a[idx]=-1;
}
int main() {int n;cin>>n;vector <int> a(200000,-1);int len=0;
    int i;
    for(i=0;i<n;i++) 
    born_Heap(a,len);
    int m;cin>>m;
    for(i=0;i<m;i++){
        string s;cin>>s;
        if(s=="EXTRACT-MIN"){
            if(a[0]==-1){
                printf("NULL\n");
            }
            else
            {printf("%d\n",a[0]);
            Extract(a);}
        }
        if(s=="ADD"){
            born_Heap(a,len);
        }
    }



}