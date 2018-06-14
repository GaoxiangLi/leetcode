//小孩分糖 遍历两次 
//第一次从左到右 右>左则右边比左多给一个 如果小于则右边只给一个
//第二次从右到左 确保每个孩子跟他右边的孩子相比，如果分高则糖至少多1个（这里至少多1个的意思是，我们要取当前孩子手里糖的数量，和其右边孩子糖的数量加1，两者的较大值）
class Solution {
public:
    int candy(vector<int>& ratings) {
		if(ratings.size()==0) return 0;
		if(ratings.size()==1) return 1;
		vector<int> candy(ratings.size());
		candy[0]=1;
		for(int i=1;i<ratings.size();i++){
			if(ratings[i]>ratings[i-1]){
				candy[i]=candy[i-1]+1;
			}else{
				candy[i]=1;
			}
		}
		
		for(int i=ratings.size()-2;i>=0;i--){
			if(ratings[i]>ratings[i+1]){
				candy[i]=max(candy[i],candy[i+1]+1);
			}
		}
        int sum=0;
        for(int i=0;i<ratings.size();i++){
            sum+=candy[i];
        }
		return sum;
    }
};