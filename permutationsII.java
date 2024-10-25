import java.sql.Array;
import java.util.ArrayList;

class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        Arrays.sort(nums);
        boolean[] used = new boolean[nums.length];

        backtrack(nums, result, new ArrayList<>(), used);
        return result;
    }

    private void backtrack(int[] nums, List<List<Integer>> result, List<Integer> currentPermutation, boolean[] used) {
        if (currentPermutation.size() == nums.length) {
            result.add(new ArrayList<>(currentPermutation));
            return;
        }

        for (int i = 0; i < nums.length; i++) {
            // Only take the first duplicate in each level
            if (used[i] || (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])) {
                continue;
            }
            used[i] = true;
            currentPermutation.add(nums[i]);

            backtrack(nums, result, currentPermutation, used);
            currentPermutation.remove(currentPermutation.size() - 1);
            used[i] = false;
        }
    }
}