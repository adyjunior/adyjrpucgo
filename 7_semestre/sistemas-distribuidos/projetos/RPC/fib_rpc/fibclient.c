#include <stdio.h>
#include "simp.h"  /* Created for us by rpcgen - has everything we need ! */

int fib( CLIENT *clnt, int x) {
  operands ops;
  int *result;

  /* Gather everything into a single data structure to send to the server */
  ops.x = x;

  /* Call the client stub created by rpcgen */
  result = fib_1(&ops,clnt);
  if (result==NULL) {
    fprintf(stderr,"Trouble calling remote procedure\n");
    exit(0);
  }
  return(*result);
}


int main( int argc, char *argv[]) {
  CLIENT *clnt;
  int x,y;

  if (argc!=3) {
    fprintf(stderr,"Parametros: %s num\n",argv[0]);
    exit(0);
  }

  clnt = clnt_create(argv[1], SIMP_PROG, SIMP_VERSION, "udp");

  /* Make sure the create worked */
  if (clnt == (CLIENT *) NULL) {
    clnt_pcreateerror(argv[1]);
    exit(1);
  }

  x = atoi(argv[2]);

  printf("Limite = %d, Resultado = %d\n",x, fib(clnt,x));


}
