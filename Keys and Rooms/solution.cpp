class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int>bfs;
        set<int>visited;
        bfs.push(0);
        while(!bfs.empty()) {
            int currRoom = bfs.front();
            if (visited.find(currRoom) == visited.end()) {
                for (int i = 0; i<rooms[currRoom].size(); i++) {
                    bfs.push(rooms[currRoom][i]);
                }
                visited.insert(currRoom);
            }
            bfs.pop();
        }
        cout << visited.size() << endl;
        cout << rooms.size() << endl;
        return visited.size() == rooms.size();
    }
};