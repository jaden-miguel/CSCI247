#include <stdio.h>
#include <string.h>
#include "sort.h"
#include <stdlib.h>

// Name: Jaden Miguel
// Date: Spring 2020
// Lab 4, CSCI247

/* Automobile
 * As an avid collector of cars, I keep track of my collection with the
 * following structure.  I want to know the model name, the year it was
 * produced, and the price that I paid.  I'm rather fond of my collection.  What
 * do you think about it?  
 */
struct automobile
{
  const char *name;
  unsigned year;
  unsigned price;
};

struct automobile one = {
    "AMC Pacer",
    1975,
    12900};

struct automobile two = {
    "Cadillac Fleetwood",
    1981,
    4995};

struct automobile three = {
    "Ford Pinto",
    1971,
    4200};

struct automobile four = {
    "Suzuki X90",
    1996,
    1625};

struct automobile five = {
    "Chrysler TC",
    1991,
    2495};

struct automobile six = {
    "Cadillac Cimarron",
    1986,
    4990};

struct automobile seven = {
    "Plymouth Prowler",
    1997,
    60000};

struct automobile eight = {
    "Ford Edsel",
    1958,
    17000};

struct automobile nine = {
    "Yugo",
    1985,
    3990};

struct automobile ten = {
    "Pontiac Aztek",
    2001,
    603};

/* Test Data
 * Here I'm creating an array that points to the structures defined above.  I'm
 * using pointers here to match the expectations of the sort routine.  
 */
unsigned data_size = 10;
struct automobile *data[10] = {
    &one,
    &two,
    &three,
    &four,
    &five,
    &six,
    &seven,
    &eight,
    &nine,
    &ten};

// function to create structs, then compare
int cmp(void *x, void *y)
{
  struct automobile *a = (struct automobile *)x;
  struct automobile *b = (struct automobile *)y;

  if (a->year < b->year)
  {
    return 0;
  }
  else if (a->year > b->year)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

/* Test program
 *
 * This program tests sort_array with an array of automobile objects.  Or
 * rather, an array of pointers to automobile objects.
 *
 *   DO NOT MODIFY THE FOR-LOOP OR ITS CONTENTS.  
 */
int main()
{
  int i;
  int status = EXIT_SUCCESS;

  sort_array((void **)data, data_size, &cmp);

  for (i = 0; i < data_size - 1; ++i)
  {
    if (data[i]->year > data[i + 1]->year)
    {
      fprintf(stderr,
              "\"%s\" and \"%s\" are out of order\n",
              data[i]->name,
              data[i + 1]->name);
      status = EXIT_FAILURE;
    }
  }

  return status;
}
