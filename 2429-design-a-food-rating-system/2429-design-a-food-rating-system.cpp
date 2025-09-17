#include <string>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;

class FoodRatings {
    // Maps food name to its current rating
    unordered_map<string, int> foodToRating;
    
    // Maps food name to its cuisine
    unordered_map<string, string> foodToCuisine;
    
    // Maps cuisine to a multiset of {rating, food} sorted by descending rating and ascending food name
    unordered_map<string, set<pair<int, string>>> cuisineToFoods;
    
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        
        for (int i = 0; i < n; ++i) {
            string food = foods[i];
            string cuisine = cuisines[i];
            int rating = ratings[i];
            
            foodToRating[food] = rating;
            foodToCuisine[food] = cuisine;
            
            // Store negative rating to sort in descending order
            cuisineToFoods[cuisine].insert({-rating, food});
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = foodToCuisine[food];
        int oldRating = foodToRating[food];
        
        // Remove old entry
        cuisineToFoods[cuisine].erase({-oldRating, food});
        
        // Update rating
        foodToRating[food] = newRating;
        
        // Insert new entry
        cuisineToFoods[cuisine].insert({-newRating, food});
    }
    
    string highestRated(string cuisine) {
        // The first element in the set is the one with highest rating and lex smallest name
        return cuisineToFoods[cuisine].begin()->second;
    }
};
