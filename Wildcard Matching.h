class Solution {
public:
	bool isMatch(const string& s, const string& p) {
		return isMatch(s.c_str(), p.c_str());
		}
private:
	bool isMatch(const char *s, const char *p) {
		bool star = false;
		const char *str, *ptr;
		for (str = s, ptr = p; *str != '\0'; str++, ptr++) {
			switch (*ptr) {
				case '?':
					break;
				case '*':
					star = true;
					s = str, p = ptr;
					while (*p == '*') p++; //skip continuous '*'
					if (*p == '\0') return true;
					str = s - 1;
					ptr = p - 1;
					break;
				default:
					if (*str != *ptr) {
					//没有star匹配不成功
						if (!star) return false;
						s++;
						str = s - 1;
						ptr = p - 1;
					}
				}
		}
		while (*ptr == '*') ptr++;
		return (*ptr == '\0');
	}
};
//https://www.cnblogs.com/yuzhangcmu/p/4116153.html思路
//如果p遇到*，p++到下一个 s不动 和p比较 如果相等则代表*匹配了0个 不相等则s继续++p不动 直到相等为止 *匹配成功

