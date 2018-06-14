class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int j=0;
		int sum=0;
		int total=0;
		for(int i=0;i<gas.size();i++){
			
			sum+=gas[i]-cost[i];
			total+=gas[i]-cost[i]; //累加用于计算是否所有油都不够跑 否则该问题必然有解
			if(sum<0){ //当前两个节点之间不够 从下一个重新开始
				sum=0;
				j=i+1;
			}
		}
		if(total<0) return -1;
		return j;
    }
};// O(N)