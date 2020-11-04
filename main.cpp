#include "lab3_functions.cpp"
#define max 200
#define pi 3.14159265
//James Darrel Bautista IT 169 Final Lab
//
//
//Input: Number of vertices of graph G, Edges of graph G
//Output: Drawing of the graph, Degrees of the Graph
//Algorithm
//1. START
//2. Identify the number of vertices or size of graph G.
//3. Identify the set of edges from a pair of distinct vertices for the graph.
//4. Display adjacency matrix from the given inputs.
//5. If the pair of vertices is adjacent return 1, otherwise 0.
//6. Draw vertices that are represented by nodes and label its edges.
//7. If nodes are adjacent then connect a line, otherwise not.
//8. Display the degrees of each vertices.
//9. Identify the Dominating set using Greedy algorithm
//10. END
//


int adj[max][max];
int n,max_edges;
int global_x[max], global_y[max];
int x_of_drawing[max],y_of_drawing[max];

int domiSet[max];

note(){
     settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
     char arr[200];
     setcolor(WHITE);
     sprintf(arr,"Dominating Set using Greedy Algorithm: ");
     outtextxy(510,60,arr);
     sprintf(arr,"> Construct a bipartite graph H by putting an edge between vertices v of A and u of B if they are adjacent to each other.");
     outtextxy(510,90,arr);
     sprintf(arr,"> Elect a node v from A such that v has the highest covering number and add it to the output set C");
     outtextxy(510,110,arr);
     sprintf(arr,"> If there is a tie, then the highest ID is used to break the tie.");
     outtextxy(510,130,arr);
     sprintf(arr,"> Remove all vertices and edges in the set B that are covered by the node v");
     outtextxy(510,150,arr);
     sprintf(arr,"> Repeat until there is no adjacency between A and B");
     outtextxy(510,170,arr);
     setcolor(BLUE);
     rectangle(500,45,1500,200);
     rectangle(500,245,1500,680);
     settextstyle(SANS_SERIF_FONT,HORIZ_DIR,4);
     sprintf(arr,":::Degrees:::");
     outtextxy(830,230,arr);
     settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);

}


main()
{
	int i,j,origin,destin;
	char graph_type;
// 1.) Identify the number of vertices in the desired V(G)
	printf("Enter number of vertices(min:2 max:18) : ");
	scanf("%d",&n);
	while(n<2|| n>18){
        printf("\n===Invalid plotting of graph! Please read the minimum and maximum number of vertices===\n");
        scanf("%d",&n);
	}
		max_edges=n*(n-1)/2;
// 2.) Identify the set of edges in the desired V(G)
	for(i=1;i<=max_edges;i++)
	{
		printf("Enter edge %d( 0 0 to quit ) : ",i);
		scanf("%d %d",&origin,&destin);
		if( (origin ==0) && (destin==0) )
			break;
		if( origin > n || destin > n || origin<=0 || destin<=0|| origin == destin)
		{
			printf("Invalid edge!\n");
			i--;
		}
		else
		{
			adj[origin][destin]=1;
            adj[destin][origin]=1; /*symmetric*/
            global_x[i] = origin;
            global_y[i] = destin;
            adj[origin][origin]=1;
            adj[destin][destin]=1;
		}
	}
// 3.) Display the adjacency matrix with nxn dimension
    printf("The adjacency matrix is :\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			printf("%3d",adj[i][j]);
		printf("\n");
	}
	printf("\n");
/////////////////////////////DRAWING//////////////////////////////////////////////
// 4.) Draw the graph based from the given adjacency matrix
    initwindow(320,320,"Ai Haibara <3",(getmaxwidth()/2)-160,(getmaxheight()/2)-160);
    readimagefile("ai.jpg",0,0,320,320);
    initwindow(getmaxwidth(),getmaxheight(),".:::***Bautista Final Problem IT169 ");
    setfillstyle(1,LIGHTBLUE);
    setlinestyle(0,0,3);
    setbkcolor(LIGHTBLUE);
    bar(0,0,getmaxwidth(),getmaxheight());
    readimagefile("think_dc.jpg",0,(getmaxheight()/2)+50,500,getmaxheight());
    setcolor(YELLOW);
    for(int i=1,x=90;i<=n;i++){
            x = x-40;
            double val = pi/180;
            if(i>9){
                int xx = 250+(170*cos(x*val));
                int yy = 215+(170*sin(x*val));
                circle(xx, yy, 20);
                x_of_drawing[i]=xx;
                y_of_drawing[i]=yy;

            }
            else{
                int xx = 250+(100*cos(x*val));
                int yy = 215+(100*sin(x*val));
                circle(xx, yy, 20);
                x_of_drawing[i]=xx;
                y_of_drawing[i]=yy;
            }
    }
    for(int ii=1; ii<=max_edges;ii++){
        char ch[9];

         if(global_x[ii]==0 || global_y[ii]==0){
            break;
        }

        for(int i=1;i<=n;i++){
            sprintf(ch,"%d",i);
            outtextxy(x_of_drawing[i],y_of_drawing[i],ch);

            if(global_x[ii]==0 || global_y[ii]==0){
                break;
            }

            for(int j = (i+1); j <= n; j++){

                if(global_x[ii]==0 || global_y[ii]==0){
                    break;
                }

                if(global_x[ii]==i && global_y[ii]==j||global_x[ii]==j && global_y[ii]==i){
                        line(x_of_drawing[i],y_of_drawing[i],x_of_drawing[j],y_of_drawing[j]);
                }
            }
        }
    }
    note();
//    checkGraph(n,adj);
    greedyAlgoDominating(n,adj,domiSet,x_of_drawing,y_of_drawing);
    getche();
    closegraph();

}/*End of main()*/
