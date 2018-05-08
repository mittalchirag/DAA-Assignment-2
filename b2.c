#include <stdio.h>
#include <stdlib.h>
#define swap(a,b) int x=a;a=b;b=x;


/*Function to implement the bubble sort algorithm
and print the moves according to the constraint */ 

void bubbleSort(int n, int a[]){
   for (int i=0;i<(2*n)-1;i++){\
	//i number of elements will already be sorted
	//j loop will always run less than size-i
       for (int j=0;j<(2*n)-i-1; j++){
		   //check the current and neighboring element
           if(a[j]>a[j+1]){
			   //swap the two elements if condition satisfies
               swap(a[j],a[j+1]);
			   //print the number(j+1) of disks to be interchange
               printf("Interchange disk %d and disk %d.\n",j+1,j+2);
           //print the disks after swapping
		   for(int k=0;k<2*n;k++)
               printf("%d ",a[k]);
           printf("\n");
           }
       }
   }
}
/*Function that prints the output i.e. the final arrangement of the disks
for verifying the output matches the expected output*/
void output(int n, int a[]){
    printf("Now, the disks are: \n"); 
    for(int i=0;i<2*n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}
/*Function to take user input i.e. it takes number of disks and 
alternating arrangement of disks in form of 1s and 0s */
void takeInput(){
    int n;
    printf("Enter number of white/dark disks: ");
    scanf("%d",&n);
    int a[2*n];
    printf("Enter %d white and %d dark disks (1=dark disk and 0=white disks):\n",n,n); 
    for (int i=0; i<2*n; i++){
        
        scanf("%d",&a[i]);
    }
    printf("Moves to get the expected output:\n");
    bubbleSort(n,a);
    output(n,a);
}
/*Driver function to call other functions*/
int main(){
    takeInput();
	return 0;
}
