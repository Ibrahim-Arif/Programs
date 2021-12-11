#include <stdio.h>
#include <stdlib.h>
#define STATION_CODE_LENGTH 4

typedef struct _station {
    char code[STATION_CODE_LENGTH];
    struct _station *next;
} Station;

typedef struct _route {
    Station *first_station;
    unsigned int num_station;
} Route;

Route* read_stations(FILE *file){
    char c[STATION_CODE_LENGTH], blankSpace[STATION_CODE_LENGTH];
    Route *list = (Route*)malloc(sizeof(Route));
    list->first_station = NULL;
    list->num_station = 0;
    Station *temp;



    while(fgets(c, STATION_CODE_LENGTH, file) != NULL) {
        fgets(blankSpace, STATION_CODE_LENGTH, file);       // reading blank space after reading each code from file.

        temp = (Station*)malloc(sizeof(Station));
        int i;
        for(i=0; i<STATION_CODE_LENGTH; i++)
            temp->code[i] = c[i];

        temp->next = list->first_station;
        list->first_station = temp;
        list->num_station++;
    }

    return list;
};

void display(Route *list){
    Station *station = list->first_station;

    while(station != NULL){
        printf("%s \n", station->code);
        station = station->next;
    }

    return;
}

void search(Route *list, char c[STATION_CODE_LENGTH]){
    Station *station = list->first_station;
    int count = 0, found = 0;

    while(station != NULL){
        count++;
        if(station->code[0] == c[0] && station->code[1] == c[1] && station->code[2] == c[2]){
            printf("Position of \"%s\": %d", c, count);

            if(station->next != NULL){
                printf("\nFirst next stop: %s", station->next->code);

                if(station->next->next  != NULL)
                    printf("\nSecond next stop: %s", station->next->next->code);
            }

            found = 1;
            break;
        }
        station = station->next;
    }

    if(!found)
        printf("!!! \"%s\" not found !!!", c);

    return;
}

int main()
{
    FILE *file = fopen("code.txt", "r");
    Route *list;
    char c[STATION_CODE_LENGTH];

    if (file == NULL){
      printf("!!! File reading failed !!! \n");
      exit(0);
    }

    list = read_stations(file);
    display(list);

    printf("\n\nPlease enter a station code to search: ");
    scanf("%s", c);
    search(list, c);

    printf("\n");
    fclose(file);
    return 0;
}
