class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty()){
			return s.empty();//若p为空，若s也为空，返回true，反之返回false
		}
		if(p.size()==1){
			return (s.size()==1&&(s[0]==p[0]||p[0]=='.')); //若p的长度为1，若s长度也为1，且相同或是p为'.'则返回true，反之返回false
		}
		if(p[1]!='*'){
			if(s.empty()) return false;
			return(s[0]==p[0]||p[0]=='.')&&isMatch(s.substr(1),p.substr(1));
			//若p的第二个字符不为*，若此时s为空返回false，否则判断首字符是否匹配，且从各自的第二个字符开始调用递归函数匹配
			//有*就扔给下面
		}
		 while (!s.empty() && (s[0] == p[0] || p[0] == '.')) {//如果有*
            if (isMatch(s, p.substr(2))) return true;//p去掉*之后是否匹配（*代替0个字符）
			//*至少代替1个的情况 去掉s首字母 再匹配 相当于把代替了的字符在s中去掉 参考举例abbbbb ab*****
            s = s.substr(1);
        }
		return isMatch(s, p.substr(2));//去掉之后在匹配
    }
};