/**
 * @file main.c
 * @author Stevie Alvarez (stevie.6strings@gmail.com)
 * @brief Calculates the monthly rent for each resident.
 * @version 0.1
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


char* USAGE = "Usage: %s [OPTIONS]... [RENT] [DATE]\nOptions\n\t-h\n\t\tprints this usage message\n\t-s\n\t\tsave's the calculated rent under the provided date in rent.csv\nArguments\n\t- Rent\n\t\trent amount to two decimal places\n\t- Date\n\t\t(optional) should be in dd-mm-yyyy format\n";


typedef enum calc_mode { CALC, SAVE } Mode;


/**
 * @brief Given monthly rent, calculate amount owed per resident.
 * 
 * @param argc Argument count
 * @param argv Argument array
 * @return int Success code
 */
int main(int argc, char const *argv[])
{
  char* date;
  float rent;
  Mode mode = CALC;
  int opt;

  while ((opt = getopt(argc, argv, "hs")) != -1) 
  {
    switch (opt) 
    {
    case 'h': fprintf(stdout, USAGE, argv[0]); return EXIT_SUCCESS;
    case 's': mode = SAVE; break;
    default: break;
    }
  }

  if (optind == argc) {
    fprintf(stderr, USAGE, argv[0]);
    return EXIT_FAILURE;
  }

  if (mode == CALC) {
    // TODO

  } else if (mode == SAVE) {
    // TODO
  }

  // read each resident file
  // generate expenditures (per roommate)
  // print to stdout
  // save results to csv
  return EXIT_SUCCESS;
}

