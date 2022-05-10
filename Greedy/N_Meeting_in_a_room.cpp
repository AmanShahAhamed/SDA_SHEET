#include<bits/stdc++.h>
bool comp(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b){
	
	return a.first.second<b.first.second;
}

vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    
	vector<pair<pair<int,int>,int>> v;
	for(int i=0;i<start.size();i++)
	v.push_back({{start[i],end[i]},i});
	sort(v.begin(),v.end(),comp);
	vector<int> ans;
	ans.push_back(v[0].second+1);
	int prev=v[0].first.second;
	for(int i=1;i<start.size();i++){
		if(v[i].first.first>prev){
			prev=v[i].first.second;
			ans.push_back(v[i].second+1);
		}
	}
	return ans;
}
