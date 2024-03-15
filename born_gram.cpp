#include <iostream>
using namespace std;
int max(int num[],int s,int e){
    int m=0;
    for(int i=s;i<=e;i++){
        if(m<num[i])
        m=num[i];    }
        return m;
}
void born_gram(int num[],int s,int e,char p[][27],int row){//row为表格的行数
    if(s==e){
        for(int j=row-1;;j--){
            if(num[e]>0){
                num[e]--;
                p[j][e]='*';
            }
            else{break;}
            
        } 
        
    }
    int m=max(num,s,e);int i;
    for(i=s;i<=e;i++){
        if(num[i]<m){
            for(int j=row-1;j>=row-m;j--)
            if(num[i]>0){num[i]-=1;;
            p[j][i]='*';}
            else
            p[j][i]=' ';
        }
        else
        {for(int j=row-1;j>=row-m;j--)
        p[j][i]='*';
        break;
        }
    }
    if(i+1<=e)
    born_gram(num,i+1,e,p,row);
}

int main() {
    int i,j;int cap_num[27]={};//从第一位开始放A的个数；
    for(i=0;i<4;i++){string str;
        getline(cin,str);
        for(j=0;j<str.size();j++)
        if(str[j]>='A'&&str[j]<='Z')
        cap_num[str[j]-'A'+1]++;
    }
    int ma=0;
    for(i=1;i<27;i++)
    if(ma<cap_num[i])
    ma=cap_num[i];
    char print[ma+1][27]={};

    for(i=1;i<27;i++){print[ma][i]='A'+i-1;
    }    
    for(j=0;j<ma+1;j++)
    print[j][0]='#';
    born_gram(cap_num,1,26,print,ma);    
    for(i=0;i<ma+1;i++){cout<<print[i][0];
    for(j=1;j<27;j++){
        if(print[i][j]!='\0')
        cout<<' '<<print[i][j];
    }
    cout<<endl;
    
    }
	return 0;
}