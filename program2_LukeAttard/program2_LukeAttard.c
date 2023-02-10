#include <stdio.h>
#include <stdlib.h>

void Get_Numb(int *numb)
{
  printf("Enter 0 or 1 to quit...");
  printf("Enter an NFL score: ");
  scanf("%d", numb);
}

void Find_Combinations(int score)
{
  int SScore = 2;
  int FGScore = 3;
  int TDScore = 6;
  int TDFGScore = 7;
  int PCScore = 8;
  
  int SCount;
  int FGCount;
  int TDCount;
  int TDFGCount;
  int PCCount;

  printf("TD+2\tTD+1\tTD\tFG\tSafety\n");
  
  for (int PCCount = 0; PCCount <= score / PCScore; PCCount++)
  {
    int temp1 = score - PCCount * PCScore;
    for (int TDFGCount = 0; TDFGCount <= temp1 / TDFGScore; TDFGCount++)
    {
      int temp2 = temp1 - TDFGCount * TDFGScore;
      for (int TDCount = 0; TDCount <= temp2 / TDScore; TDCount++)
      {
        int temp3 = temp2 - TDCount * TDScore;
        for (int FGCount = 0; FGCount <= temp3 / FGScore; FGCount++)
        {
          int temp4 = temp3 - FGCount * FGScore;
          if (temp4 % 2 ==0)
          {
            SCount = temp4 / 2;
            printf("%d\t%d\t%d\t%d\t%d\n", PCCount, TDFGCount, TDCount, FGCount, SCount);
          }
        }
      } 
    }
  }

}

void main()
{
  int score=-1;
  while (score != 0 && score !=1)
  {
    Get_Numb(&score);
    
    Find_Combinations(score);

  }
}