#include<stdio.h>

int main()

{
    int par,pro,i=0,j=0;
    printf("Enter the number of Partition : ");
    scanf("%d",&par);
    printf("Enter the number of Process : ");
    scanf("%d",&pro);
    int partition[par+2],process[pro+2];
    printf("Enter the size of Processes : \n");
    for(i=0; i<pro; i++)
    {
        scanf("%d",&process[i]);
    }
    printf("Enter the size of Blocks : \n");
    for(i=0; i<pro; i++)
    {
        scanf("%d",&partition[i]);
    }
    int internal_fragmentation=0;
    for(i=0; i<pro; i++)
    {
        for(j=0; j<par; j++)
        {
            if(process[i]<=partition[j])
            {
                internal_fragmentation+=(partition[j]-process[i]);
                partition[j]=-1;
                break;
            }
        }
    }
    printf(" Total Internal Fragmentation= %d\n",internal_fragmentation);
    return 0;
}
