#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<string.h>
 
int heap[1000000], heapSize ,ans = 0,temp = 0;
FILE *infile,*outfile;

void Init() {
    heapSize = 0;
    heap[0] = -INT_MAX;
}

void Insert(int element) {
    heapSize++;
    heap[heapSize] = element;
    int now = heapSize;
    while (element < heap[now / 2] ) {
        heap[now] = heap[now / 2];
        now /= 2;
    }
    heap[now] = element;
}
int DeleteMin() {
   
    int minElement, lastElement, child, now;
    minElement = heap[1];
    lastElement = heap[heapSize--];

    for (now = 1; now * 2 <= heapSize; now = child) {
      
        child = now * 2;
        if (child != heapSize && heap[child + 1] < heap[child]) {
            child++;
        }
       
        if (lastElement > heap[child]) {
            heap[now] = heap[child];
        } else
        {
            break;
        }
    }
    heap[now] = lastElement;
    return minElement;
}

int add(){
	if(heapSize == 1 ) return ans;
	else{
	temp = ans;
	ans +=  DeleteMin() +  DeleteMin();
	
	Insert(ans-temp);
	//printf("\nans = %d\n",ans);
	}
}
 
 
int main() {
	infile = fopen("input.txt", "r");
	outfile = fopen( "ouput.txt","w" );
	if(infile == NULL && outfile == NULL){
       printf("Files DOES NOT EXISTS!");
    }
    else{
         while(feof(infile) == 0)
         {
    int number_of_elements = 0;
    fscanf(infile,"%d", &number_of_elements);
    int  element,iter;
    Init();
    ans = 0;
	temp = 0;
    for (iter = 0; iter < number_of_elements; iter++) {
        fscanf(infile,"%d", &element);
        Insert(element);
    }
    
    for(int i = 0 ;i<iter;i++){
    	add();
	}
	
	fprintf(outfile,"%d\n",ans);
	printf("%d\n",ans);
	}
}
    return 0;
}
