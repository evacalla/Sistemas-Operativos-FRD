#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


int main(int argc, char** argv){
   int pipe(pipe1[2]);
   int pipe(pipe2[2]);
   pid_t pid = fork();
   if( pid > 0){
       // Padre P
       close(pipe1[0]);
       close(pipe1[1]);
       close(pipe2[0]);
       close(pipe2[1]);
       while(wait(NULL) != -1);
       pid = fork();
       if( pid == 0){
           //Hijo2
           printf("hijo2 pid=%d\n", getpid());
           close(pipe1[0]);
           close(pipe2[0]);
           close(pipe2[1]);
           char linea[255];
           while(strncmp(linea,"chau",4)) != 0){
               gets(linea);
               printf("H2 [%d] envio [%s]\n", getpid(), linea);
               write(pipe1[1],linea, strlen(linea);
           }
           close(pipe1[1]);
           printf("Fin H2\n");
           pid = fork();
           if( pid == 0){
               //Nieto 2
               printf("Nieto2, pid = %d\n", getpid());
               close(pipe1[0]);
               close(pipe1[1]);
               close(pipe2[1]);
               char linea[255];
               int n;
               while(strncmp(linea,"chau", 4) != 0){
                   n = read(pipe2[0]), linea, 255);
                   linea[n]='\0';
                   printf("N2 [%d] lei [%s]\n", getpid(), linea);
               }
               close(pipe2[0]);
               printf("N2 fin\n");
           }
       }
   }else{
       //hijo1
       printf("Hijo1, pid = %d\n", getpid());
       close(pipe1[0]);
       close(pipe1[1]);
       close(pipe2[0]);
       char letra;
       while(strncmp(linea, "chau", 4) != 0){
           gets(linea);
           prinft("H1 [%d] envio [%s]", getpid(), linea);
           write(pipe2[1], letra, strleng(linea));
       }
       close(pipe2[1]);
       printf("H1 fin\n");
       pid = fork();
       if( pid == 0){
           //Nieto 1
           prinft("Nieto2, pid = %d\n", getpid());
           close(pipe1[1]);
           close(pipe2[0]);
           close(pipe2[1]);
           char linea;
           int n;
           while(strncmp(linea, "chau", 4) != 0){
               n = read(pipe1[0], linea, 255);
               linea[n] = '\0';
               printf("N1 [%d] lei [%s\n]", getpid(), linea)
           }
           close(pipe1[0]);
           printf("N1 Fin\n");
       }
   }
   return 0;
}
