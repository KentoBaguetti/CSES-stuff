def topKFrequent_nlogn(nums, k):
    hm = {}
    for num in nums:
        if num not in hm:
            hm[num] = 1
        else:
            hm[num] += 1

    sorted_hm = sorted(hm, key=hm.get, reverse=True)
    return sorted_hm[:k]


def topKFrequent_n(nums, k):
    dp = []
    for i in range(len(nums) + 1):
        dp.append([])
    indexes = {}

    for i in range(len(nums)):
        if (
            nums[i] not in indexes
        ):  # if the number in nums has never been seen b4, we now have one instance of it
            dp[1].append(nums[i])
            indexes[nums[i]] = 1
        else:
            indexes[nums[i]] += 1
            dp[indexes[nums[i]]].append(nums[i])
        print(f"Iteration: {i}")
        print(dp)
        print(indexes)
        print()

    res = []
    added = set()
    for i in range(len(dp) - 1, -1, -1):
        if dp[i]:
            for num in dp[i]:
                if num not in added:
                    res.append(num)
                    added.add(num)
                if len(res) == k:
                    break
        if len(res) == k:
            break
    return res


if __name__ == "__main__":
    arr = [1, 1, 1, 2, 2, 3]
    k = 2
    # test1 = topKFrequent_n([1], 1)

    arr2 = [4, 1, -1, 2, -1, 2, 3]
    k2 = 2
    test2 = topKFrequent_n(arr2, k2)

    print(test2)
