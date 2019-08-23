// Kruskal算法生成最小生成树
void MiniSpanTree_Kruskal(MGraph G)
{
    Edge edge[MAXEDGE];  // 定义边集数组
    AdjmatToEdgeArray(G, edge);  // 该函数将邻接矩阵转化为边集数组并按权重由下到大排列
    
    int parent[MAXVEX] = {0}; // 用来边与边是否形成环路
    
    int i, j;
    for (i = 0; i < G.numEdges; i++)
    {
        n = Find(parent, edge[i].begin);
        m = Find(parent, edge[i].end);
        
        if (n != m)
        {
            parent[n] = m; // 将这条边的结尾顶点放入下标为起点的parent数组中，表示此顶点已经在生成树集合中
            printf("(%d, %d)--%d  ", edge[i].begin, edge[i].end, edge[i].weight);
        }
    }
}

int Find(int *parent, int f)
{
    while (parent[f] > 0 )
        f = parent[f];
    
    return f;
}
