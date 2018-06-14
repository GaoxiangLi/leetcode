class Solution {
public:
    string addBinary(string a, string b) {
		string result="";
		const int length=a.size()>b.size()?a.size():b.size();
		int carry=0;
		for(int i=0;i<length;i++){
			int ai=i<a.size()?a[a.size()-i-1]-'0':0;
			int bi=i<b.size()?b[b.size()-i-1]-'0':0;
			int val=(ai+bi+carry)%2;
			carry=(ai+bi+carry)/2;
			result.insert(result.begin(),val+'0');
		}
		if(carry==1){
			result.insert(result.begin(),'1');
		}
		return result;
    }
};