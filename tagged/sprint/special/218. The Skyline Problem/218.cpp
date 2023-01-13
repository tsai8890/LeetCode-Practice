#include <set>
#include <vector>
using namespace std;

class Event {
public:
    int x;
    int h;
    int type; // 0: begin, 1: end
    
    Event(int x, int h, int type) {
        this->x = x;
        this->h = h;
        this->type = type;
    }
    
    bool operator<(const Event& e) {
        if (this->x != e.x) {
            return (this->x < e.x);
        }
        
        if (this->type != e.type) {
            return (this->type == 0);
        }
        else {
            return (this->type == 1) ? (this->h < e.h) : (this->h > e.h);
        }        
    }
};

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int n = buildings.size();
        vector<Event> events;
        for (int i = 0; i < n; i ++) {
            int left = buildings[i][0];
            int right = buildings[i][1];
            int h = buildings[i][2];
            events.push_back(Event(left, h, 0));
            events.push_back(Event(right, h, 1));
        }
        sort(events.begin(), events.end());

        vector<vector<int>> res;
        multiset<int, greater<int>> rbTree;
        n *= 2;
        for (int i = 0; i < n; i ++) {
            if (events[i].type == 0) {
                if (rbTree.empty() || events[i].h > *(rbTree.begin())) {
                    res.push_back(vector<int>{events[i].x, events[i].h});
                }
                rbTree.insert(events[i].h);
            }
            else {
                rbTree.erase(rbTree.find(events[i].h));
                if (rbTree.empty()) {
                    res.push_back(vector<int>{events[i].x, 0});
                }
                else if (events[i].h > *(rbTree.begin())) {
                    res.push_back(vector<int>{events[i].x, *(rbTree.begin())});
                }
            }
        }
        return res;
    }
};
