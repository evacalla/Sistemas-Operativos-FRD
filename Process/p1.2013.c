#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char **argv) {
	pid_t pid;
	printf("\nH\n");
	pid = fork();
	if ( pid == 0 ) { // hijo z
		printf("Z\n");
		pid_t pid2 = fork();
		if ( pid2 == 0 ) { // hijo m
			printf("M\n");
		} else { // hijo z
			wait(NULL); // espero m
			pid_t pid3 = fork();
			if ( pid3 == 0 ) { // hijo x
				printf("X\n");
			} else { // hijo z
				wait(NULL); // espera x
			}
		}
	} else { // padre
		wait(NULL); // espero z
		pid_t pid4 = fork();
		if ( pid4 == 0 ) { // hijo y
			printf("Y\n");
		} else {           // padre h
			wait(NULL); // espera y
			printf("\n");
		}
	}
	exit(0);
}


