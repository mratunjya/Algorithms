#include<stdio.h>
#include<limits.h>
#include<math.h>

int heapsize = 5;

struct vertex{
    int value;
    int index; 
};

void initialize(struct vertex key[],int mst[],int parent[])
{
    for(int i=0;i<5;i++)
    {
        key[i].value = INT_MAX;
        key[i].index = i;
        parent[i] = -1;
        mst[i] = 0;
    }
    key[4].value = 0;
}

void min_heapify(struct vertex key[],int index)
{
    int l = (index*2)+1;
    int r = (index*2)+2;

    int small = index;

    if(l<heapsize && key[l].value < key[index].value)
        small = l;
    else    
        small = index;
    
    if(r<heapsize && key[r].value < key[small].value)
        small = r;
    
    if(small!=index)
    {
        struct vertex temp = key[small];
        key[small] = key[index];
        key[index] = temp;
        min_heapify(key,small);
    }


}

void build_minheap(struct vertex key[])
{
    int heapsize = 5;
    for(int i=floor(5/2)-1;i>=0;i--)
    {
        min_heapify(key,i);
    }
}

void extract_min(struct vertex key[])
{
    if(heapsize < 1)
        printf("Heap is underflow!!");
    
    key[0] = key[heapsize-1];
    heapsize--;
    min_heapify(key,0);
}

int main()
{
    int egdes[5][5] = {{-1,2,-1,6,-1},
                        {2,-1,3,8,5},
                        {-1,3,-1,-1,7},
                        {6,8,-1,-1,-1},
                        {-1,5,7,-1,-1}};

    int mst[5],parent[5];

    struct vertex key[5];

    initialize(key,mst,parent);

    build_minheap(key);

    for(int i=0;i<5;i++)
    {
        // int smallest = INT_MAX; 
        int index = -1;
        // for(int j=0;j<5;j++)
        // {
        //     if(mst[i] == 0 && smallest > key[i])
        //     {
        //         smallest = key[i];
        //         index = i;
        //     }
        // }
        
        // smallest = key[0].value;
        index = key[0].index;

        mst[index] = 1;

        for(int j=0;j<5;j++)
        {
            if(egdes[index][j]!=-1)
            {
                for(int k=0;k<heapsize;k++)
                {
                    if(j==key[k].index && egdes[index][j] < key[k].value)
                    {
                        key[k].value = egdes[index][j];
                        parent[key[k].index] = index;                           //O(n^2)
                        // printf("%d->%d\n",key[k].index,parent[key[k].index]);
                    }
                }
                // key[j].value = egdes[index][j];
                // parent[j] = index;
            }
        }
        extract_min(key);
    }

    for(int i=0;i<5;i++)
    {
        printf("%d->%d\n",i,parent[i]);
    }
}