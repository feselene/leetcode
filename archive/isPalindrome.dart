class Solution {
  public bool isPalindrome(String s) {
    // Remove non-alphanumeric characters and convert to lowercase
    StringBuilder filtered = '';
    for (int i = 0; i < s.length; i++) {
      var c = s[i];
      if (RegExp(r'[a-zA-Z0-9]').hasMatch(c)) {
        filtered += c.toLowerCase();
      }
    }

    // Initialize two pointers
    int ptr1 = 0;
    int ptr2 = filtered.length() - 1;

    // Check if the filtered string is a palindrome
    while (ptr1 < ptr2) {
      if (filtered.charAt(ptr1) != filtered.charAt(ptr2)) {
        return false;
      }
      ptr1++;
      ptr2--;
    }
    return true;
  }
}
