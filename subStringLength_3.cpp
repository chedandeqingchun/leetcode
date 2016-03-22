class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int nStart = 0, nSubIndex = -1, nLength = 0, nMaxLength = 0;
        for (int nIndex = 0; nIndex < s.length(); nIndex++) {
            nSubIndex = nStart;
            while (nSubIndex - nStart < nLength) {
                if (s[nSubIndex] == s[nIndex]) {
                    nStart = nSubIndex + 1;
                    break;
                }
                nSubIndex++;
            }
            
            if (nSubIndex - nStart >= nLength) {
                nLength++;
                if (nLength > nMaxLength) {
                    nMaxLength = nLength;
                }
            } else {
                nLength = nIndex - nStart + 1; 
            }
        }   
     
        return nMaxLength;
    }
};