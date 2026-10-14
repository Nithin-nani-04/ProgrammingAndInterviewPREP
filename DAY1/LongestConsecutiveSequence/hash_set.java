class Solution {
    public int longestConsecutive(int[] nums) {
        Set<Integer> set= new HashSet<>();
        if (nums.length==0){return 0;}
        for(int i:nums){
            set.add(i);
        }
        int longest=1;
        for(int curr:set){
            if(!set.contains(curr+1)){
            int len=1;

            while (set.contains(curr-1)){
                curr--;
                len++;
            }
            longest=Math.max(longest,len);
        }}
        return longest;
    }
}
class hash_set{
    public static void main(String[] args) {
        Solution s=new Solution();
        int[] nums={100,4,200,1,3,2};
        int result=s.longestConsecutive(nums);
        System.out.println(result);
    }
}