class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        for (int i = 0; i < asteroids.size(); i++) {
            if (asteroids[i] > 0) {
                // Right-moving asteroid, just push
                st.push_back(asteroids[i]);
            } else {
                // Left-moving asteroid: check for collisions
                while (!st.empty() && st.back() > 0 && st.back() < abs(asteroids[i])) {
                    st.pop_back(); // Smaller right-moving asteroid explodes
                }

                // If equal size, both explode
                if (!st.empty() && st.back() > 0 && st.back() == abs(asteroids[i])) {
                    st.pop_back(); // Both destroyed
                }

                // If no collision, or top is left-moving
                else if (st.empty() || st.back() < 0) {
                    st.push_back(asteroids[i]);
                }

                // Else (right-moving asteroid survives), do nothing
            }
        }
        return st;
    }
};
