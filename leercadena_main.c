/*
 * Este programa muestra como leer varias palabras del teclado (stdin)
 * Codigo tomado de: https://www.programiz.com/c-programming/c-strings
 *
 * Modificado por: John Sanabria - john.sanabria@correounivalle.edu.co
 * Fecha: 2021-02-26
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "leercadena.h"

int main(int argc, char *argv[]) {

    char *argv1[argc-1];
    for(int i=0; i<argc; i++){
      argv1[i] = argv[i+1];
      }

    pid_t pid;
    pid = fork();
    if (pid < 0) {
      perror("No se pudo crear un proceso\n");
      exit(1);
    } else if (pid == 0){
      //execvp
      execvp(argv1[0], argv1);
      perror("Return from execvp() not expected");
      exit(EXIT_FAILURE);
    } else {
      wait(NULL);
    }

  return 0;
}

