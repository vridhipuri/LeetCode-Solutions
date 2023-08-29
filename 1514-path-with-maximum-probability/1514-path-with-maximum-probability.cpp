class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        
        unordered_map<int,vector<pair<int,double>>>adj;
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            double prob=succProb[i];
            adj[u].push_back({v,prob});
            adj[v].push_back({u,prob});
        }
        vector<double>res(n,0.0);

        priority_queue<pair<double,int>>pq;

        res[start_node]=1.0;
        pq.push({1.0,start_node});

        while(!pq.empty())
        {
            int topnode=pq.top().second;
            double topprob=pq.top().first;
            pq.pop();

            for(auto temp:adj[topnode])
            {
                double currprob=temp.second;
                int adjnode=temp.first;

                if(currprob*topprob>res[adjnode])
                {
                    res[adjnode]=currprob*topprob;
                    pq.push({res[adjnode],adjnode});
                }

            }
        }
        return res[end_node];
    }
};