#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*Function to count the number of 
connected computers/devices */
int countConnections(int n, int a[][n]){
    int c=0; //counter to store the no. of connections 
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j)
                a[i][j]=1;
            if (a[i][j])
			//increment counter whenever an active edge found
                c+=a[i][j]; 
        }
    }
    return c;
}

/*Function to identify the given topology according to
the number of connections in the network*/
void identifyTopology(int n, int a[][n]){
    int c=countConnections(n,a);
    if(c==3*n)
		//each device is connected to 
		//atmost 2 devices + 1 for itself
        printf("The network is ring topology\n");
    else if(c==n*n)
		//each device is connected to 
		//all other nodes + 1 for itself
        printf("The network is fully connected mesh topology\n");
    else if(c==(2*n)-1)
		//central device is connected to 
		//all other devices + n for selfloop
        printf("The network is star topology\n");
    else
        printf("The network is not a specific topology\n");
}

/*Function to take the input*/
void takeInput(){
    int n;
    printf("Enter the number of Nodes in the network: ");
    scanf("%d",&n);
    int a[n][n];
    printf("Enter the Adjacency Matrix Representation of Graph:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d",&(a[i][j]));
        }
    }
   identifyTopology(n,a);
}

/*Driver function to take the user choice*/
int main(){
    int c=1;
    while(c){
        int ch;
        printf("1. Enter the network representation\n");
        printf("2. Exit\n");
        scanf("%d",&ch);
        switch (ch){
            case 1: takeInput();
                    break;
            case 2: exit(0);
        }
        printf("Do you want to continue? (1=yes and 0=no): ");
        scanf("%d",&c);
    }
	return 0;
}
