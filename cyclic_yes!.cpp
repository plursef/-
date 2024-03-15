#include<iostream>
using namespace std;
bool same(string s1,string s2){
    if(s1.size()!=s2.size())
    return false;
    int i,j;
    for(i=0;i<s1.size();i++){int cnt=0;
        for(j=i;j<s1.size();j++){
            if(s1[j]==s2[j-i])
            cnt++;
        }
        for(j=0;j<i;j++){
            if(s1[j]==s2[s2.size()-i+j])
            cnt++;
        }
        if(cnt==s1.size())
        return true;
    }
    return false;
}
string times(string s,int n){
    int st[100]={};int i;
    for(i=0;i<s.size();i++){
    st[i]=s[s.size()-1-i]-'0';st[i]*=n;
    }
    for(i=0;i<s.size();i++){
        st[i+1]+=st[i]/10;
        st[i]%=10;
    }
    string rts;
    if(st[s.size()]!=0){
        for(i=0;i<=s.size();i++)
        rts.push_back(st[s.size()-i]+'0');
    }
    else{
        for(i=0;i<s.size();i++)
        rts.push_back(st[s.size()-i-1]+'0');        
    }
    return rts;
    
}
int main() {
    string s;
    while(cin>>s)
    {int cnt=0,i,j;
    for(i=1;i<=s.size();i++){
        string s1=times(s,i);
        if(s1.size()<s.size()){
            for(j=0;j<s.size()-s1.size();j++){
                s1.insert(0,1,'0');
            }
        }
        if(same(s,s1))
        cnt++;
    }
    if(cnt==s.size())
    cout<<s<<" is cyclic"<<endl;
    else
    cout<<s<<" is not cyclic"<<endl;}
    return 0;

}


