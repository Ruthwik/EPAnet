
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
#define oo 100000000

int n=15;  // number of nodes
int e=14;  // number of edges
int capacity[MAX_NODES][MAX_NODES]; // capacity matrix
int flow[MAX_NODES][MAX_NODES];     // flow matrix
int color[MAX_NODES]; // needed for breadth-first search               
int pred[MAX_NODES];  // array to store augmenting path
int min (int x, int y) {
    return x<y ? x : y;  // returns minimum of x and y
}
int min2 (int x, int y) {
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

void newfordFulkerson (int source, int sink) {
    int i,j,ijk,u,r,p,ij=2,k=2,f=2,max_flow=0,min=0,index=0;
    int pa[n][n];
	int a[n]; 
 
     for (ijk=0; ijk<n; ijk++){
     	printf("\n value %d",n);
      if(ijk==9)
        print(" A VALUSE");
     	a[ijk]=oo;
	 }
	 
	 
	  for (i=2; i<=n; i++) {
	for (j=2; j<=n; j++){

       pa[i][j] = -1;
	}
    }

    for (i=2;i<=n;i++) {
	for (j=2;j<=n;j++) {
	    flow[i][j] = 0;
	}
    }
    for(i=2;i<=n;i++){
 	printf("a before value %d \n",a[i]);
 } 
      while (bfs(source,sink)) {
       int x;
	int increment = oo;
	for (u=n-1; u!=2; u=pred[u]) {
	//	printf("u value %d \n",u);
		x=pred[u];
	    increment = min2(increment,capacity[pred[u]][u]-flow[pred[u]][u]);
	   	pa[k][ij]=u;
			ij++;
			printf("increment %d \n",increment);
		}
		a[f]=increment; 
		f++;
		pa[k][ij] =x ;
		k++;

            ij=0;
 
       
	for (u=n-1; pred[u]>=2; u=pred[u]) {
	    flow[pred[u]][u] += increment;
	    flow[u][pred[u]] -= increment;
	}
	max_flow += increment;
    }
 for(i=2;i<=n;i++){
 	printf("a value %d \n",a[i]);
 }  
     minArray(a,&min,&index);
     
     //printf("Min value and index %d  %d",min,index);


    
	/*for (int j = 0; j < V; j++) {
		cout << "pa" << pa[n][j] << "\n";
	}*/	for (r = 2; r<=n; r++) {
		int q = pa[index][r]; //pa[n][r] gives the augmenting path of minmum capacity link
		int p = pa[index][r + 1];
        
        //Increasing the link capacity that less than or equal to min capacity along the path
		if (capacity[pred[u]][u]-flow[pred[u]][u] <= 0 && q != -1 && p != -1) {
		//	capacity[p][q]++;
		//	int ENsetlinkvalue( int index, int paramcode, float value ) 

		} 
	}
}
int minArray(int v[],int* min,int* index)
{
    int m=100000000,len=0; 
	int i;  
    for(i=0;v[i];i++)
        len++;

    for( i=0;i<len;i++)
        if(v[i]<m)   //for max, change '<' to '>'
          {
			  m=v[i];
			  *min=v[i];
			  *index=i;
		}

    
}
int main(int argc, char* argv[])
{    int y = 0;
	int change;
	int u = 0, v = 0;
  	int loop=0,b;
  		int maxcap;
    int   i, nnodes,Nlinks,lindex,x1,y1,maxcapacity; 
    float D,nvalue; 
   long t;
  
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
   
   	   ENgetlinknodes(i, &x1, &y1);
     //  printf(" %d %d \n",x+1,y+1);
	  ENgetlinkvalue( i, 8 , &nvalue );
	
	  
	  //printf("%f ",nvalue);

       capacity[x1+1][y1+1]=(int)nvalue;
      
	  }
 
		printf("enter the number x liters/sec\n");
       scanf("%d", &y);

    maxcapacity = fordFulkerson(2, 14);
    
	if (y > maxcapacity) {
		 loop = y - maxcapacity;
		for ( b = 0; b < loop; b++) {
			 newfordFulkerson(2, 14);
			 
			 
			 //prints the modified graph
			 for (u = 2; u <= nnodes; u++)
        	for (v = 2; v <= nnodes; v++)
		 {
	          if(capacity[u][v]>0)
			 printf("\n %d  ",capacity[u][v]);
			 
		} 
		
			maxcap =fordFulkerson(2, 14);
			 printf("\n This is the max capacity \n");
             printf("\n %d  ",maxcap);
 	}

	} else

		 printf("No capacities have to be changed");
	 /*
for (u = 2; u <= nnodes; u++)
        	for (v = 2; v <= nnodes; v++)
		 {
	          if(capacity[u][v]>0)
			 printf("\n %d  ",capacity[u][v]);
		}*/	
    //printf("\n This is the max capacity \n");
    //printf("\n %d  ",maxcapacity);
  
   ENcloseH(); 
   ENclose(); 
 }    
  
















