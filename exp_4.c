#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MSIZE 2

int main()

{

   

    int T;//number of courses
    int M=100;
    int N;//number of student

    

    scanf("%d",&T);

    float arr[T+(T*M)];

    for(int i=0; i<T; i++)

    {
        
        

        scanf("\n%d",&N);
        arr[i*M]=N;
        int sum_grades=0;

        for(int j=(i*M)+2; j< (i*M)+2+N; j++){
            
            scanf("%f",&arr[j]);

           

            sum_grades += arr[j];

           

        }

        

        float average=(float)sum_grades/N;

        

        int above_average=0;

        for (int k=(i*M)+2; k<(i*M)+2+N; k++){

            if(arr[k]>=average)

                above_average+=1;

        }

        
        arr[(i*M)+1]=100*(float)above_average/N;
        
        
    }
    
    for(int c=0; c<T; c++){
        printf("%f\n",arr[(c*M)+1]);
        
    }    
      

}

