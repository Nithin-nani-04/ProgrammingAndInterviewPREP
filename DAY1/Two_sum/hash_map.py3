from typing import List
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        d=dict()
        for i,v in enumerate(nums):
            diff=target-v
            if diff in d:
                return [i,d[diff]]
            d[v]=i
        return []
class hash_map:
    def main():
        s=Solution()
        nums=[2,7,11,15]
        target=9
        result=s.twoSum(nums,target)
        print(result)
if __name__=="__main__":
    hash_map.main()
    
