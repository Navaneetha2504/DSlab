#include <stdio.h>
#include <string.h>

void main() 
{
    char input[100];
    
    printf("Enter the string: ");
    scanf("%s", input);

    findLongestSubstring(input);
}

void findLongestSubstring(char *s) 
{
    int n = strlen(s);
    int start = 0, end = 0;
    int maxLength = 0, currentLength = 0;
    int startIndex = 0;

    int visited[256]; 

    for (int i = 0; i < 256; i++) 
    {
        visited[i] = -1; 
    }

    while (end < n)
    {
        if (visited[s[end]] == -1 || visited[s[end]] < start) 
        {
            visited[s[end]] = end;
            currentLength = end - start + 1;

            if (currentLength > maxLength) 
            {
                maxLength = currentLength;
                startIndex = start;
            }

            end++;
        }
        else 
        {
            start = visited[s[end]] + 1;
        }
    }

    printf("Length of the longest substring without repeating characters: %d\n", maxLength);
    printf("Longest substring without repeating characters: ");
    for (int i = startIndex; i < startIndex + maxLength; i++)
    {
        printf("%c", s[i]);
    }
    printf("\n");
}
