#include <vector>
#include <unordered_map>
using namespace std;

class TopVotedCandidate {
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        this->times = times;

        unordered_map<int,int> votes;
        int lead = -1;
        for (int i = 0; i < persons.size(); i ++) {
            votes[persons[i]] ++;
            if (lead == -1 || votes[persons[i]] >= votes[lead]) {
                lead = persons[i];
            }
            leads.push_back(lead);
        }
    }
    
    int q(int t) {
        if (t >= times.back()) {
            return leads.back();
        }
        
        int l = 0, r = times.size()-1;
        while (l < r-1) {
            int mid = (l+r)/2;
            if (times[mid] >= t) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
        return (times[r] == t) ? leads[r] : leads[l];
    }

private:
    vector<int> leads;
    vector<int> times;
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */