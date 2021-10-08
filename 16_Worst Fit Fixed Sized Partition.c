#include<stdio.h>
struct Data
{
    int pro,par,frag,idx;
};
int main()
{
    int no_pro,no_par=5,i=0,j=0;
    printf("Enter the Number of Process : ");
    scanf("%d",&no_pro);
    struct Data partition[no_par+2];
    struct Data process[no_pro+2];
    printf("\tEnter the Size of Partitions :\n");
    for(i=0; i<no_par; i++)
    {
        int x;
        printf("\t\tPartition %d Size=",i+1);
        scanf("%d",&x);
        partition[i].par=x;
        partition[i].idx=i+1;
    }
    printf("\tEnter the Size of Processes :\n");
    for(i=0; i<no_pro; i++)
    {
        int y;
        printf("\t\tProcess %d Need=",i+1);
        scanf("%d",&y);
        process[i].pro=y;
        process[i].idx=i+1;
    }
    for (i = 0; i < no_pro - 1; i++)
    {
        for (j = 0; j < (no_pro - 1-i); j++)
        {
            if (process[j].pro < process[j+1].pro)
            {
                struct Data temp = process[j];
                process[j] = process[j+1];
                process[j+1] = temp;
            }
        }
    }
    struct Data ans[no_pro+2];
    for(i=0; i<no_pro; i++)
    {
        int mx=0,ix=-1;
        for(j=0; j<no_par; j++)
        {
            if(mx<partition[j].par)
            {
                mx=partition[j].par;
                ix=partition[j].idx;
            }
        }
        if(mx>=process[i].pro)
        {
            ans[process[i].idx].par=ix;
            ans[process[i].idx].frag=mx-process[i].pro;
            for(j=0; j<no_par; j++)
            {
                if(mx==partition[j].par)
                {
                    partition[j].par=-1;
                    break;
                }
            }
        }
        else
        {
            ans[process[i].idx].par=-1;
        }
    }
    for(i=1; i<=no_pro; i++)
    {
        if(ans[i].par!=-1)
        {
            printf("Process %d allocates Partition %d & Available Space=%d\n",i,ans[i].par, ans[i].frag);
        }
        else
        {
            printf("Process %d can't allocates any Partition.\n",i);
        }
    }
    return 0;
}
