// this must be included if you want to use macros
#define TIMBER_MACROS

#include "Timber.h"

int main(int argc, char const *argv[])
{
    Tim::set_log_level(Tim::kALL);
    Tim::osx_notification("Hello", "This is a test");

    Tim::logf(Tim::kINFO, "Hello %s", "World");
    Tim::log(Tim::kWARNING, "omg this happend");
    Tim::trace(T_KWARNING, "yes no", TRACE);


    Tim::assert(1==2, TRACE);
    Tim::assert(2==2, TRACE);

    printf("PRINTER@@@\n");

    // lazy people way (macros)

    TSETL(T_KALL);
    TLOG(T_KINFO, "hello");
    TLOGF(T_KINFO, "y %s", "n");

    printf("BLAHBTBFB\n");

    TERROR("Errorrrrr");
    TINFO("INFO");

    TTRACE(T_KINFO, "omg no");

    TASSERT(1<3);
    TASSERT(5==3);

    return 0;
}
