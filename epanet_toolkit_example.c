
#include "epanet2.h"
#include <stdio.h>
#include <math.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>



#define WHITE 0
#define GRAY 1
#define BLACK 2
#define MAX_NODES 1000
#define oo 1000000000.0

int n=15;  // number of nodes
int e=14;  // number of edges
int capacity[MAX_NODES][MAX_NODES]; // capacity matrix
int flow[MAX_NODES][MAX_NODES];     // flow matrix
int color[MAX_NODES]; // needed for breadth-first search               
int pred[MAX_NODES];  // array to store augmenting path
int min (int x, int y) {
    return x<y ? x : y;  // returns minimum of x and y
}

int head,tail;
int q[MAX_NODES+2];
void enqueue (int x) {
    q[tail] = x;
    tail++;
    color[x] = GRAY;
}

int dequeue () {
    int x = q[head];
    head++;
    color[x] = BLACK;
    return x;
}

int bfs (int start, int target) {
    int u,v;
    
    for (u=2; u<=n; u++) {
	color[u] = WHITE;
    }   
    head = tail = 0;
    enqueue(start);
    pred[start] = -1;
    while (head!=tail) {
       
	u = dequeue();
	for (v=2; v<n; v++) {
	    if (color[v]==WHITE && capacity[u][v]-flow[u][v]>0) {
	   	
		enqueue(v);
		pred[v] = u;
		
	    }
	}
    }
    
    if(color[target]==BLACK)
    {
    	 return 1;
	}
   else
   {
   	return 0;
   }
}


int fordFulkerson (int source, int sink) {
    int i,j,u;
    
    int max_flow = 0;
    for (i=2; i<=n; i++) {
	for (j=2; j<=n; j++) {
	    flow[i][j] = 0;
	}
    }
      while (bfs(source,sink)) {
       
	int increment = oo;
	for (u=n-1; pred[u]>=2; u=pred[u]) {
	    increment = min(increment,capacity[pred[u]][u]-flow[pred[u]][u]);
	   	}
       
	for (u=n-1; pred[u]>=2; u=pred[u]) {
	    flow[pred[u]][u] += increment;
	    flow[u][pred[u]] -= increment;
	}
	max_flow += increment;
    }
   
    return max_flow;
}
int main(int argc, char* argv[])
{  

     int   i, nnodes,Nlinks,lindex,x,y,maxcapacity; 
    float D,nvalue; 
   long t;
     int u,v;
    char lid;
    float value;
     ENopen("ff.inp", "new2.rpt", ""); 
     ENopenH(); 
    
     ENgetcount(EN_LINKCOUNT, &nnodes);
     ENrunH(&t);
     
   // ENgetcount(EN_TANKCOUNT, &Nlinks); 
     
    //printf("ENgetCOUNTvalue for  returned %d\n", nnodes);
    

    for (i=2; i<=nnodes; i++)
     {
   
   	   ENgetlinknodes(i, &x, &y);
     //  printf(" %d %d \n",x+1,y+1);
	  ENgetlinkvalue( i, 8 , &nvalue );
	
	  
	  //printf("%f ",nvalue);

       capacity[x+1][y+1]=(int)nvalue;
      
	  }
  /*
for (u = 2; u <= nnodes; u++)
        	for (v = 2; v <= nnodes; v++)
		 {
	          if(capacity[u][v]>0)
			 printf("\n %d  ",capacity[u][v]);
		}*/

    maxcapacity = fordFulkerson(2, 14);
    printf("\n This is the max capacity \n");
    printf("\n %d  ",maxcapacity);
  
   ENcloseH(); 
   ENclose(); 
 }    
  

