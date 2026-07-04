class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        index_map = {v: i for i, v in enumerate(nums)}
        for i in range(len(nums)):
            diff = target - nums[i]
            if diff in index_map and i != index_map[diff]:
                return [i,index_map[diff]]
        return []