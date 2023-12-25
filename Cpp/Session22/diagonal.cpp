#include <iostream>
#include <vector>
using namespace std;

int diagonalDifference(vector<vector<int>> arr) 
{
    int sum_fwd=0;
    int sum_back=0;
    int result = 0;
//    for(int i=0;i<arr.size();i++) 
//    {
//        for(int j=0;j<=arr[i].size();j++) //fwd
//        {
//            if(i==j)
//            {
//                sum_fwd +=arr[i][j];
//            }
//        }
//    }
//    result = sum_fwd;
   int j=0;
   for(int i=arr.size()-1;i>=0;i--) //back
   {
       sum_back+=arr[i][j];
       j++;
   }
   // result = abs(sum_fwd-sum_back);
   result = sum_back;
   return result;
}

int main()
{
    vector<vector<int>> vect
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    cout << "res = " << diagonalDifference(vect) << endl;
}