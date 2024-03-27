#include <stdio.h>


int * findMin(int * start,int * end)
{
    
    
    int *min_t=start;
    
    while(start<=end)
	{
		if(*start < *min_t)
		    min_t = start;
		
		start++;
	}
	
	return min_t;
}


void sort(int * start, int  * end)
{
    
    int temp;
    while(start<=end){
        
        int *min =findMin(start,end);
        
        temp = *start;
        *start= *min;
        *min = temp;
        start++;
        
        
    }
}

int main()
{

	int arr[10]={5,11,3,12,17,25,1,9,14,2};

	sort(arr,&arr[9]);
	for(int i=0;i<10;i++)
		printf("%d ",arr[i]);
	printf("\n");
}



