// copied the following solution:
// https://atcoder.jp/contests/adt_medium_20240523_1/editorial/6855
#include <bits/stdc++.h>
using namespace std;

char s[110][110];
int check(int i, int j) {
	for (int ii=0;ii<3;ii++)for(int jj=0; jj<3; jj++)if(s[i+ii][j+jj]!='#')return 0;
	for (int ii=0;)

}