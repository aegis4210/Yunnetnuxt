#include<stdio.h>
int main(int argc, char const *argv[])
{
    int x,y,NMSL;
    printf("輸入數字");
    scanf("%d,%d",&x,&y);
    
    for (int i = x; i < y; i++)
    {
        NMSL=0;
        for (int j = 0; j < i; j++)
        {
            if (i % j==0)
            {
                NMSL=1;
            }
               
        }
        
    }
    
    
    return 0;
}
