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
	string j[10];
	string k[10] = { "" };
	string l[10] = { "a", "b", "c", "d", "d" };
	string m[10] = { "this is a string", "testing", "string" };
	string n[10] = { "a", "a", "a", "a" };
	string o[10] = { "STRING", "string" };
	string p[4] = { "j", "j", "o", "J" };
	string q[5] = { "a", "a", "B", "a", "a" };
	string h[7] = { "jill", "hillary", "donald", "tim", "", "evan", "gary" };
	string g[4] = { "jill", "hillary", "gary", "mindy" };
	string e[4] = { "donald", "tim", "", "evan" };
	string d[5] = { "hillary", "hillary", "hillary", "tim", "tim" };
	string f[3] = { "gary", "donald", "mike" };
	string r[1] = { "a" };
	string s[1] = { "this is a string" };
	/*
	assert(lookup(h, 2, "evan") == -1);
	assert(lookup(g, 4, "mindy") == 3);
	assert(lookup(j, 0, "evan") == -1);
	assert(lookup(k, 1, "evan") == -1);
	assert(lookup(k, 1, "") == 0);
	assert(lookup(l, 5, "c") == 2);
	assert(lookup(m, 3, "string") == 2);
	assert(lookup(m, 3, "STRING") == -1);

	assert(lookup(l, 5, "a") == 0);
	assert(positionOfMax(h, 7) == 3);
	assert(positionOfMax(l, 5) == 3);
	assert(positionOfMax(n, 4) == 0);
	assert(positionOfMax(j, 0) == -1);
	assert(positionOfMax(k, 1) == 0);
	assert(positionOfMax(o, 2) == 1);
	assert(positionOfMax(h, -3) == -1);
	assert(positionOfMax(h, 0) == -1);

	
	rotateLeft(j, 0, 0);
	rotateLeft(k, 1, 0);
	rotateLeft(l, 5, 4);
	rotateLeft(o, 2, 1);
	rotateLeft(j, -1, 2);
	rotateLeft(f, 3, 6);
	rotateLeft(f, 3, 3);
	

	assert(countRuns(l, 5) == 4);
	assert(countRuns(k, 1) == 1);
	assert(countRuns(o, 2) == 2);
	assert(countRuns(o, -2) == -1);
	assert(countRuns(o, 0) == 0);
	assert(countRuns(p, 4) == 3);
	assert(countRuns(d, 5) == 2);
	assert(countRuns(h, 7) == 7);
	assert(countRuns(n, 4) == 1);
	assert(countRuns(q, 5) == 3);

	assert(lookup(h, 7, "evan") == 5);
	assert(lookup(h, 7, "donald") == 2);
	assert(lookup(h, 2, "donald") == -1);
	assert(positionOfMax(h, 7) == 3);

	assert(differ(h, 4, g, 4) == 2);
	assert(appendToAll(g, 4, "?") == 4 && g[0] == "jill?" && g[3] == "mindy?");
	assert(rotateLeft(g, 4, 1) == 1 && g[1] == "gary?" && g[3] == "hillary?");

	assert(subsequence(h, 7, e, 4) == 2);
	assert(countRuns(d, 5) == 2);
	assert(lookupAny(h, 7, f, 3) == 2);
	assert(flip(f, 3) == 3 && f[0] == "mike" && f[2] == "gary");

	assert(separate(h, 7, "gary") == 3);
	

	//flip(h, 7);
	//cout << endl;
	//flip(h, 4);
	//cout << endl;
	//flip(e, 4);
	//cout << endl;
	//flip(j, 0);
	//cout << endl;
	//flip(k, 1);
	//cout << endl;
	//flip(m, 3);
	//cout << endl;
	//flip(p, 4);
	assert(flip(m, -1) == -1);
	assert(flip(m, 0) == 0);
	*/
	assert(differ(j, 0, h, 7) == 0);
	assert(differ(h, 7, j, 0) == 0);
	assert(differ(h, 7, k, 1) == 0);
	assert(differ(k, 1, h, 7) == 0);
	assert(differ(k, -1, h, 7) == -1);
	assert(differ(h, 7, k, -1) == -1);
	assert(differ(g, 4, h, 7) == 2);
	assert(differ(l, 5, n, 4) == 1);
	assert(differ(r, 1, l, 5) == 1);
	assert(differ(l, 5, r, 1) == 1);
	assert(differ(n, 4, o, 3) == 0);
	assert(differ(n, 4, n, 4) == 4);

	assert(subsequence(j, 0, k, 1) == -1);
	assert(subsequence(k, 1, g, 4) == -1);
	assert(subsequence(j, -2, g, 4) == -1);
	assert(subsequence(l, 5, r, 1) == 0);
	assert(subsequence(o, 2, m, 3) == -1);
	assert(subsequence(m, 3, s, 1) == 0);
	assert(subsequence(s, 1, m, 3) == -1);

	assert(lookupAny(f, 3, j, 0) == -1);
	assert(lookupAny(h, 7, k, 1) == 4);
	assert(lookupAny(h, 0, f, 3) == -1);
	assert(lookupAny(h, 7, f, -4) == -1);
	assert(lookupAny(m, 3, s, 1) == 0);
	assert(lookupAny(h, 7, r, 1) == -1);

	//separate(h, 7, "a");
	//separate(h, 7, "");
	//separate(g, 4, "h");
	//separate(l, 5, "B");
	//separate(m, 3, "");
	

	cout << "All tests succeeded" << endl;
}

int appendToAll(string a[], int n, string value)
{
	if (n < 0) return -1;
	for (int i = 0; i < n; i++) a[i] += value;
	return n;
}

int lookup(const string a[], int n, string target)
{
	for (int i = 0; i < n; i++)
		if (a[i] == target) return i;
	return -1;
}

int positionOfMax(const string a[], int n)
{
	string max;
	int positionOfMax = -1;

	if (n == 1) return n - 1;

	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
			positionOfMax = i;
		}
	}

	for (int i = 0; i < n; i++) //remove
		cout << a[i] << " ";	//these lines
	return positionOfMax;
}

int rotateLeft(string a[], int n, int pos)
{
	if ((n < 0) || (pos >= n) || (n == 0)) return -1;

	string temp = a[pos];
	for (int i = pos + 1; i < n; i++) 
		a[i - 1] = a[i];

	a[n - 1] = temp;

	for (int i = 0; i < n; i++)
		cout << a[i] << " ";

	return pos;
}

int countRuns(const string a[], int n)
{
	int count = 0, sameStringCount = 1;

	if (n < 0) return -1;

	for (int i = 0; i < n; i += sameStringCount)
	{
		sameStringCount = 1;
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] == a[j]) sameStringCount++;
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
	string temp;

	if (n < 0) return -1;

	for (int i = 0; i < n / 2; i++)
	{
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
		j--;
	}

	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
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
	if (n2 > n1) return -1;

	if (n2 == 0) return 0;

	for (int i = 0; i < n1; i++)
	{
		if (a1[i] == a2[0])
		{
			for (int j = 1; j < n2; j++)
			{
				if (a2[j] == a1[i + 1]) return i;
			}
			if (n2 == 1) return i;
		}
	}
	return -1;
}

int lookupAny(const string a1[], int n1, const string a2[], int n2)
{
	//if ((n1 < 0) || (n2 < 0)) return -1;

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

	if (n < 0) return -1;

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
	while ((pos < n) && (a[pos] < separator)) pos++;

	for (int i = 0; i < n; i++)
		cout << a[i] << endl;

	return pos;
}
