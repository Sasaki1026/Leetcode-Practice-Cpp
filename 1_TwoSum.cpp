/*
有暴力解和壓時間複雜度的解法
*/

/*
暴力解，T(n) = O(n**2), S(n) = O(1)
直接跑兩個迴圈

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                if(nums[i] + nums[j] == target){
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        }
        return ans;
    }
};
*/

/*
用map解，T(n) = O(n), S(n) = O(n)
遍歷過的元素全部塞進map裡
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            int t = target - nums[i];
            if (map.find(t) != map.end()) { //map裡沒有
                return { map[t], i };
            }
            map[nums[i]] = i;               //把現在這元素塞進map
        }
        return {NULL, NULL}; // or return {};
    }
};