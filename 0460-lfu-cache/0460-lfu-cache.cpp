
class LFUCache {
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (keyToValueFreq.find(key) == keyToValueFreq.end()) {
            return -1; // Key not found
        }

        // Update frequency of the key
        updateFrequency(key);
        return keyToValueFreq[key].first; // Return the value
    }

    void put(int key, int value) {
        if (capacity == 0) return; // No capacity to store elements

        if (keyToValueFreq.find(key) != keyToValueFreq.end()) {
            // Key already exists, update value and frequency
            keyToValueFreq[key].first = value;
            updateFrequency(key);
        } else {
            // Key does not exist, insert new key-value pair
            if (keyToValueFreq.size() == capacity) {
                // Cache is full, remove the least frequently used key
                int lfuKey = freqToKeys[minFreq].back(); // Least recently used key in the minimum frequency list
                freqToKeys[minFreq].pop_back(); // Remove it from the frequency list
                keyToValueFreq.erase(lfuKey); // Erase the key from key-value map
                keyToIter.erase(lfuKey); // Erase the key from key-iterator map
            }

            // Insert the new key with frequency 1
            keyToValueFreq[key] = {value, 1};
            freqToKeys[1].push_front(key);
            keyToIter[key] = freqToKeys[1].begin();
            minFreq = 1; // Reset minimum frequency to 1
        }
    }

private:
    int capacity;
    int minFreq; // Minimum frequency of keys in the cache
    unordered_map<int, pair<int, int>> keyToValueFreq; // Key to {value, frequency}
    unordered_map<int, list<int>> freqToKeys; // Frequency to list of keys
    unordered_map<int, list<int>::iterator> keyToIter; // Key to iterator in the frequency list

    void updateFrequency(int key) {
        int freq = keyToValueFreq[key].second; // Current frequency of the key
        keyToValueFreq[key].second++; // Increment frequency

        // Remove the key from the current frequency list
        freqToKeys[freq].erase(keyToIter[key]);

        // If the current frequency list is empty and this was the minimum frequency, increment minFreq
        if (freqToKeys[freq].empty() && freq == minFreq) {
            freqToKeys.erase(freq);
            minFreq++;
        }

        // Add the key to the new frequency list
        freqToKeys[freq + 1].push_front(key);
        keyToIter[key] = freqToKeys[freq + 1].begin();
    }
};
