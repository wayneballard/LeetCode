class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        size = []
        larger = False
        length_nums = len(nums)
        length = None

        for i in range(length_nums):
            if nums[i] == target:
                return i 
            elif nums[i] > target:
                size.append(nums[i])
                length = len(size)
            elif nums[length_nums - 1] < target:
                larger = True

        if size:
            target_index_number = length_nums - length
            return target_index_number

        if larger:
            return length_nums

        return 0 
