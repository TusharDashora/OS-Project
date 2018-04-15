# include <stdio.h>
#include<stdlib.h>
# include <pthread.h>
# define arrSize 10

struct StructMaxMin
{
    int iMax;
    int iMin;
};

int arr[arrSize];

void *thread_search_min_max(void *);
void *thread_avg(void *);

int main()
{
    pthread_t tid;
    struct StructMaxMin *st_main,*st_th;
    int FinalMax,FinalMin;
    
    st_main=(struct StructMaxMin*)malloc(sizeof(struct StructMaxMin));
    
    int iCount;
    for(iCount=0;iCount<arrSize;iCount++)
    {
        printf("Enter Value of arr[%d] :",iCount);
        scanf("%d",&arr[iCount]);
    }        
    pthread_create(&tid,NULL,thread_search_min_max,NULL);
    
    st_main->iMax=arr[0];
    st_main->iMin=arr[0];
    
    for(iCount=1;iCount<arrSize/2;iCount++)
    {
        if(arr[iCount] > st_main->iMax)
        {
            st_main->iMax=arr[iCount];
        }
        
        if(arr[iCount] < st_main->iMin)
        {
            st_main->iMin=arr[iCount];
        }
    }    
    
    pthread_join(tid,(void**)&st_th);    
    
    if(st_main->iMax >= st_th->iMax)
    {
        FinalMax=st_main->iMax;
    }    
    else
    {
        FinalMax=st_th->iMax;
    }
        
    if(st_main->iMin <=st_th->iMin)
    {
        FinalMin=st_main->iMin;
    }
    else
    {
        FinalMin=st_th->iMin;
    }
    
    printf("Final Max : %d \n",FinalMax);
    printf("Final Min : %d \n",FinalMin);
    return 0;
}

void *thread_avg(void *)
{
    
}
void *thread_search_min_max(void *para)
{
    struct StructMaxMin *st;
    st=(struct StructMaxMin*)malloc(sizeof(struct StructMaxMin));
        
    int iCount;
    st->iMax=arr[arrSize/2];
    st->iMin=arr[arrSize/2];
        
    
    for(iCount=arrSize/2 + 1;iCount<arrSize;iCount++)
    {
        if(arr[iCount] > st->iMax)
        {
            st->iMax=arr[iCount];
        }
        if(arr[iCount] < st->iMin)
        {
            st->iMin=arr[iCount];
        }
    }    
    
    pthread_exit((void*)st);        
}
