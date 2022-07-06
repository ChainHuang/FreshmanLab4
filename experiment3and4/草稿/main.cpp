//
//  main.cpp
//  草稿
//
//  Created by lulin on 2022/5/16.
//

#include <iostream>
#include <algorithm>
#include <math.h>
#include <climits>
const int N = 1e6 + 5;
int n, k;
int a[N];
int ra[N], la[N];
int main()
{
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    int l, sum, L;
    l = 1;
    sum = 0;
    la[0] = INT_MAX / 2 - 10;
    for(int i = 1; i <= n; i++)
    {
        sum += a[i];
        while(l <= i && sum > k)
        {
            sum -= a[l];
            l++;
        }
        if(l <= i && sum == k)
            L = l;
        else
            L = INT_MAX / 2 - 10;
        la[i] = fmin(la[i - 1], i - L + 1);
    }
    int r = n;
    sum = 0;
    ra[n + 1] = INT_MAX / 2 - 10;
    int R;
    for(int i = n; i >= 1; i--)
    {
        sum += a[i];
        while(i <= r &&sum > k)
        {
            sum -=a[r];
            r--;
        }
        if(i <= r && sum == k)
            R = r;
        else
            R = INT_MAX / 2 - 10;
        ra[i] = fmin(ra[i + 1], R - i + 1);
    }
    int ans = INT_MAX;
    for(int i = 1; i < n; i++)
    {
        ans = fmin(ans, la[i] + ra[i + 1]);
    }
    if(ans > n)
        ans = -1;
    printf("%d\n", ans);
}


