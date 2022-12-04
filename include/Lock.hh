/* Copyleft 🄯 Abhiram Shibu 2022 */

#include <iostream>
#include <string>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/file.h>

class Lock{
    private:
    std::string lf = {};
    int fd = {};
    mode_t m = {};

    public:
    Lock(std::string lockFile);

    int lock();

    int unlock();

    Lock(): Lock("/tmp/lockrun.lock"){
    }
};