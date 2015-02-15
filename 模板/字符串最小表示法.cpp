//�ַ�����С��ʾ��

int MinimumRepresentation(char *s, int l)
{
    int i = 0, j = 1, k = 0, d;
    while (i < l && j < l && k < l)
    {
        d = s[i+k>=l ? i+k-l : i+k] - s[j+k>=l ? j+k-l : j+k];
        if (d == 0) k++;
        else
        {
            if (d > 0) i = i + k + 1;
            else j = j + k + 1;
            if (i == j) j++;
            k = 0;
        }
    }
    return i < j ? i : j;
}
