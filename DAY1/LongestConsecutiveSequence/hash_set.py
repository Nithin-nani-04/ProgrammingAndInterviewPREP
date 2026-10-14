class Solution:
    def longestConsecutive(self, nums):
        if len(nums)<=1: return len(nums)
        longest=1
        nums=set(nums)
        for i in nums:
            if i-1 not in nums:
                count=1
                while count+i in nums:
                    count+=1
                longest=max(count,longest)

                
        return longest
class hash_set:
    def main():
        s=Solution()
        nums=[100,4,200,1,3,2]
        result=s.longestConsecutive(nums)
        print(result)
if __name__=="__main__":
    hash_set.main()