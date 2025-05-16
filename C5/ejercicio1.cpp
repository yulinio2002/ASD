class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> elementos;
        for(const auto& item : nums){
            if(elementos.count(item)){
                return true;
            }
            elementos.insert(item);
        } 
        return false;
    }
};