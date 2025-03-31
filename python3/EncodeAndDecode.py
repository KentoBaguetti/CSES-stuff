from typing import List


class Solution:
    def encode(self, strs: List[str]) -> str:
        res = ""
        for s in strs:
            res += str(len(s)) + "#" + s
        return res

    def decode(self, s: str) -> List[str]:
        res = []

        i = 0
        while i < len(s):
            j = i
            while s[j] != "#":
                j += 1
            length = int(s[i:j])
            i = j + 1
            j = i + length
            res.append(s[i:j])
            i = j

        return res


if __name__ == "__main__":
    obj = Solution()
    strs = ["neet", "code", "love", "you"]

    encode1 = obj.encode(strs)
    print(encode1)
    decode1 = obj.decode(encode1)
    print(decode1)
