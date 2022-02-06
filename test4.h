#pragma once
class Solution3 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() == 0 && nums2.size() != 0){
            int num = nums2.size();
            if(num%2 == 0){
                int a = num/2;
                int b = a+1;
                double result = (double)nums2[a-1]+((double)nums2[b-1]-(double)nums2[a-1])/2;
                return result;
            }
            else {
                int a = (num+1)/2;
                double result = (double)nums2[a-1];
                return result;
            }
        }
        else if(nums1.size() != 0 && nums2.size() == 0){
            int num = nums1.size();
            if(num%2 == 0){
                int a = num/2;
                int b = a+1;
                double result = (double)nums1[a-1]+((double)nums1[b-1]-(double)nums1[a-1])/2;
                return result;
            }
            else {
                int a = (num+1)/2;
                double result = (double)nums1[a-1];
                return result;
            }
        }
        else {
            for(auto it : nums2)
                nums1.push_back(it);
            for(auto it1 = nums1.end();it1 != nums1.begin();it1--){
                for(auto it2 = nums1.begin();it2 < it1-1;it2++){
                    if(*it2 > *(it2+1)){
                        int tmp = *it2;
                        *it2 = *(it2+1);
                        *(it2+1) = tmp;
                    }
                }
            }
            int num = nums1.size();
            if(num%2 == 0){
                int a = num/2;
                int b = a+1;
                double result =(double)nums1[a-1]+((double)nums1[b-1]-(double)nums1[a-1])/2;
                return result;
            }
            else {
                int a = (num+1)/2;
                double result = (double)nums1[a-1];
                return result;
            }
        }
    }
};