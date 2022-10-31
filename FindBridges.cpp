// A C# program to find bridges in a given undirected graph
using System;
using System.Collections.Generic;

public class Graph
{
	private int V; 
    private List<int> []adj;
	int time = 0;
	static readonly int NIL = -1;

	Graph(int v)
	{
		V = v;
		adj = new List<int>[v];
		for (int i = 0; i < v; ++i)
			adj[i] = new List<int>();
	}

	void addEdge(int v, int w)
	{
		adj[v].Add(w); // Add w to v's list.
		adj[w].Add(v); //Add v to w's list
	}


	void bridgeUtil(int u, bool []visited, int []disc,
					int []low, int []parent)
	{

		visited[u] = true;

		disc[u] = low[u] = ++time;

		foreach(int i in adj[u])
		{
			int v = i; // v is current adjacent of u

			if (!visited[v])
			{
				parent[v] = u;
				bridgeUtil(v, visited, disc, low, parent);

				low[u] = Math.Min(low[u], low[v]);

				if (low[v] > disc[u])
					Console.WriteLine(u + " " + v);
			}

			else if (v != parent[u])
				low[u] = Math.Min(low[u], disc[v]);
		}
	}


	void bridge()
	{
		bool []visited = new bool[V];
		int []disc = new int[V];
		int []low = new int[V];
		int []parent = new int[V];


		for (int i = 0; i < V; i++)
		{
			parent[i] = NIL;
			visited[i] = false;
		}

		for (int i = 0; i < V; i++)
			if (visited[i] == false)
				bridgeUtil(i, visited, disc, low, parent);
	}


	public static void Main(String []args)
	{
		Console.WriteLine("Bridges in first graph ");
		Graph g1 = new Graph(5);
		g1.addEdge(1, 0);
		g1.addEdge(0, 2);
		g1.addEdge(2, 1);
		g1.addEdge(0, 3);
		g1.addEdge(3, 4);
		g1.bridge();
		Console.WriteLine();

		Console.WriteLine("Bridges in Second graph");
		Graph g2 = new Graph(4);
		g2.addEdge(0, 1);
		g2.addEdge(1, 2);
		g2.addEdge(2, 3);
		g2.bridge();
		Console.WriteLine();

		Console.WriteLine("Bridges in Third graph ");
		Graph g3 = new Graph(7);
		g3.addEdge(0, 1);
		g3.addEdge(1, 2);
		g3.addEdge(2, 0);
		g3.addEdge(1, 3);
		g3.addEdge(1, 4);
		g3.addEdge(1, 6);
		g3.addEdge(3, 5);
		g3.addEdge(4, 5);
		g3.bridge();
	}
}

