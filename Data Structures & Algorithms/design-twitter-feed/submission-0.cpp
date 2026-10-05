class Twitter {
public:
    // user -> people they follow
    unordered_map<int, unordered_set<int>> following;

  
    unordered_map<int, vector<pair<int, int>>> tweets;

    int timer = 0;

    Twitter() {
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timer++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        // max heap:
        // {timestamp, userId, index of tweet}
        priority_queue<
            tuple<int, int, int>
        > pq;

        // User's own tweets
        if (tweets.count(userId) && !tweets[userId].empty()) {
            int idx = tweets[userId].size() - 1;
            auto [time, tweetId] = tweets[userId][idx];

            pq.push({time, userId, idx});
        }

        // Tweets from followed users
        for (int followee : following[userId]) {
            if (!tweets.count(followee) || tweets[followee].empty())
                continue;

            int idx = tweets[followee].size() - 1;
            auto [time, tweetId] = tweets[followee][idx];

            pq.push({time, followee, idx});
        }

        vector<int> ans;

        while (!pq.empty() && ans.size() < 10) {
            auto [time, user, idx] = pq.top();
            pq.pop();

            ans.push_back(tweets[user][idx].second);

           
            if (idx > 0) {
                int nextIdx = idx - 1;
                int nextTime = tweets[user][nextIdx].first;

                pq.push({nextTime, user, nextIdx});
            }
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};