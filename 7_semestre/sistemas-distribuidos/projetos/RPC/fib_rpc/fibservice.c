#include <stdio.h>
#include "simp.h"


int *
fib_1_svc(operands *argp, struct svc_req *rqstp)
{
	static int  result;
	int sequencia = 0;
	int x = 0 , y = 1;
	int limite = 0;
	limite = argp->x;
	int n = 0;

	//printf("Got request: mul %f, %f\n",argp->x, argp->y);

	//result = argp->x * argp->y;


	for(n = 0; n < limite; n++){
   	  sequencia = x + y;

	  x = y;
	  y = sequencia;
	}

	result = sequencia;

	return (&result);
}
