#include <stdio.h>

struct Item {
    int value;
    int weight;
    float ratio;
};

void sortItems(struct Item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (items[i].ratio < items[j].ratio) {
                struct Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}

int main() {
    int n, capacity;
    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];
    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    for (int i = 0; i < n; i++) {
        printf("Enter value and weight of item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    sortItems(items, n);

    float totalValue = 0.0;
    int remainingCapacity = capacity;

    for (int i = 0; i < n; i++) {
        if (items[i].weight <= remainingCapacity) {
            totalValue += items[i].value;
            remainingCapacity -= items[i].weight;
        } else {
            totalValue += items[i].ratio * remainingCapacity;
            break;
        }
    }

    printf("Maximum value in knapsack = %.2f\n", totalValue);
    return 0;
}
#include <stdio.h>

struct Item {
    int value;
    int weight;
    float ratio;
};

void sortItems(struct Item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (items[i].ratio < items[j].ratio) {
                struct Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}

int main() {
    int n, capacity;
    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];
    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    for (int i = 0; i < n; i++) {
        printf("Enter value and weight of item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    sortItems(items, n);

    float totalValue = 0.0;
    int remainingCapacity = capacity;

    for (int i = 0; i < n; i++) {
        if (items[i].weight <= remainingCapacity) {
            totalValue += items[i].value;
            remainingCapacity -= items[i].weight;
        } else {
            totalValue += items[i].ratio * remainingCapacity;
            break;
        }
    }

    printf("Maximum value in knapsack = %.2f\n", totalValue);
    return 0;
}
