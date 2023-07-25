#include<stdio.h>
#include<limits.h>
int checkhit(int incomingpage,int queue[],int occupied){
    for(int i=0;i<occupied;i++){
        if(incomingpage==queue[i])
        return 1;
    }
    return 0;
}

void printframe(int queue[],int occupied)
{
    for(int i=0;i<occupied;i++)
    printf("%d\t\t\t",queue[i]);

}
int main()
{  int incomingstream[]={1,2,3,2,1,5,2,1,6,2,5,6,3,1,3};
    int n=sizeof(incomingstream)/sizeof(incomingstream[0]);
    int frames=3;
    int queue[n];
    int distance[n];
    int occupied=0;
    int pagefault=0;
    printf("page\tframe1\tframe2\tframe3\n");
    for(int i=0;i<n;i++)
    {
        printf("%d:\t\t",incomingstream[i]);
        if(checkhit(incomingstream[i],queue,occupied))
      
        printframe(queue,occupied);

    
    else if(occupied<frames){
        queue[occupied]=incomingstream[i];
        pagefault++;
        occupied++;
        printframe(queue,occupied);

    }
    else{
        int max=INT_MAX;
        int index;
        for(int j=0;j<frames;j++)
        {
            distance[j]=0;
            for(int k=i;k>=0;k--)
            {
                ++distance[j];
                if(queue[j]==incomingstream[k])
                break;
            }
            if(distance[j]>max){
                max=distance[j];
                index=j;
            }
        }
        queue[index]=incomingstream[i];
        printframe(queue,occupied);
        pagefault++;

    }
    printf("\n");

    }
printf("page fault %d",pagefault);
return 0;
}