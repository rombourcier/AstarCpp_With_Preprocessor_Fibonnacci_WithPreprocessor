#include "Math.h"
#include <math.h> 
Math::Math()
{
}

float Math::Magnitude(int vecA[2], int vecB[2])
{

	int x = vecA[0] - vecB[0];
	int y = vecA[1] - vecB[1];
	return sqrt(x * x + y * y);
}
