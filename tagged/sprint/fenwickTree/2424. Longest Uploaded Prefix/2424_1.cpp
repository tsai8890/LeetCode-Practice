#include <vector>
using namespace std;

class LUPrefix {
public:
    LUPrefix(int n) {
        videos = vector<bool>(n+1, false);
        notUpload = 1;
    }
    
    void upload(int video) {
        videos[video] = true;
    }
    
    int longest() {
        while (notUpload <= videos.size() && videos[notUpload]) {
            notUpload ++;
        }
        return notUpload - 1;
    }

private:
    vector<bool> videos;
    int notUpload;
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */