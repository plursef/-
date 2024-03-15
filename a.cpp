#include<iostream>
using namespace std;
void sort(string *p,string *q){
    if(p<=q)
    {string k=*p;
    string *l=p,*r=q;
    while(l<r)
    {while(*r<=k&&r>l) r--;
    *l=*r;
    while(*l>=k&&l<r) l++;
    *r=*l;}
    *l=k;
    sort(p,l-1);
    sort(l+1,q);}
}
bool cover(string s1,string s){
    for(int i=0;i<s.size();i++)
    if(s[i]!=s1[i])
    return false;
    if(s1.size()==s.size())
    return false;
    return true;

}
int main() {
    int n;cin>>n;
    string s[n];
    int i;
    for(i=0;i<n;i++){
        cin>>s[i];
    }
    sort(s,s+n-1);//sort是我自己写的，助教请放过我，没有引用algorithm 哭唧唧 ~_~
    for(i=n-2;i>=0;i++){
        if(cover(s[i],s[i+1])){
            int out=s[i+1].size();
            int index=0;
            int k=out;
            while(k<s[i].size()&&k-out<s[i+1].size()){
            if(s[i][k]>s[i+1][k-out])
            {index=1;break;}
            else if(s[i][k]<s[i+1][k-out]) 
            {index=-1;break;}
            else{
                k++;
            }           
            }
            if(index==0){
                if(k==s[i].size())
                index=-1;
                else
                index=1;
            }
            if(index==-1){
                string s_0=s[i];
                s[i]=s[i+1];
                s[i+1]=s_0;

            }
        }
    }
    string super_star_s;
    for(i=0;i<n;i++){
        super_star_s+=s[i];
    }
    cout<<        super_star_s       <<endl;







    return 0;
}