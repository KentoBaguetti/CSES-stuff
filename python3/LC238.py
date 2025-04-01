from typing import List


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        res = [1] * len(nums)

        prefixes: List[int] = [1] * len(nums)
        suffixes: List[int] = [1] * len(nums)

        prefixes[0] = nums[0]
        suffixes[-1] = nums[-1]

        for i in range(1, len(nums)):
            prefixes[i] = nums[i] * prefixes[i - 1]

        for i in range(len(nums) - 2, -1, -1):
            suffixes[i] = nums[i] * suffixes[i + 1]

        for i in range(1, len(nums) - 1):
            res[i] *= prefixes[i - 1] * suffixes[i + 1]

        res[0] *= suffixes[1]
        res[-1] *= prefixes[-2]
        return res


if __name__ == "__main__":
    obj = Solution()
    n: List[int] = [1, 2, 3, 4]
    ans1 = obj.productExceptSelf(n)
    print(ans1)
