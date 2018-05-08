#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Function to perform linear search on the given array*/
void linearSearch(int n, int a[]){
    for( int i=0;i<n;i++){
        //store the i_th element as key
		int k=a[i];
		//check if key is visited or not
        if(k<0)
            continue;
		//if not visited
        printf("Founded %d at: ",k);
        for(int j=i;j<n;j++){
            //search for the key
			if(a[j]==k){
				//if found mark it as visited
                a[j]=-k;
				//print the position where it is found
                printf("%dth, ",j);
            }
        }
        printf("\n");
    }
}

void takeInput(){
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    printf("Enter the %d elements of the array:\n",n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    linearSearch(n,a);
}
int main(){
    clock_t t;
    t=clock();	
    takeInput();
    t=clock()-t;
    double time_taken=((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("\n\nExecution took %f seconds to execute \n", time_taken);
    return 0;
}
