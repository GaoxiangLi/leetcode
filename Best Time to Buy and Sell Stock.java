class Solution1 {
    public int maxProfit1(int[] prices) {//只能买入一次
        int length=prices.length;
        if (length==0||length==1) {
			return 0;
		}
       
        int res=prices[1]-prices[0];
        int minprice=prices[0];
        for (int i = 2; i < length; i++) {
			minprice=Math.min(minprice, prices[i-1]);//i前一个i-1，i不能算进买入
			res=Math.max(res, prices[i]-minprice);
		}
        if (res<0) {
			return 0;
		}
        return res;
    }
}
class Solution2 {
    public int maxProfit2(int[] prices) {//可多次买入
    	int res=0;
    	int length=prices.length;
    	if (length<=1) {
			return res;
		}
        for (int i = 1; i < prices.length; i++) {
			if (prices[i]>prices[i-1]) {
				res+=prices[i]-prices[i-1];
			}
		}
        return res;
    }
}
class Solution3 {
    public int maxProfit3(int[] prices) {//只允许交易两次 和solution1思路类似 把数组分成两部分
        int length=prices.length;
        if (length==0||length==1) {
			return 0;
		}
        int res=0;
       for (int i = 2; i < prices.length; i++) {
    	   res=Math.max(res, maxHelper(prices, i));
       }
     
        return res;
    }
    private int maxHelper(int[] prices, int pos) {	 
    	int res1=prices[1]-prices[0];
    	int res2=prices[pos+1]-prices[pos];
        int minprice1=prices[0];
        for (int i = 0; i < pos; i++) {
			minprice1=Math.min(minprice1, prices[i-1]);//i前一个i-1，i不能算进买入
			res1=Math.max(res1, prices[i]-minprice1);
		}
        if (res1<0) {
			res1=0;
		}
        int minprice2=prices[pos];
        for (int i = pos+2; i <prices.length; i++) {
			minprice2=Math.min(minprice2, prices[i-1]);//i前一个i-1，i不能算进买入
			res2=Math.max(res2, prices[i]-minprice2);
		}
        if (res2<0) {
			res2=0;
		}
        return Math.max(res1, res2);
	}
}
/*class Solution { c++
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) return 0;
        int n = prices.size(), g[n][3] = {0}, l[n][3] = {0};
        for (int i = 1; i < prices.size(); ++i) {
            int diff = prices[i] - prices[i - 1];
            for (int j = 1; j <= 2; ++j) {
                l[i][j] = max(g[i - 1][j - 1] + max(diff, 0), l[i - 1][j] + diff);
                g[i][j] = max(l[i][j], g[i - 1][j]);
            }
        }
        return g[n - 1][2];
    }
};
*/