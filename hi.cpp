#include <iostream>
using namespace std;

int main() {
    int n,i;
    cin>>n;
    int ma[500][4],k=0;
    bool area[501][501];
    for(int m=0;m<501;m++)
    for(int sw=0;sw<501;sw++)
    area[m][sw]=0;
    for(i=0;i<n;i++){int in;
    cin>>in;
    if(in==0){
        cin>>ma[k][0]>>ma[k][1]>>ma[k][2]>>ma[k][3];
        for(int m=ma[k][0];m<ma[k][2];m++)
        for(int sw=ma[k][1];sw<ma[k][3];sw++)
        area[m][sw]=1;
        k++;
        
    }
    else{int a0,a1,a2,a3;
        cin>>a0>>a1>>a2>>a3;
        bool ok=true;
        for(int m=a0;m<a2;m++)
        for(int sw=a1;sw<a3;sw++)
        if(area[m][sw]==0)
        ok=false;
    
    if(ok==true)
    printf("Yes\n");
    else
    printf("No\n");
        
    }
    }
    

	return 0;
}

