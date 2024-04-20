#include <math.h>
#include <stdio.h>

int min(int a, int b)
{
	return a < b ? a : b;
}

int max(int a, int b)
{
	return a > b ? a : b;
}

double calculateLineLength(int *A, int *B)
{
	if (A[0] == B[0])
		return max(A[1], B[1]) - min(A[1], B[1]);
	else if (A[1] == B[1])
		return max(A[0], B[0]) - min(A[0], B[0]);

	int xDiff = max(A[0], B[0]) - min(A[0], B[0]);
	int yDiff = max(A[1], B[1]) - min(A[1], B[1]);
	double lineLen = (xDiff * xDiff) + (yDiff * yDiff);

	return sqrt(lineLen);
}

void longestLine(int **points, int pointsSize, int *pointsColSize, int *A, int *B)
{
	*A = 0;		//corners of triangle/endpoints of longest side of triangle
	*B = 1;
	int longestLine = calculateLineLength(points[*A], points[*B]);
	for (int i = 0; i < pointsSize; i++)
	{
		for (int j = 0; j < *pointsColSize; j++)
		{
			;
		}
	}
}

double largestTriangleArea(int** points, int pointsSize, int* pointsColSize) {
	return 0;
}

int main()
{
	int A[] = {1, 0};
	int B[] = {1, 1};
	printf("%f\n", calculateLineLength(A, B));
}

/*
wanted to calculate longest line in matrix(gives longest side and 2 corners of the trinagle)
and then find the 3rd corner, that is the farthest from both other corners
but the area of a triangle is not determined by the circumference
with given circumference, the triangle with the largest area is the equilateral triangle
so this approach is out of the window

nandis other idea: the longest side/line can still be used to draw a cube around the line
the you want to search the points that are closest to the corner of this cube
and go towards the edges to inwards

but then this is similar than my other idea, where you just start calculating the
area of triangles, but you go from the edges of the matrix towards the inside
then i just need a logic to not miss any possible triangles while still minimising
the amount of triangles that are searched 

*/