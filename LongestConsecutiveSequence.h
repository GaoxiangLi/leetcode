// Leet Code, Longest Consecutive Sequence
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
using namespace std;
class solution{
	public:  
    int longestConsecutive(vector<int>& nums) {  
        unordered_map<int, bool> hash;  
        for(auto val: nums) hash[val] = true;  
        int Max = 0;  
        for(auto val: nums)  
        {  
            int len = 1, tem = val+1;  
            while(hash.count(tem))  
            {  
                hash.erase(tem);  
                len++, tem++;  
            }  
            tem = val-1;  
            while(hash.count(tem))  
            {  
                hash.erase(tem);  
                len++, tem--;  
            }  
            Max = max(len, Max);  
        }  
        return Max;  
    }  
	
};