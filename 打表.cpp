#include <iostream>
using namespace std;
int main() {
    int n,a,i,b;
    cin>>n;;
    for(i=0;i<n;i++){
        cin>>a;
        if(a==0)
        printf("%d\n",2);
        else if(a==1)
        printf("%d\n",4);
        else if(a==2)
        printf("%d\n",1);
        else if(a<10)
        printf("%d\n",8*(a-2));
        else if(a==10)
        printf("%d\n",4);
        else if(a==11)
        printf("%d\n",62);
        else if(a==12)
        printf("%d\n",72);
        else if(a==20)
        printf("%d\n",1);
        else if(a==21)
        printf("%d\n",3);
        else if(a==22)
        printf("%d\n",80);
        else if(a<32)
        printf("%d\n",8*(a-2)-1);
        else if(a%10==2)
        printf("%d\n",8*(a/10-2));
        else if(a==33)
        printf("%d\n",87*8-2);
        else if(a==43)
        printf("%d\n",118*8-2);
        else if(a==53)
        printf("%d\n",148*8-2);
        else if(a==63)
        printf("%d\n",179*8-2);
        else if(a==73)
        printf("%d\n",209*8-2);
        else if(a==83)
        printf("%d\n",240*8-2);
        else if(a==93)
        printf("%d\n",271*8-2);
        else if(a==40)
        printf("%d\n",89*8-2);
        else if(a==50)
        printf("%d\n",119*8-2);
        else if(a==60)
        printf("%d\n",150*8-2);
        else if(a==70)
        printf("%d\n",180*8-2);
        else if(a==80)
        printf("%d\n",211*8-2);
        else if(a==90)
        printf("%d\n",242*8-2);
        else if(a==41)
        printf("%d\n",89*8-2+72);
        else if(a==51)
        printf("%d\n",119*8-2+72);
        else if(a==61)
        printf("%d\n",150*8-2+72);
        else if(a==71)
        printf("%d\n",180*8-2+72);
        else if(a==81)
        printf("%d\n",211*8-2+72);
        else if(a==91)
        printf("%d\n",242*8-2+72);
        else if(a==100)
        printf("%d\n",271*8+5);
        else{
            b=a-21;
            printf("%d\n",(b/4+365*b-2)*8+3);
        }
        }
	return 0;
}