#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 20011

typedef struct
{
    int key;
    int index;
    int used;
} Entry;

int hash(int key)
{
    unsigned int x = (unsigned int)key;
    return x % TABLE_SIZE;
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    Entry *table = calloc(TABLE_SIZE, sizeof(Entry));
    if (table == NULL)
    {
        *returnSize = 0;
        return NULL;
    }

    for (int i = 0; i < numsSize; i++)
    {
        int complement = target - nums[i];
        int pos = hash(complement);

        while (table[pos].used)
        {
            if (table[pos].key == complement)
            {
                int *result = malloc(2 * sizeof(int));

                if (result == NULL)
                {
                    free(table);
                    *returnSize = 0;
                    return NULL;
                }

                result[0] = table[pos].index;
                result[1] = i;
                *returnSize = 2;

                free(table);
                return result;
            }

            pos = (pos + 1) % TABLE_SIZE;
        }

        pos = hash(nums[i]);

        while (table[pos].used && table[pos].key != nums[i])
        {
            pos = (pos + 1) % TABLE_SIZE;
        }

        if (!table[pos].used)
        {
            table[pos].key = nums[i];
            table[pos].index = i;
            table[pos].used = 1;
        }
    }

    free(table);
    *returnSize = 0;
    return NULL;
}

int main()
{
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int returnSize;
    int *result = twoSum(nums, 4, target, &returnSize);

    if (result != NULL)
    {
        for (int i = 0; i < returnSize; i++)
        {
            printf("%d ", result[i]);
        }
        free(result);
    }
    else
    {
        printf("No solution found.\n");
    }

    return 0;
}