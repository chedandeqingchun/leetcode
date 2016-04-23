class Solution {
public:
    string convert(string s, int numRows) {
        int nIndex, nEleIndex;
        string strFinalResult = "";
        
        if (numRows < 1) {
            return "";
        } else if (numRows == 1) {
            return s;
        }
        
        for (nIndex = 0; nIndex < numRows; nIndex++) {
            for (nEleIndex = nIndex; nEleIndex < s.length(); nEleIndex++) {
                if ((-abs(nEleIndex % ((2 * numRows) - 2) - (numRows - 1)) + (numRows - 1)) == nIndex) {
                    strFinalResult += s[nEleIndex];
                }
            }
        }
        return strFinalResult;
    }
};