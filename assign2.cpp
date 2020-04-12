#include <bits/stdc++.h> 
#include<iostream>
using namespace std; 
  
int c_one(int n) 
{ 
    int count = 0; 
    while (n) { 
        n = n & (n - 1); 
        count++; 
    } 
  
    if (count % 2 == 0) 
        return 1; 
    else
        return 0; 
} 
  
int addition(int n) 
{ 
    int sum = 0; 
    while (n != 0) { 
        sum += n % 10; 
        n /= 10; 
    } 
  
    return sum; 
} 
  
int main() 
{ 
    int arr[] = { 4, 9, 15 }; 
      
    int n = sizeof(arr) / sizeof(arr[0]); 
    int total_sum = 0; 
    for (int i = 0; i < n; i++) { 
        if (c_one(arr[i])) 
            total_sum += addition(arr[i]); 
    } 
  
    cout << total_sum << '\n'; 
      
    return 0; 
} 
