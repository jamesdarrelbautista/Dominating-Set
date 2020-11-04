#include<stdio.h>
#include <iostream>
#include <graphics.h>
#include <math.h>
#include <windows.h>
#include <conio.h>
#include <stdbool.h>

int color;

inspectG(int n,int adj[200][200]){
    int odd=0;
    settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
    for(int i=1; i<=n; i++){
        for(int j=1,val=0; j<=n; j++){
            if(adj[i][j]==1){
                val=val+1;
                adj[i][0]=val;
            }
        }
        if(adj[i][0]%2!=0){
            odd=odd+1;
        }
    }
}
showG(int n,int adj[200][200],int place){
    char arr[50];
    color++;
    setbkcolor(LIGHTBLUE);
    if(color%2==0)
        setcolor(BLUE);
    else
        setcolor(YELLOW);

    for(int i=1,counter=0;i<=n;i++){

        if(i>9){
            counter=counter+1;

            sprintf(arr,"D(%d) = %d ",i,adj[i][0]);
            outtextxy(575+(place),250+(counter*40),arr);
        }
        else{

            sprintf(arr,"D(%d) = %d ",i,adj[i][0]);
            outtextxy(510+(place),250+(i*40),arr);
        }
    }
    setbkcolor(WHITE);
}



int sumOfDegrees(int adj[200][200],int n){
    int sum = 0;
    for(int i=1;i<=n;i++){
        sum=sum+adj[i][0];

    }
    printf("Sum is %d\n",sum);
    return sum;
}


greedyAlgoDominating(int n, int adj[200][200],int domiSet[],int x_of_drawing[200],int y_of_drawing[200]){
    int place = 0;
    inspectG(n,adj);
    showG(n,adj,place);

    int iOfBig, counter=0;
    int sum = 0;
    char arr[50];
//  while the sum of degrees is not zero the algo will always continue
    do{
        int biggest = 0;
        //check the biggest degree and idnumber
        for(int i=1 ; i<=n; i++){

            if(adj[i][0]>=biggest){

                biggest = adj[i][0];
                iOfBig = i;

            }
        }
        //insert the biggest number in an array called domiSet
        counter=counter+1;
        domiSet[counter] = iOfBig;
        printf("DomiSet[%d]: %d \nBiggest number is %d",counter, domiSet[counter],biggest);


        //delete the rows and columns of the biggest degree and idnumber

        for(int i=1;i<=n;i++){
            adj[i][0]=0;

            if(adj[iOfBig][i]!=0){
                for(int j=1;j<=n;j++){
                    adj[j][i]=0;
                }
            }
        }


        inspectG(n,adj);
        place=place+140;
        sum = sumOfDegrees(adj,n);
//        if(sum == 0)
//            break;
        showG(n,adj,place);
        settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
//        for(int i=1;i<=n;i++)
//        {
//            for(int j=1;j<=n;j++)
//                printf("%3d",adj[i][j]);
//            printf("\n");
//        }
        printf("Place: %d",place);
        setbkcolor(LIGHTBLUE);
        setcolor(BLACK);
        sprintf(arr,"The Dominating Set using Greedy Algorithm is: ");
        outtextxy(45,(getmaxheight()/2)+50,arr);
//        setbkcolor(WHITE);
        settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
        for(int i=1;i<=n;i++)
        {
            setcolor(WHITE);
            setbkcolor(BLACK);
            if(domiSet[i]==0){
                sprintf(arr,"---");
                outtextxy(30+(i*30),(getmaxheight()/2)+90,arr);
                break;
            }

            sprintf(arr,"%d, ",domiSet[i]);
            outtextxy(30+(i*30),(getmaxheight()/2)+90,arr);
            printf("I: %d \n",i);
            setcolor(RED);
            circle(x_of_drawing[domiSet[i]],y_of_drawing[domiSet[i]],20);
        }
    }while(sum!=0);
    char ch[9];
    settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
    setbkcolor(LIGHTBLUE);
    setcolor(YELLOW);
    for(int i=1;i<=n;i++){
            sprintf(ch,"%d",i);
            outtextxy(x_of_drawing[i],y_of_drawing[i],ch);

    }
    setcolor(BLUE);
    sprintf(arr,"Submitted by: James Darrel Bautista");
    outtextxy(getmaxwidth()-300,getmaxheight()-30,arr);


}
