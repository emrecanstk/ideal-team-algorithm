#include<stdio.h>
/*
	changes from previous version:
	 1- player capacity: from 6 to infinity
	 2- 20 lines less code
	 3- 5 less definitions
	
	future changes:
	 1- uneven number of matches
	 2- set score criteria
*/
struct player{
	char name[20];
	int height;
	int weight;
	int point;
	int score;
};

main() {
	
	int i,j,size=1;

	while(size%2==1) {
		printf("(even) total number of players: ");
		scanf("%d",&size);
	}
	
	struct player players[size];
	
	for(i=0;i<size;i++) {
		printf("(number %d) Name of player: ",i+1);
		scanf("%s",players[i].name);
	}
	
	for(i=0;i<size;i++) {
		printf("\n%s\n--------\n",players[i].name);
		printf("height: ");
		scanf("%d",&players[i].height);
		printf("weight: ");
		scanf("%d",&players[i].weight);
		printf("last match pointed: ");
		scanf("%d",&players[i].point);
		players[i].score = players[i].point*3+players[i].height*2+players[i].weight*1;
		printf("%s has %d score.\n",players[i].name,players[i].score);
	}
	
    for(i=0;i<size;i++) {
        for(j=0;j<size-1;j++) {     // bubble sort
            if(players[j+1].score < players[j].score) {
                struct player temp = players[j+1];
                players[j+1] = players[j];
                players[j] = temp;
            }
        }
    }
    
	int sumA=0,sumB=0;
	struct player teamA[size/2],teamB[size/2];
	teamA[0] = players[0],teamB[0] = players[1];
	sumA+=players[0].score;
	sumB+=players[1].score;
	j=1;
	
	for(i=2;i<size-1;i+=2) {
		if(sumA>sumB) {
			teamA[j] = players[i];
			teamB[j] = players[i+1];
		}
		else {
			teamA[j] = players[i+1];
			teamB[j] = players[i];
		}
		j++;
	}
	
	printf("\n\nTeam A:\n");
	for(i=0;i<size/2;i++) printf("%s\n",teamA[i].name);
	printf("\n\nTeam B:\n");
	for(i=0;i<size/2;i++) printf("%s\n",teamB[i].name);
}
