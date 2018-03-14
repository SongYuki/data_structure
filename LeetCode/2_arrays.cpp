/*
	2.1.1 Remove Duplicates from Sorted Array
	do not allocate extra space for another array,you must do this in place with constant memory.
*/

//ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)
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
	��һ��������¼һ��Ԫ�س��ֵĴ������ɣ�������Ϊ���Ѿ���������飬����һ���������ɽ����
	�����û����������飬����Ҫ����һ��hashmap����¼���ִ���
	*/

class Solution0 {
public:
	int removeDuplicates(int A[], int n) {
		if (n<=2)		//��occur<2 ��Ϊoccur<3,�ͱ���������ظ��������
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
	���ֲ��ң��Ѷ���Ҫ�������ұ߽��ȷ��
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
	�����ظ�Ԫ�أ�����һ�������A[m]>=A[l].��ô[l,m]Ϊ�������еļ���Ͳ��ܳ����ˣ�����[1,3,1,1,1]
	���A[m]>=A[l]����ȷ����������ô�Ͱ�����ֳ���������
	1.��A[m]>A[l],������[l,m]һ������
	2.��A[m]==A[l]ȷ�����ˣ��Ǿ�l++�����¿�һ������
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
	����һ���ǳ�������⣬�����ͨ�õ���ʽ�ǣ����������Ѿ�����õ����飬�ҵ���������Ԫ���е�k���Ԫ��
	O(m+n)�Ľⷨ�Ƚ�ֱ�ۣ�ֱ��merge�������飬Ȼ�����k���Ԫ��
	�������ǽ�����Ҫ��K���Ԫ�أ��ǲ���Ҫ������ô���ӵĲ����ģ�������һ������������¼��ǰ�Ѿ��ҵ���m���Ԫ���ˡ�
	ͬʱ����ʹ������ָ��pA��pB,�ֱ�ָ��A��B����ĵ�һ��Ԫ�أ�ʹ��������merge sort��ԭ���������A��ǰԪ��С����ôpA++,ͬʱm++
	�������B��ǰԪ��С����ôpB++ͬʱm++
	���յ�m����k��ʱ�򣬾͵õ������ǵĴ𰸣�O(k)ʱ�䣬O(1)�ռ䡣��k�ܽӽ�m+n��ʱ�������������O(m+n)��
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
	�������O(nlogn)�ĸ��Ӷȣ���ô���������򣬱���Ҫ��O(n)
	�����������Ԫ��������ģ���Ҫ��O(n),����Ҫ�뵽�ù�ϣ��
	��һ����ϣ��unordered_map<int,bool>used��¼ÿ��Ԫ���Ƿ�ʹ�ã���ÿ��Ԫ�أ��Ը�Ԫ��Ϊ���ģ����������ţ�ֱ��������Ϊֹ����¼����ĳ���
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
	�������
	����Ĳ�����Ӧ����union,find�Ĳ������������п��������˺ͳ�������ʾ��
	���������˾Ϳ��Ա�ʾ�������ǵ���ѯ�����󣬽����˷ֱ�¶������unordered_map<int,int>map���洢
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
	1.���������Ӷ�O(n*n)������ʱ
	2.hash����һ����ϣ���洢ÿ������Ӧ���±꣬���Ӷ�O(n)
	3.������Ȼ�����Ҽбƣ�����O(nlogn),���Ҽб�O(n),����O(nlogn).������Ҫ���ص����±꣬���������ֱ�����������в�ͨ
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
	������Ȼ�����Ҽбƣ����Ӷ�O(n*n)
	������������ƹ㵽k-sum��������Ȼ����k-2��ѭ���������ڲ�ѭ�����Ҽбƣ�ʱ�临�Ӷ���O(max{nlogn,n��k-1�η�})
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
