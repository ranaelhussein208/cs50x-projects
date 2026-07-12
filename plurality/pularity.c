#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

int j;
int k;
int winner;
int winner_1;

// Function prototypes
bool vote(string name);
void print_winner(void);



int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}


bool vote(string name)
{
    for (i=0;i<candidate_count;i++)
    {
     if (name==candidates[i].name)
     {
      candidates[i].votes=candidates[i].votes+1;
      return true;
     }

    }
    return false;
}


void print_winner(void)
{


  winner_1=candidates[0].votes;
   for( j=1 ;j < candidate_count; j++)
   {
     if (candidates[j].votes >  winner_1)
     {
     winner_1 =candidates[j].votes;
     winner=j;
     }

   }
   printf("The winner is %s",candidates[winner].name );
    return;
}
