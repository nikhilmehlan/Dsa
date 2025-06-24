
struct Item{
    int value;
    int weight;
};


bool compare(Item a ,Item b){
    return ((double)a.value/a.weight) > ((double)b.value/b.weight);
}

class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n=val.size();
        vector<Item> temp(n);
        for(int i=0;i<n;i++){
            temp[i]={val[i],wt[i]};
        }
        sort(temp.begin(),temp.end(),compare);
        
        double totalvalue=0.0;
        for(int i=0;i<n;i++){
            if(temp[i].weight <= capacity){
                totalvalue += temp[i].value;
                capacity -= temp[i].weight;
            } else {
                totalvalue += ((double)temp[i].value / temp[i].weight) * capacity;
                break;
            }

        }
        return totalvalue;
    }
};
