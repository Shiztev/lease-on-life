/**
 * @file expenser.h
 * @author Stevie Alvarez (stevie.6strings@gmail.com)
 * @brief Process resident expenditures.
 * @version 0.1
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "expenses.h"

struct expense
{
  char *expense_type;
  float amount;
};

struct resident
{
  char *name;
  Expense *expenses;
  int num_expenses;
};
