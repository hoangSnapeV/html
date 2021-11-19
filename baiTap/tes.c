
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
int ran_dom(int minN, int maxN){
    return minN + rand() % (maxN + 1 - minN);
}

int sum_duong(int matrix[][10])
{   
    int sum = 0;
    for(int i = 0; i < 10; ++i)
    {
        for(int j = 0; j < 10; ++j)
        {   
            int r = matrix[i][j];
            if(r > 0)
            {
                sum += r;
            }        
        }
        
        
    }

    return sum;   
}

int checkPrimeNumber_c2(int m)
{   
    if(m < 2)
    {
        return 0;
    }
    int n = m / 2;
    int count = 0;

    for (int i = 2; i <= n; i++)
    {
        if (m % i == 0)
        {
            return 0;
        }
        
    }
    return 1;
}

int inPrimeNumber(int matrix[][10])
{   
    int a[100];
    int x = 0;
    for(int i = 0; i < 10; ++i)
    {   
        for(int j = 0; j < 10; ++j)
        {   
            int r = matrix[i][j];
            int result = checkPrimeNumber_c2(r);
            if (result) 
            {
                printf("cac so nguyen to = %d\n", r);
                a[x] = r;
                x++;
            }
        }
    }

    printf("a =");

    for (int i = 0; i < x; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    printf("x= %d\n", x);

    int d[100];
    d[0] = 0;

    for (int i = 0; i < x; i++)
    {
        int b = a[i];
        int j = i + 1;
        for(j; j < x; j++)
        {
            if (b == a[j])
            {
                d[j] = 1;
            }
            else d[j] = 0;
        }
        printf("%d ", d[i]);
    }
    
}

    
int main(){
    srand((int)time(0));
    int r;
    int matrix[10][10];

    for(int i = 0; i < 10; ++i)
    {
        for(int j = 0; j < 10; ++j)
        {
            r = ran_dom(1, 50);
            matrix[i][j] = r;
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }    
    
    int result = sum_duong(matrix);
    printf("sum_positive = %d \n", result);

    inPrimeNumber(matrix);
}