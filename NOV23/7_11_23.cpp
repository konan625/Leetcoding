https : // leetcode.com/problems/eliminate-maximum-number-of-monsters/submissions/

        O(NxN) +
        O(NlogN) + O(N) class Solution
{
public:
    int eliminateMaximum(vector<int> &dist, vector<int> &speed)
    {
        int n = dist.size();
        vector<int> time(n);
        for (int i = 0; i < n; i++)
        {
            time[i] = (dist[i]) / speed[i];
            if (dist[i] % speed[i] != 0)
                time[i]++;
        }
        sort(time.begin(), time.end());
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            count++;
            for (int j = i + 1; j < n; j++)
            {
                time[j]--;
                if (time[j] <= 0)
                    return count;
            }
        }
        return count;
    }
};

O(NlogN) + O(N) + O(N) class Solution
{
public:
    int eliminateMaximum(vector<int> &dist, vector<int> &speed)
    {
        int n = dist.size();
        vector<int> time(n);
        for (int i = 0; i < n; i++)
        {
            time[i] = (dist[i]) / speed[i];
            if (dist[i] % speed[i] != 0)
                time[i]++;
        }
        sort(time.begin(), time.end());
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            time[i] = time[i] - count;
            if (time[i] <= 0)
                return count;
            count++;
        }
        return count;
    }
};