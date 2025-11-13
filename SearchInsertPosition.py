#O(N) time complexity

nums = [1,3,5,6]
target = 6.5

size = []
larger = False

length_nums = len(nums)
length = None


for i in range(length_nums):
    if nums[i] == target:
        print(f"The target number is found at index position {i}")
        break
    elif nums[i] > target:
        size.append(nums[i])
        length = (len(size))
    elif nums[length_nums-1] < target:
        larger = True

if size:
    target_index_number = length_nums - length
    print(target_index_number)

if larger:
    print(length_nums)
