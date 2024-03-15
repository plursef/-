#include<iostream> 
#include<vector>   
using namespace std;

int main()  {
    int n,m;cin>>n>>m;int sum=0;
    while(n--){
    vector<vector<int>> rel(m,vector<int>(m,0)),add(m,vector<int>(m,0));//[i][j]元表示i到j的塔最大和
    vector<int> v(m,0);
    int i,j;
    for(i=0;i<m;i++)
    {cin>>v[i];
    rel[i][i]=v[i];
    add[i][i]=v[i];

    }
    for(i=0;i<m;i++){
        for(j=i+1;j<m;j++){
            add[i][j]=add[i][j-1]+v[j];
        }
    }
    for(int len=1;len<m;len++){
        for(i=0;i+len<m;i++){
            rel[i][i+len]=add[i][i+len]+max(rel[i][i+len-1],rel[i+1][i+len]);

        }
    }
    sum+=rel[0][m-1];
    


    }
    cout<<sum;
    return 0;
}