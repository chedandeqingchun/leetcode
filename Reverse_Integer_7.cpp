class Solution {
public:
    int reverseInt(int nNum) {
        queue<long> qQueue;
        long nWeight =  1, nLength = 0;
        long nResult = 0, nLocalNum = 0;
        bool bPositiveFlag = true; 
        if (nNum < 0) {
            bPositiveFlag = false;
        }
        nLocalNum = abs(nNum);
        
        while (nLocalNum > 0) {
            qQueue.push(nLocalNum % 10);
            nLocalNum = nLocalNum / 10;
        }
            
        nLength = qQueue.size();
        nWeight = pow(10, (nLength - 1));
            
        while (!qQueue.empty()) {
            nResult += (nWeight * qQueue.front());
            qQueue.pop();
            nWeight /= 10;
        }
        
        if (bPositiveFlag&&nResult > 2147483647 || !bPositiveFlag&&(-nResult) < -2147483648) {
            return 0;
        }
        if (!bPositiveFlag) {
            return -nResult;
        }
        return nResult;
    }

    int reverse(int x) {
        if (x != 0) {
            return reverseInt(x);
        } else {
            return 0;
        }
    }
};