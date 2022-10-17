class Solution {
    public int[][] diagonalSort(int[][] mat) {
        
    // creating a hashmap which stores all the elements in a priorityQueue on the basis of gap(diagonal)
        HashMap<Integer,PriorityQueue<Integer>> hm = new HashMap<>();
        for(int i=0;i<mat.length;i++){
            for(int j=0;j<mat[i].length;j++){
                int gap = i - j;
                if(hm.containsKey(gap)){
                    PriorityQueue<Integer> pq = hm.get(gap);
                    pq.add(mat[i][j]);
                }
                else{
                    PriorityQueue<Integer> pq = new PriorityQueue<>();
                    pq.add(mat[i][j]);
                    hm.put(gap,pq);
                }
            }
        }
        
        
        
        for(int i=0;i<mat.length;i++){
            for(int j=0; j<mat[0].length ; j++){
                int gap = i -j;
                PriorityQueue<Integer> pq = hm.get(gap);
                mat[i][j] = pq.remove();
            }
        }
        
        
        return mat;
    }
}
