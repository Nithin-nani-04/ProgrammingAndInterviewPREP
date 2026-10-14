#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define TABLE_SIZE 200003

typedef struct
{
    int key;
    int used;
} Entry;

int hash(int key)
{
    unsigned int x = (unsigned int)key;
    x ^= x >> 16;
    x *= 0x7feb352dU;
    x ^= x >> 15;
    return x % TABLE_SIZE;
}

int contains(Entry *set, int key)
{
    int pos = hash(key);

    while (set[pos].used)
    {
        if (set[pos].key == key)
            return 1;

        pos = (pos + 1) % TABLE_SIZE;
    }

    return 0;
}

void insert(Entry *set, int key)
{
    int pos = hash(key);

    while (set[pos].used)
    {
        if (set[pos].key == key)
            return;

        pos = (pos + 1) % TABLE_SIZE;
    }

    set[pos].key = key;
    set[pos].used = 1;
}

int longestConsecutive(int *nums, int numsSize)
{
    if (numsSize == 0)
        return 0;

    Entry *set = calloc(TABLE_SIZE, sizeof(Entry));
    if (set == NULL)
        return 0;

    for (int i = 0; i < numsSize; i++)
        insert(set, nums[i]);

    int longest = 0;

    for (int i = 0; i < numsSize; i++)
    {
        int x = nums[i];

        // Start only at the beginning of a sequence.
        if (x != (-2147483647 - 1) && contains(set, x - 1))
            continue;

        int count = 1;
        while (x != 2147483647 && contains(set, x + 1))
        {
            x++;
            count++;
        }

        if (count > longest)
            longest = count;
    }

    free(set);
    return longest;
}
int main()
{
    int nums[] = {100, 4, 200, 1, 3, 2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    printf("Longest consecutive sequence: %d\n", longestConsecutive(nums, numsSize));
    return 0;
}