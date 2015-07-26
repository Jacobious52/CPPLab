// this must be included if you want to use macros
#define TIMBER_MACROS

#include "Timber.h"

int main(int argc, char const *argv[])
{
    tim::set_log_level(tim::kALL);
    tim::osx_notification("Hello", "This is a test");

    tim::logf(tim::kINFO, "Hello %s", "World");
    tim::log(tim::kWARNING, "omg this happend");
    tim::trace(T_KWARNING, "yes no", TRACE);


    tim::check(1==2, TRACE);
    tim::check(2==2, TRACE);

    printf("PRINTER@@@\n");

    // lazy people way (macros)

    TSETL(T_KALL);
    TLOG(T_KINFO, "hello");
    TLOGF(T_KINFO, "y %s", "n");

    printf("BLAHBTBFB\n");

    TERROR("Errorrrrr");
    TINFO("INFO");

    TTRACE(T_KINFO, "omg no");

    TCHECK(1<3);
    TCHECK(5==3);

    return 0;
}
