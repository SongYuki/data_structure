#include<unordered_set>
class Solution
{
public:
	vector<int> intersection(vector<int>&nums1, vector<int>&nums2) {
		if (nums1.empty()||nums2.empty())
		{
			return std::vector<int>();
		}
		std::unordered_set<int> set{ nums1.cbegin(),nums1.cend() };
		std::vector<int> intersections;
		for (auto n:nums2)
		{
			if (set.erase(n)>0)
			{
				intersections.push_back(n);
			}
		}
		return intersections;
	}

};

