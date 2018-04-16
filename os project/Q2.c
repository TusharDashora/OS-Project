# include <stdio.h>
# include <pthread.h>
# define arrSize 7

struct StructMaxMin
{
    int max1;
    int min1;
};

int arr[arrSize];

void *thread_search_min_max(void *);

int main()
{
    pthread_t tid;
    struct StructMaxMin *st_main,*st_th;
    int Max2,Min2;
    
    st_main=(struct StructMaxMin*)malloc(sizeof(struct StructMaxMin));
    
    int iCount;
    for(iCount=0;iCount<arrSize;iCount++)
    {
        printf("Enter Value of arr[%d] :",iCount);
        scanf("%d",&arr[iCount]);
    }        
    pthread_create(&tid,NULL,thread_search_min_max,NULL);
    
    st_main->max1=arr[0];
    st_main->min1=arr[0];
    
    for(iCount=1;iCount<arrSize/2;iCount++)
    {
        if(arr[iCount] > st_main->max1)
        {
            st_main->max1=arr[iCount];
        }
        
        if(arr[iCount] < st_main->min1)
        {
            st_main->min1=arr[iCount];
        }
    }    
    
    pthread_join(tid,(void**)&st_th);    
    
    if(st_main->max1 >= st_th->max1)
    {
        Max2=st_main->max1;
    }    
    else
    {
        Max2=st_th->max1;
    }
        
    if(st_main->min1 <=st_th->min1)
    {
        Min2=st_main->min1;
    }
    else
    {
        Min2=st_th->min1;
    }
    
    printf("Final Max : %d \n",Max2);
    printf("Final Min : %d \n",Min2);
    return 0;
}


void *thread_search_min_max(void *para)
{
    struct StructMaxMin *st;
    st=(struct StructMaxMin*)malloc(sizeof(struct StructMaxMin));
        
    int iCount;
    st->max1=arr[arrSize/2];
    st->min1=arr[arrSize/2];
        
    
    for(iCount=arrSize/2 + 1;iCount<arrSize;iCount++)
    {
        if(arr[iCount] > st->max1)
        {
            st->max1=arr[iCount];
        }
        if(arr[iCount] < st->min1)
        {
            st->min1=arr[iCount];
        }
    }    
    
    pthread_exit((void*)st);        
}

