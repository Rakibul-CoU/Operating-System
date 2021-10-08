#include<stdio.h>
int bno,pno,block[109],process[109],allocation[109],blockused[109],processinblock[109];
int main()
{
    int i,j,k;
    printf("Number of memory partition/block: ");
    scanf("%d",&bno);
    for(i=1 ; i<=bno ; i++)
    {
        printf("Partition %d size = ",i);
        scanf("%d",&block[i]);
    }
    printf("Number of process: ");
    scanf("%d",&pno);
    for(i=1 ; i<=pno ; i++)
    {
        printf("Process %d need = ",i);
        scanf("%d",&process[i]);
    }
    for(i=1 ; i<=pno ; i++)
    {
        for(j=1 ; j<=bno ; j++)
        {
            if(!blockused[j] && block[j] >= process[i])
            {
                allocation[i] = j;
                blockused[j] = 1;
                processinblock[j] = i;
                break;
            }
        }
    }
    printf("\n");
    for(i=1 ; i<=pno ; i++)
    {
        if(allocation[i] == 0)
        {
            printf("Process %d is unable to allocate any partition of memory.\n",i);
            continue;
        }
        int availablespace = block[allocation[i]] - process[i];
        printf("Process %d allocates partition %d. Available space = %d\n",i,allocation[i],availablespace);
    }
///Grant chart
    printf("\n");
    for(i=1 ; i<=bno ; i++)
    {
        if(processinblock[i] != 0)
            printf("Process in partition %d -> P%d(%d)\n",i,processinblock[i],process[processinblock[i]]);
        else
            printf("%dth partition is empty\n",i);
    }
    return 0;
}
