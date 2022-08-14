#include <string>
#include <vector>
#include <utility>
#include <unordered_map>
using namespace std;

class TimeMap {
    /*
        Title: 981. Time Based Key-Value Store
        Time Complexity:
            1. set(): O(1)-time
            2. get(): O(logN)-time
            3. query times: 2*10^5

        Algorithm: 
            1. Hashmap(STL unordered_map)
            2. Binary Search

        Date: 12/16/2021 01:15				
        Time: 300ms  -- beat 59.19%
        Memory: 128.2 MB  -- beat 68.50%
    */
public:
    TimeMap() {
        hashmap.clear();            
    }
    
    void set(string key, string value, int timestamp) {
        hashmap[key].push_back(make_pair(value, timestamp));
    }
    
    string get(string key, int timestamp) {
        if (hashmap.count(key) == 0) {
            return "";
            
        } else {
            if (timestamp < hashmap[key][0].second)
                return "";
            
            int left = 0, right = hashmap[key].size() - 1;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (hashmap[key][mid].second < timestamp) {
                    left = mid + 1;
                } else if (hashmap[key][mid].second > timestamp) {
                    right = mid - 1;
                } else {
                    return hashmap[key][mid].first;
                }
            }
            return hashmap[key][right].first;
        }
    }
    
private:
    unordered_map<string, vector<pair<string, int>>> hashmap;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */