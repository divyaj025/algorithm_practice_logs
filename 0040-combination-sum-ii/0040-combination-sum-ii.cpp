class Solution {
public:
    void help(vector<int>& candidates, int target, int index, vector<vector<int>>& ans, vector<int>& res) {
    if (target == 0) {
        ans.push_back(res);
        return;
    }
    for (int i = index; i < candidates.size(); i++) {
        if (i > index && candidates[i] == candidates[i-1]) continue; // Skip duplicates.
        if (candidates[i] > target) break; // No need to continue if the current number exceeds the target.

        res.push_back(candidates[i]);
        help(candidates, target - candidates[i], i + 1, ans, res); // Only use each element once.
        res.pop_back();
    }
}
   vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> res;
    sort(candidates.begin(), candidates.end()); // Sort to handle duplicates and make the breaking condition effective.
    help(candidates, target, 0, ans, res);
    return ans;
}
};