#include <vector>
#include <utility>
using namespace std;

class SnapshotArray {
    /*
        Title: 1146. Snapshot Array
        Time Complexity:
            1. set(): O(1)-time
            2. snap(): O(1)-time
            3. get(): O(logN)-time, where N is the times calling snap()

        Algorithm: 
            1. Binary Search

        Note:
            1. 這題和 981. Time Based Key-Value Store 很像，
               都是先存index_key，然後每個index後面接著一系列依timestamp排序
               的value。在搜尋特定key的時候使用二分搜尋可以大大加快速度。

            2. snapshots只存有改動過的，可以大幅減少使用的記憶體空間。

            3. 題目敘述
                Your SnapshotArray object will be instantiated and called as such:
                SnapshotArray* obj = new SnapshotArray(length);
                obj->set(index,val);
                int param_2 = obj->snap();
                int param_3 = obj->get(index,snap_id);
                
        Date: 12/16/2021 18:16					
        Time: 192ms  -- beat 89.32%
        Memory: 98.3 MB  -- beat 48.18%
    */

public:
    SnapshotArray(int length) {
        for (int i = 0; i < length; i ++) {
            pair<int, int> initial = make_pair(0, 0);
            snapshots.push_back(vector<pair<int,int>>(1, initial));
        }
        n_snapshots = 0;
    }
    
    void set(int index, int val) {
        int last = snapshots[index].size() - 1;

        if (val == snapshots[index][last].first)
            return;
        
        if (snapshots[index][last].second < n_snapshots) {
            snapshots[index].push_back(make_pair(val, n_snapshots));
        } else {
            snapshots[index][last].first = val;
        }
    }
    
    int snap() {
        return n_snapshots++;
    }
    
    int get(int index, int snap_id) {
        int left = 0, right = snapshots[index].size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            
            if (snap_id < snapshots[index][mid].second) {
                right = mid - 1;
            } else if (snap_id > snapshots[index][mid].second) {
                left = mid + 1;                
            } else {
                return snapshots[index][mid].first;
            }
        }
        return snapshots[index][right].first;
    }
    
private:
    int n_snapshots;
    vector<vector<pair<int, int>>> snapshots;
};

