#include<iostream>
#include<fstream>
#include<queue>

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


//===================================================================

bool isConnect(Graph &g, int u, int v)
{
    return (g.adjMatrix[u][v] == 1);
}
void BFS_VISIT(Graph &g, int &u, int &t, int d[], int p[], int color[])
{
    color[u] = 1;//GRAY
    d[u] = 0;
    queue<int> Q;
    Q.push(u);
    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();
         cout << u << " ";
        for(int i=0; i<g.numV; i++)
        {

            if(color[i] == 0 && isConnect(g,u,i))
            {
                color[i] = 1;//GRAY
                d[i] = d[u]+1;
                p[i] = u;
                Q.push(i);
            }
        }
        color[u] = 2;
    }
}

void BFS(Graph &g, int &t, int d[], int p[], int color[])
{
    for(int u=0; u<g.numV; u++)
    {
        color[u] = 0;
        d[u] = -1;
        p[u] = -1;
    }
    for(int u=0; u<g.numV; u++)
    {
        if(color[u] == 0)
        {

            BFS_VISIT(g,u,t,d,p,color);
        }
    }
}
void showBFS(Graph g, int d[])
{
    cout << endl;
    for(int u=0; u<g.numV; u++)
    {
        cout << "\n" << u << ": " << d[u];
    }
}

int main()
{
    ifstream ifFile("BFS.IN");
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
    int d[g.numV]; // d la thoi diem bat dau tham
    int p[g.numV]; // f la thoi diem ket thuc tham
    int color[g.numV]; // mau cua cac  dinh 0-trang, 1 xam 2 den
    int t = 0; //
    BFS(g,t,d,p,color);
    showBFS(g,d);
    return 0;
}
