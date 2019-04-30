/*Each input file contains one test case. For each case,
the first line contains 3 numbers (all no more than 1000): 
M (the maximum capacity of the stack), N (the length of push sequence), and K (the number of pop sequences to be checked). 
Then K lines follow, each contains a pop sequence of N numbers. 
All the numbers in a line are separated by a space.*/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main(){
	int m,n,k;
	cin>>m>>n>>k;
	for(int i=0;i<k;i++){
		stack<int> s;
		vector<int> v(n + 1);
		for(int j=1;j<=n;j++)
			cin>>v[j];
		int cur=1;
		for(int j=1;j<=n;j++){
			s.push(j);
			if(s.size() > m)
				break;
			while(!s.empty() && s.top()==v[cur]){
				s.pop();
				cur++;
			}
		}
		if(cur == n+1)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
