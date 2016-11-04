#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int appendToAll(string a[], int n, string value);
int lookup(const string a[], int n, string target);
int positionOfMax(const string a[], int n);
int rotateLeft(string a[], int n, int pos);
int countRuns(const string a[], int n);
int flip(string a[], int n);
int differ(const string a1[], int n1, const string a2[], int n2);
int lookupAny(const string a1[], int n1, const string a2[], int n2);

int main()
{
	string arr[5] = { "one", "two", "three", "four", "five" };
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
	//int p = countRuns(arr, 5);  //  returns 5
	//cout << p << endl;

	//string folks[6] = { "ajamu", "mike", "", "tim", "mindy", "bill" };
	//int q = flip(folks, 4);  // returns 4
							 // folks now contains:  "tim"  ""  "mike"  "ajamu"  "mindy"  "bill"
	string folks[6] = { "ajamu", "mike", "", "tim", "mindy", "bill" };
	string group[5] = { "ajamu", "mike", "bill", "", "tim" };
	string test[5] = { "one", "two", "three", "four", "five" };
	int r = differ(folks, 6, group, 5);  //  returns 2
	int s = differ(folks, 2, group, 1);  //  returns 1
	int t = differ(arr, 5, test, 5);
	cout << r << endl << s << endl << t << endl;
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
	int count = 0;

	for (int i = 0; i < n; i++)
	{

	}

	return count;
}

int flip(string a[], int n)
{
	return 0;
}

int differ(const string a1[], int n1, const string a2[], int n2)
{
	int index;

	if (n1 < n2) index = n1;
	if (n2 < n1) index = n2;
	else index = n1;

	for (int i = 0; i < index; i++)
	{
		if (a1[i] != a2[i])
		{
			return i;
		}
		if (i == index - 1) return index;
	}
}

int lookupAny(const string a1[], int n1, const string a2[], int n2)
{

	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < n2; j++)
		{
			if (a1[i] == a2[j]) return i;
		}
	}
	return -1;
}
