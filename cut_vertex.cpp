#include<iostream>
#include <list>

#define NIL -1

using namespace std;

class GraphEx
{
  int Ver;
    list < int >*adj;
  void cut_vertices_helper (int v, bool visited[], int disc[], int low[],
	       int parent[], bool cut_vertices[]);
public:
    GraphEx (int Ver);
  void add_edge (int v, int w);
  void find_cut_vertices ();
};

GraphEx::GraphEx (int Ver)
{
  this->Ver = Ver;
  adj = new list < int >[Ver];
}

void
GraphEx::add_edge (int v, int w)
{
  adj[v].push_back (w);
  adj[w].push_back (v);
}

void
GraphEx::cut_vertices_helper (int u, bool visited[], int disc[],
		 int low[], int parent[], bool cut_vertices[])
{

  static int time = 0;

  int children = 0;

  visited[u] = true;

  disc[u] = low[u] = ++time;

  list < int >::iterator i;
  for (i = adj[u].begin (); i != adj[u].end (); ++i)
    {
      int v = *i;
      if (!visited[v])
	{
	  children++;
	  parent[v] = u;
	  cut_vertices_helper (v, visited, disc, low, parent, cut_vertices);

	  low[u] = min (low[u], low[v]);

	  if (parent[u] == NIL && children > 1)
	    cut_vertices[u] = true;

	  if (parent[u] != NIL && low[v] >= disc[u])
	    cut_vertices[u] = true;
	}
      else if (v != parent[u])
	low[u] = min (low[u], disc[v]);
    }
}

void
GraphEx::find_cut_vertices ()
{
  bool *visited = new bool[Ver];
  int *disc = new int[Ver];
  int *low = new int[Ver];
  int *parent = new int[Ver];
  bool *cut_vertices = new bool[Ver];

  for (int i = 0; i < Ver; i++)
    {
      parent[i] = NIL;
      visited[i] = false;
      cut_vertices[i] = false;
    }

  for (int i = 0; i < Ver; i++)
    if (visited[i] == false)
      cut_vertices_helper (i, visited, disc, low, parent, cut_vertices);

  for (int i = 0; i < Ver; i++)
    if (cut_vertices[i] == true)
      cout << i << " ";
  cout << endl << endl;
}

int
main ()
{


  cout << "        (1)          \n";
  cout << "       / | \\        \n";
  cout << "      /  |  \\       \n";
  cout << "     /   |   \\      \n";
  cout << "    /    |    (3)    \n";
  cout << "  (0)    |   /  |    \n";
  cout << "  |      |  /   |    \n";
  cout << "  |      | /    |    \n";
  cout << " (5)    (2)----(4)   \n";
  cout << "                     \n";

  cout << "\n--------------------------------------------------\n";

  cout << "\ncut vertices in the above given  graph using DFS are : ";
  int V = 6;
  GraphEx g2 (V);
  g2.add_edge (0, 5);
  g2.add_edge (0, 1);
  g2.add_edge (1, 2);
  g2.add_edge (1, 3);
  g2.add_edge (2, 3);
  g2.add_edge (2, 4);
  g2.add_edge (3, 4);
  g2.find_cut_vertices ();

  return 0;
}
