#include<iostream>
using namespace std;
int main() {
    int n,a[200],i,j;
    scanf("%d",&n);
    for (i=0;i<n;i++)
    scanf("%d",&a[i]);
    for (i=0;i<n;i++)
    for (j=1;j<n-i;j++){
        if (a[j-1]>a[j]){
        int tem=a[j];
        a[j]=a[j-1];
        a[j-1]=tem;
        }
    }
    for (i=0;i<n;i++)
    printf("%d\n",a[i]);



}