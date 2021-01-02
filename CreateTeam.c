#include<stdio.h>
#include<math.h>
#include<string.h>

/*
	Emre Can Satýk's note:
	An example I wrote for 2v2 and 3v3 matches. You can adapt this for any type of encounter you want.
*/

int main() {
	
	int height[10],points[10],weight[10],score[10],dif[126];
	int selection,i,x,y,min=999999999,max=-1;
	char n0[20],n1[20],n2[20],n3[20],n4[20],n5[20];
	char *names[6]={n0,n1,n2,n3,n4,n5};
	
	printf("1. 2v2\n2. 3v3\nselection: ");
	scanf("%d",&selection);
	
	if(selection==1) {x=4; y=3;}    //   2v2
	if(selection==2) {x=6; y=10;}   //   3v3
	//  x: number of players
	//  y: number of teams that can be produced.

	/*  if(selection==3) {x=8; y=35;}  
        if(selection==4) {x=10; y=126;}              
	*/
	
	for(i=0;i<x;i++) {
		printf("(number %d) Name of player: ",i+1);
		scanf("%s",names[i]);	
	}
			
	for(i=0;i<x;i++) {
		printf("\n%s\n--------\n",names[i]);
		printf("height: ");
		scanf("%d",&height[i]);
		printf("last match pointed: ");
		scanf("%d",&points[i]);
		printf("weight: ");
		scanf("%d",&weight[i]);
		score[i]=height[i]*2+points[i]*3+weight[i]*1;          // You can change this.
	}
	
	if(selection==1) {                                           // These are for calculate different teams.
		dif[0]=abs((score[0]+score[1])-(score[2]+score[3]));
		dif[1]=abs((score[0]+score[2])-(score[1]+score[3]));
		dif[2]=abs((score[0]+score[3])-(score[1]+score[2]));		
	}
	 
	if(selection==2) {                                            // These are for calculate different teams.
		dif[0]=abs((score[0]+score[1]+score[2])-(score[3]+score[4]+score[5]));
		dif[1]=abs((score[0]+score[1]+score[3])-(score[2]+score[4]+score[5]));
		dif[2]=abs((score[0]+score[1]+score[4])-(score[2]+score[3]+score[5]));
		dif[3]=abs((score[0]+score[1]+score[5])-(score[2]+score[3]+score[4]));
		dif[4]=abs((score[1]+score[2]+score[3])-(score[0]+score[4]+score[5]));
		dif[5]=abs((score[1]+score[2]+score[4])-(score[0]+score[3]+score[5]));
		dif[6]=abs((score[1]+score[2]+score[5])-(score[0]+score[3]+score[4]));
		dif[7]=abs((score[2]+score[0]+score[3])-(score[1]+score[4]+score[5]));
		dif[8]=abs((score[2]+score[0]+score[4])-(score[1]+score[3]+score[5]));
		dif[9]=abs((score[2]+score[0]+score[5])-(score[1]+score[3]+score[4]));
	}
	
	for(i=0;i<x;i++) {                               // This is for see this player's score. (if you want, you can delete this loop.)
		printf("\n- %s's Score: %d",names[i],score[i]);
	}
	
	for(i=0;i<y;i++) {            // This is for ideal dif. (dif: difference)
		if(dif[i]<min) {
			min=dif[i];
			x=i;
		}
	}
	i=x;     // i: number of dif.
	
	printf("\n\nIdeal Teams:\n");
	if(selection==1) {                                                      // these are for 2v2.
		if(i==0) printf("A: %s and %s\nB: %s and %s",n0,n1,n2,n3);
		if(i==1) printf("A: %s and %s\nB: %s and %s",n0,n2,n1,n3);
		if(i==2) printf("A: %s and %s\nB: %s and %s",n0,n3,n1,n2);
	}
	if(selection==2) {                                                      // these are for 3v3.
		if(i==0) printf("A: %s, %s, %s\nB: %s, %s, %s",n0,n1,n2,n3,n4,n5);
		if(i==1) printf("A: %s, %s, %s\nB: %s, %s, %s",n0,n1,n3,n2,n4,n5);
		if(i==2) printf("A: %s, %s, %s\nB: %s, %s, %s",n0,n1,n4,n2,n3,n5);
		if(i==3) printf("A: %s, %s, %s\nB: %s, %s, %s",n0,n1,n5,n2,n3,n4);
		if(i==4) printf("A: %s, %s, %s\nB: %s, %s, %s",n1,n2,n3,n0,n4,n5);
		if(i==5) printf("A: %s, %s, %s\nB: %s, %s, %s",n1,n2,n4,n0,n3,n5);
		if(i==6) printf("A: %s, %s, %s\nB: %s, %s, %s",n1,n2,n5,n0,n3,n4);
		if(i==7) printf("A: %s, %s, %s\nB: %s, %s, %s",n2,n0,n3,n1,n4,n5);
		if(i==8) printf("A: %s, %s, %s\nB: %s, %s, %s",n2,n0,n4,n1,n3,n5);
		if(i==9) printf("A: %s, %s, %s\nB: %s, %s, %s",n2,n0,n5,n1,n3,n4);
	}
	
	/*
		If you like this, please add a star.
	*/
	return 0;
}
