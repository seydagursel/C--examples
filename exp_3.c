#include<stdio.h>
int main()
{
    int n,a,i,j,u,spaces;
    

    printf("enter n:");
    scanf("%d",&n);

    while(n%2!=0)
    {
        printf("enter n:");
        scanf("%d",&n);
    }
    u=n;
    int l=1;
    spaces = 0 ;


    for (i=1; i<=n; i++)
    {
        
        for( a = 0; a<spaces; a++ ) printf( " " );
        spaces+=2;
        if (i%2==0)//çift satirin çift ile baslamasi icin
        {
            l=i+1;
            for( j=u; j>0; j=j-2 )
            {
                printf( "%d ", j);
                if (l<n)
                    printf("%d ", l);
                l=l+2;

            }
            u=u-2;
        }
        else
        {
            l=i;
            for( j=u; j>0; j=j-2 )
            {
                
                printf( "%d ", l);

                printf("%d ", j);

                l=l+2;
            }
        }
        printf( "\n" );


    }



    printf( "\n\n\n" );

}
