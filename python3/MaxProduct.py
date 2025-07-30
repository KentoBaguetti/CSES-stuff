class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        global_max = max(nums)
        curr_max = 1
        curr_min = 1

        for n in nums:
            temp = n * curr_max
            curr_max = max(temp, n * curr_min, n)
            curr_min = min(temp, n * curr_min, n)
            global_max = max(global_max, curr_max)
        
        return global_max