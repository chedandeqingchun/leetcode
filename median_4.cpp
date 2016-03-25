class Solution {
public:

    double findKthNum(vector<int> &vNums1, int nNums1Len, vector<int> &vNums2, int nNums2Len, int nKth) {
        
        int nPVec1, nPVec2;
        
        if (nNums1Len > nNums2Len) {
            return findKthNum(vNums2, nNums2Len, vNums1, nNums1Len, nKth);
        }
        
        if (nNums1Len == 0) {
            return vNums2[nKth - 1];
        }
        
        if (nKth == 1) {
            return min(vNums1[0], vNums2[0]);
        }
        
        nPVec1 = min(nNums1Len,  nKth / 2);
        nPVec2 = nKth - nPVec1;
        
        if (vNums1[nPVec1 - 1] < vNums2[nPVec2 - 1]) {
            vector<int> vIndex(vNums1.begin() + nPVec1, vNums1.end());
            return findKthNum(vIndex, nNums1Len - nPVec1, vNums2, nNums2Len, nKth - nPVec1);            
        } else if (vNums1[nPVec1 - 1] > vNums2[nPVec2 - 1]){
            vector<int> vIndex(vNums2.begin() + nPVec2, vNums2.end());
            return findKthNum(vNums1, nNums1Len, vIndex, nNums2Len - nPVec2, nKth - nPVec2);
        } else {
            return vNums1[nPVec1 - 1];
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int nNum1Len = nums1.size();
        int nNum2Len = nums2.size();
        int nTotalLen = nums1.size() + nums2.size();
        
        if ((nNum1Len + nNum2Len) % 2 == 0) {
            return (findKthNum(nums1, nNum1Len, nums2, nNum2Len, nTotalLen / 2) + findKthNum(nums1, nNum1Len, nums2, nNum2Len, (nTotalLen / 2) + 1)) / 2;
        } else {
            return findKthNum(nums1, nNum1Len, nums2, nNum2Len, (nTotalLen + 1) / 2);
        }
    }
};