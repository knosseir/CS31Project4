#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int appendToAll(string a[], int n, string value);
int lookup(const string a[], int n, string target);
int positionOfMax(const string a[], int n);
int rotateLeft(string a[], int n, int pos);
int countRuns(const string a[], int n);

int main()
{
	string arr[] = { "one", "two", "three", "four", "five" };
	//int y = appendToAll(arr, -2, "mississippi");
	//cout << y << endl;

	//int r = lookup(arr, -2, "two");
	//cout << r << endl;

	//string cand[6] = { "jill", "hillary", "donald", "tim", "evan", "mike" };
	//int k = positionOfMax(cand, 6);   // returns 3, since  tim  is latest
									  // in alphabetic order
	//cout << k << endl;

	//string running[5] = { "evan", "donald", "gary", "jill", "hillary" };
	//int m = rotateLeft(running, 5, 1);  // returns 1
										// running now contains:  "evan", "gary", "jill", "hillary", "donald"
	//cout << m << endl;

	//int f = rotateLeft(arr, 5, 2);
	//cout << f << endl;

	string d[9] = {
		"tim", "ajamu", "mike", "mike", "donald", "donald", "donald", "mike", "mike"
	};
	int p = countRuns(d, 9);  //  returns 5
	cout << p << endl;
}

int appendToAll(string a[], int n, string value)
{
	if (n < 0) return -1;
	for (int i = 0; i < n; i++)
	{
		a[i] += value;
		cout << a[i] << endl;	//remember to remove this line
	}
	return n;

}

int lookup(const string a[], int n, string target)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == target) return i;
	}
	return -1;
}

int positionOfMax(const string a[], int n)
{
	string max = "";
	int positionOfMax = -1;

	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
			positionOfMax = i;
		}
	}
	return positionOfMax;
}

int rotateLeft(string a[], int n, int pos)
{
	if (n < 0) return -1;

	string temp = a[pos];
	for (int i = pos + 1; i < n; i++)
	{
		a[i - 1] = a[i];
	}
	a[n - 1] = temp;

	for (int i = 0; i < n; i++)		//remove
		cout << a[i] << endl;		//these lines
	return pos;
}

int countRuns(const string a[], int n)
{
	string current = "";
	int consecutiveStringCount = 0;

	for (int i = 0; i < n; i++)
	{
		current = a[i];
		while (a[i + 1] == current)
		{
			i++;
		}
		consecutiveStringCount++;
	}
	return consecutiveStringCount;

}
