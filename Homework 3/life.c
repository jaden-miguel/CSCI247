/* This is a cellular automation simulator.  The rules are very
 * simple.  The board is a grid.  Each grid square can hold at most
 * one cell.  For a cell to survive from generation to generation it
 * needs two or three neighbors.  Too many neighbors causes the cell
 * to starve.  Too few causes an incurable case of ennui.  All is not
 * lost.  If a grid square has exactly three neighbors, a new cell is
 * born, which is kind of strange when you think about it.
 */

// Name: Jaden Miguel
// Date: Summer 2020
// Purpose: CSCI247 HW3

#include "liblife.h"
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#define ALIVE(n, b) (n == 3) | (b & (n == 2))

int generation = 0;
int printLazy = 0;

void lazyPrint(board prv)
{
  int i = 9;
  while (i--)
  {
    printf("%d", prv[i][0]);
    printf("%d", prv[i][1]);
    printf("%d", prv[i][2]);
    printf("%d", prv[i][3]);
    printf("%d", prv[i][4]);
    printf("%d", prv[i][5]);
    printf("%d", prv[i][6]);
    printf("%d", prv[i][7]);
    printf("%d", prv[i][8]);
    printf("%d", prv[i][9]);

    printf("\n");
  }
  printf("\n");

  // sleep 1 second
  unsigned int time_to_sleep = 1;
  while (time_to_sleep)
  {
    time_to_sleep = sleep(time_to_sleep);
  }
}

/* Evolve: This is a very simple evolution function.  It applies the
 * rules of Conway's Game of Live as written.  There are a lot of
 * improvements that you can make.  Good luck beating lovelaa, she is
 * really good. I beat her tho !!
 */
void evolve(board prv, board nxt)
{
  register int i, j, n;

  //print statement for generations
  printf("\rGeneration %d\n", generation++);
  if (printLazy)
  {
    lazyPrint(prv);
  }

  //use loop unrolling to speed up process
  n = prv[0][1] + prv[1][0] + prv[1][1];
  nxt[0][0] = (n == 3) | (prv[0][0] & (n == 2));

  n = prv[0][WIDTH - 2] + prv[1][WIDTH - 2] + prv[1][WIDTH - 1];
  nxt[0][WIDTH - 1] = (n == 3) | (prv[0][WIDTH - 1] & (n == 2));

  n = prv[HEIGHT - 2][0] + prv[HEIGHT - 2][1] + prv[HEIGHT - 1][1];
  nxt[HEIGHT - 1][0] = ALIVE(n, prv[HEIGHT - 1][0]);

  n = prv[HEIGHT - 2][WIDTH - 2] + prv[HEIGHT - 2][WIDTH - 1] + prv[HEIGHT - 1][WIDTH - 2];
  nxt[HEIGHT - 1][WIDTH - 1] = ALIVE(n, prv[HEIGHT - 1][WIDTH - 1]);

  // first loop
  for (j = 1; j < WIDTH - 1; ++j)
  {
    n = prv[0][j - 1] + prv[0][j + 1] + prv[1][j - 1] + prv[1][j] + prv[1][j + 1];
    nxt[0][j] = (n == 3) | (prv[0][j] & (n == 2));
    n = prv[HEIGHT - 2][j - 1] + prv[HEIGHT - 2][j] + prv[HEIGHT - 2][j + 1] + prv[HEIGHT - 1][j - 1] + prv[HEIGHT - 1][j + 1];
    nxt[HEIGHT - 1][j] = (n == 3) | (prv[HEIGHT - 1][j] & (n == 2));
  }
  // continue
  for (i = 1; i < HEIGHT - 1; ++i)
  {
    n = prv[i - 1][0] + prv[i - 1][1] + prv[i][1] + prv[i + 1][0] + prv[i + 1][1];
    nxt[i][0] = (n == 3) | (prv[i][0] & (n == 2));
    n = prv[i - 1][WIDTH - 2] + prv[i - 1][WIDTH - 1] + prv[i][WIDTH - 2] + prv[i + 1][WIDTH - 2] + prv[i + 1][WIDTH - 1];
    nxt[i][WIDTH - 1] = (prv[i][WIDTH - 1] & (n == 2)) | (n == 3);
  }
  // unroll
  for (i = HEIGHT - 2; i > 0; --i)
  {
    for (j = WIDTH - 2; j > 0; --j)
    {
      n = prv[i - 1][j - 1] + prv[i - 1][j] + prv[i - 1][j + 1] + prv[i][j - 1] + prv[i][j + 1] + prv[i + 1][j - 1] + prv[i + 1][j] + prv[i + 1][j + 1];
      nxt[i][j] = (prv[i][j] & (n == 2)) | (n == 3);
    }
  }
}

/* The program takes one optional arugment: -fg (full GUI) or -lg
 * (lazy GUI).  The default (no option) tells the program to skip the
 * GUI components (in other words run silently), while lg tells the
 * program to print to the screen the left-most 10 x 10 cells of the
 * board using a "text-only" (hence lazy) GUI. The silent mode is much
 * more stable than the fg mode and what will be used measure your
 * code's performance.
 */
int main(int argc, char *argv[])
{

  // mode 1 : invalid number of arguments specified
  // mode 2 : -fg full GUI mode
  // mode 3 : -lg (lazy gui) console print GUI mode
  // mode 4 : silent (default)

  if (argc > 2)
  {
    fprintf(stderr, "Usage: %s [-fg or -lg]\n\t-fg Full GUID\n\t-lg Lazy GUI Mode\n", argv[0]);
    return EXIT_FAILURE;
  }
  else if ((argc == 2 && 0 == strcmp(argv[1], "-lg")))
  {
    printf("Running in -lg (Lazy GUI) mode\n");
    printLazy += 1;
    add_method("miguelj2", &evolve);
    run_game(1);
  }
  else if ((argc == 2 && 0 == strcmp(argv[1], "-fg")))
  {
    printf("Running in GUI mode\n");
    add_method("miguelj2", &evolve);
    run_game(0);
  }
  else if ((argc == 2 && (1 != strcmp(argv[1], "-fg") || 1 != strcmp(argv[1], "-lg"))))
  {
    fprintf(stderr, "Usage: %s [-fg or -lg]\n\t-fg Full GUID\n\t-lg Lazy GUI Mode\n", argv[0]);
    return EXIT_FAILURE;
  }
  else
  {
    printf("Running in silent (no GUI window) mode\n");
    add_method("miguelj2", &evolve);
    run_game(1);
  }
  return 0;
}
