class Solution {
    public int[] countBits(int num) {
        int[] res=new int[num+1];
        res[0]=0;
        for(int i=1;i<=num;i++) {
        	res[i]=res[i/2]+(i%2);
        }
        return res;
    }
}

//在后面加了0或1组成新的数 所以/2取之前的数 再加%2后新的数位
//a[i]=a[i/2]+i%2

0	0
1	1 
10	2
11	3

100	4
101	5
110	6
111	7

1000	8
1001	9
1010	10
1011	11
1100	12
1101	13
1110	14
1111	15
10000	16
