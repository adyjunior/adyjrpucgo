/* RPC client for simple addition example */

#include <stdio.h>
#include "simp.h"  /* Created for us by rpcgen - has everything we need ! */

float mul( CLIENT *clnt, float x, float y) {
  operands ops;
  float *result;

  /* Gather everything into a single data structure to send to the server */
  ops.x = x;
  ops.y = y;

  /* Call the client stub created by rpcgen */
  result = mul_1(&ops,clnt);
  if (result==NULL) {
    fprintf(stderr,"Trouble calling remote procedure\n");
    exit(0);
  }
  return(*result);
}

float divisao( CLIENT *clnt, float x, float y) {
  operands ops;
  float *result;

  /* Gather everything into a single data structure to send to the server */
  ops.x = x;
  ops.y = y;

  /* Call the client stub created by rpcgen */
  result = div_1(&ops,clnt);
  if (result==NULL) {
    fprintf(stderr,"Trouble calling remote procedure\n");
    exit(0);
  }
  return(*result);
}



int main( int argc, char *argv[]) {
  CLIENT *clnt;
  float x,y;
  if (argc!=4) {
    fprintf(stderr,"Usage: %s hostname num1 num\n",argv[0]);
    exit(0);
  }

  /* Create a CLIENT data structure that reference the RPC
     procedure SIMP_PROG, version SIMP_VERSION running on the
     host specified by the 1st command line arg. */

  clnt = clnt_create(argv[1], SIMP_PROG, SIMP_VERSION, "udp");

  /* Make sure the create worked */
  if (clnt == (CLIENT *) NULL) {
    clnt_pcreateerror(argv[1]);
    exit(1);
  }

  /* get the 2 numbers that should be added */
  x = atof(argv[2]);
  y = atof(argv[3]);


  printf("%f * %f = %f\n",x,y, mul(clnt,x,y));
  printf("%f / %f = %f\n",x,y, divisao(clnt,x,y));
  return(0);
}



