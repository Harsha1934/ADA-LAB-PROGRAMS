#include <stdio.h>
#define I 9999
int main()
{
    int n;
    printf("enter the no of vertexs:");
    scanf("%d",&n);
    int d[4][4]={{0,I,3,I},{2,0,I,I},{I,7,0,1},{6,I,I,0}
    };
    for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(d[i][k]+d[k][j]<d[i][j])
                    {
                        d[i][j]=d[i][k]+d[k][j];
                    }
                }
            }
        }
    for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;      j++)
                {
                    if(d[i][j]==I)
                        {
                            printf("I ");
                        }
                    else{
                            printf("%d ",d[i][j]);
                        }
                }
                printf("\n");
        }
    return 0;
}

