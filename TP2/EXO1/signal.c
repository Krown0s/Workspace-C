#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void traiterSignal(int numSignal);

typedef void (*PtrFunction) (int);

int main(void)
{
 	time_t t;
	t = time(NULL);
	printf("Date : %s", ctime(&t));

	printf("Login : %s\n", getenv("LOGNAME"));

	printf("UID : %i\n", getuid());

	PtrFunction function;

	function = signal(SIGUSR1, traiterSignal);
	
	if(function == SIG_ERR)
	{
		perror("Erreur");
		exit(0);
	}

	while(1){}	

	return 0;
}

void traiterSignal(int numSignal)
{
	if(numSignal != SIGUSR1)
	{
		perror("Erreur (2)");
		exit(0);
	}
	printf("SIGUSR1 reçu");
}
