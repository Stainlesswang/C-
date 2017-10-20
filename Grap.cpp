//
// Created by stanwang on 2017/9/19.
//

/*图的存储及遍历*/
#include<iostream>
using namespace std;
//-----------------------------------  
//邻接矩阵的存储及深度和广度遍历  
//-----------------------------------  

/*邻接矩阵的类型定义*/
#define MAX 10000000
#define MAX_VERTEX_NUM 20
typedef enum{ DG,DN,UDG,UDN }GraphKind;//有向图，有向网，无向图，无向网  
typedef struct
{
    char vexs[MAX_VERTEX_NUM];//用一维数组存储顶点信息  
    int edges[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//用二维数组充当矩阵，来存储顶点边的信息  
    int vexnum,edgenum;//顶点树和边数  
    GraphKind kind;//图的种类  
}MGraph;

/*构造无向图的邻接矩阵*/
void CreateUDG_AM(MGraph &G,int n,int e)
{
    G.vexnum=n;
    G.edgenum=e;

    int i,j,k;
    for(i=0;i<n;i++)
        cin>>G.vexs[i];//输入顶点信息  

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            G.edges[i][j]=0;//将矩阵初始化为0  

    for(k=0;k<e;k++)
    {
        cin>>i>>j;//这里只用输入对称的边就行，也就是输入下矩阵或是上矩阵  
        G.edges[i][j]=G.edges[j][i]=1;//输入边的信息  
    }
}

/****************************无向图的深度优先遍历************************/
int visited[MAX_VERTEX_NUM];

void DF_AM(MGraph &G,int i)
{
    int j;
    cout<<G.vexs[i]<<" ";
    visited[i]=1;
    for(j=0;j<G.vexnum;j++)
    {
        if((G.edges[i][j])==1&&(visited[j])==0)
            DF_AM(G,j);
    }
}

void DF_Traverse_AM(MGraph &G)
{
    int i;
    for(i=0;i<G.vexnum;i++)
    {
        visited[i]=0;
    }
    for(i=0;i<G.vexnum;i++)
    {
        if(!visited[i])
            DF_AM(G,i);
    }
}

/*********************无向图的广度优先遍历*****************************/

//循环队列的类型定义  
const int Queue_Size=100;

typedef struct circlQueue
{
    int *elem;
    int rear;
    int front;
    int queueSize;
}circlQueue;

//初始化  
void initQueue_C(circlQueue &Q)
{
    Q.elem=new int[Queue_Size];
    Q.front=Q.rear=0;//首尾指针相等说明队列为空。  
    Q.queueSize=Queue_Size;
}

//入队列  
void enterQueue_C(circlQueue &Q,int x)
{
    if(((Q.rear+1)%Q.queueSize)==Q.front)//判断栈满的情况  
        cout<<"Queue OverFlow!";
    Q.elem[Q.rear]=x;
    Q.rear=(Q.rear+1)%Queue_Size;//尾指针应以此种方式加1，才会实现循环队列。  
}

//出队列  
char outputQueue_C(circlQueue &Q)
{
    int e;
    if(Q.rear==Q.front)
        cout<<"Queue Empty";
    e=Q.elem[Q.front];
    Q.front=(Q.front+1)%Q.queueSize;;//头指针应以此种方式加1，才会实现循环队列。  
    return e;
}
//广度遍历  
void BF_Traverse_AM(MGraph &G)
{
    int i,j,v;
    for(i=0;i<G.vexnum;i++)
        visited[i]=0;
    circlQueue Q;
    initQueue_C(Q);//队列实现了“先被访问的顶点的邻接点”先于“后被访问的顶点的邻接点”被访问  
    for(i=0;i<G.vexnum;i++)
    {
        if(!visited[i])
        {
            cout<<G.vexs[i]<<" ";
            visited[i]=1;
            enterQueue_C(Q,i);
            while(Q.front!=Q.rear)
            {//这个循环是将队列里面的顶点取出来，然后进行下面的for循环  
                v=outputQueue_C(Q);
                for(j=0;j<G.vexnum;j++)
                {//这个循环是将顶点的全部邻接点依次访问并且入队列  
                    if(G.edges[v][j]&&(!visited[j]))
                    {
                        cout<<G.vexs[j]<<" ";
                        visited[j]=1;
                        enterQueue_C(Q,j);
                    }
                }
            }
        }
    }
}

//-----------------------------------------------  
//邻接表的存储及深度和广度遍历  
//-----------------------------------------------  
typedef struct EdgeNode
{//边表结点的定义  
    int adjvex;//存放邻接点在顶点表中的位置  
    struct EdgeNode * nextedge;//指向下一个边表结点  
    int weight;
}EdgeNode;

typedef struct VexNode
{//顶点表结点的定义  
    char vex;//存放顶点信息  
    EdgeNode * firstedge;//指向第一个边表结点  
}VexNode;

typedef struct
{//顶点表的定义    
    VexNode vexs[MAX_VERTEX_NUM];
    int vexnum,edgenum;
    GraphKind kind;
}LGraph;

/*构造有向图的邻接表*/
void CreateDG_AL(LGraph &G,int n,int e)
{
    int i,j,k;
    G.vexnum=n;
    G.edgenum=e;
    G.kind=DG;
    for(i=0;i<n;i++)
    {
        cin>>G.vexs[i].vex;
        G.vexs[i].firstedge=NULL;//初始化为空  
    }
    for(k=0;k<e;k++)
    {
        EdgeNode *p;
        cin>>i>>j;
        p=new EdgeNode;
        p->adjvex=j;
        p->nextedge=G.vexs[i].firstedge;
        G.vexs[i].firstedge=p;//采用头插法  
    }
}

/*********************有向图的深度优先遍历**************************/
void DF_AL(LGraph &G,int v)
{
    int j;
    EdgeNode *p;
    cout<<G.vexs[v].vex<<" ";
    visited[v]=1;
    for(p=G.vexs[v].firstedge;p;p=p->nextedge)
    {
        j=p->adjvex;
        if(!visited[j])
            DF_AL(G,j);
    }
}

void DF_Traverse_AL(LGraph &G)
{
    int i;
    for(i=0;i<G.vexnum;i++)
    {
        visited[i]=0;
    }
    for(i=0;i<G.vexnum;i++)
    {
        if(!visited[i])
            DF_AL(G,i);
    }
}  /* 何问起 hovertree.com */
/*********************有向图的广度优先遍历**************************/
void BF_Traverse_AL(LGraph &G)
{
    int i,j,v;
    EdgeNode *p;
    for(i=0;i<G.vexnum;i++)
        visited[i]=0;
    circlQueue Q;
    initQueue_C(Q);//队列实现了“先被访问的顶点的邻接点”先于“后被访问的顶点的邻接点”被访问  
    for(i=0;i<G.vexnum;i++)
    {
        if(!visited[i])
        {
            cout<<G.vexs[i].vex<<" ";
            visited[i]=1;
            enterQueue_C(Q,i);
            while(Q.front!=Q.rear)
            {//这个循环是将队列里面的顶点取出来，然后进行下面的for循环  
                v=outputQueue_C(Q);
                for(p=G.vexs[v].firstedge;p;p=p->nextedge)
                {//这个循环是将顶点的全部邻接点依次访问并且入队列  
                    j=p->adjvex;
                    if(!visited[j])
                    {
                        cout<<G.vexs[j].vex<<" ";
                        visited[j]=1;
                        enterQueue_C(Q,j);
                    }
                }
            }
        }
    }
}
//void main()
//{
//    /*MGraph G;
//    CreateUDG_AM(G,6,6);
//    DF_Traverse_AM(G);
//    cout<<endl;
//    BF_Traverse_AM(G);*/
//
//    LGraph G;
//    CreateDG_AL(G,5,7);
//    DF_Traverse_AL(G);
//    cout<<endl;
//    BF_Traverse_AL(G);
//}