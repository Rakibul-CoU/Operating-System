#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESS 100

struct process {
    int pid;
    int burst_time;
    int waiting_time;
};

typedef struct process Process;


double average_waiting_time;
int total_waiting_time;

void sort_process_by_burst_time(Process p[], int n);
void calculate_waiting_time(Process p[], int n);
void print_gantt_chart(Process p[], int n);

int main()
{
    Process p[MAX_PROCESS];
    int n, i, j;
    puts("SHORTEST JOB FIRST SCHEDULING ALGORITHM");
    puts("=======================================");
    printf("Enter total process: ");
    scanf("%d", &n);
    printf("Enter burst time for each process:\n");
    for(i=0; i<n; i++) {
        printf("P[%d]: ", i+1);
        scanf("%d", &p[i].burst_time);
        p[i].pid = i+1;
    }
    /*ctt[0]=p[0].burst_time;
    for(i=1; i<n; i++) {
        //scanf("%d", &p[i].burst_time);
        ctt[i]=(ctt[i-2]+p[i].burst_time+p[i-1].burst_time);
    }
    printf("\n");
    int ct_sum=0;
    for(i=0; i<n; i++)
    {
        ct_sum+=ctt[i];
        printf("%d ", ct_sum);
    }
    printf("\n");
    for(i=0; i<n; i++)
    {
        printf("%d ", ctt[i]);
    }
    printf("\n");*/
    sort_process_by_burst_time(p, n);
    calculate_waiting_time(p, n);

    average_waiting_time = (double) ( (double)total_waiting_time / (double) n );
    //average_trun_around_time = (double) ( (double)ct_sum / (double) n );

    puts("");
    printf("Average Waiting Time: %.2lf\n",average_waiting_time);

    printf("Gantt Chart:\n");
    print_gantt_chart(p, n);


    return 0;
}

void sort_process_by_burst_time(Process p[], int n)
{
    int i, j;
    Process temp;
    for(i=0; i<n-1; i++) {
        for(j=0; j<n-1-i; j++) {
            if(p[j].burst_time > p[j+1].burst_time) {
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
}

void calculate_waiting_time(Process p[], int n)
{
    int i;
    total_waiting_time = 0;
    p[0].waiting_time = 0;
    for(i=1; i<n; i++) {
        p[i].waiting_time = p[i-1].waiting_time + p[i-1].burst_time;
        total_waiting_time += p[i].waiting_time;
    }
}

void print_gantt_chart(Process p[], int n)
{
    int i, j;
    int last = p[n-1].burst_time + ( n== 1 ? 0 : p[n-1].waiting_time);
    // printing top bar
    printf(" ");
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].burst_time; j++) printf("--");
        printf(" ");
    }
    printf("\n|");
    // middle position
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].burst_time-1; j++) printf(" ");
        printf("p%d", p[i].pid);
        for(j=0; j<p[i].burst_time-1; j++) printf(" ");
        printf("|");
    }
    printf("\n ");
    // bottom bar
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].burst_time; j++) printf("--");
        printf(" ");
    }
    printf("\n");

    // printing waiting time
    int pp=0;
    int minus = 0;
    for(i=0; i<n; i++) {
        if(p[i].waiting_time>9) printf(" ");
        printf("%d", p[i].waiting_time);
        //pp+=p[i].waiting_time;
        if(p[i+1].waiting_time>9){
          minus = 1;
        }
        if(i+1 == n )  if (last>9) minus = 1;
        for(j=0; j<p[i].burst_time-minus; j++) printf("  ");

    }
    if(last>9) printf(" ");
    printf("%d\n", last);
    for(i=0; i<n; i++)
    {
        pp+=p[i].waiting_time;
    }
    pp+=last;
    //pp+=p[n-1].waiting_time;
    double average_trun_around_time = (double) ( (double)pp / (double) n );
    printf("Average_Trun_Around_Time= %.2lf\n", average_trun_around_time);
}
