#include<iostream>
#define R 20
#define C 20
using namespace std;
    int M[R][C],n1,n2;
    bool visited[R][C];

        void input(){
        cout<<"enter the number of rows: \n";
        cin>>n1;
        cout<<"enter the number of columns:\n";
        cin>>n2;
        for (int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
            visited[i][j]=false;
        }
        }
        cout<<"input the matrix of graph:\n";
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                cin>>M[i][j];
            }}
       }
       int isSafe(int M[][C],int row,int col,bool visited[][C]){
           return ((row>=0)&&(row<n1)&&(col>=0)&&(col<n2)&&(M[row][col]&& !visited[row][col]));
       }
       void DFS(int M[][C],int row,int col,bool visited[][C]){
           static int rowNbr[]={-1,-1,-1,0,0,1,1,1};
           static int colNbr[]={-1,0,1,-1,1,-1,0,1};
           visited[row][col]=true;
           for(int k=0;k<8;k++){
            if(isSafe(M,row+rowNbr[k],col+colNbr[k],visited)){
                DFS(M,row+rowNbr[k],col+colNbr[k],visited);
            }
           }
       }
       int countIslands(int M[][C]){
           int count=0;
           for(int i=0;i<n1;++i){
            for(int j=0;j<n2;++j){
                if(M[i][j] && !visited[i][j]){
                DFS(M,i,j,visited);
                ++count;
                }
            }
           }
           return count;

       }


int main(){
input();
int n=countIslands(M);
cout<<"no. of islands present are:"<<n;
return 0;
}
