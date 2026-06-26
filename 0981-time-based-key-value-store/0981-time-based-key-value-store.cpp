class TimeMap {
private:
    unordered_map<string, vector<pair<int,string>>>store;
public:
    TimeMap() {
 
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(store.find(key) == store.end()) return "";

        vector<pair<int,string>>&values = store[key];

        int left = 0;
        int right = values.size()-1;
        string answer = "";

        while(left <= right){
            int mid = left + (right-left)/2;

            if(values[mid].first <= timestamp){
                answer = values[mid].second;
                left = mid+1;
            } else{
                right = mid-1;
            }
        }
        return answer;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */