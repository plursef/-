#include <iostream>
using namespace std;
struct e_dim{
    int x;
    int y;
};
int max(int a1,int a2,int a3,int a4,int a5){
    int m=a1;
    if(m<a2)
    m=a2;
    if(m<a3)
    m=a3;
    if(m<a4)
    m=a4;
    if(m<a5)
    m=a5;
    return m;
}

int main() {
    int m,n;
    cin>>m>>n;
    e_dim a[n],b[n];
    int i=0,k=0,j=0;
    while(i<n){
        cin>>a[k].x>>a[k].y;
        i++;
        if(i<n)
        {cin>>b[k].x>>b[k].y;
        i++;
        k++;}
    }
    int board[m+1][m+1];
    for(i=0;i<=m;i++)
    for(j=0;j<=m;j++)
    board[i][j]=0;
    for(i=0;i<n-k;i++){
        board[a[i].x][a[i].y]=i+1;
    }
    for(i=0;i<k;i++){
        board[b[i].x][b[i].y]=-(i+1);
    }
    int min_a=0x0fffffff,min_b=0x0fffffff;
    for(i=0;i<m+1;i++)
    for(j=0;j<m+1;j++){
        if(j<n-4&&board[i][j]>0&&board[i][j+1]>0&&board[i][j+2]>0&&board[i][j+3]>0&&board[i][j+4]>0)
        if(min_a>max(board[i][j],board[i][j+1],board[i][j+2],board[i][j+3],board[i][j+4]))
        min_a=max(board[i][j],board[i][j+1],board[i][j+2],board[i][j+3],board[i][j+4]);
        if(i<n-4&&board[i][j]>0&&board[i+1][j]>0&&board[i+2][j]>0&&board[i+3][j]>0&&board[i+4][j]>0)
        if(min_a>max(board[i][j],board[i+1][j],board[i+2][j],board[i+3][j],board[i+4][j]))
        min_a=max(board[i][j],board[i+1][j],board[i+2][j],board[i+3][j],board[i+4][j]);
        if(i<n-4&&j<n-4&&board[i][j]>0&&board[i+1][j+1]>0&&board[i+2][j+2]>0&&board[i+3][j+3]>0&&board[i+4][j+4]>0)
        if(min_a>max(board[i][j],board[i+1][j+1],board[i+2][j+2],board[i+3][j+3],board[i+4][j+4]))
        min_a=max(board[i][j],board[i+1][j+1],board[i+2][j+2],board[i+3][j+3],board[i+4][j+4]);
        if(i<n-4&&j>=4&&board[i][j]>0&&board[i+1][j-1]>0&&board[i+2][j-2]>0&&board[i+3][j-3]>0&&board[i+4][j-4]>0)
        if(min_a>max(board[i][j],board[i+1][j-1],board[i+2][j-2],board[i+3][j-3],board[i+4][j-4]))
        min_a=max(board[i][j],board[i+1][j-1],board[i+2][j-2],board[i+3][j-3],board[i+4][j-4]);



        if(j<n-4&&board[i][j]<0&&board[i][j+1]<0&&board[i][j+2]<0&&board[i][j+3]<0&&board[i][j+4]<0)
        if(min_b>max(-board[i][j],-board[i][j+1],-board[i][j+2],-board[i][j+3],-board[i][j+4]))
        min_b=max(-board[i][j],-board[i][j+1],-board[i][j+2],-board[i][j+3],-board[i][j+4]);
        if(i<n-4&&board[i][j]<0&&board[i+1][j]<0&&board[i+2][j]<0&&board[i+3][j]<0&&board[i+4][j]<0)
        if(min_b>max(-board[i][j],-board[i+1][j],-board[i+2][j],-board[i+3][j],-board[i+4][j]))
        min_b=max(-board[i][j],-board[i+1][j],-board[i+2][j],-board[i+3][j],-board[i+4][j]);
        if(i<n-4&&j<n-4&&board[i][j]<0&&board[i+1][j+1]<0&&board[i+2][j+2]<0&&board[i+3][j+3]<0&&board[i+4][j+4]<0)
        if(min_b>max(-board[i][j],-board[i+1][j+1],-board[i+2][j+2],-board[i+3][j+3],-board[i+4][j+4]))
        min_b=max(-board[i][j],-board[i+1][j+1],-board[i+2][j+2],-board[i+3][j+3],-board[i+4][j+4]);
        if(i<n-4&&j>=4&&board[i][j]<0&&board[i+1][j-1]<0&&board[i+2][j-2]<0&&board[i+3][j-3]<0&&board[i+4][j-4]<0)
        if(min_b>max(-board[i][j],-board[i+1][j-1],-board[i+2][j-2],-board[i+3][j-3],-board[i+4][j-4]))
        min_b=max(-board[i][j],-board[i+1][j-1],-board[i+2][j-2],-board[i+3][j-3],-board[i+4][j-4]);   

    }
    int p1=min_a*2-1;
    int p2=min_b*2;
    if(p1>p2)
    printf("%d 1",p2);
    else
    printf("%d 0",p1);
	return 0;
}