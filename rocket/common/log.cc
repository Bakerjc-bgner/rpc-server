#include "log.h"
#include <sys/time.h>
namespace rocket{

    void logEvent::printLog(){
        struct timeval now_tv;
        


        gettimeofDay(&m_time, nullptr);
    }
}