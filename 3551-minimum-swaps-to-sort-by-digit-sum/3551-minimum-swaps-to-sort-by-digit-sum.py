class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        li = sorted([sum(map(int, str(x))), x, i] for i, x in enumerate(nums))
        cur = 0
        
        for _, _, i in li:
            if i < 0:
                continue
            cur += 1
            while i >= 0:
                li[i][2], i = -1, li[i][2]

        return len(li) - cur