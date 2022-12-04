#include "Shell.hh"
#include "Lock.hh"
#include "Debug.hh"
#include <iostream>

#define LOCKFILE "/tmp/lockrun.lck"

int main(int argc, char const *argv[])
{
    Lock l = Lock(LOCKFILE);
    if(argc < 2){
        std::cout<<"Please give the command you wish to run"<<std::endl;
    }
    int fd = l.lock();
    #ifdef DEBUG
    std::cout<<"Debug FD:"<<fd<<std::endl;
    #endif
    if(fd>=0){
        execCommand(argv+1);
    }
    else{
        std::cout<<"Locking Failure!"<<std::endl;
    }
    l.unlock();
    return 0;
}
