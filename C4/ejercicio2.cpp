class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> mayor(n,0);
        stack<int> day;
        for(int i = 0; i < n; ++i){
            while (!day.empty() && temperatures[day.top()] < temperatures[i]){
                int previo = day.top();
                day.pop();
                mayor[previo] = i - previo;
                }
            day.push(i);
        }
        return mayor;
    }
};