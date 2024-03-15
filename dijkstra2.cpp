#include<iostream>
#include<fstream>
using namespace std;
#define inf 0x3f3f3f3f; 
int minimum(int a[],int n){int min=inf;
    while(n--){
        if(min>a[n])
        min=a[n];
    }
    return min;
}
int minimum_num(int a[],int n){int min=inf;int nu;
    while(n--){
        if(min>a[n])
        {min=a[n];
        nu=n;}
    }
    return nu;
}

int main() {ifstream in;
    in.open("E:\\code\\C++\\algorithm\\coin\\dij_file.txt");
    int element_nums,relations;
    in>>element_nums>>relations;
    int distance[element_nums][element_nums];bool set_OK[element_nums]={};
    int i,j;
    for(i=0;i<element_nums;i++)
    for(j=0;j<element_nums;j++){
        if(i==j)
        {distance[i][j]=0;}
        else
        {distance[i][j]=inf;}
    }
    set_OK[0]=1;
    
    while(relations--){int send_objt,receive_objt,interval;
        in>>send_objt>>receive_objt>>interval;
        distance[send_objt][receive_objt]=interval;
    }in.close();
    int index=element_nums;
    for(i=0;i<element_nums;i++){
        int min[element_nums];
        for(j=0;j<element_nums;j++)
        min[j]=inf;
        for(j=0;j<element_nums;j++){
        if(set_OK[j])
        continue;
        int k;
        for(k=0;k<element_nums;k++){
            if(set_OK[k]==0)
            continue;
            if(distance[k][j]<0x3f3f3f3f){
                if(min[j]>distance[0][k]+distance[k][j])
                min[j]=distance[0][k]+distance[k][j];
            }
        }
        }int s=minimum(min,element_nums);
        if(s!=0x3f3f3f3f){
        distance[0][minimum_num(min,element_nums)]=s;
        set_OK[minimum_num(min,element_nums)]=1;
        }


    }
    for(i=0;i<element_nums;i++){
        cout<<"0点到"<<i<<"点的距离是";
        if(distance[0][i]!=0x3f3f3f3f)
        cout<<distance[0][i]<<endl;
        else
        cout<<"INF"<<endl;
    }

    
    return 0;
}