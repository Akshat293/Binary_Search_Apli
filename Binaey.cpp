// These Programs are written by Akshat saxena
#include <sstream>
#include <iostream>
#include <string>
#include <list>
#include <map>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <stack>
#include <unordered_map>
#include <utility>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair
const int mod = 1e9 + 7;
#define REP(i, a, b) for (int i = a; i <= b; i++)
// binary serach is used on sorted array
//Time Complexity is O(logn)
int  binarysearch(int arr[], int n, int key)
{
    int start = 0, end = n - 1;
    while (end >= start)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            end = mid - 1;
        }
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }
    }

    return -1;
}
int recbinary(int arr[], int low, int high, int x)
{
    if (low > high)
    {
        return -1;
    }
    int mid = (low + high) / 2;
    if (arr[mid] == x)
        return mid;
    else if (arr[mid] > x)
        return recbinary(arr, low, mid - 1, x);
    else
        return recbinary(arr, mid + 1, high, x);
}
int firstinrec(int arr[], int low, int high, int x)
{
    // Time complexity O(logn)
    // space Complexity O(logn)
    if (low > high)
    {
        return -1;
    }
    int mid = (low + high) / 2;
    if (arr[mid] == x && arr[mid - 1] < x)
        return mid;
    else if (arr[mid] > x)
        return recbinary(arr, low, mid - 1, x);
    else if (arr[mid] < x)
        return recbinary(arr, mid + 1, high, x);
    else if (mid == 0 || arr[mid - 1] != arr[mid]) // corner case
        return mid;
    else
        return recbinary(arr, low, mid - 1, x);
}
int firstinIt(int arr[], int low, int high, int x)
{
    while (high >= low)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > x)
            high = mid - 1;
        else if (arr[mid] < x)
            low = mid + 1;
        else if (mid == 0 || arr[mid - 1] != arr[mid])
            return mid;
        else
            high = mid - 1;
    }
    return -1;
}
int lastinIt(int arr[], int low, int high, int x, int n)
{
    while (high >= low)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > x)
            high = mid - 1;
        else if (arr[mid] < x)
            low = mid + 1;
        else if (mid == n - 1 || arr[mid + 1] != arr[mid])
            return mid;
        else
            low = mid + 1;
    }
    return -1;
}
int reclast(int arr[], int low, int high, int x, int n)
{
    if (low > high)
    {
        return -1;
    }
    int mid = (low + high) / 2;
    if (arr[mid] > x)
        return reclast(arr, low, mid - 1, x, n);
    else if (arr[mid] < x)
        return reclast(arr, mid + 1, high, x, n);
    else if (mid == n - 1 || arr[mid + 1] != arr[mid]) // corner case
        return mid;
    else
        return reclast(arr, mid + 1, high, x, n);
}
// count occurance using binary search
int cntusingbin(int arr[], int n, int x)
{
    int first = firstinIt(arr, 0, n - 1, x);
    if (first == -1)
        return -1;
    else
        return (lastinIt(arr, 0, n - 1, x, n) - first + 1);
}
// count 1 in sorted binary search
// Since array is sorted after 1st on rest will be 1
int countOnes(int arr[], int n)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == 0)
            low = mid + 1;
        else
        {
            if (mid == 0 || arr[mid - 1] == 0)
                return (n - mid);
            else
                high = mid - 1;
        }
    }

    return 0;
}
// find square root of the number
// Time complexity O(sqrt(n))
int sq(int n){
    int res=1, i=1;
    while(res<=n){
        i++;
        res=i*i;
    }
    return i-1;
}
// find square root using binary search
int binsqrt(int n){
// Base cases
    if (n == 0 || n == 1)
    return n;
 
    // Do Binary Search for floor(sqrt(x))
    int start = 1, end = n, ans;
    while (start <= end)
    {        
        int mid = (start + end) / 2;
 
        // If x is a perfect square
        if (mid*mid == n)
            return mid;
 
        // Since we need floor, we update answer when mid*mid is
        // smaller than n, and move closer to sqrt(n)
        if (mid*mid < n)
        {
            start = mid + 1;
            ans = mid;
        }
        else // If mid*mid is greater than x
            end = mid-1;        
    }
    return ans;
}
// Binary search to find cube root;
int bincube(int n){
// Base cases
    if (n == 0 || n == 1)
    return n;
 
    // Do Binary Search for floor(sqrt(x))
    int start = 1, end = n, ans;
    while (start <= end)
    {        
        int mid = (start + end) / 2;
 
        // If x is a perfect cube
        if (mid*mid*mid == n)
            return mid;
 
        // Since we need floor, we update answer when mid*mid is
        // smaller than n, and move closer to cuberoot(n)
        if (mid*mid*mid < n)
        {
            start = mid + 1;
            ans = mid;
        }
        else // If mid*mid*mid is greater than x
            end = mid-1;        
    }
    return ans;




}
// Search in Infinite sized  sorted array
// Unbounded Binary Search
//Time complexity O(log(position))
int search(int arr[], int x)
{
    if(arr[0] == x) return 0;

	int i = 1;

	while(arr[i] < x)
		i = i * 2;

	if(arr[i] == x) return i;


	return recbinary(arr, i / 2 + 1, i - 1, x);
}
// Search in sorted rotated array
// compare middle with high and low
int searchinRO(int arr[], int n, int x)
{
   	int low = 0, high = n - 1;

	while(low <= high)
	{
		int mid = (low + high) / 2;

		if(arr[mid] == x)
			return mid;
		if(arr[low] < arr[mid])
		{
			if(x >= arr[low] && x < arr[mid])
				high = mid - 1;
			else 
				low = mid + 1;
		}
		else
		{
			if(x > arr[mid] && x <= arr[high])
				low = mid + 1;
			else
				high = mid - 1;
		}
	}
	

	return -1;
}
// Get the peak element of a unsorted array
int getPeak(int arr[], int n)
{
	int low = 0, high = n - 1;

		while(low <= high)
		{
			int mid = (low + high) / 2;

			if((mid == 0 || arr[mid - 1] <= arr[mid]) &&
				(mid == n - 1 || arr[mid + 1] <= arr[mid]))
				return mid;
			if(mid > 0 && arr[mid - 1] >= arr[mid])
				high = mid -1;
			else
				low = mid + 1;
		}
	return -1;
}

int main()
{

    int a[6] = {4, 5, 6, 6, 6, 54};
    sort(a, a + 5);
    //binarysearch(a,5,54);
    //cout<<recbinary(a,0,4,4)<<endl;
    //cout<<firstinrec(a,0,4,67)<<endl;
    //cout << firstinIt(a, 0, 4, 67) << endl;
    // cout<<lastinIt(a,0,5,6,6)<<endl;
    //cout<<reclast(a,0,5,6,6)<<endl;
    //cout<<cntusingbin(a,6,6)<<endl;
     int b[8]={0,0,0,0,1,1,1,1};
     //cout<<countOnes(b,8)<<endl;
       //cout<<sq(12)<<endl;
       //cout<<binsqrt(9)<<endl;  
       //cout<<bincube(1331)<<endl;
      //cout<<search(a,54)<<endl;

    return 0;
}