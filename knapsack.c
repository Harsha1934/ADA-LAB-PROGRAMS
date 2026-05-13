
#include <stdio.h>
int main()
{
    int n, cap;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    int w[n], p[n], index[n];
    float ratio[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter weight and profit of item %d: ", i + 1);
        scanf("%d %d", &w[i], &p[i]);
        ratio[i] = (float)p[i] / w[i];
        index[i] = i + 1;
    }
    printf("Enter the capacity: ");
    scanf("%d", &cap);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (ratio[i] < ratio[j])
            {

                float temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;
                int t = w[i];
                w[i] = w[j];
                w[j] = t;
                t = p[i];
                p[i] = p[j];
                p[j] = t;
                t = index[i];
                index[i] = index[j];
                index[j] = t;
            }
        }
    }
    float totalProfit = 0;
    int remaining = cap;
    float taken[n];
    for (int i = 0; i < n; i++)
        taken[i] = 0;
    for (int i = 0; i < n; i++)
    {
        if (w[i] <= remaining)
        {
            taken[i] = 1;
            totalProfit += p[i];
            remaining -= w[i];
        }
        else
        {
            taken[i] = (float)remaining / w[i];
            totalProfit += taken[i] * p[i];
            break;
        }
    }
    printf("\nObjects taken:\n");
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (taken[i] > 0)
        {
            printf("Item %d -> %.2f\n", index[i], taken[i]);
            count++;
        }
    }
    printf("\nNumber of objects taken: %d\n", count);
    printf("Maximum Profit: %.2f\n", totalProfit);

    return 0;
}
