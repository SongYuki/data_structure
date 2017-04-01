/**
m: nums1.size n: nums2.size

Hash table solution:
Time: O(m + n) Space: O(m + n)
**/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> dict;
        vector<int> res;
        for(int i = 0; i < (int)nums1.size(); i++) dict[nums1[i]]++;
        for(int i = 0; i < (int)nums2.size(); i++)
            if(--dict[nums2[i]] >= 0) res.push_back(nums2[i]);
        return res;
    }
};


/**
Hash table solution2:
Time: O(m + n) Space: O(m)
**/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> dict;
        vector<int> res;
        for(int i = 0; i < (int)nums1.size(); i++) dict[nums1[i]]++;
        for(int i = 0; i < (int)nums2.size(); i++)
            if(dict.find(nums2[i]) != dict.end() && --dict[nums2[i]] >= 0) res.push_back(nums2[i]);
        return res;
    }
};

/**
Sort and two pointers Solution:
Time: O(max(m, n) log(max(m, n))) Space: O(m + n)
**/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n1 = (int)nums1.size(), n2 = (int)nums2.size();
        int i1 = 0, i2 = 0;
        vector<int> res;
        while(i1 < n1 && i2 < n2){
            if(nums1[i1] == nums2[i2]) {
                res.push_back(nums1[i1]);
                i1++;
                i2++;
            }
            else if(nums1[i1] > nums2[i2]){
                i2++;
            }
            else{
                i1++;
            }
        }
        return res;
    }
};

/**
C++ solution using stl
**/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        if(!nums1.size() || !nums2.size())
            return ans;
        ans.resize(nums1.size() + nums2.size());
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int>::iterator it = set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), ans.begin());
        ans.resize(it-ans.begin());
        return ans;
    }
};
