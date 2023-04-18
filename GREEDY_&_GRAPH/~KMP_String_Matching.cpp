#include <bits/stdc++.h>
using namespace std;


void KMPSearch(string &pat, string &txt)
{
	int M = pat.size();
	int N = txt.size();

	int lps[M];

	LPS(pat, M, lps);

	int i = 0; // index for txt[]
	int j = 0; // index for pat[]
	while ((N - i) >= (M - j)) {
		if (pat[j] == txt[i]) {
			j++;
			i++;
		}

		if (j == M) {
			printf("Found pattern at index %d ", i - j);
			j = lps[j - 1];
		}

		else if (i < N && pat[j] != txt[i]) {
			if (j != 0){j = lps[j - 1];}
			else{i = i + 1;}	
		}
	}
}

void LPS(string pat, int M, int* lps)
{
	int len = 0;
	lps[0] = 0; 

	
	int i = 1;
	while (i < M) {
		if (pat[i] == pat[len]) {
			len++;
			lps[i] = len;
			i++;
		}
		else{
			if (len != 0) {len = lps[len - 1];}
			else {
				lps[i] = 0;
				i++;
			}
		}
	}
}

// Driver program to test above function
int main()
{

    string txt, pat;
    txt = "ABABDABACDABABCABAB";
    pat = "ABABCABAB";
	KMPSearch(pat, txt);
	return 0;
}
