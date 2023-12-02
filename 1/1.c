// --- Day 1: Trebuchet?! ---
// Kosa Matyas

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *file = fopen("input.txt", "r");

    char line[1001];
    int sum = 0;

    while (fgets(line, sizeof(line), file) != NULL)
    {

        char firstDigit = '\0';
        char lastDigit = '\0';

        for (int i = 0; i < strlen(line); i++)
        {
            if (line[i] >= '0' && line[i] <= '9')
            {
                firstDigit = line[i];
                break;
            }
        }

        for (int i = strlen(line) - 1; i >= 0; i--)
        {
            
            if (line[i] >= '0' && line[i] <= '9')
            {
                lastDigit = line[i];
                break;
            }
        }

        if (firstDigit != '\0' && lastDigit != '\0')
        {
            int calibrationValue = (firstDigit - '0') * 10 + (lastDigit - '0');
            sum += calibrationValue;
        }
    }

    fclose(file);

    printf("%d\n", sum);
    return 0;
}
