class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int ans = 0;
        map<vector<int>,int> mp;
        for(auto &row : grid){
            mp[row]++;
        }

        vector<int> col ;
        for(int i = 0 ;i<grid[0].size();i++){
            col.clear();
            for(int j= 0 ;j<grid.size();j++){
                col.push_back(grid[j][i]);
            };
            ans += mp[col];
        }
        return ans;
        
    }
};