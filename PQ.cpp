#include<iostream>
#include<algorithm>
using namespace std;

int n,d[66];//n个数据棍
int len,m,l=0;//len是长度 m是原始木棍个数,l是总长
int next[66];//为了去除重复,直接给出下一个点的位置
bool cpl=0,used[66]={};

void dfs(int k,int just,int rest)//在拼接第k根棍子时,刚刚利用了第just根棍,还剩rest长
{   if(!rest){
    if(k==m){cpl = 1;return;}
    int i=1;
    while(used[i]) i++;
    used[i] = 1;
    dfs(k+1,i,len-d[i]);
    used[i] = 0;
    if(cpl) return;

}
    //二分查找第一个小于rest的棍子
    int lef=just+1,r=n,mid;
    while(lef<r){
        mid = (lef+r)>>1;
        if(d[mid]>rest) lef=mid+1;
        else r=mid;
    }
    for(int i=lef;i<=n;i++){
        if(!used[i]){
            used[i] = 1;
            dfs(k,i,rest-d[i]);
            used[i] = 0;
            if(cpl) return;
        if(rest==d[i]||rest==len) return;   
        i = ::next[i]; 
        if(i==n) return;
        }    
    }

}


int main() {
    cin>>n;int cnt=1;
    for(int i=1;i<=n;i++) {
    cin>>d[cnt];if(d[cnt]<=50) {l+=d[cnt];cnt++;}
    }
    cnt -= 1;
    n = cnt;
    sort(d+1,d+n+1,greater<int>());
    int i=1;
    while(i<=n){int j=i+1;
        while(j<=n&&d[j]==d[i]) j++;
        for(int k=i;k<j;k++){
            ::next[k] = j; 
    } 
    i = j;
}
    for(len=d[1];len<=l/2;len++){
        if(l%len!=0) continue;
        m=l/len;
        cpl=0;
        used[1] = 1;
        dfs(1,1,len-d[1]);
        used[1] = 0;
        if(cpl) printf("%d",len); return 0;
    }
    printf("%d",l);  return 0;
}