nums = [1, 3, 5, 2, 12, 43, 2, 34, 5, 0, 10]

print(nums)

swaps = True
while swaps:
    swaps = False

    for j in range(len(nums)-1):
        if nums[j] > nums[j+1]:
            swaps = True
            nums[j], nums[j+1] = nums[j+1], nums[j]

print(nums)