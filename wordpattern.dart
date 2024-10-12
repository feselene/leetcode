class Solution {
  bool wordPattern(String pattern, String s) {
    String[] words = s.split(' ');
    unordered_map<char, String> bijection = new unordered_map<char, String>();
    for (int i = 0; i < words.length; i++) {
      if (bijection[s[i]] != null) {
        if (words[s[i]] != bijection[s[i]]) {
          return false;
        }
      }
      else {
        bijection[s[i]] = words[i];
      }
    }

    return true;
  }
}