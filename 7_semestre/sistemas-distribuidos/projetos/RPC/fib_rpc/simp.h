/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _SIMP_H_RPCGEN
#define _SIMP_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif

#define foo 127

struct operands {
	int x;
};
typedef struct operands operands;

#define SIMP_PROG 555555555
#define SIMP_VERSION 1

#if defined(__STDC__) || defined(__cplusplus)
#define FIB 1
extern  int * fib_1(operands *, CLIENT *);
extern  int * fib_1_svc(operands *, struct svc_req *);
extern int simp_prog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define FIB 1
extern  int * fib_1();
extern  int * fib_1_svc();
extern int simp_prog_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_operands (XDR *, operands*);

#else /* K&R C */
extern bool_t xdr_operands ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_SIMP_H_RPCGEN */
