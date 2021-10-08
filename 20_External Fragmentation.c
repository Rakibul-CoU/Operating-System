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
    for(i=0; i<par; i++)
    {
        scanf("%d",&partition[i]);
    }
    int internal_fragmentation=0,exF=1000;
    for(i=0; i<pro; i++)
    {
        int x=0;
        for(j=0; j<par; j++)
        {
            if(process[i]<=partition[j])
            {
                internal_fragmentation+=(partition[j]-process[i]);
                partition[j]=-1;
                x=1;
                break;
            }
        }
        if(x==0)
        {
            if(exF>process[i])
                exF=process[i];
        }
    }
    if(exF<=internal_fragmentation)
        printf("External Fragmentation = %d\n",internal_fragmentation);
    else
        printf("There is no External Fragmentation\n");
    return 0;
}
