#include <iostream>
using namespace std;
int main()
{
	// These first three lines are the player array,
	// the obstacle array, and the test array.
	// These arrays all store character and obstacle positions.
	int plx[3] = {1, 1, 5};
	int plo[3] = {3, 3, 4};
	int plo2[3] = {3, 4, 5};
	int plt[3] = {0, 0, 0};
	// This part asks the user to input a value to make a field
	// of some size.
	int x;
	cout << "Game Field Size:	|";
	cin >> x;
	char disp[x][x];
	// This for loop is the generic mapping function that displays
	// positions of given characters.
	for(int n = 0; n <= x; n++)
		{
			int v = 0;
			while(v <= x)
				{
					// This if else statement sets exception rules
					// in the loop specifically for the display of
					// obstacles.
					if ((v == plx[1])&&(n == plx[0]))
						{
							disp[v][n] = 'X';
							v = v + 1;
							cout << disp[v][n];
						}
					else if((v == plo[1])&&(n == plo[0]))
						{
							disp[v][n] = 'O';
							v = v + 1;
							cout << disp[v][n];
						}
					else if((v == plo2[1])&&(n == plo2[0]))
						{
							disp[v][n] = '^';
							v = v + 1;
							cout << disp[v][n];
						}
					else
						{
							disp[v][n] = '_';
							cout << disp[v][n];
							v = v + 1;
						}
				}
			cout << endl;
		}
	// The do while loop here controls the motion of the character by
	// asking the user for directions.
	char ply;
	do
		{
			cout << "Direction?	|";
			cin >> ply;
			cout << "~~~" << endl;
			int s = 1;
			// This switch statement contains all potential motion
			// posibilities and valid user commands.
			switch (ply)
				{
					case 'w':
						plt[0] = plx[0] - (1);
						plt[1] = plx[1];
						// This if else statement checks to see if the
						// obstacle location is the same as the
						// predicted player location and if so
						// prevents the player from moving in that
						// direction.
						if ((plt[0] == plo[0])&&(plt[1] == plo[1]))
							{
								s = 0;
								plx[0] = plx[0] - (1*s);
							}
						else if ((plt[0] == plo2[0])&&(plt[1] == plo2[1]))
							{
								s = 3;
								plx[0] = plx[0] - (1*s);
							}
						else
							{
								plx[0] = plx[0] - (1*s);
							}
						break;
					case 's':
						plt[0] = plx[0] + (1);
						plt[1] = plx[1];
						if ((plt[0] == plo[0])&&(plt[1] == plo[1]))
							{
								s = 0;
								plx[0] = plx[0] + (1*s);
							}
						else if ((plt[0] == plo2[0])&&(plt[1] == plo2[1]))
							{
								s = 3;
								plx[0] = plx[0] + (1*s);
							}
						else
							{
								plx[0] = plx[0] + (1*s);
							}
						break;
					case 'a':
						plt[1] = plx[1] - (1);
						plt[0] = plx[0];
						if ((plt[0] == plo[0])&&(plt[1] == plo[1]))
							{
								s = 0;
								plx[1] = plx[1] - (1*s);
							}
						else if ((plt[0] == plo2[0])&&(plt[1] == plo2[1]))
							{
								s = 3;
								plx[1] = plx[1] - (1*s);
							}
						else
							{
								plx[1] = plx[1] - (1*s);
							}
						break;
					case 'd':
						plt[1] = plx[1] + (1);
						plt[0] = plx[0];
						if ((plt[0] == plo[0])&&(plt[1] == plo[1]))
							{
								s = 0;
								plx[1] = plx[1] + (1*s);
							}
						else if ((plt[0] == plo2[0])&&(plt[1] == plo2[1]))
							{
								s = 3;
								plx[1] = plx[1] + (1*s);
							}
						else
							{
								plx[1] = plx[1] + (1*s);
							}
						break;
					// This case series controls the exit program
					// options.
					case 'e':
						ply = 'e';
						cout << "Goodbye!" << endl;
						break;
					case 'E':
						ply = 'e';
						cout << "Goodbye!" << endl;
						break;
					default:
						cout << "Input valid value!" << endl;
				}
			// This for loop is a more compact reiteration of the
			// earlier display loop with this loop checking for
			// exceptions to display.
			for(int n = 0; n <= x; n++)
				{
					int v = 0;
					while(v <= x)
						{
							disp[v][n] = '_';
							int q = plx[1];
							int z = plx[0];
							int r = plo[1];
							int t = plo[0];
							int l = plo2[1];
							int k = plo2[0];
							disp[q][z] = 'X';
							disp[r][t] = 'O';
							disp[l][k] = '^';
							cout << disp[v][n];
							v = v + 1;
						}
					cout << endl;
				}
		}
	while(ply != 'e');
}

