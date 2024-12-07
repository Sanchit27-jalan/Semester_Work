/* Write a program in C to find the determinant of a matrix based
on Laplace Expansion Theorem. Choose a matrix of shape 5x5 and you
need to expand using the nth row or column based on your roll number :
n = roll_numbder%5.

If the last digit of your roll number is ODD, Go for Row Expansion,
otherwise go for Column Expansion.
*/

// Save the file as <RollNo>_Q4.c

// Use the following matrix to test your program.
// Matrix = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10},
// {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20},
// {21, 22, 23, 24, 25}}

/*Roll No is :- 2022101070
  n=0 and column expansion
  */

#include <stdio.h>
#define MATRIX_SIZE 5
int get_cofactor(int size, int cofactor[size][size])
{
  if (size == 2)
  {
    int t = cofactor[0][0] * cofactor[1][1] - cofactor[0][1] * cofactor[1][0];
    return t;
  }
  else
  {
    int to_be_calc[size - 1][size - 1];
    int ans = 0;
    int sign = 1;
    for (int i = 0; i < size; ++i)
    {
      int row = 0;
      int col = 0;
      for (int j = 0; j < size; ++j)
      {
        for (int k = 1; k < size; k++)
        {
          if (j == i)
          {
            continue;
          }
          else
          {
            to_be_calc[row][col] = cofactor[j][k];
            col++;
            if (col == (size - 1))
            {
              col = 0;
              row++;
            }
          }
        }
      }
      ans = ans + cofactor[i][0] * sign * get_cofactor(size - 1, to_be_calc);
      sign = -1 * sign;
    }
    return ans;
  }
}
int determinant_recursive(int matrix[MATRIX_SIZE][MATRIX_SIZE], int n)
{
  // Implementation of determinant_recursive function...
  int sign = 1;
  if (n % 2 == 1)
  {
    sign = -1;
  }
  int ans = 0;
  int cofactor[MATRIX_SIZE - 1][MATRIX_SIZE - 1];
  for (int i = 0; i < MATRIX_SIZE; ++i)
  {
    int row = 0;
    int column = 0;
    for (int j = 0; j < MATRIX_SIZE; ++j)
    {
      for (int k = 0; k < MATRIX_SIZE; ++k)
      {
        if (j == i)
        {
          continue;
        }
        else if (k == n)
        {
          continue;
        }
        else
        {
          cofactor[row][column] = matrix[j][k];
          column++;
          if (column == (MATRIX_SIZE - 1))
          {
            column = 0;
            row++;
          }
        }
      }
    }
    ans = ans + matrix[i][n] * sign * get_cofactor(MATRIX_SIZE - 1, cofactor);
    sign = -1 * sign;
  }
  return ans;
}
int laplace_expansion(int matrix[MATRIX_SIZE][MATRIX_SIZE], int n)
{
  return determinant_recursive(matrix, n);
}

int main()
{
  int matrix[MATRIX_SIZE][MATRIX_SIZE];
  printf("Enter the value of n:\n");
  int n;
  scanf("%d", &n);
  printf("Enter the elements of the matrix:\n");
  for (int i = 0; i < MATRIX_SIZE; i++)
  {
    for (int j = 0; j < MATRIX_SIZE; j++)
    {
      scanf("%d", &matrix[i][j]);
    }
  }
  printf("The determinant of the matrix is %d.\n", laplace_expansion(matrix, n));
  return 0;
}