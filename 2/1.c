//--- Day 2: Cube Conundrum ---
// Kosa Matyas


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isGamePossible(char game[], int redCount, int greenCount, int blueCount)
{

    int gameRed = 0;
    int gameGreen = 0;
    int gameBlue = 0;
    char *gameRecord = strchr(game, ':') + 2;
    char *subsetStart = gameRecord;
    char *subsetEnd;

    do
    {
        subsetEnd = strchr(subsetStart, ';');

        if (subsetEnd != NULL)
        {
            *subsetEnd = '\0';
        }

        char *cube = strtok(subsetStart, ",");
        while (cube != NULL)
        {
            char color[10];
            int count;
            sscanf(cube, "%d %s", &count, color);

            if (strcmp(color, "red") == 0)
            {
                gameRed += count;
            }
            else if (strcmp(color, "green") == 0)
            {
                gameGreen += count;
            }
            else if (strcmp(color, "blue") == 0)
            {
                gameBlue += count;
            }

            cube = strtok(NULL, ",");
        }
        if ((gameRed <= redCount) && (gameGreen <= greenCount) && (gameBlue <= blueCount))
        {
            gameRed = 0;
            gameGreen = 0;
            gameBlue = 0;
        }
        else{
            return 0;
        }

        subsetStart = subsetEnd + 1;
    } while (subsetEnd != NULL);

    return 1;
}

int main()
{
    int redCount = 12;
    int greenCount = 13;
    int blueCount = 14;

    FILE *file = fopen("input.txt", "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    char line[200];
    int gameID = 1;
    int sumOfPossibleGames = 0;

    while (fgets(line, sizeof(line), file) != NULL)
    {
        line[strcspn(line, "\n")] = 0;
        if (isGamePossible(line, redCount, greenCount, blueCount))
        {
            sumOfPossibleGames += gameID;
            
        }
        gameID++;
    }

    fclose(file);

    printf("Sum of IDs of possible games: %d\n", sumOfPossibleGames);

    return 0;
}
