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

#if !defined(HAVE_GETOPT_H)  // from getopt.h
int optind = 0;
#endif


char* USAGE = "Usage: %s [OPTIONS]... [RENT] [DATE]\nOptions\n\t-h\n\t\tprints this usage message\n\t-s\n\t\tsave's the calculated rent under the provided date in rent.csv\nArguments\n\t- Rent\n\t\trent amount to two decimal places\n\t- Date\n\t\t(necessary for -s) should be in dd-mm-yyyy format\n";
int ARG_CALC_C = 2;
int ARG_SAVE_C = 4;


typedef enum calc_mode { CALC, SAVE } Mode;


int handle_error(char* name)
{
  fprintf(stderr, USAGE, name);
  return EXIT_FAILURE;
}


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
    case 's': if (argc >= ARG_SAVE_C) { mode = SAVE; break; }
              else { return handle_error(argv[0]); }

    default: break;
    }
  }

  if (optind == argc) {  // Note: optind defined by unistd.h
    return handle_error(argv[0]);
  }

  if (argc >= ARG_CALC_C) {
    rent = atof(argv[optind++]);
    // TODO: calculate rent per roommate

    // read each resident file
    // generate expenditures (per roommate)
    // print to stdout

    if (mode == SAVE) {
      date = argv[optind++];
      // TODO: save results to csv
    }

  } else {
    return handle_error(argv[0]);
  }

  return EXIT_SUCCESS;
}

