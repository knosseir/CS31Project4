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
	
	string h[7] = { "jill", "hillary", "donald", "tim", "", "evan", "gary" };
	assert(lookup(h, 7, "evan") == 5);
	assert(lookup(h, 7, "donald") == 2);
	assert(lookup(h, 2, "donald") == -1);
	assert(positionOfMax(h, 7) == 3);

	string g[4] = { "jill", "hillary", "gary", "mindy" };
	//assert(differ(h, 4, g, 4) == 2);
	assert(appendToAll(g, 4, "?") == 4 && g[0] == "jill?" && g[3] == "mindy?");
	assert(rotateLeft(g, 4, 1) == 1 && g[1] == "gary?" && g[3] == "hillary?");

	string e[4] = { "donald", "tim", "", "evan" };
	assert(subsequence(h, 7, e, 4) == 2);

	string d[5] = { "hillary", "hillary", "hillary", "tim", "tim" };
	assert(countRuns(d, 5) == 2);

	string f[3] = { "gary", "donald", "mike" };
	assert(lookupAny(h, 7, f, 3) == 2);
	assert(flip(f, 3) == 3 && f[0] == "mike" && f[2] == "gary");

	assert(separate(h, 7, "gary") == 3);

	cout << "All tests succeeded" << endl;
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
	int count = 0, sameStringCount = 1;

	for (int i = 0; i < n; i += sameStringCount)
	{
		sameStringCount = 1;
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] == a[j])
			{
				sameStringCount++;
			}
			else
			{
				count++;
				break;
			}
		}
		if (i >= n - sameStringCount) count++;
	}
	return count;
}

int flip(string a[], int n)
{
	int j = n - 1;
	string temp = "";

	for (int i = 0; i < n / 2; i++)
	{
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
		j--;
	}

	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	return n;

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
	return -1;
}

int subsequence(const string a1[], int n1, const string a2[], int n2)
{
	for (int i = 0; i < n1; i++)
	{
		if (a2[0] == a1[i])
		{
			for (int j = 0; j < n2; j++)
			{
				if (a2[j] == a1[i + 1])
				{
					return i;
				}
			}
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
			if (a1[i] == a2[j]) return i;
		}
	}
	return -1;
}

int separate(string a[], int n, string separator)
{
	int pos = 0;
	string temp;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i] < a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}

	while ((a[pos] < separator) && pos < n) pos++;

	for (int i = 0; i < n; i++) cout << a[i] << " ";

	return pos;
}
