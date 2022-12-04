#include "Lock.hh"

Lock::Lock(std::string lockFile){
    lf = lockFile;
}

int Lock::lock(){
    m = umask(0);
    fd = open(lf.c_str(), O_RDWR|O_CREAT, 0600);
    umask(m);
    if( fd >= 0 && flock( fd, LOCK_EX | LOCK_NB ) < 0 )
    {
        close( fd );
        fd = -1;
    }
    return fd;
}

int Lock::unlock(){
    if( fd < 0 )
        return 0;
    remove(lf.c_str());
    close( fd );
    return 1;
}
