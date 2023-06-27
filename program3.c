float sum,at;
printf("\n enter number of process");
scanf("%d",&n);
for(i=0;i<n;i++)
{
    printf("\n p%d",i);
    scanf("%d",&bt[i]);
}
for(i=0;i<n-1;i++)
{
    for(j=i+1;j<n;j++)
    {
        if(bt[i]>bt[j])
        {
            temp=bt[i];
            bt[i]=bt[j];
            bt[j]=temp;
            temp=pno[i];
            pno[i]=pno[j];
            pno[j]=temp;
        }
        }

        }
        wt[0]=0;
        for(i=0;i<n;i++)
        {
            wt[i]=bt[i-1]+wt[i-1];
            sum=sum+wt[i];
        }
        printf("\nprocess no\tburst time\t waiting time\t turn around time\n");
        {
            for(i=0;i<n;i++)
            {
                tt[i]=bt[i]+wt[i];
                at+=tt[i];
                printf("\np%d\t\tt%d\t\tt%d",i,bt[i],wt[i],tt[i]);
                printf("\n\n\t average waiting time %f\n\tAverage turn around time %f,sum,at");
            }
        }
    }
}