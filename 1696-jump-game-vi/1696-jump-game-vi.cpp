class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        	int n = nums.size();

	deque<pair<int, int>> q; // <index, max_path_sum>
	q.push_back({0, nums[0]});

	for (int i = 1; i < n; ++i) {
		int cur = nums[i] + q.front().second;
		while (!q.empty() && cur >= q.back().second)
			q.pop_back();
		q.push_back({i, cur});
		
		if (q.front().first <= i - k)
			q.pop_front();
	}

	return q.back().second;
    }
};