#include <stdio.h>
#include <stdlib.h>

struct candidate {
    char letter;
    int votes;
    float percent;
};

// a helper function to return total number of lines in text file.
// total number of line = total districts
int getTotalDistricts(char filename[]){
    FILE *file = fopen(filename, "r");
    int totalDist=0;

    char line[80];
    while(fgets(line, 80, file))
        totalDist++;

    fclose(file);
    return totalDist;
}

// function to sort candidates by votes in descending order.
void sortByVotes(struct candidate candidates[4]){
    int i, j, tempIndex;
    struct candidate temp;

    for(i=0; i<3; i++) {
        tempIndex = i;
        for(j=i+1; j<=3; j++){
            if(candidates[j].votes > candidates[tempIndex].votes)
                tempIndex = j;
        }

        temp = candidates[tempIndex];
        candidates[tempIndex] = candidates[i];
        candidates[i] = temp;
    }
}

// function to read data from file and store in cross-ponding dynamically allocated array.
int readFile(char filename[], int *aVotes, int *bVotes, int *cVotes, int *dVotes){
    FILE * file = fopen(filename, "r");
    int totalVotes=0, vote, i=0;
    char temp[20];

    if (file == 0)
        return totalVotes;

    while (fscanf(file, "%s", temp) != EOF){
        vote = atoi(temp);
        totalVotes += vote;
        aVotes[i] = vote;

        fscanf(file, "%s", temp);
        vote = atoi(temp);
        totalVotes += vote;
        bVotes[i] = vote;

        fscanf(file, "%s", temp);
        vote = atoi(temp);
        totalVotes += vote;
        cVotes[i] = vote;

        fscanf(file, "%s", temp);
        vote = atoi(temp);
        totalVotes += vote;
        dVotes[i] = vote;

        i++;
    }

    fclose(file);
    return totalVotes;
}

// function to calculate total votes and average for each candidate.
void calculate(struct candidate candidates[4], int *aVotes, int *bVotes, int *cVotes, int *dVotes, int totalVotes, int totalDist){
    int i;
    for(i=0; i<totalDist; i++){
        candidates[0].votes += aVotes[i];
        candidates[1].votes += bVotes[i];
        candidates[2].votes += cVotes[i];
        candidates[3].votes += dVotes[i];
    }

    for(i=0; i<4; i++)
        candidates[i].percent = ((float)candidates[i].votes / (float)totalVotes) *100;
}

// function to display winner;
void getWinner(struct candidate candidates[4]){
    int i;
    for(i=0; i<4; i++){
        if(candidates[i].percent > 50){
            printf("Winner: %c", candidates[i].letter);
            return;
        }
    }

    sortByVotes(candidates);
    printf("Second round: %c and %c", candidates[0].letter, candidates[1].letter);
    return;
}


int main(int argc, char *argv[])
{
    // if no filename given then program will break.
    if(argc < 2){
        printf("Insufficient arguments !!! \n");
        exit(0);
    }

    struct candidate candidates[4];
    int totalVotes=0, i, totalDist;
    totalDist = getTotalDistricts(argv[1]);

    // dynamically allocation of memory to arrays of votes.
    int *aVotes = (int*) malloc(sizeof(int) * totalDist);
    int *bVotes = (int*) malloc(sizeof(int) * totalDist);
    int *cVotes = (int*) malloc(sizeof(int) * totalDist);
    int *dVotes = (int*) malloc(sizeof(int) * totalDist);


    // initializing candidates.
    char ch='A';
    for(i=0; i<4; i++){
        candidates[i].letter = ch++;
        candidates[i].votes = 0;
        candidates[i].percent = 0;
    }

    totalVotes = readFile(argv[1], aVotes, bVotes, cVotes, dVotes);
    calculate(candidates, aVotes, bVotes, cVotes, dVotes, totalVotes, totalDist);
    getWinner(candidates);

    return 0;
}
