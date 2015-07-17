#ifndef TIMBER_H
#define TIMBER_H

#include <cstdio>
#include <cstdarg>
#include <cstdlib>
#include <string>

#define __FILENAME__ (strrchr(__FILE__, '/') + 1)

/**
 * @brief macros for timber commands
 * @details allows lazy people to ignore Tim:: namespace
 * @usage for macros to be enabled #define TIMBER_MACROS must
 *        be called BEFORE you include "Timber.h"
 */
#ifdef TIMBER_MACROS
#define TLOG(__LEVEL__, __STR__) Tim::log((__LEVEL__), (__STR__))
#define TLOGF(__LEVEL__, __STR__, args...) Tim::logf((__LEVEL__), (__STR__), (args))
#define TSETL(__LEVEL__) Tim::set_log_level((__LEVEL__))
#define TTRACE(__LEVEL__, __STR__) Tim::trace((__LEVEL__), (__STR__), (__FILENAME__), (__FUNCTION__), (__LINE__))
#define TASSERT(__PARAM__) Tim::assert((__PARAM__), (__FILENAME__), (__FUNCTION__), (__LINE__))
#define T_KNONE Tim::kNONE
#define T_KERROR Tim::kERROR
#define T_KWARNING Tim::kWARNING
#define T_KINFO Tim::kINFO
#define T_KDEBUG Tim::kDEBUG
#define T_KALL Tim::kALL
#endif

namespace Tim
{

/**
 * enumeration of Log levels
 * higher log levels are inclusive of lower ones
 * for example: info includes error, but error does not include info
 */
enum LogType
{
    kNONE = 0,
    kERROR = 1,
    kWARNING = 2,
    kINFO = 3,
    kDEBUG = 4,
    kALL = 5
};

/**
 * @brief Configuration singleton class for logging
 * @details Access through shared_config()
 */
class Config
{
public:
    static Config &shared_config()
    {
        static Config instance;
        return instance;
    }

    // get log level
    LogType get_log_level() const
    {
        return _level;
    }
    // set log level
    void set_log_level(LogType level)
    {
        _level = level;
    }
private:
    Config() : _level(kINFO)
    {}

    LogType _level;
};

const char *_expandchr(char chr, int len)
{
    char *str = new char[len];
    for (int i = 0; i < len; ++i)
    {
        *(str+i) = chr;
    }
    return (const char*)str;
}

/**
 * @brief Check if level has access
 *
 * @param level level to use
 * @return if level has privileges
 */
static inline bool _has_level(LogType level)
{
    return (level <= static_cast<LogType>(Config::shared_config().get_log_level()));
}

/**
 * @brief printable string from levels
 *
 * @param level level to print
 * @return string from level
 */
static inline const char *_level_to_str(LogType level)
{
    switch (level)
    {
        case kNONE:
            return "NONE";
        case kERROR:
            return "ERROR";
        case kWARNING:
            return "WARNING";
        case kINFO:
            return "INFO";
        case kDEBUG:
            return "DEBUG";
        case kALL:
            return "ALL";
        default:
            return "UNKNOWN";
    }
}

/**
 * @brief prints log to stderr with format
 *
 * @param level level to print
 * @param format_str string to use as formatter
 */
static inline void logf(LogType level, const char *format_str, ...)
{
    if (_has_level(level))
    {
        fprintf(stderr, "[%s] ", _level_to_str(level));
        va_list args;
        va_start (args, format_str);
        vfprintf(stderr, format_str, args);
        va_end(args);
        fprintf(stderr, "\n");
    }
}

/**
 * @brief print to stderr without formatting
 *
 * @param level to print
 * @param str string to print
 */
static inline void log(LogType level, const char *str)
{
    if (_has_level(level))
    {
        fprintf(stderr, "[%s] %s\n", _level_to_str(level), str);
    }
}

#define TRACE (__FILENAME__), (__FUNCTION__), (__LINE__)
static inline void trace(LogType level, const char *str, const char *file, const char *func, int line)
{
    logf(level, "%s: %s in %s() at L%d", str, file, func, line);
}

/**
 * @brief global func to set log level
 * @details because it is a common use
 *
 * @param level level to set
 */
static inline void set_log_level(LogType level)
{
    Config::shared_config().set_log_level(level);
    logf(kDEBUG, "Log level set to [%s]", _level_to_str(level));
}

static inline bool assert(bool param, const char *file, const char *func, int line)
{
    if (!param)
    {
        trace(kERROR, "[Assertion Failed]", file, func, line);
        return false;
    }
    return true;
}

/**
 * @brief displays an osx UI notifcation
 * @details will only work on osx 10.10 +
 * This will always be INFO
 *
 * @param subtitle bold text to display
 * @param message info text to display
 */
static inline void osx_notification(const char *subtitle, const char *message)
{
    if (_has_level(kALL))
    {
        #ifdef __APPLE__
        char output[255];
        snprintf(output, 255, "osascript -e 'display notification \"%s\" with title \"Timber\" subtitle \"%s\"'", subtitle, message);
        system(output);
        #endif
        char const *line = _expandchr('_', strlen(message) + 2);
        logf(kINFO, "[OSX NOTIFICATION]\n%s\n|%s%s|\n|%s%s|\n|%s", line, subtitle, _expandchr(' ', strlen(line) - strlen(subtitle) - 1), message, _expandchr(' ', 1), line);
    }
}

}  // namespace Tim

#endif  // TIMBER_H
