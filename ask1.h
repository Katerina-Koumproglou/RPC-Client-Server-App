/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _ASK1_H_RPCGEN
#define _ASK1_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct ques1 {
	int n;
	struct {
		u_int Y_len;
		int *Y_val;
	} Y;
};
typedef struct ques1 ques1;

struct ques2 {
	int n;
	struct {
		u_int Y_len;
		int *Y_val;
	} Y;
};
typedef struct ques2 ques2;

struct ques3 {
	int n;
	struct {
		u_int Y_len;
		int *Y_val;
	} Y;
	float a;
};
typedef struct ques3 ques3;

struct return2 {
	int Arr1[2];
};
typedef struct return2 return2;

struct return3 {
	struct {
		u_int Arr2_len;
		float *Arr2_val;
	} Arr2;
};
typedef struct return3 return3;

#define ASK1_PROG 0x12345678
#define QUES1_VERSION 1

#if defined(__STDC__) || defined(__cplusplus)
#define QUES1 1
extern  float * ques1_1(ques1 *, CLIENT *);
extern  float * ques1_1_svc(ques1 *, struct svc_req *);
extern int ask1_prog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define QUES1 1
extern  float * ques1_1();
extern  float * ques1_1_svc();
extern int ask1_prog_1_freeresult ();
#endif /* K&R C */
#define QUES2_VERSION 2

#if defined(__STDC__) || defined(__cplusplus)
#define QUES2 1
extern  return2 * ques2_2(ques2 *, CLIENT *);
extern  return2 * ques2_2_svc(ques2 *, struct svc_req *);
extern int ask1_prog_2_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define QUES2 1
extern  return2 * ques2_2();
extern  return2 * ques2_2_svc();
extern int ask1_prog_2_freeresult ();
#endif /* K&R C */
#define QUES3_VERSION 3

#if defined(__STDC__) || defined(__cplusplus)
#define QUES3 1
extern  return3 * ques3_3(ques3 *, CLIENT *);
extern  return3 * ques3_3_svc(ques3 *, struct svc_req *);
extern int ask1_prog_3_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define QUES3 1
extern  return3 * ques3_3();
extern  return3 * ques3_3_svc();
extern int ask1_prog_3_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_ques1 (XDR *, ques1*);
extern  bool_t xdr_ques2 (XDR *, ques2*);
extern  bool_t xdr_ques3 (XDR *, ques3*);
extern  bool_t xdr_return2 (XDR *, return2*);
extern  bool_t xdr_return3 (XDR *, return3*);

#else /* K&R C */
extern bool_t xdr_ques1 ();
extern bool_t xdr_ques2 ();
extern bool_t xdr_ques3 ();
extern bool_t xdr_return2 ();
extern bool_t xdr_return3 ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_ASK1_H_RPCGEN */
