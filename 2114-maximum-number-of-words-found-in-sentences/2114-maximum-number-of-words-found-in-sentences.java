class Solution {

    public int mostWordsFound(String[] sentences) {
        int maxi = Integer.MIN_VALUE;

        // iterating each string in list
        for (String s : sentences) {
            // Splitting the string using " " blank space regex. //Example : "My Name is"
            // split function will return all the words in an array // ["My", "Name", "is"]
            // so we call its length and it will return the number of words in that entire string // 3

            // Max function will return the max value between maxi and current string's length
            maxi = Math.max(s.split(" ").length, maxi);
        }

        return maxi;
    }
}
