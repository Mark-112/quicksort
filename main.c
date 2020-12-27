#include <stdio.h>
#include <stdlib.h>
void quicksort(int *a, int l, int r, int* s, int* p)
{
    if(r - l <= 0)
        return;
    int l1, r1, tmp;
    l1 = l;
    r1 = r;
    int m = a[(l + r) / 2];
    while(l1 < r1)
    {
        while(l1 != (l + r) / 2)
        {
            *s += 1;
            if (a[l1] < m)
                l1++;
            else
                break;
        }
        while(r1 != (l + r) / 2)
        {
            *s += 1;
            if(a[r1] > m)
                r1--;
            else
                break;
        }
        if(l1 < r1)
        {
            *p+=1;
            tmp = a[l1];
            a[l1] = a[r1];
            a[r1] = tmp;
            r1--;
            l1++;
        }
        else
        {
            if(l1 == r1)
                l1 += 1;
            break;
        }
    }
    quicksort(a, l, r1, s, p);
    quicksort(a, l1, r, s, p);
}

int main()
{
    printf("vvedite chislo elemintov massiva\n");
    int n, i, s, p;
    s = 0;
    p = 0;
    scanf("%d", &n);
    int a[n];
    printf("vvedite massiv\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    quicksort(&a, 0, n-1, &s, &p);

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\nkolichestvo sravneniy: %d", s);
    printf("\nkolichestvo perestanovok: %d", p);

    return 0;
}

/* ÌÀÑÑÈÂ 2 3 1 4
1) ÑÐÀÂÍÈÂÀÅÌ 2 È 3
2) ÑÐÀÂÍÈÂÀÅÌ 4 È 3
3) ÑÐÀÂÍÈÂÀÅÌ 1 È 3
4) ÏÅÐÅÑÒÀÂËßÅÌ 3 È 1
5) ÑÐÀÂÍÈÂÀÅÌ 1 È 2
6) ÏÅÐÅÑÒÀÂËßÅÌ 1 È 2
7) ÑÐÀÂÍÈÂÀÅÌ 4 È 3
ÏÎËÓ×ÈËÎÑÜ 5 ÑÐÀÂÍÅÍÈÉ È 2 ÏÅÐÅÑÒÀÍÎÂÊÈ
*/
