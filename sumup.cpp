#include<iostream>
using namespace std;
int main()  {
    int n,sumup=0,sumdown=1,u,d,i;
    cin>>n;
    char woc;
    for (i=0;i<n;i++){
        scanf("%d%c%d",&u,&woc,&d);
        sumup =d*sumup+u*sumdown;
        sumdown *=d;
    }
    int a =sumdown,b=sumup,c;
    while (a!=0) {
        c=a;a=b%a;b=c;

    }
    sumup /= b;
    sumdown /= b;
    if (sumdown>1)     
    printf("%d/%d",sumup,sumdown);
    else
    printf("%d",sumup);
}