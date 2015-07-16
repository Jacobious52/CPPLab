// this must be included if you want to use macros
#define TIMBER_MACROS

#include "Timber.h"

int main(int argc, char const *argv[])
{
    Tim::set_log_level(Tim::kDEBUG);
    Tim::osx_notification("Hello", "This is a test");

    Tim::logf(Tim::kINFO, "Hello %s", "World");
    Tim::log(Tim::kERROR, "omg this happend");
    Tim::trace(T_KERROR, "yes no", TRACE);

    // lazy people way (macros)

    TSETL(T_KWARNING)
    TLOG(T_KWARNING, "hello")
    TLOG(T_KINFO, "not seen")
    TLOGF(T_KWARNING, "y %s", "n")

    TTRACE(T_KERROR, "omg no")

    return 0;
}
