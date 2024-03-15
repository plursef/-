#include <iostream>
using namespace std;

void sort(int a[],int s,int e){
    if(s<e){
    int L=s,R=e;
    int k=a[L];
    while(L!=R){
    while(R>L&&a[R]>k){
        R--;
    }
    if(L<R){
        a[L]=a[R];
        L++;
    }
    while(L<R&&a[L]<k)
    L++;
    if(L<R){
       a[R]=a[L];
       R--;
    }
        
    }
    a[L]=k;
    sort(a,s,L-1);
    sort(a,L+1,e);
}
    }

int main(){
    int n;cin>>n;int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    sort(a,0,n-1);
    for(int i=0;i<n;i++)
    printf("%d\n",a[i]);
}