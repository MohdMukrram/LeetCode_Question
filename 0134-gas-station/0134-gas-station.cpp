class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totalgas = accumulate(gas.begin(), gas.end(), 0);
        int totalcost = accumulate(cost.begin(), cost.end(), 0);
        if(totalgas < totalcost) return -1;

        int idx = 0;
        int total = 0;
        for(int i=0;i<n;i++){
            total += gas[i] - cost[i];
            if(total < 0){
                idx = i+1;
                total = 0;
            } 
        }
        return idx;
    }
};