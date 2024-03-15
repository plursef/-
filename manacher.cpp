#include<bits/stdc++.h>
using namespace std;
int manacher(string str)
{
    if(!str.length()) return 0;
    int l=(int)(str.length()*2+1);
    char *s=new char[l];//记录回文子串
    int *p=new int[l];//记录每个位置最大回文半径
    int r,c,index,mx;
    r=c=-1;
    index=mx;
    for(int i=0;i<l;i++) s[i]=i&1?str[index++]:'#';
    for(int i=0;i<l;i++)
    {
        p[i]=r>i?min(r - i, p[2 * c - i]):1;
        while(i+p[i]<l&&i-p[i]> -1)
        {
            if(s[i+p[i]]==s[i-p[i]]) p[i]++;
            else break;
        }
        if(i+p[i]>r) 
        {
            r=i+p[i];
            c=i;
        }
        mx=max(mx,p[i]);
    }
    delete[] s;
	delete[] p;
    return mx-1;
    
}
int main()
{
    string str;
    cin>>str;
    cout<<manacher(str)<<endl;
    return 0;
}
