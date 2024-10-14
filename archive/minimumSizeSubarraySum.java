package archive;

class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int minSize = Integer.MAX_VALUE;
        int windowSum = 0;
        int leftSideOfWindow = 0;

        for (int rightSideOfWindow = 0; rightSideOfWindow < nums.length; rightSideOfWindow++) {
            windowSum += nums[rightSideOfWindow];
            if (windowSum >= target) {
                minSize = Math.min(minSize, rightSideOfWindow - leftSideOfWindow);
                windowSum -= nums[leftSideOfWindow];
                leftSideOfWindow++;
            }
        }

        return minSize == Integer.MAX_VALUE ? 0 : minSize;
    }
}