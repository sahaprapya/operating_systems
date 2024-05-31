#include <stdio.h>
#include <stdbool.h>
int pn;
int predict(int page[], int fr[], int pn, int fn, int index)
{
    int res = -1, farthest = index;
    for (int i = 0; i < fn; i++)
    {
        int j;
        for (j = index; j < pn; j++)
        {
            if (fr[i] == page[j])
            {
                if (j > farthest)
                {
                    farthest = j;
                    res = i;
                }
                break;
            }
        }
        if (j == pn)
            return i;
    }
    return (res == -1) ? 0 : res;
}
bool search(int key, int fr[], int fn)
{
    for (int i = 0; i < fn; i++)
        if (fr[i] == key)
            return true;
    return false;
}
void opr(int page[], int pn, int fn)
{
    float rh,rf;
    int fr[fn];
    int hit = 0;
    int filled = 0;
    for (int i = 0; i < fn; i++)
    {
        fr[i] = -1;
    }
    for (int i = 0; i < pn; i++)
    {
        if (search(page[i], fr, fn))
        {
            hit++;
            continue;
        }
        if (filled < fn)
        {
            fr[filled] = page[i];
            filled++;
        }
        else
        {
            int j = predict(page, fr, pn, fn, i + 1);
            fr[j] = page[i];
        }
    }
    rh=((float)hit/pn)*100.0;
    rf=((float)(pn-hit)/pn)*100.0;
    printf("Hits = %d\n", hit);
    printf("Misses = %d\n", pn - hit);
    printf("Hits = %.2f%\n", rh);
    printf("Misses = %.2f%\n", rf);
}
int main()
{
    printf("Enter the number of pages: ");
    scanf("%d", &pn);
    int page[pn];
    printf("Enter the pages: ");
    for (int i = 0; i < pn; i++)
    {
        scanf("%d", &page[i]);
    }
    int fn;
    printf("Enter the number of frames: ");
    scanf("%d", &fn);
    opr(page, pn, fn);
    return 0;
}

// 7 0 1 2 0 3 0 4 2 3 0 3 0 3 2 1 2 0 1 7 0 1
