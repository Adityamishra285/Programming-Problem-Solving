// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//PRIM'S Algo
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    // Weighted Graph it is
    // [a,a,a,a,a]
    // [[wt,wt], [wt,wt].....]
    {
        // code here
        // min heap(PQ) agar pair hai to <int,int>, first int ke hisab se max ya min nikalta. 
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        //Store node and wt
        
        vector<int> key(V,INT_MAX);
        vector<int> mst(V,false);
        vector<int> parent(V,-1);
        int sum = 0;
        key[0] = 0;
        
        pq.push({0,0});
        
        while(!pq.empty()){
            int node = pq.top().second;
            pq.pop();
            mst[node] = true;
            // sum = sum + key[node];
            for(auto it: adj[node]){
                int adjNode = it[0];
                int wt = it[1];
                if(mst[adjNode]==false && key[adjNode]>wt){
                    parent[adjNode] = node;
                    key[adjNode] = wt;
                    pq.push({key[adjNode], adjNode});
                }
            }
        }
        for(int i=0;i<V;i++ )
      {
          
          if(key[i]!=INT_MAX)
          sum=sum+key[i];
          
      }
        return sum;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends