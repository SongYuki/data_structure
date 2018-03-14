/*
	2.1.1 Remove Duplicates from Sorted Array
	do not allocate extra space for another array,you must do this in place with constant memory.
*/

//时间复杂度O(n)，空间复杂度O(1)
class Solution0 {
public:
	int removeDuplicates(int A[], int n) {
		if (n==0)
		{
			return 0;
		}
		int index = 0;
		for (int i = 1; i < n; i++)
		{
			if (A[index]!=A[i])
			{
				A[++index] = A[i];
			}
		}
		return index + 1;
	}
};

class Solution1 {
public:
	int removeDuplicates(int A[], int n) {
		return distance(A, unique(A, A + n));
	}
};

class Solution2 {
public:
	int removeDuplicates(int A[], int n) {
		return removeDuplicates(A, A + n, A) - A;
	}

	template<typename InIt,typename OutIt>
	OutIt removeDuplicates(InIt first, InIt last, OutIt output) {
		while (first!=last)
		{
			*output++ = *first;
			first = upper_bound(first, last, *first);
		}
		return output;
	}
};

/*
	Remove Duplicates from Sorted ArrayII
	加一个变量记录一下元素出现的次数即可，这题因为是已经排序的数组，所以一个变量即可解决。
	如果是没有排序的数组，则需要引入一个hashmap来记录出现次数
	*/

class Solution0 {
public:
	int removeDuplicates(int A[], int n) {
		if (n<=2)		//将occur<2 改为occur<3,就变成了允许重复最多三次
		{
			return n;
		}

		int index = 2;
		for (int i=2;i<n;i++)
		{
			if (A[i]!=A[index-2])
			{
				A[index++] = A[i];
			}
		}
		return index;
	}
};

class Solution1 {
public:
	int removeDuplicates(int A[], int n) {
		int index = 0;
		for (int i = 0; i < n; ++i)
		{
			if (i>0&&i<n-1&&A[i]==A[i-1]&&A[i]==A[i+1])
			{
				continue;
			}
			A[index++] = A[i];
		}
		return index;
	}
};

/*
	Search in Rotated Sorted Array
	二分查找，难度主要在于左右边界的确定
*/
class Solution0{
public:
	int search(int A[], int n, int target) {
		int first = 0, last = n;
		while (first!=last)
		{
			const int mid = (first + last) / 2;
			if (A[mid]==target)
			{
				return mid;
			}
			if (A[first]<=A[mid])
			{
				if (A[first]<=target&&target<A[mid])
				{
					last = mid;
				}
				else
				{
					first = mid + 1;
				}
			}
			else
			{
				if (A[mid]<target&&target<=A[last-1])
				{
					first = mid + 1;
				}
				else
				{
					last = mid;
				}
			}
		}
		return -1;
	}
};


/*
	Search in Rotated Sorted ArrayII
	what if duplicates are allowed
	允许重复元素，则上一题中如果A[m]>=A[l].那么[l,m]为递增序列的假设就不能成立了，比如[1,3,1,1,1]
	如果A[m]>=A[l]不能确定递增，那么就把它拆分成两个条件
	1.若A[m]>A[l],则区间[l,m]一定递增
	2.若A[m]==A[l]确定不了，那就l++，往下看一步即可
*/

class Solution{
public:
	bool search(int A[], int n, int target) {
		int first = 0, last = n;
		while (first != last)
		{
			const int mid = (first + last) / 2;
			if (A[mid] == target)
			{
				return true;
			}
			if (A[first] < A[mid])
			{
				if (A[first] <= target&&target<A[mid])
				{
					last = mid;
				}
				else
				{
					first = mid + 1;
				}
			}
			else  if(A[first]>A[mid])
			{
				if (A[mid]<target&&target <= A[last - 1])
				{
					first = mid + 1;
				}
				else
				{
					last = mid;
				}
			}
			else
			{
				//skip duplicate one
				first++;
			}
		}
		return false;
	}
};

/*
	Median of Two Sorted Arrays
	这是一道非常经典的题，这题更通用的形式是，给定两个已经排序好的数组，找到两者所有元素中第k大的元素
	O(m+n)的解法比较直观，直接merge两个数组，然后求第k大的元素
	不过我们仅仅需要第K大的元素，是不需要排序这么复杂的操作的，可以用一个计数器，记录当前已经找到第m大的元素了。
	同时我们使用两个指针pA和pB,分别指向A和B数组的第一个元素，使用类似于merge sort的原理，如果数组A当前元素小，那么pA++,同时m++
	如果数组B当前元素小，那么pB++同时m++
	最终当m等于k的时候，就得到了我们的答案，O(k)时间，O(1)空间。当k很接近m+n的时候，这个方法还是O(m+n)的
*/
class Solution {
public:
	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		int total = m + n;
		if (total&Ox1)
		{
			return find_kth(A, m, B, n, total / 2 + 1);
		}
		else
		{
			return(find_kth(A, m, B, n, total / 2) + find_kth(A, m, B, n, total / 2 + 1)) / 2.0;
		}
	}
private:
	static int find_kth(int A[], int m, int B[], int n, int k) {
		//always assume that m is equal or smaller than n
		if (m>n)
		{
			return find_kth(B, n, A, m, k);
		}
		if (m==n)
		{
			return B[k - 1];
		}
		if (k==1)
		{
			return min(A[0], B[0]);
		}

		//divide k into two parts
		int ia = min(k / 2, m), ib = k - ia;
		if (A[ia-1]<B[ib-1])
		{
			return find_kth(A + ia, m - ia, B, n, k - ia);
		}
		else if (A[ia-1]>B[ib-1])
		{
			return find_kth(A, m, B + ib, n - ib, k - ib);
		}
		else
		{
			return A[ia - 1];
		}
	}
};

/*
	Longest Consecutive Sequence
	如果允许O(nlogn)的复杂度，那么可以先排序，本题要求O(n)
	由于序列里的元素是无序的，又要求O(n),首先要想到用哈希表
	用一个哈希表unordered_map<int,bool>used记录每个元素是否使用，对每个元素，以该元素为中心，往左右扩张，直到不连续为止，记录下最长的长度
*/
class Solution {
public:
	int longestConsecutive(const vector<int> &num) {
		unordered_map<int, bool>used;
		for (auto i :num)
		{
			used[i] = false;
		}
		int longest = 0;
		for (auto i :num)
		{
			if (used[i])
			{
				continue;
			}
			int length = 1;
			used[i] = true;
			for (int j = i+1; used.find(j)!=used.end(); ++j)
			{
				used[j] = true;
				++length;
			}
			for (int j = i-1; used.find(j)!=used.end(); --j)
			{
				used[j] = true;
				++length;
			}
			longest = max(longest, length);
		}
		return longest;
	}
};


/*
	最长子序列
	聚类的操作，应该有union,find的操作，连续序列可以用两端和长度来表示。
	本来用两端就可以表示，但考虑到查询的需求，将两端分别暴露出来用unordered_map<int,int>map来存储
*/
class Solution {
public:
	int longestConsecutive(vector<int>&num) {
		unordered_map<int, int>map;
		int size = num.size();
		int l = 1;
		for (int i = 0; i < size; i++) {
			if (map.find(num[i])!=map.end())
			{
				continue;
			}
			map[num[i]] = 1;
			if (map.find(num[i]-1!=map.end())
			{
				l = max(l, mergeCluster(map, num[i] - 1, num[i]));
			}
			if (map.find(num[i]+1!=map.end())
			{
				l = max(l, mergeCluster(map, num[i], num[i] + 1));
			}
		}
		return size == 0 ? 0 : 1;
	}

private:
	int mergeCluster(unordered_map<int, int>&map, int left, int right) {
		int upper = right + map[right] - 1;
		int lower = left - map[left] + 1;
		int length = upper - lower + 1;
		map[upper] = length;
		map[lower] = length;
		return length;
	}
};


/*
	Two Sum
	1.暴力，复杂度O(n*n)，超超时
	2.hash，用一个哈希表，存储每个数对应的下标，复杂度O(n)
	3.先排序，然后左右夹逼，排序O(nlogn),左右夹逼O(n),最终O(nlogn).本题需要返回的是下标，而不是数字本身，这个方法行不通
*/

class Solution {
public:
	vector<int>twoSum(vector<int>&num, int target) {
		unordered_map<int, int>mapping;
		vector<int>result;
		for (int i = 0; i < num.size(); i++)
		{
			mapping[num[i]] = i;
		}
		for (int i = 0; i < num.size(); i++)
		{
			const int gap = target - num[i];
			if (mapping.find(gap)!=mapping.end()&&mapping[gap]>i)
			{
				result.push_back(i + 1);
				result.push_back(mapping[gap] + 1);
				break;
			}
		}
		return result;
	}
};

/*
	3Sum
	先排序，然后左右夹逼，复杂度O(n*n)
	这个方法可以推广到k-sum，先排序，然后做k-2次循环，在最内层循环左右夹逼，时间复杂度是O(max{nlogn,n的k-1次方})
*/
class Solution {
public:
	vector<vector<int>>threeSum(vector<int>&num) {
		vector<vector<int>>result;
		if (num.size()<3)
		{
			return result;
		}
		sort(num.begin(), num.end());
		const int target = 0;

		auto last = num.end();
		for (auto a = num.begin(); a < prev(last,2); ++a)
		{
			auto b = next(a);
			auto c = prev(last);
			while (b<c)
			{
				if (*a+*b+*c<target)
				{
					++b;
				}
				else if (*a+*b+*c>target)
				{
					--c;
				}
				else
				{
					result.push_back({ *a,*b,*c });
					++b;
					--c:
				}
			}
		}
		sort(result.begin(), result.end());
		result.erase(unique(result.begin(), result.end()), result.end());
		return result;
	}
};
