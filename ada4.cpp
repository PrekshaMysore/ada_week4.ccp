#include<iostream>
using namespace std;
class connected{
    int adj[10][10],visited[10],v,n;
public:
        void input(){
        cout<<"enter the number of components\n";
        cin>>n;
        for (int i=0;i<n;i++){
            visited[i]=0;
        }
        cout<<"enter the adjacent matrix of graph\n";
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>adj[i][j];
            }}
      

        }

        void DFS(int v){
            cout<<v+1<<",";
            visited[v]=1;
            for (int i=0;i<n;i++){
                if(adj[v][i]==1 && visited[i]==0){
                    DFS(i);
                }
            }
        }
        void conn(){
            for(int j=0;j<n;j++){
                if(visited[j]==0){
                    DFS(j);
                    cout<<"\n";
                }
            }
        }



};
int main(){
    connected c;
    c.input();
    c.conn();
    return 0;

}
