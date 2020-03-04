#include<iostream>

using namespace std;

void insertion_sort(int *si,int n)
{
	int key1,key2,j;
	for(int i=1; i<n; i++)
	{
		key1 = si[i];
		key2 = fi[i];
		j = i-1;
		while(j>=0 && si[j]>key)
		{
			si[j+1] = si[j];
			fi[j+1] = ji[j];
			j--;
		}
		si[j+1] = key1;
		fi[j+1] = key2;
	}
}

void count_meeting(int *si,int *fi,int n);
{
	int max[n],top=-1,count = 0,s,f;
	for(int i=0; i<n; i++)
	{
		s = si[i];
		f = fi[i];
		for(j=i+1; j<n, j++)
		{
			
		}
	}
}


int main()
{
	int n;
	cout<<"\n Enter the number of meetings:";
	cin>>n;
	int Si[n],Fi[n];
	cout<<"\n Enter Start time and Finish time :";
	for(int i=0; i<n; i++)
	{
		cout<<"\nSi:";
		cin>>Si[i];
		cout<<"\t Fi:";
		cin>>Fi[i];
		cout<<"\n";
	}
	count_meeting(Si[],Fi[],n);
	return 0;
}
