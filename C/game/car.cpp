#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;


const int row = 52;
const int column = 72;


void printRace(char array1[row][column])   //prints 52 by 72 grid
{
   for (int i = 0; i < row; i++)
   {
      for (int j = 0; j < column; j++)
      {
         cout << array1[i][j];
      }
      cout << endl;
   }
}


void initRace(char array2[row][column])  //prints track layout
{

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (i == 0)     //top boundary
			{
				array2[i][j] = 'X';
			}
			else if (i == 51 && j < 65)   //bottom boundary
			{
				array2[i][j] = 'X';
			}
			else if (i == 51 && j < 71)  //prints finish line
			{
				array2[i][j] = 'F';
			}
			else if ((i >= 1 && i <= 51) && j == 0)   //left boundary
			{
				array2[i][j] = 'X';
			}
			else if ((i >= 1 && i <= 51) && j == 71)   //right boundary
			{
				array2[i][j] = 'X';
			}
			else if ((i >= 1 && i <= 35) && (j >= 10 && j <= 29))  //left barrier
			{
				array2[i][j] = 'X';
			}
			else if ((i >= 16 && i <= 50) && (j >= 40 && j <= 64))  //right barrier
			{
				array2[i][j] = 'X';
			}
			else
			{
				array2[i][j] = ' ';
			}
		}
	}
}




int main()
{
   char track[row][column];
   initRace(track);
   track[1][1] = '0';
   printRace(track);

   int xVelocity = 0, xAcceleration = 0;
   int yVelocity = 0, yAcceleration = 0;
   int xPosition = 1, yPosition = 1;
   int counter = 0;   //counter for seconds

   bool ontrack;

   while(1)
   {
      cout << "Horizontal and vertical acceleration (-1, 0, 1): ";
      cin >> xAcceleration >> yAcceleration;
      counter++;

      if (xAcceleration < -1 || xAcceleration > 1)
      {
			printRace(track);
         cout << "Crashed after " << counter << " seconds" << endl;
			return -1;
      }
      if (yAcceleration < -1 || yAcceleration > 1)
      {
			printRace(track);
         cout << "Crashed after " << counter << " seconds" << endl;
			return -1;
      }


      xVelocity = xVelocity + xAcceleration;
      yVelocity = yVelocity + yAcceleration;

      xPosition = xPosition + xVelocity;
      yPosition = yPosition + yVelocity;


      track[yPosition][xPosition] = '0';
      printRace(track);


      if ((yPosition == 0 && xPosition < 10) || (yPosition == 0 && xPosition > 30))   //when car is embedded in top boundary
      {
         track[0][xPosition] = '0';
         printRace(track);
         cout << "Crashed after " << counter << " seconds" << endl;
      }

      if (yPosition == 51 && xPosition < 41)  //when car is embedded in bottom boundary
      {
         track[51][xPosition] = '0';
         printRace(track);
         cout << "Crashed after " << counter << " seconds" << endl;
      }

      if ((yPosition >= 1 && yPosition <= 51) && xPosition == 0)  //when car is embedded in left boundary
      {
         track[yPosition][0] = '0';
         printRace(track);
         cout << "Crashed after " << counter << " seconds" << endl;
      }

      if ((yPosition >= 1 && yPosition <= 51) && xPosition == 71)   //when car is embedded in right boundary
      {
         track[yPosition][71] = '0';
         printRace(track);
         cout << "Crashed after " << counter << " seconds" << endl;
      }


   return 0;

}
}

