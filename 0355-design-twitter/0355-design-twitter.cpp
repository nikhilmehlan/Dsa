class Twitter {
private:
    unordered_map<int,unordered_set<int>> followers;
    unordered_map<int,vector<pair<int,int>>> tweets;
    int time;
public:
    Twitter() {
        time=0;

    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;
        vector<int> feed;

        if(tweets.find(userId) !=tweets.end()){
            for(auto& entry:tweets[userId]){
                pq.push(entry);
            }
        }
        if(followers.find(userId) !=followers.end()){
            for(int fId:followers[userId]){
                if(tweets.find(fId) !=tweets.end()){
                    for(auto& t:tweets[fId]){
                        pq.push(t);
                    }
                }
            }
        }

        int count=10;
        while(!pq.empty() && count--){
            feed.push_back(pq.top().second);
            pq.pop();
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId!=followeeId){
            followers[followerId].erase(followeeId);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */