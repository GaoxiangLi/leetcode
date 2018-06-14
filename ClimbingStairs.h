int climbStairsRecur(int n) {  
        if (n == 1) return 1;  
        if (n == 2) return 2;  
        return climbStairsRecur(n-1) + climbStairsRecur(n-2);  
    }  
	//递归 但是太慢 每一层执行运算重复 效率低
	//动态规划 每一层只计算一次
	int climbStairs(int n)  
    {  
        vector<int> res(n+1);  
        res[0] = 1;  
        res[1] = 1;  
        for (int i = 2; i <= n; i++)  
        {  
            res[i] = res[i-1] + res[i-2];  
        }  
        return res[n];  
    }  