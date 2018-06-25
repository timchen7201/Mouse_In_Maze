#include<stdio.h>
#include<stdlib.h>
#include<queue>
#include<stack>

using namespace std;

struct dot{
	int x;
	int y;
	dot(){}
	dot(int xi,int yi){
		x=xi;
		y=yi;
	}
}d,d1;

queue<dot>road;

int maze[9][9]={{0,0,2,2,2,2,2,2,2},
				{2,0,0,0,0,0,0,0,2},
				{2,0,2,2,0,2,2,0,2},
				{2,0,2,0,0,2,0,0,2},
				{2,0,2,0,2,0,2,0,2},
				{2,0,0,0,0,0,2,0,2},
				{2,2,0,2,2,0,2,2,2},
				{2,0,2,0,0,0,0,0,2},
				{2,2,2,2,2,2,2,0,0}
			   };

int Newmaze[11][11];
int i,j;
void build(int x,int y,int value);

int main(){
	for(i=0;i<11;i++){
		for(j=0;j<11;j++){
			if(i==0||j==0||i==10||j==10)
				Newmaze[i][j]=-1;
			else if(maze[i-1][j-1]==2)
				Newmaze[i][j]=-1;
			else if(maze[i-1][j-1]==0)
				Newmaze[i][j]=10000;
		}
	}
	Newmaze[1][1]=0;
	road.push(dot(1,1));
	while(!road.empty()){
		d=road.front(); road.pop();
		if(d.y<j && Newmaze[d.x][d.y]+1<Newmaze[d.x][d.y+1]){
			Newmaze[d.x][d.y+1]=Newmaze[d.x][d.y]+1;
			road.push(dot(d.x,d.y+1));
		}
		if(d.y&&Newmaze[d.x][d.y]+1<Newmaze[d.x][d.y-1]){
			Newmaze[d.x][d.y-1]=Newmaze[d.x][d.y]+1;
			road.push(dot(d.x,d.y-1));
		}
		if(d.x<i&&Newmaze[d.x][d.y]+1<Newmaze[d.x+1][d.y]){
			Newmaze[d.x+1][d.y]=Newmaze[d.x][d.y]+1;
			road.push(dot(d.x+1,d.y));
		}
		if(d.x&&Newmaze[d.x][d.y]+1<Newmaze[d.x-1][d.y]){
			Newmaze[d.x-1][d.y]=Newmaze[d.x][d.y]+1;
			road.push(dot(d.x-1,d.y));
		}

	}
	printf("%d\n",Newmaze[9][9]);
	build(9,9,Newmaze[9][9]);
	for(i=1;i<10;i++){
		for(j=1;j<10;j++){
		 	if(Newmaze[i][j]>1 &&Newmaze[i][j]<16)
		 		Newmaze[i][j]=0;
			else if(Newmaze[i][j]==10000)
				Newmaze[i][j]=0;
			else if(Newmaze[i][j]==-1)
				Newmaze[i][j]=2;
			printf("%d ",Newmaze[i][j]);
		}
		printf("\n");
	}
}

void build(int x, int y ,int value){
	Newmaze[x][y]=1;
	if(x!=0&&y!=0){
		if(value-1==Newmaze[x-1][y]){value=Newmaze[x-1][y];Newmaze[x-1][y]=1;build(x-1,y,value);
		}
		else if(value-1==Newmaze[x][y+1]){value=Newmaze[x][y+1];Newmaze[x][y+1]=1;build(x,y+1,value);
		}
		else if(value-1==Newmaze[x+1][y]){value=Newmaze[x+1][y];Newmaze[x+1][y]=1;build(x+1,y,value);
		}
		else if(value-1==Newmaze[x][y-1]){value=Newmaze[x][y-1];Newmaze[x][y-1]=1;build(x,y-1,value);
		}
	}
}
