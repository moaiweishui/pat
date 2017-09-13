#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  int n;
  cin >> n;
  
  vector<int> v;
  vector<int> left;
  vector<int> right(n);
  
  int tmp;
  
  int max = -1;
  
  for(int i = 0; i < n; i++)
  {
    cin>>tmp;
    v.push_back(tmp);
    left.push_back(max);
    if (v[i] > max)
      max = v[i];
  }
  
  int min = 1000000000 + 1;
  for (int i = n - 1; i >= 0; i--)
  {
    right[i] = min;
    if (v[i] < min)
      min = v[i];
  }
  
  int cnt = 0;
  vector<int> nums;

  for (int i = 0; i < n; i++)
  {
    if (v[i]>left[i] && v[i] < right[i])
    {
      cnt++;
      nums.push_back(v[i]);
    }
  }
  cout << cnt << endl;
  sort(nums.begin(), nums.end());

  for (int i = 0; i < cnt; i++)
  {
    cout << nums[i];
    if (i != cnt - 1)
      cout << ' ';
  }
  if(cnt == 0)
    cout<<'\n';
  
  return 0;
  
}
