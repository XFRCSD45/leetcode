class Solution {
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
        List<List<Integer>> list = new ArrayList<>();
        Arrays.sort(arr);
        int min = Integer.MAX_VALUE;
        for(int i = 0; i< arr.length-1; i++){
            min = Math.min(Math.abs(arr[i] - arr[i+1]), min);
        }
        for(int i = 0; i< arr.length -1; i++){
            List<Integer> lst = new ArrayList<>();
            if(Math.abs(arr[i] - arr[i+1]) == min){
                lst.add(arr[i]);
                lst.add(arr[i+1]);
                list.add(lst);
            }

        }
        return list;
    }
}