class Solution {
public:

    void dfs(string src, string dest,unordered_map<string,vector<pair<string,double>>>& adj,unordered_set<string>& visited,double prod, double& ans)
    {
        if(visited.find(src)!=visited.end())
        {
            return;
        }
        visited.insert(src);
        if(src==dest)
        {
            ans=prod;
            return;
        }
        for(auto node:adj[src])
        {
            string adjnode=node.first;
            double currprod=node.second;
            dfs(adjnode,dest,adj,visited,prod*currprod,ans);
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        unordered_map<string,vector<pair<string,double>>>adj;
        for(int i=0;i<equations.size();i++)
        {
            string u=equations[i][0];
            string v=equations[i][1];
            double val=values[i];

            adj[u].push_back({v,val});
            adj[v].push_back({u,1.0/val});

        }

        vector<double>res;

        for(auto query:queries)
        {
            string src=query[0];
            string dest=query[1];

            double ans=-1.0;
            double prod=1.0;

            if(adj.find(src)!=adj.end())
            {
                unordered_set<string>visited;
                dfs(src,dest,adj,visited,prod,ans);
            }
            res.push_back(ans);
        }
        return res;
    }
};