#include <iostream>
#include <string>
#include <cctype>
#include <cassert>

using namespace std;

int appendToAll(string a[], int n, string value);
int lookup(const string a[], int n, string target);
int positionOfMax(const string a[], int n);
int rotateLeft(string a[], int n, int pos);
int countRuns(const string a[], int n);
int flip(string a[], int n);
int differ(const string a1[], int n1, const string a2[], int n2);
int subsequence(const string a1[], int n1, const string a2[], int n2);
int lookupAny(const string a1[], int n1, const string a2[], int n2);
int separate(string a[], int n, string separator);

int main()
{
		
}

int appendToAll(string a[], int n, string value)
{
	if (n < 0) return -1;						
	for (int i = 0; i < n; i++) a[i] += value;		//append value to each element of a[]
	return n;
}

int lookup(const string a[], int n, string target)
{
	for (int i = 0; i < n; i++)
		if (a[i] == target) return i;				//return the index of the element that matches target
	return -1;										//if no elements in a[] match target, return 1
}

int positionOfMax(const string a[], int n)
{
	string max;
	int positionOfMax = -1;							//initialize positionOfMax to -1 so that the function returns -1 if n < 0

	if (n == 1) return n - 1;

	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];								//sets the maximum string
			positionOfMax = i;						//sets the index of the string
		}
	}
	return positionOfMax;
}

int rotateLeft(string a[], int n, int pos)
{
	if ((n < 0) || (pos >= n) || (n == 0)) return -1;

	string temp = a[pos];						//keep track of current element in the array at position pos
	for (int i = pos + 1; i < n; i++)			//starts at pos + 1 so that nothing before pos is affected
		a[i - 1] = a[i];						//move each element to the left

	a[n - 1] = temp;							//move the original element at pos to the very end of the array

	return pos;
}

int countRuns(const string a[], int n)
{
	int count = 0, sameStringCount = 1;

	if (n < 0) return -1;

	for (int i = 0; i < n; i += sameStringCount)		//i += sameStringCount so the loop skips words that are the same
	{
		sameStringCount = 1;
		for (int j = i + 1; j < n; j++)					//j begins at i + 1 because there is no use checking for the same word prior to the current element
		{
			if (a[i] == a[j]) sameStringCount++;
			else
			{
				count++;								//increment count if the current element is not followed by the same element
				break;
			}
		}
		if (i >= n - sameStringCount) count++;			//handles case where the last element of the array is the same as the one before it
	}
	return count;
}

int flip(string a[], int n)
{
	int j = n - 1;										//j begins at n - 1 so that it is the last element in the array
	string temp;

	if (n < 0) return -1;

	for (int i = 0; i < n / 2; i++)			//i < n / 2 so that the loop doesn't reverse the changes it made, otherwise the function would be useless
	{
		temp = a[i];	//temporarily store the current element
		a[i] = a[j];	//set the current element equal to the element at j
		a[j] = temp;	//set the element at j equal to the element previously at the current index
		j--;			//decrement j so that it moves backwards
	}

	return n;
}

int differ(const string a1[], int n1, const string a2[], int n2)
{
	int index = n1;

	if (n2 < n1) index = n2;

	if ((n1 < 0) || (n2 < 0)) return -1;

	for (int i = 0; i < index; i++)
	{
		if (a1[i] != a2[i]) return i;

		if (i == index - 1) return index;
	}
	return 0;
}

int subsequence(const string a1[], int n1, const string a2[], int n2)
{
	if (n2 > n1) return -1;							//a2 cannot be a subsequence of a1 if a2 is longer than a1, so return -1 if this is the case

	if (n2 == 0) return 0;							//if a2 is empty, then it is a subsequence of everything starting at position 0

	for (int i = 0; i < n1; i++)
	{
		if (a1[i] == a2[0])							//go on if an element in a1 equals the first element in a2
		{
			for (int j = 1; j < n2; j++)
			{
				if (a2[j] == a1[i + 1]) return i;	//return the first position in which the subsequence begins if a2 is a subsequence of a1
			}	
			if (n2 == 1) return i;					//if n2 only has one element, then no need to check its subsequent elements
		}
	}
	return -1;
}

int lookupAny(const string a1[], int n1, const string a2[], int n2)
{
	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < n2; j++)
		{
			if (a1[i] == a2[j]) return i;			//check every element in a1 for any element of a2
		}
	}
	return -1;
}

int separate(string a[], int n, string separator)	//arranges a into alphabetical order
{
	int pos = 0;
	string temp;

	if (n < 0) return -1;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i] < a[j])
			{
				temp = a[i];	//temporarily store the current element
				a[i] = a[j];	//set the current element equal to the element at j
				a[j] = temp;	//set the element at j equal to the element previously at the current index
			}
		}
	}
	while ((pos < n) && (a[pos] < separator)) pos++;	//finds the first element that is not less than separator

	return pos;
}
