public class Solution {
    public int[][] reconstructQueue(int[][] people) {
        Arrays.sort(people, new Comparator<int[]>(){
            public int compare(int[] a, int[] b) {
                if(a[0] != b[0]) return -a[0]+b[0];
                else return a[1]-b[1];
            }
        });
        
        List<int[]> res = new LinkedList<>();
        for(int[] p : people) {
            res.add(p[1], p);
        }
        
        return res.toArray(new int[people.length][]);
    }
}
/*
Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

[[7,0], [6,1], [7,1], [5,0], [4,4], [5,2]]


Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

*/