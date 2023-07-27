class TimeMap {
public:
    
    unordered_map<string,vector<pair<int,string>>> m;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        
        m[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        
        int n=m[key].size();
        int low=0;
        int high=n-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(m[key][mid].first==timestamp)
            {
                return m[key][mid].second;
            }
            else if(m[key][mid].first<timestamp)
            {
                if(mid==high || m[key][mid+1].first>timestamp)
                {
                    return m[key][mid].second;
                }
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */