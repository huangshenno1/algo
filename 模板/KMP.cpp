//KMP

void getnext(char *P,int *next)
{
	int i = 0, j = -1;
	next[0] = -1;
	while(i < strlen(P))
	{
		if (j == -1 || P[i] == P[j])
		{
			i++; j++;
			if (P[i] == P[j]) next[i] = next[j]; // optimize
			else next[i] = j;
		}
		else j = next[j];
	}
}

int kmp(char* S,char* P,int pos)
{
	int i = pos, j = 0, lenS = strlen(S), lenP = strlen(P);
	while (i < lenS && j < lenP)
	{
		if (j==-1 || S[i] == P[j]) {i++; j++;}
		else j = next[j];
	}
	if (j == lenP) return i - lenP;
	else return -1;
}