#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
  
  // Function to count substrings with at most k distinct characters
  long long int countAtMostK(string s, int k){
      int left = 0, right = 0;
      long long int count = 0;
      int freq[26] = {0}; // Frequency array for lowercase characters
      int distinct = 0;   // Number of distinct characters in the window
      
      while (right < s.length()) {
          // Add the current character to the window
          if (freq[s[right] - 'a'] == 0) {
              distinct++; // New distinct character found
          }
          freq[s[right] - 'a']++;
          right++;
          
          // If the number of distinct characters exceeds 'k', shrink the window
          while (distinct > k) {
              freq[s[left] - 'a']--;
              if (freq[s[left] - 'a'] == 0) {
                  distinct--; // One distinct character is completely removed
              }
              left++;
          }
          
          // Add valid substrings from left to right
          count += (right - left);
      }
      
      return count;
  }
  
  // Function to count substrings with exactly k distinct characters
  long long int substrCount (string s, int k) {
      // Substrings with exactly k distinct characters = 
      // Substrings with at most k distinct characters - Substrings with at most k-1 distinct characters
      return countAtMostK(s, k) - countAtMostK(s, k-1);
  }
};