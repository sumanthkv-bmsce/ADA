#include<stdio.h>


void towerOfHanoi(int n, char src, char dest, char temp) 
{ 
    if (n == 1) 
    { 
        printf("\n Move disk 1 from rod %c to rod %c", src, dest); 
        return; 
    } 
    towerOfHanoi(n-1, src, temp, dest); 
    printf("\n Move disk %d from rod %c to rod %c", n, src, dest); 
    towerOfHanoi(n-1, temp, dest, src); 
} 
  
int main() 
{ 
    int n = 4; 
    towerOfHanoi(n, 'A', 'C', 'B');  
    return 0; 
} 

