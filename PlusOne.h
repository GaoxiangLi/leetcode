class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        const int n=digits.size();
		for(int i=n-1;i>=0;i--){
			if(digits[i]!=9){
				digits[i]+=1;
				return digits;
			}else{
				digits[i]=0;
			}
		}
		if(digits[0]==0){
			digits.insert(digits.begin(),1);
			return digits;
		}
    }
};

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
		if(digits.empty())
			return digits;
        int n=digits.size();
		int carry=1;
		for(int i=n-1;i>=0;i--){
			if(carry==0){
				return digits;
			}else{
				int sum=carry+digits[i];
				digits[i]=sum%10;
				carry=sum/10;
			}
		}
		if(carry==1){
			digits.insert(digits.begin(),1);
			
		}
		return digits;
    }
};