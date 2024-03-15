#include <iostream>
using namespace std;
#define inf 100000
int n,m;
int island[50][50];

void explore(int i,int j, int k){
    island[i][j] = k;
    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1};
    for(int s=0;s<4;s++){
        if(i+dx[s]>=0&&i+dx[s]<n&&j+dy[s]>=0&&j+dy[s]<m&&island[i+dx[s]][j+dy[s]]==-1){
            island[i+dx[s]][j+dy[s]] = k;
            explore(i+dx[s],j+dy[s],k);
        }
    }

}
int distance(int x,int y){
    int d[4]={inf,inf,inf,inf};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(island[i][j]!=0){
                d[island[i][j]] = min(d[island[i][j]],max(i-x,x-i)+max(j-y,y-j));
            }
        }
    }
    return d[3]+d[1]+d[2]-2;
}
int distance2(const int &a,const int &b){
    int mmm=1000;
for(int x=0;x<n;x++){
        for(int y=0;y<m;y++){
            if(island[x][y]==a){
                int md=1000;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(island[i][j]==b){
                md = min(md,max(i-x,x-i)+max(j-y,y-j));
            }
        }
    }
    
    if(md<mmm)
    mmm=md;

}
}
}return mmm;}
    
    

    
int main() {
    cin>>n>>m;
    int i,j;
    char c;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin>>c;
            if(c=='X')
            island[i][j] = -1;
            else
            island[i][j] = 0;

        }
    }
    int k=1;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
        if(island[i][j] < 0){
            explore(i,j,k);
            k++;

        }
        }
    }
    int res=inf;int x,y;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int d=distance(i,j);
            if(d<res)
            {res=d;}
        }
    }
    int d1=distance2(1,2),d2=distance2(1,3),d3=distance2(2,3);
    res = min(res,min(d1+d2,min(d2+d3,d1+d3)));
    cout<<res;

    
    
    return 0;
}