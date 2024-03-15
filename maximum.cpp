#include<iostream>
using namespace std;
int main()  {
    int n,i;
    cin>>n;
    int a[n],max=0;

    for(i=0;i<n;i++)
    cin>>a[i];

    for(i=0;i<n;i++)
    if(max<a[i]){
    max=a[i];
    }
    printf("最大值是%d",max);
    return 0;


}