#include <bits/stdc++.h>
using namespace std;

int getDeepestPit(vector<int> &heights){
  int maxL=-1;
  bool isDecreasing=true;
  int curL=0;

  for(int i =1; i<(int)heights.size(); i++){
    if (heights[i] < heights[i-1]) {
      if (isDecreasing) { // suppose to decrease
        curL++;
      } else { // suppose to increase
        maxL = max(maxL, curL);
        curL = 0;
        isDecreasing = true;
      }
    } else if (heights[i] > heights[i-1]) {
      if (isDecreasing) { // suppose to decrease
        if (curL == 0) { // could happen when finding first seq
          curL = 0;
        } else { // could happen when finding reached bottom fo pit
          curL++;
          maxL = max(maxL, curL);
          isDecreasing = false;
        }
      } else { // suppose to increase
        curL++;
        maxL = max(maxL, curL);
      }
    }
  }
  return maxL;
}

int main() {
  vector<int> heights = {5,4,3,2,1,2};
  cout << getDeepestPit(heights) << endl;
  return 0;
}
