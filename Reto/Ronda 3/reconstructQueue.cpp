/*
406. Queue Reconstruction by Height
Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person 
and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.

Note:
	The number of people is less than 1,100.


Example
	Input:
		[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

	Output:
		[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
*/


class Solution {
public:

    static bool flag(const pair<int,int> &x, const pair<int,int> &y){
	    return ((x.second<y.second) || (x.second==y.second&&x.first>y.first));
	}

	vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
	    
	    sort(people.begin(),people.end(), flag);   
	    
	    for(int i=0; i<people.size(); i++){
	        
	        int curr = people[i].second;
	        
	        if(curr<i){

	            int index = 0;

	            for(; index<i && curr>0; index++)
	                if(people[index].first>=people[i].first)
	                    curr--;

	            people.insert(people.begin()+index,people[i]);
	            people.erase(people.begin()+i+1);
	        }
	    }
	    
	    return people;
	}
};

