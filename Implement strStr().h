class Solution {
public:
	int strStr(const string& haystack, const string& needle) {
		if (needle.empty()) return 0;
		const int N = haystack.size() - needle.size() + 1;
		for (int i = 0; i < N; i++) {
			int j = i;
			int k = 0;
			while (j < haystack.size() && k < needle.size() && haystack[j] == needle[k]) {
					j++;
					k++;
				}
			if (k == needle.size()) return i;
		}
		return -1;
	}
};
class kmpSolution {
public:
	void cal_next( char * str, int * next, int len )  
{  
    int i, j;  
  
    next[0] = -1;  
    for( i = 1; i < len; i++ )  
    {  
        j = next[ i - 1 ];  //j所对应的是之前最大前缀最后一位
        while( str[ j + 1 ] != str[ i ] && ( j >= 0 ) ) //在之前对称的基础上 找新的对称（添加一个新的j+1位和i位比较）） 
        {  												//在最长前缀后面j+1 和最长后缀后面i相比较
            j = next[ j ];  //不断寻求最小的对称 如果上面等式不想等 则再分割 直到相等或j<0
        }  
        if( str[ i ] == str[ j + 1 ] )  
        {  
            next[ i ] = j + 1;    //相等 找到新对称 在j的基础上+1
        }  
        else  
        {  
            next[ i ] = -1;      //没有对称性 -1
        }  
    }  
}  
  
int KMP( char * str, int slen, char * ptr, int plen, int * next )  
{  
    int s_i = 0, p_i = 0;  
  
    while( s_i < slen && p_i < plen )  
    {  
        if( str[ s_i ] == ptr[ p_i ] )  
        {  
            s_i++;  
            p_i++;  
        }  
        else  
        {  
            if( p_i == 0 )  
            {  
                s_i++;  
            }  
            else  
            {  
                p_i = next[ p_i - 1 ] + 1;  
            }  
        }  
    }  
    return ( p_i == plen ) ? ( s_i - plen ) : -1;  
}  
};