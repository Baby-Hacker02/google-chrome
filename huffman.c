#include <stdio.h>

int main()
{
    int n, i, j, min1, min2;
    int freq[20], left[40], right[40];
    int code[20], top, node;
    char ch[20];

    printf("Enter number of characters: ");
    scanf("%d", &n);

    printf("Enter characters and frequencies:\n");

    for (i = 0; i < n; i++)
    {
        scanf(" %c %d", &ch[i], &freq[i]);
        left[i] = right[i] = -1;
    }

    for (i = n; i < 2 * n - 1; i++)
    {
        min1 = -1;
        min2 = -1;

        for (j = 0; j < i; j++)
        {
            if (left[j] == -1 && right[j] == -1)
            {
                if (min1 == -1 || freq[j] < freq[min1])
                {
                    min2 = min1;
                    min1 = j;
                }
                else if (min2 == -1 || freq[j] < freq[min2])
                {
                    min2 = j;
                }
            }
        }

        freq[i] = freq[min1] + freq[min2];
        left[i] = min1;
        right[i] = min2;
    }

    printf("\nHuffman Codes:\n");

    for (i = 0; i < n; i++)
    {
        node = i;
        top = 0;

        while (node >= n)
        {
            if (node == left[node])
                break;

            code[top++] = 0;
            node = left[node];

            if (node == i)
                break;
        }

        // Generate code by traversing from leaf to root
        node = i;
        top = 0;

        while (node < 2 * n - 1)
        {
            int parent = -1;

            for (j = n; j < 2 * n - 1; j++)
            {
                if (left[j] == node || right[j] == node)
                {
                    parent = j;

                    if (right[j] == node)
                        code[top++] = 1;
                    else
                        code[top++] = 0;

                    break;
                }
            }

            if (parent == -1)
                break;

            node = parent;
        }

        printf("%c : ", ch[i]);

        for (j = top - 1; j >= 0; j--)
        {
            printf("%d", code[j]);
        }

        printf("\n");
    }

    return 0;
}
