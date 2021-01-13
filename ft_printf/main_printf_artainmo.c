#include <stdio.h>
#include "ft_printf.h"

#define TITLE_GRN(x) puts("\033[32m"x"\033[m")
#define TITLE_BLU(x) puts("\033[36m"x"\033[m")
#define TITLE_YLW(x) puts("\033[33m"x"\033[m")
#define TITLE_RED(x) puts("\033[31m"x"\033[m")

#define BONUS 0

#define SEP puts("\033[33m======\033[m")

int main()
{
  char c = 'a';
  char *s = "string";
  int i = -132454845;
  int x = 1213432;
  int x2 = 0;
  unsigned int u = 2147483649;
  int amp = 12;
  int n;
  char *sc = "";


  int ret = 0;
  int ret2 = 0;

  /*
  **MANDATORY_PART SPECIFIERS
  */

TITLE_GRN("            ____  _____ ____ ___ _   _            ");
TITLE_GRN("           | __ )| ____/ ___|_ _| \\ | |           ");
TITLE_GRN("           |  _ \\|  _|| |  _ | ||  \\| |           ");
TITLE_GRN("           | |_) | |__| |_| || || |\\  |           ");
TITLE_GRN(" _____ ____|____/|_____\\____|___|_| \\_|____ _____ ");
TITLE_GRN("|_____|_____|                        |_____|_____|");

TITLE_YLW(" _  __       ");
TITLE_YLW("(_)/ /   ___ ");
TITLE_YLW("  / /   / __|");
TITLE_YLW(" / /_  | (__ ");
TITLE_YLW("/_/(_)  \\___|");
TITLE_YLW("             ");

  //char test
  TITLE_BLU("\n|%c basic test|\n");

  ret = fprintf(stdout, "printf c:\n\n%cl\n", c);
  fprintf(stdout, "printf ret:\n%i\n", ret);
  ret2 = ft_printf("ft_printf c:\n%cl\n", c);
  ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

  /*ret = fprintf(stdout, "printf c with space between modulo and specifier:\nq%   cq\n", c);
  fprintf(stdout, "printf ret:\n%i\n", ret);
  write(1, "ft_", 3);
  ret2 = ft_printf("printf c with space between modulo and specifier:\nq%   cq\n", c);
  ft_printf("ft_printf ret:\n%i\n", ret2);*/

SEP;

  ret = fprintf(stdout, "printf 2 c:\n%c, %cl\n", c, c);
  fprintf(stdout, "printf ret:\n%i\n", ret);
  write(1, "ft_", 3);
  ret2 = ft_printf("printf 2 c:\n%c, %cl\n", c, c);
  ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

TITLE_YLW(" _  __  _  __");
TITLE_YLW("(_)/ / (_)/ /");
TITLE_YLW("  / /    / / ");
TITLE_YLW(" / /_   / /_ ");
TITLE_YLW("/_/(_) /_/(_)");
TITLE_YLW("             ");

  TITLE_BLU("\n|%% basic test|\n");

SEP;

  ret = fprintf(stdout, "printf %%:\n%%l\n");
  fprintf(stdout, "printf ret:\n%i\n", ret);
  write(1, "ft_", 3);
  ret2 = ft_printf("printf %%:\n%%l\n");
  ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

  ret = fprintf(stdout, "printf %% with space between modulo and specifier:\nq%   %q\n");
  fprintf(stdout, "printf ret:\n%d\n", ret);
  write(1, "ft_", 3);
  ret2 = ft_printf("printf %% with space between modulo and specifier:\nq%   %q\n");
  ft_printf("ft_printf ret:\n%d\n", ret2);

SEP;

  ret = fprintf(stdout, "printf 2 %%:\n%%, \n");
  fprintf(stdout, "printf ret:\n%i\n", ret);
  write(1, "ft_", 3);
  ret2 = ft_printf("printf 2 %%:\n%%, \n");
  ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

TITLE_YLW(" _  __  _ ");
TITLE_YLW("(_)/ / (_)");
TITLE_YLW("  / /  | |");
TITLE_YLW(" / /_  | |");
TITLE_YLW("/_/(_) |_|");
TITLE_YLW("          ");

  //integer test
  TITLE_BLU("\n|%i basic test|\n");

SEP;

  ret = fprintf(stdout, "printf i:\n%il\n", i);
  fprintf(stdout, "printf ret:\n%i\n", ret);
  write(1, "ft_", 3);
  ret2 = ft_printf("printf i:\n%il\n", i);
  ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

  ret = fprintf(stdout, "printf i with space between modulo and specifier:\nq%   iq\n", i);
  fprintf(stdout, "printf ret:\n%i\n", ret);
  write(1, "ft_", 3);
  ret2 = ft_printf("printf i with space between modulo and specifier:\nq%   iq\n", i);
  ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

  ret = fprintf(stdout, "printf 2 i:\n%i, %il\n", i, i);
  fprintf(stdout, "printf ret:\n%i\n", ret);
  write(1, "ft_", 3);
  ret2 = ft_printf("printf 2 i:\n%i, %il\n", i, i);
  ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

TITLE_YLW(" _  __      _ ");
TITLE_YLW("(_)/ /   __| |");
TITLE_YLW("  / /   / _` |");
TITLE_YLW(" / /_  | (_| |");
TITLE_YLW("/_/(_)  \\__,_|");
TITLE_YLW("              ");

  TITLE_BLU("\n|%d basic test|\n");

SEP;

  ret = fprintf(stdout, "printf d:\n%dl\n", i);
  fprintf(stdout, "printf ret:\n%d\n", ret);
  write(1, "ft_", 3);
  ret2 = ft_printf("printf d:\n%dl\n", i);
  ft_printf("ft_printf ret:\n%d\n", ret2);

SEP;

  ret = fprintf(stdout, "printf d with space between modulo and specifier:\nq%   dq\n", i);
  fprintf(stdout, "printf ret:\n%d\n", ret);
  write(1, "ft_", 3);
  ret2 = ft_printf("printf d with space between modulo and specifier:\nq%   dq\n", i);
  ft_printf("ft_printf ret:\n%d\n", ret2);

SEP;

  ret = fprintf(stdout, "printf 2 d:\n%d, %dl\n", i, i);
  fprintf(stdout, "printf ret:\n%i\n", ret);
  write(1, "ft_", 3);
  ret2 = ft_printf("printf 2 d:\n%d, %dl\n", i, i);
  ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

TITLE_YLW(" _  __        ");
TITLE_YLW("(_)/ /  _   _ ");
TITLE_YLW("  / /  | | | |");
TITLE_YLW(" / /_  | |_| |");
TITLE_YLW("/_/(_)  \\__,_|");
TITLE_YLW("              ");

  TITLE_BLU("\n|%u basic test|\n");

SEP;

  ret = fprintf(stdout, "printf u:\n%ul\n", u);
  fprintf(stdout, "printf ret:\n%i\n", ret);
  write(1, "ft_", 3);
  ret2 = ft_printf("printf u:\n%ul\n", u);
  ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

  /*ret = fprintf(stdout, "printf u with space between modulo and specifier:\nq%   uq\n", u);
  fprintf(stdout, "printf ret:\n%i\n", ret);
  write(1, "ft_", 3);
  ret2 = ft_printf("printf u with space between modulo and specifier:\nq%   uq\n", u);
  ft_printf("ft_printf ret:\n%i\n", ret2);*/

SEP;

  ret = fprintf(stdout, "printf 2 u:\n%u, %ul\n", u, u);
  fprintf(stdout, "printf ret:\n%i\n", ret);
  write(1, "ft_", 3);
  ret2 = ft_printf("printf 2 u:\n%u, %ul\n", u, u);
  ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

TITLE_YLW(" _  __      ");
TITLE_YLW("(_)/ /  ___ ");
TITLE_YLW("  / /  / __|");
TITLE_YLW(" / /_  \\__ \\");
TITLE_YLW("/_/(_) |___/");
TITLE_YLW("            ");

  //str test
  TITLE_BLU("\n|%s basic test|\n");

SEP;

  ret = fprintf(stdout, "printf s:\n%sl\n", s);
  fprintf(stdout, "printf ret:\n%i\n", ret);
  write(1, "ft_", 3);
  ret2 = ft_printf("printf s:\n%sl\n", s);
  ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

  /*ret = fprintf(stdout, "printf s with space between modulo and specifier:\nq%   sq\n", s);
  fprintf(stdout, "printf ret:\n%i\n", ret);
  write(1, "ft_", 3);
  ret2 = ft_printf("printf s with space between modulo and specifier:\nq%   sq\n", s);
  ft_printf("ft_printf ret:\n%i\n", ret2);*/

SEP;

  ret = fprintf(stdout, "printf 2 s:\n%s, %sl\n", s, s);
  fprintf(stdout, "printf ret:\n%i\n", ret);
  write(1, "ft_", 3);
  ret2 = ft_printf("printf 2 s:\n%s, %sl\n", s, s);
  ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

TITLE_YLW(" _  __        ");
TITLE_YLW("(_)/ /  _ __  ");
TITLE_YLW("  / /  | '_ \\ ");
TITLE_YLW(" / /_  | |_) |");
TITLE_YLW("/_/(_) | .__/ ");
TITLE_YLW("       |_|    ");

  TITLE_BLU("\n|%p basic test|\n");

SEP;

  ret = fprintf(stdout, "printf p:\n%pl\n", s);
  fprintf(stdout, "printf ret:\n%i\n", ret);
  write(1, "ft_", 3);
  ret2 = ft_printf("printf p:\n%pl\n", s);
  ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

  /*ret = fprintf(stdout, "printf p with space between modulo and specifier:\nq%   pq\n", s);
  fprintf(stdout, "printf ret:\n%d\n", ret);
  write(1, "ft_", 3);
  ret2 = ft_printf("printf p with space between modulo and specifier:\nq%   pq\n", s);
  ft_printf("ft_printf ret:\n%d\n", ret2);*/

SEP;

  ret = fprintf(stdout, "printf 2 p:\n%p, %pl\n", s, s);
  fprintf(stdout, "printf ret:\n%i\n", ret);
  write(1, "ft_", 3);
  ret2 = ft_printf("printf 2 p:\n%p, %pl\n", s, s);
  ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

TITLE_YLW(" _  __       ");
TITLE_YLW("(_)/ / __  __");
TITLE_YLW("  / /  \\ \\/ /");
TITLE_YLW(" / /_   >  < ");
TITLE_YLW("/_/(_) /_/\\_\\");
TITLE_YLW("             ");

  //hexadecimal test
  TITLE_BLU("\n|%x basic test|\n");

SEP;

  ret = fprintf(stdout, "printf x:\n%xl\n", x);
  fprintf(stdout, "printf ret:\n%i\n", ret);
  write(1, "ft_", 3);
  ret2 = ft_printf("printf x:\n%xl\n", x);
  ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

  /*ret = fprintf(stdout, "printf x with space between modulo and specifier:\nq%   xq\n", x);
  fprintf(stdout, "printf ret:\n%i\n", ret);
  write(1, "ft_", 3);
  ret2 = ft_printf("printf x with space between modulo and specifier:\nq%   xq\n", x);
  ft_printf("ft_printf ret:\n%i\n", ret2);*/

SEP;

  ret = fprintf(stdout, "printf 2 x:\n%x, %xl\n", x, x);
  fprintf(stdout, "printf ret:\n%i\n", ret);
  write(1, "ft_", 3);
  ret2 = ft_printf("printf 2 x:\n%x, %xl\n", x, x);
  ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

TITLE_YLW(" _  __ __  __");
TITLE_YLW("(_)/ / \\ \\/ /");
TITLE_YLW("  / /   \\  / ");
TITLE_YLW(" / /_   /  \\ ");
TITLE_YLW("/_/(_) /_/\\_\\");
TITLE_YLW("             ");

  TITLE_BLU("\n|%X basic test|\n");

SEP;

  ret = fprintf(stdout, "printf X:\n%Xl\n", x);
  fprintf(stdout, "printf ret:\n%i\n", ret);
  write(1, "ft_", 3);
  ret2 = ft_printf("printf X:\n%Xl\n", x);
  ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

  /*ret = fprintf(stdout, "printf X with space between modulo and specifier:\nq%   Xq\n", x);
  fprintf(stdout, "printf ret:\n%d\n", ret);
  write(1, "ft_", 3);
  ret2 = ft_printf("printf X with space between modulo and specifier:\nq%   Xq\n", x);
  ft_printf("ft_printf ret:\n%d\n", ret2);*/

SEP;

  ret = fprintf(stdout, "printf 2 X:\n%X, %Xl\n", x, x);
  fprintf(stdout, "printf ret:\n%i\n", ret);
  write(1, "ft_", 3);
  ret2 = ft_printf("printf 2 X:\n%X, %Xl\n", x, x);
  ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

TITLE_YLW("                 _ _   _ ");
TITLE_YLW(" _ __ ___  _   _| | |_(_)");
TITLE_YLW("| '_ ` _ \\| | | | | __| |");
TITLE_YLW("| | | | | | |_| | | |_| |");
TITLE_YLW("|_| |_| |_|\\__,_|_|\\__|_|");
TITLE_YLW("                         ");

  TITLE_BLU("\n|Multiple specifiers test|\n");

SEP;

  ret = fprintf(stdout, "printf c, %%, d, i, u, s, p, x, X:\n%c, %%, %d, %i, %u, %s, %p, %x, %Xl\n", c, i, i, u, s, s, x, x);
  fprintf(stdout, "printf ret:\n%i\n", ret);
  write(1, "ft_", 3);
  ret2 = ft_printf("printf c, %%, d, i, u, s, p, x, X:\n%c, %%, %d, %i, %u, %s, %p, %x, %Xl\n", c, i, i, u, s, s, x, x);
  ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

  /*
  **MANDATORY_PART FLAGS
  */

SEP;

  //Minimum field witdh = a number between the modulo and the specifier or flag, this will print out spaces before the argument output if the minimum field witdh is not attained
  // - flag is used to put the minimum space witdh spaces after the argument output instead of after the argument output
  //the 0 flag right after the modulo and before the space width fills the minimum field width with 0s instead of spaces
  // the . flag right after the modulo or minimum field witdh must be followed by a number, this number indicates how much decimals should be written after the decimal point, problem only works with f specifier
  // the * flag can be used as a width specifier in the form of an argument

SEP;

    TITLE_BLU("\n|min space width basic test|\n");

SEP;

    ret = fprintf(stdout, "printf 12 min width for i:\n%12i\n", i);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 12 min width for i:\n%12i\n", i);
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    ret = fprintf(stdout, "printf 12 min width for d:\n%12d\n", x);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 12 min width for d:\n%12d\n", x);
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    ret = fprintf(stdout, "printf 12 min width for s:\n%12s\n", s);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 12 min width for s:\n%12s\n", s);
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    ret = fprintf(stdout, "printf 12 min width for u:\n%12u\n", u);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 12 min width for u:\n%12u\n", u);
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    ret = fprintf(stdout, "printf 12 min width for x:\n%12x\n", x);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 12 min width for x:\n%12x\n", x);
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    ret = fprintf(stdout, "printf 12 min width for X:\n%12X\n", x);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 12 min width for X:\n%12X\n", x);
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    ret = fprintf(stdout, "printf 12 min width for p:\n%12p\n", s);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 12 min width for p:\n%12p\n", s);
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    ret = fprintf(stdout, "printf 12 min width for c:\n%12c\n", c);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 12 min width for c:\n%12c\n", c);
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    ret = fprintf(stdout, "printf 12 min width for %%:\n%12%\n");
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 12 min width for %%:\n%12%\n");
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    TITLE_BLU("\n|Multiple specifiers test with min witdh 3|\n");

SEP;

    ret = fprintf(stdout, "printf c, %%, d, i, u, s, p, x, X:\n%3c, %3%, %3d, %3i, %3u, %3s, %3p, %3x, %3Xl\n", c, i, i, u, s, s, x, x);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf c, %%, d, i, u, s, p, x, X:\n%3c, %3%, %3d, %3i, %3u, %3s, %3p, %3x, %3Xl\n", c, i, i, u, s, s, x, x);
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    TITLE_BLU("\n|minus flag basic test|\n");

SEP;

    ret = fprintf(stdout, "printf 12 min width for i with - flag:\n%-12il\n", i);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 12 min width for i with - flag:\n%-12il\n", i);
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    ret = fprintf(stdout, "printf 12 min width for d with - flag:\n%-12dl\n", x);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 12 min width for d with - flag:\n%-12dl\n", x);
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    ret = fprintf(stdout, "printf 12 min width for s with - flag:\n%-12sl\n", s);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 12 min width for s with - flag:\n%-12sl\n", s);
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    ret = fprintf(stdout, "printf 12 min width for u with - flag:\n%-12ul\n", u);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 12 min width for u with - flag:\n%-12ul\n", u);
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    ret = fprintf(stdout, "printf 12 min width for x with - flag:\n%-12xl\n", x);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 12 min width for x with - flag:\n%-12xl\n", x);
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    ret = fprintf(stdout, "printf 12 min width for X with - flag:\n%-12Xl\n", x);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 12 min width for X with - flag:\n%-12Xl\n", x);
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    ret = fprintf(stdout, "printf 12 min width for p with - flag:\n%-12pl\n", s);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 12 min width for p with - flag:\n%-12pl\n", s);
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    ret = fprintf(stdout, "printf 12 min width for c with - flag:\n%-12cl\n", c);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 12 min width for c with - flag:\n%-12cl\n", c);
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    ret = fprintf(stdout, "printf 12 min width for %% with - flag:\n%-12%\n");
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 12 min width for %% with - flag:\n%-12%\n");
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    TITLE_BLU("\n|Multiple specifiers test with minus flag|\n");

SEP;

    ret = fprintf(stdout, "printf c, %%, d, i, u, s, p, x, X:\n%-3c, %-3%, %-3d, %-3i, %-3u, %-3s, %-3p, %-3x, %-3Xl\n", c, i, i, u, s, s, x, x);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf c, %%, d, i, u, s, p, x, X:\n%-3c, %-3%, %-3d, %-3i, %-3u, %-3s, %-3p, %-3x, %-3Xl\n", c, i, i, u, s, s, x, x);
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    TITLE_BLU("\n|min space width 0 flag basic test|\n"); //- flag is used to put the minimum space witdh spaces after the argument output instead of before the argument output, it doesn't work in combination with the - flag

SEP;

    ret = fprintf(stdout, "printf 12 min width for i:\n%012i\n", i);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 12 min width for i:\n%012i\n", i);
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    ret = fprintf(stdout, "printf 12 min width for d:\n%012d\n", x);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 12 min width for d:\n%012d\n", x);
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    /*ret = fprintf(stdout, "printf 12 min width for s:\n%012s\n", s);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 12 min width for s:\n%012s\n", s);
    ft_printf("ft_printf ret:\n%i\n", ret2);*/

SEP;

    ret = fprintf(stdout, "printf 12 min width for u:\n%012u\n", u);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 12 min width for u:\n%012u\n", u);
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    ret = fprintf(stdout, "printf 12 min width for x:\n%012x\n", x);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 12 min width for x:\n%012x\n", x);
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    ret = fprintf(stdout, "printf 12 min width for X:\n%012X\n", x);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 12 min width for X:\n%012X\n", x);
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    /*ret = fprintf(stdout, "printf 12 min width for p:\n%012p\n", s);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 12 min width for p:\n%012p\n", s);
    ft_printf("ft_printf ret:\n%i\n", ret2);*/

SEP;

    /*ret = fprintf(stdout, "printf 12 min width for c:\n%012c\n", c);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 12 min width for c:\n%012c\n", c);
    ft_printf("ft_printf ret:\n%i\n", ret2);*/

SEP;

    ret = fprintf(stdout, "printf 12 min width for %%:\n%012%\n");
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 12 min width for %%:\n%012%\n");
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    TITLE_BLU("\n|Multiple specifiers test with 0 flag|\n");

SEP;

    ret = fprintf(stdout, "printf c, %%, d, i, u, s, p, x, X:\n%3c, %03%, %03d, %03i, %03u, %3s, %3p, %03x, %03Xl\n", c, i, i, u, s, s, x, x);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf c, %%, d, i, u, s, p, x, X:\n%3c, %03%, %03d, %03i, %03u, %3s, %3p, %03x, %03Xl\n", c, i, i, u, s, s, x, x);
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

TITLE_YLW("         __ _             ");
TITLE_YLW("__/\\__  / _| | __ _  __ _ ");
TITLE_YLW("\\    / | |_| |/ _` |/ _` |");
TITLE_YLW("/_  _\\ |  _| | (_| | (_| |");
TITLE_YLW("  \\/   |_| |_|\\__,_|\\__, |");
TITLE_YLW("                    |___/ ");

    TITLE_BLU("\n|* flag basic test|\n"); //* flag is used as a way to insert the min_witdh as an argument

SEP;

    ret = fprintf(stdout, "printf 12 min width for i with * flag:\n%*i\n", amp, i);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 12 min width for i with * flag:\n%*i\n", amp, i);
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    TITLE_BLU("\n|Multiple specifiers test with * flag|\n");

SEP;

    ret = fprintf(stdout, "printf c, %%, d, i, u, s, p, x, X:\n%*c, %*%, %*d, %*i, %*u, %*s, %*p, %*x, %*Xl\n", amp, c, amp, amp, i, amp, i, amp, u, amp, s, amp, s, amp, x, amp, x);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf c, %%, d, i, u, s, p, x, X:\n%*c, %*%, %*d, %*i, %*u, %*s, %*p, %*x, %*Xl\n", amp, c, amp, amp, i, amp, i, amp, u, amp, s, amp, s, amp, x, amp, x);
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

TITLE_YLW("      __ _             ");
TITLE_YLW("     / _| | __ _  __ _ ");
TITLE_YLW("    | |_| |/ _` |/ _` |");
TITLE_YLW(" _  |  _| | (_| | (_| |");
TITLE_YLW("(_) |_| |_|\\__,_|\\__, |");
TITLE_YLW("                 |___/ ");

    TITLE_BLU("\n|. flag special test|\n");

SEP;

    ret = fprintf(stdout, "printf 12 precision for i with .* flag:\n%.*i\n", amp, i);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 12 precision for i with .* flag:\n%.*i\n", amp, i);
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;


    ret = fprintf(stdout, "printf 0 precision for i with . flag:\n%.i\n", i);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 0 precision for i with . flag:\n%.i\n", i);
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    ret = fprintf(stdout, "printf 0 precision for value 0 with . flag:\n%.i\n", x2);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 0 precision for value 0 with . flag:\n%.i\n", x2);
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    ret = fprintf(stdout, "printf 12 precision for i with . flag:\n%.12i\n", i);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 12 precision for i with . flag:\n%.12i\n", i);
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    TITLE_BLU("\n|. flag basic test|\n");

SEP;

    ret = fprintf(stdout, "printf 12 precision for i with . flag:\n%.12i\n", i);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 12 precision for i with . flag:\n%.12i\n", i);
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    ret = fprintf(stdout, "printf 12 precision for d with . flag:\n%.12d\n", x);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 12 precision for d with . flag:\n%.12d\n", x);
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    ret = fprintf(stdout, "printf 12 precision for s with . flag:\n%.12s\n", s);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 12 precision for s with . flag:\n%.12s\n", s);
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    ret = fprintf(stdout, "printf 2 precision for s with . flag:\n%.2s\n", s);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 2 precision for s with . flag:\n%.2s\n", s);
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    ret = fprintf(stdout, "printf 12 precision for u with . flag:\n%.12u\n", u);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 12 precision for u with . flag:\n%.12u\n", u);
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    ret = fprintf(stdout, "printf 12 precision for x with . flag:\n%.12x\n", x);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 12 precision for x with . flag:\n%.12x\n", x);
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    ret = fprintf(stdout, "printf 12 precision for X with . flag:\n%.12X\n", x);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 12 precision for X with . flag:\n%.12X\n", x);
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    /*ret = fprintf(stdout, "printf 12 precision for p with . flag:\n%.12p\n", s);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 12 precision for p with . flag:\n%.12p\n", s);
    ft_printf("ft_printf ret:\n%i\n", ret2);*/

SEP;

    /*ret = fprintf(stdout, "printf 12 precision for c with . flag:\n%.12c\n", c);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 12 precision for c with . flag:\n%.12c\n", c);
    ft_printf("ft_printf ret:\n%i\n", ret2);*/

SEP;

    ret = fprintf(stdout, "printf 12 precision for %% with . flag:\n%.12%\n");
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 12 precision for %% with . flag:\n%.12%\n");
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    TITLE_BLU("\n|Multiple specifiers test with . flag|\n");

SEP;

    // ret = fprintf(stdout, "printf c, %%, d, i, u, s, p, x, X:\n%.5c, %.3%, %.3d, %.19i, %.3u, %.3s, %3p, %.3x, %.3Xl\n", c, i, i, u, s, s, x, x);
    // fprintf(stdout, "printf ret:\n%i\n", ret);
    // write(1, "ft_", 3);
    // ret2 = ft_printf("printf c, %%, d, i, u, s, p, x, X:\n%.5c, %.3%, %.3d, %.19i, %.3u, %.3s, %3p, %.3x, %.3Xl\n", c, i, i, u, s, s, x, x);
    // ft_printf("ft_printf ret:\n%i\n", ret2);
    
    TITLE_RED("GET_CRAZY / FLAG COMBINATIONS");
    
    TITLE_BLU("\n|% space basic test|\n"); //If min witdh follows not taken into account, unless min witdh is less than string lenght

SEP;

    ret = fprintf(stdout, "printf one space with flag space:\n% i\n", x);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf one space with flag space:\n% i\n", x);
    ft_printf("ft_printf ret:\n%i\n", ret2);
    
SEP;

    ret = fprintf(stdout, "printf one space with flag space:\n%.0i\n", 0);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf one space with flag space:\n%.0i\n", 0);
    ft_printf("ft_printf ret:\n%i\n", ret2);
    
SEP;

    write(1,"\n|special cases|\n",17); //If min witdh follows not taken into account, unless min witdh is less than string lenght
    
SEP;

    ret = fprintf(stdout, "Multiple same flags 0:\n%00021i\n", i);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("Multiple same flags 0:\n%00021i\n", i);
    ft_printf("ft_printf ret:\n%i\n", ret2);
    
SEP;

    ret = fprintf(stdout, "Multiple same flags -:\n%---21il\n", i);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("Multiple same flags -:\n%---21il\n", i);
    ft_printf("ft_printf ret:\n%i\n", ret2);
    
SEP;

    // ret = fprintf(stdout, "Multiple same flags .:\n%...21il\n", i);
    // fprintf(stdout, "printf ret:\n%i\n", ret);
    // write(1, "ft_", 3);
    // ret2 = ft_printf("Multiple same flags .:\n%...21il\n", i);
    // ft_printf("ft_printf ret:\n%i\n", ret2);
    
SEP;

    ret = fprintf(stdout, "precision of zero:\n%.0i\n", 0);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("precision of zero:\n%.0i\n", 0);
    ft_printf("ft_printf ret:\n%i\n", ret2);
    
SEP;

    ret = fprintf(stdout, "");
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("");
    ft_printf("ft_printf ret:\n%i\n", ret2);
    
SEP;

    ret = fprintf(stdout, "printf empty string:\n%s", sc);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf empty string:\n%s", sc);
    ft_printf("ft_printf ret:\n%i\n", ret2);
    
SEP;

    // ret = fprintf(stdout, "printf Minimum int:\n%i\n", -2147483648);
    // fprintf(stdout, "printf ret:\n%i\n", ret);
    // write(1, "ft_", 3);
    // ret2 = ft_printf("printf Minimum int:\n%i\n", -2147483648);
    // ft_printf("ft_printf ret:\n%i\n", ret2);
    
SEP;

    ret = fprintf(stdout, "printf Int 0:\n%i\n", 0);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf Int 0:\n%i\n", 0);
    ft_printf("ft_printf ret:\n%i\n", ret2);
    
SEP;

    ret = fprintf(stdout, "printf NULL pointer:\n%s\n", NULL);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf NULL pointer:\n%s\n", NULL);
    ft_printf("ft_printf ret:\n%i\n", ret2);
    
SEP;

    TITLE_BLU("\n|Flag combinations|\n");
    
SEP;

    ret = fprintf(stdout, "printf modulo minus zero 5 modulo:\n%-05%\n");
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf modulo minus zero 5 modulo:\n%-05%\n");
    ft_printf("ft_printf ret:\n%i\n", ret2);
    
SEP;

    ret = fprintf(stdout, "printf modulo precision 5 s modulo 7 s:\n%.5s%7s\n", "yo", "boi");
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf modulo precision 5 s modulo 7 s:\n%.5s%7s\n", "yo", "boi");
    ft_printf("ft_printf ret:\n%i\n", ret2);
    
SEP;

    ret = fprintf(stdout, "printf modulo 7 precision 5 s:\n%7.5s\n", "bombastic");
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf modulo 7 precision 5 s:\n%7.5s\n", "bombastic");
    ft_printf("ft_printf ret:\n%i\n", ret2);
    
SEP;

    ret = fprintf(stdout, "printf modulo 7 point 5 s:\n%7.5s\n", "yolo");
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf modulo 7 point 5 s:\n%7.5s\n", "yolo");
    ft_printf("ft_printf ret:\n%i\n", ret2);
    
SEP;

    ret = fprintf(stdout, "printf modulo 8 point 5 i:\n%8.5i\n", 34);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf modulo 8 point 5 i:\n%8.5i\n", 34);
    ft_printf("ft_printf ret:\n%i\n", ret2);
    
SEP;

    ret = fprintf(stdout, "modulo 10 point 5 i:\n%10.5i\n", -216);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("modulo 10 point 5 i:\n%10.5i\n", -216);
    ft_printf("ft_printf ret:\n%i\n", ret2);
    
SEP;

    ret = fprintf(stdout, "modulo 8 point 3 i:\n%8.3i\n", -8473);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("modulo 8 point 3 i:\n%8.3i\n", -8473);
    ft_printf("ft_printf ret:\n%i\n", ret2);
    
SEP;

    ret = fprintf(stdout, "modulo minus 8 point 5 i:\n%-8.5il\n", 34);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("modulo minus 8 point 5 i:\n%-8.5il\n", 34);
    ft_printf("ft_printf ret:\n%i\n", ret2);
    
SEP;

    ret = fprintf(stdout, "mdulo 0 8 point 5:\n%08.5i\n", 34);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("mdulo 0 8 point 5:\n%08.5i\n", 34);
    ft_printf("ft_printf ret:\n%i\n", ret2);
    
SEP;

    ret = fprintf(stdout, "modulo 5 point 0 i:\n%5.0il\n", 0);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("modulo 5 point 0 i:\n%5.0il\n", 0);
    ft_printf("ft_printf ret:\n%i\n", ret2);
    
SEP;

    ret = fprintf(stdout, "modulo 8 point 5 u:\n%8.5u\n", 34);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("modulo 8 point 5 u:\n%8.5u\n", 34);
    ft_printf("ft_printf ret:\n%i\n", ret2);
    
SEP;

    ret = fprintf(stdout, "modulo - 8 point 5u:\n%-8.5ul\n", 34);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("modulo - 8 point 5u:\n%-8.5ul\n", 34);
    ft_printf("ft_printf ret:\n%i\n", ret2);
    
SEP;

    ret = fprintf(stdout, "print x 0 :\n%x\n", 0);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("print x 0 :\n%x\n", 0);
    ft_printf("ft_printf ret:\n%i\n", ret2);
    
SEP;

    ret = fprintf(stdout, "modulo 4 point 8 x:\n%4.8x\n", 424242424);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("modulo 4 point 8 x:\n%4.8x\n", 424242424);
    ft_printf("ft_printf ret:\n%i\n", ret2);
    
SEP;

    ret = fprintf(stdout, "modulo 20 point 5 d:\n%20.5d\n", -1024);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("modulo 20 point 5 d:\n%20.5d\n", -1024);
    ft_printf("ft_printf ret:\n%i\n", ret2);
    
SEP;

    ret = fprintf(stdout, "printf:\n neg7 %*.*s\n", -1586, 15, "coucou");
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf:\n neg7 %*.*s\n", -1586, 15, "coucou");
    ft_printf("ft_printf ret:\n%i\n", ret2);
    
SEP;

    ret = fprintf(stdout, "braket modulo star d braket:\n{%*d}\n", -5, 42);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("braket modulo star d braket:\n{%*d}\n", -5, 42);
    ft_printf("ft_printf ret:\n%i\n", ret2);
    
SEP;

    ret = fprintf(stdout, "printf:\n {%.*s}\n", -5, "42");
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf:\n {%.*s}\n", -5, "42");
    ft_printf("ft_printf ret:\n%i\n", ret2);
    
SEP;

    ret = fprintf(stdout, "printf:\n {%05.*d}\n", -15, 42);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf:\n {%05.*d}\n", -15, 42);
    ft_printf("ft_printf ret:\n%i\n", ret2);
    
SEP;

    ret = fprintf(stdout, "modulo p NULLpointer:\n%p\n", NULL);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("modulo p NULLpointer:\n%p\n", NULL);
    ft_printf("ft_printf ret:\n%i\n", ret2);
    
SEP;

    ret = fprintf(stdout, "printf:\n %.p\n", s);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf:\n %.p\n", s);
    ft_printf("ft_printf ret:\n%i\n", ret2);
    
SEP;

    ret = fprintf(stdout, "printf:\n%20.u\n", 1024u);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf:\n%20.u\n", 1024u);
    ft_printf("ft_printf ret:\n%i\n", ret2);
    
SEP;

    ret = fprintf(stdout, "printf:\n %5.0u\n", 0);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf:\n %5.0u\n", 0);
    ft_printf("ft_printf ret:\n%i\n", ret2);
    
SEP;

    ret = fprintf(stdout, "printf:\n p30 %.0u\n", 100);
    fprintf(stdout, "printf ret:\n%i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf:\n p30 %.0u\n", 100);
    ft_printf("ft_printf ret:\n%i\n", ret2);
    
SEP;

    /*ret = fprintf(stdout, "%015p\n", NULL);
     fprintf(stdout, "printf ret:\n%i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("%015p\n", NULL);
     ft_printf("ft_printf ret:\n%i\n", ret2);*///ERROR
    
SEP;

    /*ret = fprintf(stdout, "modulo point zero p:\n%.0p\n", 0);
     fprintf(stdout, "printf ret:\n%i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("modulo point zero p:\n%.0p\n", 0);
     ft_printf("ft_printf ret:\n%i\n", ret2);*///warning
    
SEP;

    /*ret = fprintf(stdout, "%020.5s\n", "Hallo heimur");
     fprintf(stdout, "printf ret:\n%i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("%020.5s\n", "Hallo heimur");
     ft_printf("ft_printf ret:\n%i\n", ret2);*///warning
    
SEP;

    /*ret = fprintf(stdout, "%04.3s%-7.4s", "hello", "world");
     fprintf(stdout, "printf ret:\n%i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("%04.3s%-7.4s", "hello", "world");
     ft_printf("ft_printf ret:\n%i\n", ret2);*///warning
    
SEP;

    /*ret = fprintf(stdout, "%\n");
     fprintf(stdout, "printf ret:\n%i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("%\n");
     ft_printf("ft_printf ret:\n%i\n", ret2);*///warning
    
SEP;

    /*ret = fprintf(stdout, "%-05\n");
     fprintf(stdout, "printf ret:\n%i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("%-05\n");
     ft_printf("ft_printf ret:\n%i\n", ret2);*///warning
    
    
    //15 warning tests inide the unit test, do no need to be able to do

SEP;

  if (BONUS == 0)
    return 0;

  /*
  **BONUS_PART
  */
  /*
  **BONUS_PART SPECIFIERS
  */

TITLE_GRN("            ____   ___  _   _ _   _ ____            ");
TITLE_GRN("           | __ ) / _ \\| \\ | | | | / ___|           ");
TITLE_GRN("           |  _ \\| | | |  \\| | | | \\___ \\           ");
TITLE_GRN("           | |_) | |_| | |\\  | |_| |___) |          ");
TITLE_GRN(" _____ ____|____/ \\___/|_| \\_|\\___/|____/____ _____ ");
TITLE_GRN("|_____|_____|                          |_____|_____|");

SEP;

  TITLE_BLU("\n|%n basic test|\n"); //n doesn't print anything but takes the value of number of prior written chars

SEP;

  ret = fprintf(stdout, "printf n:\n%n\n", &n);
  fprintf(stdout, "printf n value:\n%i\n", n);
  fprintf(stdout, "printf ret:\n%i\n", ret);
  write(1, "ft_", 3);
  ret2 = ft_printf("printf n:\n%n\n", &n);
  ft_printf("ft_printf n value:\n%i\n", n);
  ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

TITLE_YLW(" _  __   __ ");
TITLE_YLW("(_)/ /  / _|");
TITLE_YLW("  / /  | |_ ");
TITLE_YLW(" / /_  |  _|");
TITLE_YLW("/_/(_) |_|  ");
TITLE_YLW("            ");

  TITLE_BLU("\n|%f basic test|\n"); //Used to write integers with decimals after the comma max 6 thus prints doubles

SEP;

   ret = fprintf(stdout, "printf 4 with f:\n%f\n", 4.);
   fprintf(stdout, "printf ret:\n %i\n", ret);
   write(1, "ft_", 3);
   ret2 = ft_printf("printf 4 with f:\n%f\n", 4.);
   ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

   ret = fprintf(stdout, "printf 4 with f:\n%f\n", 1000000000000000000.);
   fprintf(stdout, "printf ret:\n %i\n", ret);
   write(1, "ft_", 3);
   ret2 = ft_printf("printf 4 with f:\n%f\n", 1000000000000000000.);
   ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

   ret = fprintf(stdout, "printf 4.1 with f:\n%f\n", 4.1); //ERROR when casting to int, only with 4.1 for unknown reason
   fprintf(stdout, "printf ret:\n %i\n", ret);
   write(1, "ft_", 3);
   ret2 = ft_printf("printf 4.1 with f:\n%f\n", 4.1);
   ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

   ret = fprintf(stdout, "printf 0.32 with f:\n%f\n", 0.32);
   fprintf(stdout, "printf ret:\n %i\n", ret);
   write(1, "ft_", 3);
   ret2 = ft_printf("printf 0.32 with f:\n%f\n", 0.32);
   ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

   ret = fprintf(stdout, "printf 4.001 with f:\n%f\n", 4.001);
   fprintf(stdout, "printf ret:\n %i\n", ret);
   write(1, "ft_", 3);
   ret2 = ft_printf("printf 4.001 with f:\n%f\n", 4.001);
   ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

   ret = fprintf(stdout, "printf 4.5345435; with f:\n%f\n", 4.5345435);
   fprintf(stdout, "printf ret:\n %i\n", ret);
   write(1, "ft_", 3);
   ret2 = ft_printf("printf 4.5345435; with f:\n%f\n", 4.5345435);
   ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

   ret = fprintf(stdout, "printf 4.5345437; with f:\n%f\n", 4.5345437);
   fprintf(stdout, "printf ret:\n %i\n", ret);
   write(1, "ft_", 3);
   ret2 = ft_printf("printf 4.5345437; with f:\n%f\n", 4.5345437);
   ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

   TITLE_BLU("\n|%f precision test|\n"); //Used to write integers with decimals after the comma max 6 thus prints doubles

SEP;

    ret = fprintf(stdout, "printf 4 with f:\n%.5f\n", 4.);
    fprintf(stdout, "printf ret:\n %i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 4 with f:\n%.5f\n", 4.);
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    ret = fprintf(stdout, "printf 4 with f:\n%.5f\n", 1000000000000000000.);
    fprintf(stdout, "printf ret:\n %i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 4 with f:\n%.5f\n", 1000000000000000000.);
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    ret = fprintf(stdout, "printf 4.1 with f:\n%.5f\n", 4.1); //ERROR when casting to long long int, only with 4.1 for unknown reason
    fprintf(stdout, "printf ret:\n %i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 4.1 with f:\n%.5f\n", 4.1);
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    ret = fprintf(stdout, "printf 0.32 with f:\n%.5f\n", 0.3298651);
    fprintf(stdout, "printf ret:\n %i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 0.32 with f:\n%.5f\n", 0.3298651);
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    ret = fprintf(stdout, "printf 4.001 with f:\n%.5f\n", 4.001);
    fprintf(stdout, "printf ret:\n %i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 4.001 with f:\n%.5f\n", 4.001);
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    ret = fprintf(stdout, "printf 4.5345435; with f:\n%.8f\n", 4.5345435); //ERROR when casting to long long int for unknown reason
    fprintf(stdout, "printf ret:\n %i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 4.5345435; with f:\n%.8f\n", 4.5345435);
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    ret = fprintf(stdout, "printf 4.5345437; with f:\n%.8f\n", -4.5345437);
    fprintf(stdout, "printf ret:\n %i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 4.5345437; with f:\n%.8f\n", -4.5345437);
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    ret = fprintf(stdout, "printf 4.2345437; with f:\n%.4f\n", -4.99999);
    fprintf(stdout, "printf ret:\n %i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 4.2345437; with f:\n%.4f\n", -4.99999);
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    ret = fprintf(stdout, "printf 4.2345437; with f:\n%.4f\n", -99.99999);
    fprintf(stdout, "printf ret:\n %i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 4.2345437; with f:\n%.4f\n", -99.99999);
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    TITLE_BLU("\n|%f min_witdh test|\n");

SEP;

     ret = fprintf(stdout, "printf 4 with f:\n%12f\n", 4.);
     fprintf(stdout, "printf ret:\n %i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("printf 4 with f:\n%12f\n", 4.);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     ret = fprintf(stdout, "printf 4 with f:\n%12f\n", 1000000000000000000.);
     fprintf(stdout, "printf ret:\n %i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("printf 4 with f:\n%12f\n", 1000000000000000000.);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     ret = fprintf(stdout, "printf -4.001 with e:\n%34f\n", -4.001);
     fprintf(stdout, "printf ret:\n %i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("printf -4.001 with e:\n%34f\n", -4.001);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     ret = fprintf(stdout, "printf 4 with f:\n%-12fg\n", 4.);
     fprintf(stdout, "printf ret:\n %i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("printf 4 with f:\n%-12fg\n", 4.);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     ret = fprintf(stdout, "printf 4 with f:\n%-12fg\n", 1000000000000000000.);
     fprintf(stdout, "printf ret:\n %i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("printf 4 with f:\n%-12fg\n", 1000000000000000000.);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     ret = fprintf(stdout, "printf 4 with f:\n%012fg\n", 4.);
     fprintf(stdout, "printf ret:\n %i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("printf 4 with f:\n%012fg\n", 4.);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     ret = fprintf(stdout, "printf 4 with f:\n%012fg\n", 1000000000000000000.);
     fprintf(stdout, "printf ret:\n %i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("printf 4 with f:\n%012fg\n", 1000000000000000000.);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

TITLE_YLW(" _  __       ");
TITLE_YLW("(_)/ /   ___ ");
TITLE_YLW("  / /   / _ \\");
TITLE_YLW(" / /_  |  __/");
TITLE_YLW("/_/(_)  \\___|");
TITLE_YLW("             ");

     TITLE_BLU("\n|%e basic test|\n");

SEP;

    //Used to write integers with decimals after the comma max 6 thus prints doubles in scientific notation
    //Only possible if the %f is completely functional
    //Test %e evan more and use the flags on it, min_witdh, 0-, precision

SEP;

    ret = fprintf(stdout, "printf 4 with e:\n%e\n", 4.);
    fprintf(stdout, "printf ret:\n %i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 4 with e:\n%e\n", 4.);
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    ret = fprintf(stdout, "printf 4 with e:\n%e\n", 1000000000000000000.);
    fprintf(stdout, "printf ret:\n %i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 4 with e:\n%e\n", 1000000000000000000.);
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    ret = fprintf(stdout, "printf 4.1 with e:\n%e\n", 4.1); //ERROR when casting to long long int, only with 4.1 for unknown reason
    fprintf(stdout, "printf ret:\n %i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 4.1 with e:\n%e\n", 4.1);
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    ret = fprintf(stdout, "printf 0.3298651 with e:\n%e\n", 0.3298651);
    fprintf(stdout, "printf ret:\n %i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 0.3298651 with e:\n%e\n", 0.3298651);
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    ret = fprintf(stdout, "printf 4.001 with e:\n%e\n", 4.001);
    fprintf(stdout, "printf ret:\n %i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 4.001 with e:\n%e\n", 4.001);
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    ret = fprintf(stdout, "printf 4.5345437 with e:\n%e\n", 4.5345437);
    fprintf(stdout, "printf ret:\n %i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 4.5345437 with e:\n%e\n", 4.5345437);
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    ret = fprintf(stdout, "printf 0.0323243 with e:\n%e\n", 0.0323243);
    fprintf(stdout, "printf ret:\n %i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 0.0323243 with e:\n%e\n", 0.0323243);
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    ret = fprintf(stdout, "printf 430.05345437 with e:\n%e\n", 430.05345437);
    fprintf(stdout, "printf ret:\n %i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 430.05345437 with e:\n%e\n", 430.05345437);
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    ret = fprintf(stdout, "printf -4.001 with e:\n%e\n", -4.001);
    fprintf(stdout, "printf ret:\n %i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf -4.001 with e:\n%e\n", -4.001);
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    TITLE_BLU("\n|%e min witdh basic test|\n");

SEP;

   //Used to write integers with decimals after the comma max 6 thus prints doubles in scientific notation
   //Only possible if the %f is completely functional
   //Test %e evan more and use the flags on it, min_witdh, 0- and precision

SEP;

   ret = fprintf(stdout, "printf 0.0323243 with e:\n%4e\n", 0.0323243);
   fprintf(stdout, "printf ret:\n %i\n", ret);
   write(1, "ft_", 3);
   ret2 = ft_printf("printf 0.0323243 with e:\n%4e\n", 0.0323243);
   ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

   ret = fprintf(stdout, "printf 430.05345437 with e:\n%34e\n", 430.05345437);
   fprintf(stdout, "printf ret:\n %i\n", ret);
   write(1, "ft_", 3);
   ret2 = ft_printf("printf 430.05345437 with e:\n%34e\n", 430.05345437);
   ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

   ret = fprintf(stdout, "printf -4.001 with e:\n%34e\n", -4.001);
   fprintf(stdout, "printf ret:\n %i\n", ret);
   write(1, "ft_", 3);
   ret2 = ft_printf("printf -4.001 with e:\n%34e\n", -4.001);
   ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

   ret = fprintf(stdout, "printf 4 with e:\n%-34ee\n", 4.);
   fprintf(stdout, "printf ret:\n %i\n", ret);
   write(1, "ft_", 3);
   ret2 = ft_printf("printf 4 with e:\n%-34ee\n", 4.);
   ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

   ret = fprintf(stdout, "printf 4 with e:\n%-12ee\n", 1000000000000000000.);
   fprintf(stdout, "printf ret:\n %i\n", ret);
   write(1, "ft_", 3);
   ret2 = ft_printf("printf 4 with e:\n%-12ee\n", 1000000000000000000.);
   ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

   ret = fprintf(stdout, "printf 4 with e:\n%034eg\n", 4.);
   fprintf(stdout, "printf ret:\n %i\n", ret);
   write(1, "ft_", 3);
   ret2 = ft_printf("printf 4 with e:\n%034eg\n", 4.);
   ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

   ret = fprintf(stdout, "printf 4 with e:\n%012ee\n", 1000000000000000000.);
   fprintf(stdout, "printf ret:\n %i\n", ret);
   write(1, "ft_", 3);
   ret2 = ft_printf("printf 4 with e:\n%012ee\n", 1000000000000000000.);
   ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

   TITLE_BLU("\n|%e precision test|\n"); //Used to write integers with decimals after the comma max 6 thus prints doubles

SEP;

    ret = fprintf(stdout, "printf 4 with e:\n%.2e\n", 4.);
    fprintf(stdout, "printf ret:\n %i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 4 with e:\n%.2e\n", 4.);
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    ret = fprintf(stdout, "printf 4 with e:\n%.2e\n", 1000000000000000000.);
    fprintf(stdout, "printf ret:\n %i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 4 with e:\n%.2e\n", 1000000000000000000.);
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    ret = fprintf(stdout, "printf 4.1 with e:\n%.2e\n", 4.1); //ERROR when casting to long long int, only with 4.1 for unknown reason
    fprintf(stdout, "printf ret:\n %i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 4.1 with e:\n%.2e\n", 4.1);
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    ret = fprintf(stdout, "printf 0.32 with e:\n%.2e\n", 0.3298651);
    fprintf(stdout, "printf ret:\n %i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 0.32 with e:\n%.2e\n", 0.3298651);
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    ret = fprintf(stdout, "printf 4.001 with e:\n%.2e\n", 4.001);
    fprintf(stdout, "printf ret:\n %i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 4.001 with e:\n%.2e\n", 4.001);
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    ret = fprintf(stdout, "printf 4.2345435; with e:\n%.8e\n", 4.2345435);
    fprintf(stdout, "printf ret:\n %i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf 4.2345435; with e:\n%.8e\n", 4.2345435);
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    ret = fprintf(stdout, "printf -4.99999 with e:\n%.4e\n", -4.99999);
    fprintf(stdout, "printf ret:\n %i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf -4.99999 with e:\n%.4e\n", -4.99999);
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    ret = fprintf(stdout, "printf -9.99999 with e:\n%.4e\n", -9.99999);
    fprintf(stdout, "printf ret:\n %i\n", ret);
    write(1, "ft_", 3);
    ret2 = ft_printf("printf -9.99999 with e:\n%.4e\n", -9.99999);
    ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

TITLE_YLW(" _  __        ");
TITLE_YLW("(_)/ /   __ _ ");
TITLE_YLW("  / /   / _` |");
TITLE_YLW(" / /_  | (_| |");
TITLE_YLW("/_/(_)  \\__, |");
TITLE_YLW("        |___/ ");

    TITLE_BLU("\n|%g basic test|\n");
  /*
  **Used to write integers with decimals after the comma in scientific or decimal notation whatver is shorter, max 6 numbers, precision is about all significant numbers not only after the comma, eliminates all that is insignificant
  */
     ret = fprintf(stdout, "printf 4 with g:\n%g\n", 4.);
     fprintf(stdout, "printf ret:\n %i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("printf 4 with g:\n%g\n", 4.);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     ret = fprintf(stdout, "printf 4 with g:\n%g\n", 1000000000000000000.);
     fprintf(stdout, "printf ret:\n %i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("printf 4 with g:\n%g\n", 1000000000000000000.);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     ret = fprintf(stdout, "printf 4.1 with g:\n%g\n", 4.1);
     fprintf(stdout, "printf ret:\n %i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("printf 4.1 with g:\n%g\n", 4.1);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     ret = fprintf(stdout, "printf 0.3298651 with g:\n%g\n", 0.3298651);
     fprintf(stdout, "printf ret:\n %i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("printf 0.3298651 with g:\n%g\n", 0.3298651);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     ret = fprintf(stdout, "printf 4.001 with g:\n%g\n", 4.001);
     fprintf(stdout, "printf ret:\n %i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("printf 4.001 with g:\n%g\n", 4.001);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     ret = fprintf(stdout, "printf 4.2345435; with g:\n%g\n", 4.2345435);
     fprintf(stdout, "printf ret:\n %i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("printf 4.2345435; with g:\n%g\n", 4.2345435);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     ret = fprintf(stdout, "printf 34.2345435 with g:\n%g\n", 34.2345435);
     fprintf(stdout, "printf ret:\n %i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("printf 34.2345435 with g:\n%g\n", 34.2345435);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     ret = fprintf(stdout, "printf -4.999999 with g:\n%g\n", -4.999999);
     fprintf(stdout, "printf ret:\n %i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("printf -4.999999 with g:\n%g\n", -4.999999);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     ret = fprintf(stdout, "printf -99.99999 with g:\n%g\n", -99.99999);
     fprintf(stdout, "printf ret:\n %i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("printf -99.99999 with g:\n%g\n", -99.99999);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;



     TITLE_BLU("\n|%g min witdh basic test|\n");

SEP;

     ret = fprintf(stdout, "printf 0.0323243 with g:\n%4g\n", 0.0323243);
     fprintf(stdout, "printf ret:\n %i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("printf 0.0323243 with g:\n%4g\n", 0.0323243);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     ret = fprintf(stdout, "printf 430.05345437 with g:\n%34g\n", 430.05345437);
     fprintf(stdout, "printf ret:\n %i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("printf 430.05345437 with g:\n%34g\n", 430.05345437);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     ret = fprintf(stdout, "printf -4.001 with g:\n%34g\n", -4.001);
     fprintf(stdout, "printf ret:\n %i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("printf -4.001 with g:\n%34g\n", -4.001);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     ret = fprintf(stdout, "printf 4 with g:\n%-34ge\n", 4.);
     fprintf(stdout, "printf ret:\n %i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("printf 4 with g:\n%-34ge\n", 4.);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     ret = fprintf(stdout, "printf 4 with g:\n%-12ge\n", 1000000000000000000.);
     fprintf(stdout, "printf ret:\n %i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("printf 4 with g:\n%-12ge\n", 1000000000000000000.);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     ret = fprintf(stdout, "printf 4 with e:\n%034ge\n", 4.);
     fprintf(stdout, "printf ret:\n %i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("printf 4 with e:\n%034ge\n", 4.);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     ret = fprintf(stdout, "printf 4 with e:\n%012gg\n", 1000000000000000000.);
     fprintf(stdout, "printf ret:\n %i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("printf 4 with e:\n%012gg\n", 1000000000000000000.);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     write(1,"\n|%g precision test|\n",21); //Used to write integers with decimals after the comma max 6 thus prints doubles

SEP;

     ret = fprintf(stdout, "printf 4 with g:\n%.2g\n", 4.);
     fprintf(stdout, "printf ret:\n %i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("printf 4 with g:\n%.2g\n", 4.);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     ret = fprintf(stdout, "printf 4 with g:\n%.2g\n", 1000000000000000000.);
     fprintf(stdout, "printf ret:\n %i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("printf 4 with g:\n%.2g\n", 1000000000000000000.);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     ret = fprintf(stdout, "printf 4.1 with g:\n%.2g\n", 4.1); //ERROR when casting to long long int, only with 4.1 for unknown reason
     fprintf(stdout, "printf ret:\n %i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("printf 4.1 with g:\n%.2g\n", 4.1);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     ret = fprintf(stdout, "printf 0.32 with g:\n%.2g\n", 0.3298651);
     fprintf(stdout, "printf ret:\n %i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("printf 0.32 with g:\n%.2g\n", 0.3298651);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     ret = fprintf(stdout, "printf 4.001 with g:\n%.2g\n", 4.001);
     fprintf(stdout, "printf ret:\n %i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("printf 4.001 with g:\n%.2g\n", 4.001);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     ret = fprintf(stdout, "printf 4.2345435; with g:\n%.8g\n", 4.2345435);
     fprintf(stdout, "printf ret:\n %i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("printf 4.2345435; with g:\n%.8g\n", 4.2345435);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     ret = fprintf(stdout, "printf -4.99999 with g:\n%.4g\n", -4.99999);
     fprintf(stdout, "printf ret:\n %i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("printf -4.99999 with g:\n%.4g\n", -4.99999);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     ret = fprintf(stdout, "printf -9.99999 with g:\n%.4g\n", -9.99999);
     fprintf(stdout, "printf ret:\n %i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("printf -9.99999 with g:\n%.4g\n", -9.99999);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     /*
     ** BONUS specifiers FLAG combinations
     */

SEP;

     write(1,"\n|Flag combinations|\n",21);

SEP;

TITLE_YLW("  __ ");
TITLE_YLW(" / _|");
TITLE_YLW("| |_ ");
TITLE_YLW("|  _|");
TITLE_YLW("|_|  ");
TITLE_YLW("     ");

     TITLE_BLU("\n|Flag combinations f|\n");

SEP;

     ret = fprintf(stdout, "printf modulo 7 precision 5 f:\n%7.5f\n", -9.99999);
     fprintf(stdout, "printf ret:\n%i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("printf modulo 7 precision 5 f:\n%7.5f\n", -9.99999);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     ret = fprintf(stdout, "modulo 8 point 3 f:\n%16.3f\n", -8473.0);
     fprintf(stdout, "printf ret:\n%i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("modulo 8 point 3 f:\n%16.3f\n", -8473.0);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     ret = fprintf(stdout, "modulo minus 8 point 5 f:\n%-16.5fl\n", 34.0);
     fprintf(stdout, "printf ret:\n%i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("modulo minus 8 point 5 f:\n%-16.5fl\n", 34.0);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     ret = fprintf(stdout, "modulo 0 8 point 5 f:\n%016.5fl\n", -34.0);
     fprintf(stdout, "printf ret:\n%i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("modulo 0 8 point 5 f:\n%016.5fl\n", -34.0);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     ret = fprintf(stdout, "modulo 0 8 point 5 f:\n%016.5fl\n", 34.0);
     fprintf(stdout, "printf ret:\n%i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("modulo 0 8 point 5 f:\n%016.5fl\n", 34.0);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     ret = fprintf(stdout, "modulo 5 point 0 f:\n%5.0fl\n", 0.0);
     fprintf(stdout, "printf ret:\n%i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("modulo 5 point 0 f:\n%5.0fl\n", 0.0);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     ret = fprintf(stdout, "print f 0 :\n%f\n", 0.0);
     fprintf(stdout, "printf ret:\n%i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("print f 0 :\n%f\n", 0.0);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     ret = fprintf(stdout, "modulo 4 point 8 f:\n%4.8f\n", 424242424.0);
     fprintf(stdout, "printf ret:\n%i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("modulo 4 point 8 f:\n%4.8f\n", 424242424.0);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     ret = fprintf(stdout, "printf:\n p30 %.0f\n", 100.0);
     fprintf(stdout, "printf ret:\n%i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("printf:\n p30 %.0f\n", 100.0);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

TITLE_YLW("  ___ ");
TITLE_YLW(" / _ \\");
TITLE_YLW("|  __/");
TITLE_YLW(" \\___|");
TITLE_YLW("      ");

     TITLE_BLU("\n|Flag combinations e|\n");

SEP;

     ret = fprintf(stdout, "printf modulo 7 precision 5 e:\n%7.5e\n", -9.99999);
     fprintf(stdout, "printf ret:\n%i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("printf modulo 7 precision 5 e:\n%7.5e\n", -9.99999);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     ret = fprintf(stdout, "modulo 8 point 3 e:\n%16.3e\n", -8473.0);
     fprintf(stdout, "printf ret:\n%i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("modulo 8 point 3 e:\n%16.3e\n", -8473.0);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     ret = fprintf(stdout, "modulo minus 8 point 5 e:\n%-33.5el\n", 34.0);
     fprintf(stdout, "printf ret:\n%i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("modulo minus 8 point 5 e:\n%-33.5el\n", 34.0);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     ret = fprintf(stdout, "modulo 0 8 point 5 e:\n%016.5el\n", -34.0);
     fprintf(stdout, "printf ret:\n%i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("modulo 0 8 point 5 e:\n%016.5el\n", -34.0);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     ret = fprintf(stdout, "modulo 0 8 point 5 e:\n%016.5el\n", 34.0);
     fprintf(stdout, "printf ret:\n%i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("modulo 0 8 point 5 e:\n%016.5el\n", 34.0);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     ret = fprintf(stdout, "print e 0 :\n%e\n", 0.1);
     fprintf(stdout, "printf ret:\n%i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("print e 0 :\n%e\n", 0.1);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     ret = fprintf(stdout, "print e 0 :\n%e\n", 0.0);
     fprintf(stdout, "printf ret:\n%i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("print e 0 :\n%e\n", 0.0);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     ret = fprintf(stdout, "modulo 5 point 0 e:\n%5.0el\n", 0.0);
     fprintf(stdout, "printf ret:\n%i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("modulo 5 point 0 e:\n%5.0el\n", 0.0);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     ret = fprintf(stdout, "modulo 5 point 0 e:\n%5.0el\n", 4453434.0);
     fprintf(stdout, "printf ret:\n%i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("modulo 5 point 0 e:\n%5.0el\n", 4454343.0);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     ret = fprintf(stdout, "modulo 4 point 8 e:\n%4.8e\n", 424242424.0);
     fprintf(stdout, "printf ret:\n%i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("modulo 4 point 8 e:\n%4.8e\n", 424242424.0);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     ret = fprintf(stdout, "printf:\n p30 %.0e\n", 100.0);
     fprintf(stdout, "printf ret:\n%i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("printf:\n p30 %.0e\n", 100.0);
     ft_printf("ft_printf ret:\n%i\n", ret2);

         
TITLE_YLW("  __ _ ");
TITLE_YLW(" / _` |");
TITLE_YLW("| (_| |");
TITLE_YLW(" \\__, |");
TITLE_YLW(" |___/ ");

     TITLE_BLU("\n|Flag combinations g|\n");

SEP;

     ret = fprintf(stdout, "printf modulo 7 precision 5 g:\n%7.5g\n", -9.99999);
     fprintf(stdout, "printf ret:\n%i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("printf modulo 7 precision 5 g:\n%7.5g\n", -9.99999);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     /*ret = fprintf(stdout, "modulo 8 point 3 g:\n%16.3g\n", -8473.0);
     fprintf(stdout, "printf ret:\n%i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("modulo 8 point 3 g:\n%16.3g\n", -8473.0);
     ft_printf("ft_printf ret:\n%i\n", ret2);*///Real function ERROR

SEP;

    //  ret = fprintf(stdout, "modulo minus 8 point 5 g:\n%-16.5gl\n", 34.0);
    //  fprintf(stdout, "printf ret:\n%i\n", ret);
    //  write(1, "ft_", 3);
    //  ret2 = ft_printf("modulo minus 8 point 5 g:\n%-16.5gl\n", 34.0);
    //  ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     ret = fprintf(stdout, "modulo 0 8 point 5 g:\n%016.5gl\n", -34.0);
     fprintf(stdout, "printf ret:\n%i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("modulo 0 8 point 5 g:\n%016.5gl\n", -34.0);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     ret = fprintf(stdout, "modulo 0 8 point 5 g:\n%016.5gl\n", 34.0);
     fprintf(stdout, "printf ret:\n%i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("modulo 0 8 point 5 g:\n%016.5gl\n", 34.0);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     ret = fprintf(stdout, "modulo 5 point 0 g:\n%5.0gl\n", 0.0);
     fprintf(stdout, "printf ret:\n%i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("modulo 5 point 0 g:\n%5.0gl\n", 0.0);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     ret = fprintf(stdout, "print g 0 :\n%g\n", 0.0);
     fprintf(stdout, "printf ret:\n%i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("print g 0 :\n%g\n", 0.0);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     /*ret = fprintf(stdout, "modulo 4 point 8 g:\n%4.8g\n", 424242424.0);
     fprintf(stdout, "printf ret:\n%i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("modulo 4 point 8 g:\n%4.8g\n", 424242424.0);
     ft_printf("ft_printf ret:\n%i\n", ret2);*///real function ERROR

SEP;

     /*ret = fprintf(stdout, "printf:\n p30 %.0g\n", 100.0);
     fprintf(stdout, "printf ret:\n%i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("printf:\n p30 %.0g\n", 100.0);
     ft_printf("ft_printf ret:\n%i\n", ret2);*///real function ERROR

SEP;


     /*
     **BONUS_PART flags
     */

SEP;

TITLE_YLW(" _    __ _             ");
TITLE_YLW("| |  / _| | __ _  __ _ ");
TITLE_YLW("| | | |_| |/ _` |/ _` |");
TITLE_YLW("| | |  _| | (_| | (_| |");
TITLE_YLW("|_| |_| |_|\\__,_|\\__, |");
TITLE_YLW("                 |___/ ");

     TITLE_BLU("\n|l flag tests|\n");

SEP;

     ret = fprintf(stdout, "printf i:\n%li\n", 2147483649);
     fprintf(stdout, "printf ret:\n%i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("printf i:\n%li\n", 2147483649);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     ret = fprintf(stdout, "printf u:\n%lu\n", 2147483649 * 3);
     fprintf(stdout, "printf ret:\n%i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("printf u:\n%lu\n", 2147483649 * 3);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     ret = fprintf(stdout, "printf X:\n%lX\n", 2147483649 * 3);
     fprintf(stdout, "printf ret:\n%i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("printf X:\n%lX\n", 2147483649 * 3);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     ret = fprintf(stdout, "printf x:\n%lx\n", 2147483649 * 3);
     fprintf(stdout, "printf ret:\n%i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("printf x:\n%lx\n",2147483649 * 3);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

TITLE_YLW("  _ _    __ _             ");
TITLE_YLW(" | | |  / _| | __ _  __ _ ");
TITLE_YLW(" | | | | |_| |/ _` |/ _` |");
TITLE_YLW(" | | | |  _| | (_| | (_| |");
TITLE_YLW(" |_|_| |_| |_|\\__,_|\\__, |");
TITLE_YLW("                    |___/ ");

     TITLE_BLU("\n|ll flag tests|\n");

SEP;

    //  ret = fprintf(stdout, "printf i:\n%lli\n", -9223372036854775807);
    //  fprintf(stdout, "printf ret:\n%i\n", ret);
    //  write(1, "ft_", 3);
    //  ret2 = ft_printf("printf i:\n%lli\n", -9222372036854775807);
    //  ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    //  ret = fprintf(stdout, "printf u:\n%llu\n", 18446744073709551615);
    //  fprintf(stdout, "printf ret:\n%i\n", ret);
    //  write(1, "ft_", 3);
    //  ret2 = ft_printf("printf u:\n%llu\n", 18446744073709551615);
    //  ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    //  ret = fprintf(stdout, "printf X:\n%llX\n", 18446744073709551615);
    //  fprintf(stdout, "printf ret:\n%i\n", ret);
    //  write(1, "ft_", 3);
    //  ret2 = ft_printf("printf X:\n%llX\n", 18446744073709551615);
    //  ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    //  ret = fprintf(stdout, "printf x:\n%llx\n", 18446744073709551615);
    //  fprintf(stdout, "printf ret:\n%i\n", ret);
    //  write(1, "ft_", 3);
    //  ret2 = ft_printf("printf x:\n%llx\n", 18446744073709551615);
    //  ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

TITLE_YLW(" _        __ _             ");
TITLE_YLW("| |__    / _| | __ _  __ _ ");
TITLE_YLW("| '_ \\  | |_| |/ _` |/ _` |");
TITLE_YLW("| | | | |  _| | (_| | (_| |");
TITLE_YLW("|_| |_| |_| |_|\\__,_|\\__, |");
TITLE_YLW("                     |___/ ");

     TITLE_BLU("\n|h flag tests|\n");

SEP;

    //  ret = fprintf(stdout, "printf i:\n%hi\n", -32768);
    //  fprintf(stdout, "printf ret:\n%i\n", ret);
    //  write(1, "ft_", 3);
    //  ret2 = ft_printf("printf i:\n%hi\n", -32768);
    //  ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    //  ret = fprintf(stdout, "printf u:\n%hu\n", 65535);
    //  fprintf(stdout, "printf ret:\n%i\n", ret);
    //  write(1, "ft_", 3);
    //  ret2 = ft_printf("printf u:\n%hu\n", 65535);
    //  ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    //  ret = fprintf(stdout, "printf X:\n%hX\n", 65535);
    //  fprintf(stdout, "printf ret:\n%i\n", ret);
    //  write(1, "ft_", 3);
    //  ret2 = ft_printf("printf X:\n%hX\n", 65535);
    //  ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    //  ret = fprintf(stdout, "printf x:\n%hx\n", 65535);
    //  fprintf(stdout, "printf ret:\n%i\n", ret);
    //  write(1, "ft_", 3);
    //  ret2 = ft_printf("printf x:\n%hx\n", 65535);
    //  ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

TITLE_YLW("  _     _        __ _             ");
TITLE_YLW(" | |__ | |__    / _| | __ _  __ _ ");
TITLE_YLW(" | '_ \\| '_ \\  | |_| |/ _` |/ _` |");
TITLE_YLW(" | | | | | | | |  _| | (_| | (_| |");
TITLE_YLW(" |_| |_|_| |_| |_| |_|\\__,_|\\__, |");
TITLE_YLW("                            |___/ ");

     write(1,"\n|hh flag tests|\n",17);

SEP;

    //  ret = fprintf(stdout, "printf i:\n%hhi\n", -122);
    //  fprintf(stdout, "printf ret:\n%i\n", ret);
    //  write(1, "ft_", 3);
    //  ret2 = ft_printf("printf i:\n%hhi\n", -122);
    //  ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    //  ret = fprintf(stdout, "printf u:\n%hhu\n", 200);
    //  fprintf(stdout, "printf ret:\n%i\n", ret);
    //  write(1, "ft_", 3);
    //  ret2 = ft_printf("printf u:\n%hhu\n", 200);
    //  ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    //  ret = fprintf(stdout, "printf X:\n%hhX\n", 200);
    //  fprintf(stdout, "printf ret:\n%i\n", ret);
    //  write(1, "ft_", 3);
    //  ret2 = ft_printf("printf X:\n%hhX\n", 200);
    //  ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

    //  ret = fprintf(stdout, "printf x:\n%hhx\n", 200);
    //  fprintf(stdout, "printf ret:\n%i\n", ret);
    //  write(1, "ft_", 3);
    //  ret2 = ft_printf("printf x:\n%hhx\n", 200);
    //  ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     /*
     **Last bonus flags, don't work in combination with other flags
     */

SEP;

TITLE_YLW("  _  __    _  _   ");
TITLE_YLW(" (_)/ /  _| || |_ ");
TITLE_YLW("   / /  |_  ..  _|");
TITLE_YLW("  / /_  |_      _|");
TITLE_YLW(" /_/(_)   |_||_|  ");
TITLE_YLW("                  ");

     TITLE_BLU("\n|%# basic test|\n");

SEP;

     ret = fprintf(stdout, "printf x with flag #:\n%#x\n", x);
     fprintf(stdout, "printf ret:\n%i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("printf x with flag #:\n%#x\n", x);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     ret = fprintf(stdout, "printf X with flag #:\n%#X\n", x);
     fprintf(stdout, "printf ret:\n%i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("printf X with flag #:\n%#X\n", x);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     ret = fprintf(stdout, "printf x with flag # and value 0:\n%#x\n", x2);
     fprintf(stdout, "printf ret:\n%i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("printf x with flag # and value 0:\n%#x\n", x2);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     ret = fprintf(stdout, "printf X with flag # and value 0:\n%#X\n", x2);
     fprintf(stdout, "printf ret:\n%i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("printf X with flag # and value 0:\n%#X\n", x2);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

TITLE_YLW(" _  __        ");
TITLE_YLW("(_)/ /    _   ");
TITLE_YLW("  / /   _| |_ ");
TITLE_YLW(" / /_  |_   _|");
TITLE_YLW("/_/(_)   |_|  ");
TITLE_YLW("             ");

     TITLE_BLU("\n|%+ basic test|\n"); //Forces a plus sign in front of positive numbers works with d and i specifiers but not u.

SEP;

     ret = fprintf(stdout, "printf i with flag + on pos numbers:\n%+i\n", x);
     fprintf(stdout, "printf ret:\n%i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("printf i with flag + on pos numbers:\n%+i\n", x);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     ret = fprintf(stdout, "printf i with flag + on neg numbers:\n%+i\n", i);
     fprintf(stdout, "printf ret:\n%i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("printf i with flag + on neg numbers:\n%+i\n", i);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     ret = fprintf(stdout, "printf d with flag + on pos numbers:\n%+d\n", x);
     fprintf(stdout, "printf ret:\n%i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("printf d with flag + on pos numbers:\n%+d\n", x);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     ret = fprintf(stdout, "printf d with flag + on neg numbers:\n%+d\n", i);
     fprintf(stdout, "printf ret:\n%i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("printf d with flag + on neg numbers:\n%+d\n", i);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;

     ret = fprintf(stdout, "printf i with flag + on zero:\n%+i\n", x2);
     fprintf(stdout, "printf ret:\n%i\n", ret);
     write(1, "ft_", 3);
     ret2 = ft_printf("printf i with flag + on zero:\n%+i\n", x2);
     ft_printf("ft_printf ret:\n%i\n", ret2);

SEP;


  return(0);
}
