import java.util.Arrays;

class Solution {
    public String longestWord(String[] words) {
        // sort array
        Arrays.sort(words);
        String longestWord = "";
        String currentWord = words[0];
        int count = 0;
        for (int i = 1; i < words.length; i++) {
            if (words[i].substring(0, currentWord.length() - 1).equals(currentWord)) {
                count += 1;
            }
            else {
                count = 1;
            }
            if (count > maxCount) {
                longestWord = words[i];
            }
        }

        return longestWord;

    }
}