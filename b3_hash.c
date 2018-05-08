/*
 * 
 * author: Chirag Mittal
 * github: miitalchirag
 * 
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}
int max(int n, int a[n]){
    int max=a[0];
    for(int i=1;i<n;i++){
        if(a[i]>max){
            max=a[i];
        }
    }
    return max;
}
/*Function to fill the hash map and print the output also*/
void hashSearch(int n, int a[]){
	//find the maximum element of the array
    int m=max(n,a);
	//create the hash map of m+1 elements each pointing to a dynamic list
    int hashMap[m+1][n];
    int freq[m+1];
    for(int i=0;i<m+1;i++){
        freq[i]=0;
    }
	//iterate over all the elements of the array
    for(int i=0;i<n;i++){
        int x=a[i];
		//go to the i_th element as an index in hash map
		// append i in the list
        hashMap[x][freq[x]]=i;
        freq[x]++;
    }
	//output the values stored in hash map
    for(int i=1;i<m+1;i++){
        if(freq[i]>0){
			//for the element i
            printf("Founded %d at: ",i);
            //output all the elements of the list stored at i_th index
			for(int j=0;j<freq[i];j++){
                printf("%dth, ",hashMap[i][j]);
            }
            printf("\n");
        }
    }
}

void takeInput(){
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the %d elements of the array:\n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    hashSearch(n,a);
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


