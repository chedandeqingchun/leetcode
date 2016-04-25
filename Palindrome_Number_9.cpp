class Solution {
public:
    bool isPalindrome(int x) {
        int nLength = 0;
        int nNum = x, nPre, nNext, nEleIndex;
        
        if (x < 0) {
            return false;
        }
        
        while (nNum > 0) {
            nLength++;
            nNum /= 10;
        }
        
        
        for (nEleIndex = 1; nEleIndex <= (nLength + 1) / 2; nEleIndex++) {
            nPre = (x / (int)pow(10, (nLength -nEleIndex))) % 10;
            nNext = (x % (int)pow(10, (nEleIndex))) / (int)pow10(nEleIndex - 1);
            if (nPre != nNext) {
                break;
            }
        }
        
        if (nEleIndex > (nLength + 1) / 2) {
            return true;
        }
        return false;
    }
};