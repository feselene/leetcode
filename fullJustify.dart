class Solution {
  List<String> fullJustify(List<String> words, int maxWidth) {
    List<String> result = [];
    int index = 0;

    while (index < words.length) {
      int totalChars = words[index].length;
      int last = index + 1;

      // Find how many words fit in the current line
      while (last < words.length) {
        if (totalChars + 1 + words[last].length > maxWidth) break;
        totalChars += 1 + words[last].length;
        last++;
      }

      StringBuffer line = StringBuffer();
      int numberOfWords = last - index;
      int spacesToDistribute = maxWidth - totalChars + (numberOfWords - 1);

      // Distribute spaces evenly for lines with more than one word
      if (numberOfWords == 1 || last == words.length) {
        for (int i = index; i < last; i++) {
          line.write(words[i]);
          if (i < last - 1) line.write(' ');
        }

        // Fill in remaining spaces at the end of the line
        while (line.length < maxWidth) line.write(' ');
      } else {
        int spacesBetweenWords = spacesToDistribute ~/ (numberOfWords - 1);
        int extraSpaces = spacesToDistribute % (numberOfWords - 1);

        for (int i = index; i < last; i++) {
          line.write(words[i]);
          if (i < last - 1) {
            for (int j = 0; j <= (spacesBetweenWords + (i - index < extraSpaces ? 1 : 0)); j++) {
              line.write(' ');
            }
          }
        }
      }

      result.add(line.toString());
      index = last;
    }

    return result;
  }
}
