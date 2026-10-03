class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        // Count frequency of each task
        vector<int> freq(26, 0);

        for (char task : tasks) {
            freq[task - 'A']++;
        }

        // Find maximum frequency
        int maxFreq = 0;

        for (int f : freq) {
            maxFreq = max(maxFreq, f);
        }

        // Count how many tasks have maximum frequency
        int countMax = 0;

        for (int f : freq) {
            if (f == maxFreq) {
                countMax++;
            }
        }

        int N = tasks.size();

        // Minimum cycles forced by the cooldown
        int formula = (maxFreq - 1) * (n + 1) + countMax;

        // Either cooldown is the limiting factor,
        // or the number of tasks itself is the limiting factor.
        return max(formula, N);
    }
};