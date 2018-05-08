#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}
void binarySearch(int n, int a[]){
    qsort(a,n,sizeof(int),cmpfunc);
    for(int i=0;i<n;i++){
        int x=a[i];
        if(x<0)
            continue;
        printf("Founded %d at: ",x);
        int l=0,r=n-1;
        while (l <= r){
		    int m = l + (r-l)/2;
            // Check if x is present at mid
            if (a[m] == x){
                a[m]=-x;
                printf("%dth, ",m);
            }                
            // If x greater, ignore left half
            if (a[m] < x)
                l = m + 1;
            // If x is smaller, ignore right half
            else
                r = m - 1;
        }
        printf("\n");
    }
    
}

void takeInput(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    binarySearch(n,a);
}
int main(){
    takeInput();
    return 0;
}

