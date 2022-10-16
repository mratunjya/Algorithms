#include<stdio.h>
#include<math.h>
#include<limits.h>

int heapsize = -1;

struct vertex{
    int d;
    struct vertex *parent;
    int flag;
    int index;
};

void min_heapify(struct vertex ver[], int i)
{
    int smallest;
    int l = (2*i)+1;
    int r = (2*i)+2;

    // ver[i].flag = 1;
    
    if(l<=heapsize && ver[l].d < ver[i].d)
        smallest = l;
    else    
        smallest = i;
    
    if(r<=heapsize && ver[r].d < ver[smallest].d)
        smallest = r;
    
    if(smallest != i)
    {
        struct vertex temp = ver[i];
        ver[i] = ver[smallest];
        ver[smallest] = temp;
        // if(ver[smallest].flag == 0)
        min_heapify(ver,smallest);
    }
}

void build_minHeap(struct vertex ver[], int v)
{
    heapsize = v;
    for(int i=floor(v/2);i<heapsize;i++)
    {
        ver[i].flag = 1;
    }
}

struct vertex extract_min(struct vertex ver[])
{
    if(heapsize < 1)
    {
        printf("Heap Underflow");
    }    

    struct vertex min = ver[0];
    ver[0] = ver[heapsize];
    heapsize--;
    min_heapify(ver,0);
    return min;
}
void initializeSequence(struct vertex ver[])
{
    for(int i=0;i<heapsize;i++)
    {
        ver[i].d = INT_MAX;
        ver[i].parent = NULL;
        ver[i].flag = 0;
    }
    ver[0].d = 0;
    ver[0].flag = 1;
    ver[1].d = 5;
    ver[1].flag = 1;
    ver[2].d = 10;
    ver[2].flag = 1;
}

void relax(struct vertex u,struct vertex v,int w)
{
    if(v.d>(u.d+w))
    {
        v.d = u.d + w;
        v.parent = &u;
    }
}
int main()
{
    int v = 5, e = 10;

    struct vertex ver[v];

    int edges[5][5] = {{-1,10,5,-1,-1}
                    ,{-1,-1,2,1,-1}
                    ,{-1,3,-1,9,2}
                    ,{-1,-1,-1,4}
                    ,{7,-1,-1,6,-1}};

    //Dijkstra Algorithm

    heapsize = v;
    initializeSequence(ver);

    // build_minHeap(ver,v);

    while(heapsize>0)
    {
        struct vertex u = extract_min(ver);

        for(int i=0;i<v;i++)
        {
            if(edges[u.index][i] > -1)
            {
                relax(u,ver[i],edges[u.index][i]);
            }
        }
    }

    for(int i=0;i<v;i++)
    {
        printf("%d --> %d\n",i,ver[i].d);
    }

}
