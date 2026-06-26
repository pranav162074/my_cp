class Solution {
public:
    vector<int> generaterow(int rowno) {
        int ans=1;
        vector<int> row;
        row.push_back(1);
        for (int col=1; col<rowno; col++) {
            ans *= (rowno-col);
            ans = ans/col;
            row.push_back(ans);
        }
        return row;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int i=1; i<=numRows; i++) {
            ans.push_back(generaterow(i));
        }
        return ans;
    }
};
