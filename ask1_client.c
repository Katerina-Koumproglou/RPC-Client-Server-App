#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include "ask1.h"


#define BUFSIZE 1024
#define SERVER_PORT 6060

//Question 1
void
ask1_prog_1(char *host, int n, int *Y)
{
	CLIENT *clnt;
	float  *result_1;
	ques1  ques1_1_arg;

	#ifndef	DEBUG
	clnt = clnt_create (host, ASK1_PROG, QUES1_VERSION, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
	#endif	/* DEBUG */

  	//Initialising
  	ques1_1_arg.n = n;
  	ques1_1_arg.Y.Y_val = Y;
  	ques1_1_arg.Y.Y_len = n;

  	result_1 = ques1_1(&ques1_1_arg, clnt);
  	if (result_1 == (float *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	else {
		printf("Μέση τιμή του Y = %f\n", *result_1);
	}

	#ifndef	DEBUG
	clnt_destroy (clnt);
	#endif	 /* DEBUG */
}

//Question 2
void
ask1_prog_2(char *host, int n, int *Y)
{
	CLIENT *clnt;
	return2  *result_2;
	ques2  ques2_2_arg;

	#ifndef	DEBUG
	clnt = clnt_create (host, ASK1_PROG, QUES2_VERSION, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
	#endif	/* DEBUG */

  	//Initialising
  	ques2_2_arg.n = n;
  	ques2_2_arg.Y.Y_val = Y;
  	ques2_2_arg.Y.Y_len = n;

  	result_2 = ques2_2(&ques2_2_arg, clnt);
  	if (result_2 == NULL) {
		clnt_perror (clnt, "call failed");
	}
	else {
		printf("Ελάχιστη τιμή του Y = %d\n", result_2->Arr1[0]);
		printf("Μέγιστη τιμή του Y = %d\n", result_2->Arr1[1]);
	}

	#ifndef	DEBUG
	clnt_destroy (clnt);
	#endif	 /* DEBUG */
}

//Question 3
void
ask1_prog_3(char *host, int n, int *Y, float a)
{
	CLIENT *clnt;
	return3  *result_3;
	ques3  ques3_3_arg;

	#ifndef	DEBUG
	clnt = clnt_create (host, ASK1_PROG, QUES3_VERSION, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
	#endif	/* DEBUG */

	//Initialising
  	ques3_3_arg.n = n;
  	ques3_3_arg.Y.Y_val = Y;
  	ques3_3_arg.Y.Y_len = n;
  	ques3_3_arg.a = a;

  	result_3 = ques3_3(&ques3_3_arg, clnt);
  	if (result_3 == NULL) {
		clnt_perror (clnt, "call failed");
	}
	else {
		for (int i = 0; i < n; i++){
			printf("Γινόμενο α*Υ[%d] = %f\n", i + 1, result_3->Arr2.Arr2_val[i]);
		}
	}

	#ifndef	DEBUG
	clnt_destroy (clnt);
	#endif	 /* DEBUG */
}

int main (int argc, char *argv[])
{
	// int sd; /* Socket descriptor */
	// struct sockaddr_in server; /* Server to connect */
	// struct hostent *server_host; /* Host info */
	// char *host="localhost";

	// /* Get info on host */
	// if ( (server_host=gethostbyname(host)) == NULL )
	// { fprintf(stderr, "%s: unknown host %s\n", argv[0], argv[1]);
  	// 	exit(1);
	// }
	// /* Set up struct sockaddr_in */
	// server.sin_family = AF_INET;
	// server.sin_port = htons(SERVER_PORT);
	// bcopy((char*)server_host->h_addr, (char*)&server.sin_addr, server_host->h_length);

	// /* Connect */
	// if ( connect(sd, &server, sizeof(server)) < 0 )
	// {
 	// 	fprintf(stderr, "%s: cannot connect to server: ", argv[0]);
 	// 	perror(0);
 	// 	exit(1);
	// }

	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];

	int n, i;
	float a;

  	printf("Δώσε n: ");
  	scanf("%d", &n);

  	int* Y = (int *)malloc(n * sizeof(int));

  	//Fill matrix Y
  	for (i = 0; i < n; i++){
    	printf("Δώσε Y[%d] = ", i + 1);
    	scanf("%d", &Y[i]);
  	}

  	printf("Δώσε α: ");
  	scanf("%f", &a);

	int choice = 0;
  	while (choice != 4){
    	do{
      	printf("--------------------------------------------\n");
      	printf("Μενού\n");
      	printf("1. Μέση τιμή του διανύσματος Υ\n");
      	printf("2. Μέγιστη και ελάχιστη τιμή του Υ\n");
      	printf("3. Γινόμενο α * Y\n");
      	printf("4. Έξοδος\n");
      	printf("--------------------------------------------\n");
      	printf("Εισάγετε την επιλογή σας: ");
      	scanf("%d", &choice);
    	} while(choice < 1 || choice > 4);

    	if (choice == 4){
      	printf("Αντίο!\n");
      	exit(1);
    	}

    	switch (choice){
      	case 1:
      		printf("\n\n*************************************\n");
        	ask1_prog_1(host, n, Y);  //Call function for question 1
        	printf("*************************************\n\n");
        	break;

      	case 2:
      		printf("\n\n*************************************\n");
      	  	ask1_prog_2(host, n, Y);  //Call function for question 2
      	  	printf("*************************************\n\n");
      	  	break;

      	case 3:
      		printf("\n\n*************************************\n");
      	  	ask1_prog_3(host, n, Y, a);  //Call function for question 3
      	  	printf("*************************************\n\n");
      	  	break;

      	default:
        printf("Error\n");
    	}
  	}
  	free(Y);
	exit (0);
}
