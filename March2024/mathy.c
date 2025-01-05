#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int formula(int n)
{
    int i,j;
    float tmp=0;
    float max=-2147483648.0f;
    for(i=-n;i<=n;i++)
 {
     for(j=-n;3*j<=n;j++)
    {
        tmp=(sin(i)+cos(j))/(2+pow(i,2)+pow(j,4));
         if(tmp>max)
           max=tmp;
    }
 }
printf("answer= %f",max);
}


int main()
{
int n;
scanf("%d",&n);
formula(n);
return 0;
}
