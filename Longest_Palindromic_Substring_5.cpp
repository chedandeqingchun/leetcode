class Solution {
public:
    int CalculRealLength(char *gStr, int nStart, int nEnd, char cFilled) {
        int nIndex, nStrLength, nRealLength = 0;
        if (gStr == NULL || strlen(gStr) == 0) {
            return 0;
        }
        
        nStrLength = strlen(gStr);
        
        if (nStart > nEnd || nStart < 0 || nEnd >= nStrLength) {
            return 0;
        }
        
        for (nIndex = nStart; nIndex <= nEnd; nIndex++) {
            if (gStr[nIndex] != cFilled) {
                nRealLength++;
            }
        }
        return nRealLength;
    }


    int judgePalindrome(char *gStr, int nIndex, int &nRadius) {
        int nStrLength = 0, nSubPrevIndex, nSubNextIndex;
        
        if (gStr == NULL || strlen(gStr) == 0) {
            return -1;
        }
        
        nStrLength = strlen(gStr);
        
        if (nIndex < 0 || nIndex >= nStrLength) {
            return -1;
        }
        
        nRadius = 1;

        if (nIndex >= 0 && nIndex < nStrLength) {
            nSubPrevIndex = nIndex - 1;
            nSubNextIndex = nIndex + 1;
           
            while (nSubPrevIndex >= 0 && nSubNextIndex < nStrLength) {
                if (gStr[nSubPrevIndex] == gStr[nSubNextIndex]) {
                    nRadius++;
                } else {
                    break;
                }
                nSubPrevIndex -= 1;
                nSubNextIndex += 1;
            }
        }
        
        return 1;
    }
    
    int shrinkStr(string &strStr, char cFilled) {
        string::iterator ite;
        
        for (ite = strStr.begin(); ite != strStr.end(); ) {
            if (*ite == cFilled) {
                ite = strStr.erase(ite);
            } else {
                ite++;
            }
        }
        return 1;
    }
    
    string longestPalindrome(string s) {
        int nContainerIndex = 0;
        int nMaxLengthIndex = -1, nMaxLength = -1, nCurrentLength = -1, nRealLength = 0, nMaxRealLength = 0;
        int nStrLength = s.length();
        char *gContainer = NULL;
        string strResult;
        stringstream ioStreamForString;
        
        if (nStrLength > 0) {
            gContainer = new char[2 * nStrLength];
        } else {
            return "";
        }
        
        if (gContainer == NULL) {
            return "";
        }
        
        memset(gContainer, '\0', 2 * nStrLength);
        
        for (int nIndex = 0; nIndex < nStrLength; nIndex++) {/* Convert s to array */
            gContainer[nContainerIndex] = s[nIndex];
            nContainerIndex++;
            if (nContainerIndex < 2 * nStrLength - 1) {
                gContainer[nContainerIndex] = '#';
                nContainerIndex++;
            }
        }
        
        for (nContainerIndex = 0; nContainerIndex < (2 * nStrLength) - 1; nContainerIndex++) {
            if (-1 == judgePalindrome(gContainer, nContainerIndex, nCurrentLength)) {
                continue;
            }
            nRealLength = CalculRealLength(gContainer, nContainerIndex - nCurrentLength + 1, nContainerIndex + nCurrentLength - 1, '#');
            
            if (nRealLength > nMaxRealLength) {
                nMaxRealLength = nRealLength;
                nMaxLengthIndex = nContainerIndex;
                nMaxLength = nCurrentLength;
            }
        }
        ioStreamForString << gContainer;
        strResult = ioStreamForString.str();
        strResult.assign(strResult, nMaxLengthIndex - nMaxLength + 1, 2 * nMaxLength - 1);
        
        if (1 != shrinkStr(strResult, '#')) {
            return "";
        }
        
        return strResult;
    }
};