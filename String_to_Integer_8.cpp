class Solution {
public:
    int myAtoi(string str) {
        stack<char> stNum;
        int nIndex = 0;
        bool bHeadFlag = true, bTooMax = false;
        long long llResult = 0, nWeight = 1;
        map <char, int> hmNumMapping;
        
        for (char cStart = '0'; cStart <= '9'; cStart++) {
            hmNumMapping[cStart] = nIndex;
            nIndex++;
        }
        
        if (str.length() == 0) {
            return 0;
        }
        
        for (nIndex = 0; nIndex < str.length(); nIndex++) {
            if (bHeadFlag == true && (str[nIndex] == '-' || str[nIndex] == '+' || str[nIndex] >= '0' && str[nIndex] <= '9')) {
                stNum.push(str[nIndex]);
                bHeadFlag = false;
                continue;
            }
            
            if (bHeadFlag == false && str[nIndex] >= '0' && str[nIndex] <= '9') {
                stNum.push(str[nIndex]);
            } else if (bHeadFlag == true && str[nIndex] == ' ') {
                continue;
            } else {
                break;
            }
        }
        
        if (stNum.size() > 12) {
            bTooMax = true;
        }

        while (!stNum.empty()) {
            
            if (stNum.top() != '-' && stNum.top() != '+') {
                llResult += hmNumMapping[stNum.top()] * nWeight;
                nWeight *= 10;
            } else if (stNum.top() == '-') {
                if (bTooMax == true) {
                    return -2147483648;
                }
                llResult = -llResult;
            } else if (stNum.top() == '+') {
                
            }
            stNum.pop();
        }
        
        if (bTooMax == true) {
            return 2147483647;
        }
        
        if (llResult < -2147483648 || llResult > 2147483647) {
            if (llResult < 0) {
                return -2147483648;    
            }
            return 2147483647;
        }
        
        return llResult;
    }
};