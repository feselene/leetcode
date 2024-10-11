class Solution {
    public String intToRoman(int num) {
        Map<Integer, String> digitMap = new HashMap<>();
        // Map<Type> mapName = new HashMap<>();
        digitMap.put(1000, "M");
        digitMap.put(500, "D");
        digitMap.put(100, "C");
        digitMap.put(50, "L");
        digitMap.put(10, "X");
        digitMap.put(5, "V");
        digitMap.put(1, "I");
        digitMap.put(9, "IX");
        digitMap.put(4, "IV");
        digitMap.put(90, "XC");
        digitMap.put(40, "XL");
        digitMap.put(400, "CD");
        digitMap.put(900, "CM");

        StringBuilder ans = new StringBuilder();

        Map<Integer, String> sortedDigits = new TreeMap<>((a, b) -> b - a);
        sortedDigits.putAll(digitMap);
        for (int key : sortedDigits.keySet()) {
            while (num >= key) {
                ans.append(sortedDigits.get(key));
                num -= key;
            }
        }

        return ans.toString();
    }
}