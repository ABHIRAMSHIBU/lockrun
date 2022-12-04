/* Copyleft 🄯 Abhiram Shibu 2022 */

#include "Shell.hh"

void * execCommand(const char * commandArgs[]){
    execvp(commandArgs[0],(char **)(&commandArgs[0]));
    return 0;
}