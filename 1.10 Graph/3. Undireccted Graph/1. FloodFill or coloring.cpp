/*
  1.Simple varient of dfs/bfs can be used to label the various connected components
    present in a graph
  2.Generally performed in implicit graphs (2D matrices)
  3.Starting from a particular cell we call 'DFS' on neighbouring cells to color
    them.Neihbours can be '4' (up,down,left,right) OR '8' (including diagonals also)

*/

#include<iostream>
#include<list>
#include<map>
#include<queue>
using namespace std;

int R,C;

//w,n,e,s
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};

//ch is the character to be replaced
//color is the charcter to be added in place of ch
void floodFill(char mat[][50],int i,int j,char ch,char color){
  //base case
    if(i<0 || j<0|| i>=R||j>=C)
      return;
  //boundary case
    if(mat[i][j]!=ch)
      return;

  //recursive call : 4 neighbour approach
    mat[i][j]=color;
    //print(mat); //to see how coloring works

    for(int k=0;k<4;k++)
      floodFill(mat,i+dx[k],j+dy[k],ch,color);
}

void print(char input[][50]){
  cout<<"\n\n";
  for (int i = 0; i < R; ++i){
    for (int j = 0; j < C; ++j)
      cout<<input[i][j];
    cout<<"\n";
  }
  cout<<"\n\n";
}

int main(int argc, char const *argv[])
{
  cin>>R>>C;
  char input[15][50];

  for (int i = 0; i < R; ++i)
    for (int j = 0; j < C; ++j)
      cin>>input[i][j];

    floodFill(input,6,10,'.','=');
    floodFill(input,0,0,'*','!');

    print(input);


  return 0;
}

/*
input:

10 20
********************
*****########*******
*****#......#*******
***###......###*****
**###........###****
**##..........##****
**#............#****
**##..........##****
***############*****
********************

output:
!!!!!!!!!!!!!!!!!!!!
!!!!!########!!!!!!!
!!!!!#======#!!!!!!!
!!!###======###!!!!!
!!###========###!!!!
!!##==========##!!!!
!!#============#!!!!
!!##==========##!!!!
!!!############!!!!!
!!!!!!!!!!!!!!!!!!!!

*/