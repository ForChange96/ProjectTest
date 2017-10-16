#include<iostream>
#include<fstream>
using namespace std;
struct Graph
{
    int numV;
    int **adjMatrix;
};
Graph newGraph(int num)
{
    Graph g;
    g.numV = num;
    //tao ra cac dong
    g.adjMatrix = new int *[g.numV];
    for(int i=0; i<g.numV; i++)
    {
        g.adjMatrix[i] = new int[g.numV];
    }
    //mac dinh giua 2 dinh k noi voi nhau
    for(int i=0; i<g.numV; i++)
    {
        for(int j=0; j<g.numV; j++)
        {
            g.adjMatrix[i][j] = 0;
        }
    }
    return g;
}
//
void addEdge(Graph &g, int u, int v, bool isDerect)
{
    g.adjMatrix[u][v] = 1;
    if(!isDerect)
    {
        g.adjMatrix[v][u] = 1;
    }
}

void show(Graph g)
{

    for(int i=0; i<g.numV; i++)
    {
        for(int j=0; j<g.numV; j++)
        {
            cout << g.adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isConnect(Graph &g, int u, int v)
{
    return (g.adjMatrix[u][v] == 1);
}
void DFS_VISIT(Graph &g, int u, int &t, int d[], int f[], int color[])
{
    t++;
    d[u] = t;
    color[u] = 1;//GRAY
    cout << u << " ";
    for(int v=0; v<g.numV; v++)
    {
        if(color[v]==0 && isConnect(g,u,v))
        {
            DFS_VISIT(g,v,t,d,f,color);
        }
    }
    color[u] = 2;
    t++;
    f[u] = t;
}
void DFS(Graph &g, int &t, int d[], int f[], int color[])
{
    cout << endl;
    for(int u=0; u<g.numV; u++)
    {
        color[u] = 0;
    }
    t=0;
    for(int u=0; u<g.numV; u++)
    {

        if(color[u] == 0)
        {
            DFS_VISIT(g,u,t,d,f,color);
        }
    }
}
void showDFS(Graph g, int d[], int f[])
{
    cout << endl;
    for(int u=0; u<g.numV; u++)
    {
        cout << "\n" << u << ": " << d[u] << " " << f[u];
    }
}

int main()
{

    ifstream ifFile("DFS.IN");
    int m,n;
    Graph g;
    int isDerect;
    if(!ifFile.is_open())
    {
        cout << "\nKhong the mo File\n";
        return 0;
    }
    else
    {
        ifFile >> isDerect;
        //cout <<"\nisDerect: " <<isDerect;
        ifFile >> n;
        //cout << "\nn = " << n;
        ifFile >> m;
        //cout << "\nm = " << m;
        g= newGraph(n);
        for(int i=0; i<m; i++)
        {
            int u, v;
            ifFile >> u;
            ifFile >> v;
            addEdge(g,u,v,isDerect);
        }
        ifFile.close();
    }
    //show(g);
    int d[g.numV];
    int f[g.numV];
    int color[g.numV];
    int t = 0;
    DFS(g,t,d,f,color);
    showDFS(g,d,f);

    return 0;
}
