bool numLess(const pair<int, int>& left, const pair<int, int> &right) {
    if (left.first == right.first) {    
        return true;
    } 
    return left.first < right.first;
}


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> mapNums;
        vector<int>indices;
        int begin = -1, end = -1;
     
        for (int i = 0; i < nums.size(); i++) {
            mapNums.push_back(make_pair(nums[i], i));
        }
        
        sort(mapNums.begin(), mapNums.end(), numLess);
        
        begin = 0;
        end = mapNums.size() - 1;
     
        while (begin < end) {
            if (mapNums[begin].first + mapNums[end].first == target) {
                indices.push_back(mapNums[begin].second);
                indices.push_back(mapNums[end].second);
                break;
            } else if (mapNums[begin].first + mapNums[end].first < target) {
                begin++;
                
            } else if (mapNums[begin].first + mapNums[end].first > target) {
                end--;
            }
        }
        return indices;
    }
};