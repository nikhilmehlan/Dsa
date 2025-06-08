class Solution {
public:
    vector<int> majorityElement(vector<int>& v) {
    int cnt1=0;
	int cnt2=0;
	int el1=INT_MIN;
	int el2=INT_MIN;

	for(int i=0;i<v.size();i++){
		if(cnt1==0 && v[i]!=el2){
			cnt1=1;
			el1=v[i];
		}
		else if(cnt2==0 && v[i]!=el1){
			cnt2=1;
			el2=v[i];
		}
		else if(v[i]==el1){
			cnt1++;
		}
		else if(v[i]==el2){
			cnt2++;
		}
		else{
			cnt1--;
			cnt2--;
		}
	}
	vector<int> ans;
	int ct1=0; int ct2=0;
	for(int i=0;i<v.size();i++){
		if(v[i]==el1) ct1++;
		if(v[i]==el2) ct2++;
	}
	int mini=(v.size()/3)+1;
	if(ct1>=mini){
		ans.push_back(el1);
	}
	if(ct2>=mini){
		ans.push_back(el2);
	}
	return ans;
    }
};