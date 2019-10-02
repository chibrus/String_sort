#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<math.h>



const double EPS = 0.0000000000001;
const int INF = 3; \



//-------------------------------------------------—
//! @param [out] a Pointer to the coefficient of x^2
//! @param [out] b Pointer to the coefficient of x^1
//! @param [out] c Pointer to the coefficient of x^0
//-------------------------------------------------—
void input(double *a, double *b, double *c);



//-------------------------------------------------—
//! @param [in] b b-coefficient
//! @param [in] c c-coefficient
//! @param [out] x1 Pointer to the 1st root
//!
//! @return Number of roots
//!
//! @note In case of infinite number of roots ,
//! returns INF
//-------------------------------------------------—
int solvelinear(double b, double c, double *x1);



//-------------------------------------------------—
//! @param [in] a a-coefficient
//! @param [in] b b-coefficient
//! @param [in] c c-coefficient
//! @param [out] x1 Pointer to the 1st root
//! @param [out] x2 Pointer to the 2nd root
//!
//! @return number of roots
//-------------------------------------------------—
int solvesquare(double a, double b, double c, double *x1, double *x2);



//-------------------------------------------------—
//! @param [in] n n-double type number
//! @param [in] EPS EPS-const
//!
//! @return is the result of comparation
//-------------------------------------------------—
double checkdouble(double t);



//-------------------------------------------------—
//! UNIT TEST
//-------------------------------------------------—
void progcheck();



//-------------------------------------------------—
//@param [in] number of roots
//@param [in] first root
//@param [in] second root
//-------------------------------------------------—
void otvet(int number, double x1, double x2);



int main()
{						
	int number = 0;
	double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
	printf("Please, enter a, b, c:\n");
	input(&a, &b, &c);
	if (a != 0)
		number = solvesquare(a, b, c, &x1, &x2);
	else
		number = solvelinear(b, c, &x1);
	otvet(number, x1, x2);
	progcheck();
	system("pause");
	return 0;
}



void input(double *a, double *b, double *c)
{
	int norm;
	norm = scanf("%lg %lg %lg", a, b, c);
	while (norm != 3)
	{
		char* s = (char*)calloc(100, sizeof(char));
		scanf("%s", s);
		printf("Please enter a, b, c again:\n");
		norm = scanf("%lg %lg %lg", a, b, c);

	}
}



int solvesquare(double a, double b, double c, double *x1, double *x2)
{
	double d = checkdouble(sqrt(b * b - (4 * a * c)));
	if (d == 0)
	{
		*x1 = checkdouble(-b / (2 * a));
		return 1;
	}
	else if (d > 0)
	{
		*x1 = checkdouble((-b + d) / (2 * a));
		*x2 = checkdouble((-b - d) / (2 * a));
		return 2;
	}
	else
		return 0;
}



int solvelinear(double b, double c, double *x1)
{
	if (c == 0)
	{			
		if (b == 0)
			return INF;
		else
			{
				*x1 = 0;
				return 1;
			}
		}
	else
	{	
		if (b == 0)
			return 0;
		else
		{
				*x1 = checkdouble(-c / b);	
				return 1;
		}
	}
}



double checkdouble(double t)
{
	if (EPS > fabs(t))
		return 0;
	else
		return t;
}



void progcheck()
{
	printf("If you want to check the program write 1, other case - 0\n");
	int ans;
	scanf("%d", &ans);
	if (ans == 1)
	{
		double tempx1, tempx2;
		if (solvelinear(0, 0, &tempx1, &tempx2) == 3)
			printf("Ok\n");
		else
			printf("Error 1");
		if (solvesquare(1, 2, 1, &tempx1, &tempx2) == 1)
		{
			if (tempx1 == -1)
				printf("OK\n");
			else
				printf("Error 2");
		}
		if (solvelinear(0, 1, &tempx1, &tempx2) == 0)
			printf("OK\n");
		else
			printf("Error 3");
		if (solvelinear(1, -1, &tempx1, &tempx2) == 1)
		{
			if (tempx1 == 1)
				printf("OK\n");
			else
				printf("Error 4");
		}
		if (solvesquare(1, 0, -1, &tempx1, &tempx2) == 2)
		{
			if (tempx1 == 1 && tempx2 == -1)
				printf("OK\n");
			else
				printf("Error 5");
		}
		}

}



void otvet(int number, double x1, double x2)
{
	if (number == 0)
		printf("No roots\n");
	else if (number == 1)
		printf("x=%lg\n", x1);
	else if (number == 2)
		printf("x1=%lg, x2=%lg\n", x1, x2);
	else
		printf("Infinity number of roots\n");
}
