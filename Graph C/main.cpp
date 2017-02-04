#include <iostream>

using namespace std;

int vbfs[100],vdfs[100],a[100][100],q[100];
int i,j,n,s;
int f=-1,r=-1,c=0;

void dfs(int s){
    cout<<s<<" ";
    vdfs[s]=1;

    for(i=0;i<n;i++)
        if(vdfs[i]!=1 && a[s][i]==1)
            dfs(i);
}

void bfs(int s){

    vbfs[s]=1;
    f++;
    r++;
    c++;
    q[f]=s;

    while(c!=0){
        s=q[r];
        cout<<s<<" ";
        r++;
        c--;
        for(i=0;i<n;i++){
            if(vbfs[i]!=1 && a[s][i]==1){
                vbfs[i]=1;
                f++;
                c++;
                q[f]=i;
            }
        }
    }
}

int main()
{
    cin>>n;
    cout<<"Enter Adjacency Matrix: "<<endl;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            cin>>a[i][j];
    cout<<"Start Point: ";
    cin>>s;
    cout<<"BFS: ";
    bfs(s);
    cout<<"\nDFS: ";
    dfs(s);
    return 0;
}
