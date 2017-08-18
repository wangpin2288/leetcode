class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> record;
        for(int i=0;i<nums.size();i++){
            if(record.find(target-nums[i]) != record.end()) return vector<int>{i,record[target-nums[i]]};
            else record[nums[i]] = i;
        }
    }
};
