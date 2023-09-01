#include <bits/stdc++.h>
using namespace std;


void LPS(string pat, int M, int* lps){
	int len = 0, i = 1;
	lps[0] = 0; 
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

void KMPSearch(string &pat, string &txt)
{
	int M = pat.size(), N = txt.size();
	int lps[M];
	LPS(pat, M, lps);
	int i = 0, j = 0;
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

// Driver program to test above function
int main()
{
    string txt, pat;
    txt = "saippuakauppias";
    pat = "pp";
	KMPSearch(pat, txt);
	return 0;
}
