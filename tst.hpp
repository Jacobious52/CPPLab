#ifndef TST_H
#define TST_H

#include <iostream>
#include <string>
#include <vector>
#include <chrono>

class tst {
public:
    static void timer(bool t) {
        timed = t;
    }

    static void start(std::string group) {
        testCount = 0;
        passed = 0;
        failed = 0;

        std::cout << clr::header << "[" << group << "]" << clr::none << std::endl;
    }

    template <typename Func, typename Expect, typename... Args>
    static void test(Func f, Expect e, Args... a) {
        // time function
        auto start = std::chrono::high_resolution_clock::now();
        Expect r = f(a...);
        auto end = std::chrono::high_resolution_clock::now();
        auto elapsed = std::chrono::duration<double, std::milli>(end-start).count();

        // print results
        std::cout << (++testCount) << ": ";
        if (r == e){
            std::cout << clr::ok << "PASSED" << clr::info;
            if (timed) {
                std::cout << "\t" << elapsed << "ms";
            }
            passed++;
        } else {
            std::cout << clr::error << "FAILED" << clr::info;
            if (timed) {
                std::cout << "\t" << elapsed << "ms";
            }
            std::cout << clr::none << "\n\texpected: ";
            print(e);
            std::cout << "\n\treturned: ";
            print(r);
            failed++;
        }

        std::cout << clr::none << std::endl;
    }

    static void end() {
        if (passed != testCount) {
            std::cout << " - " << clr::info << "Passed: " << clr::ok << passed << "/" << testCount << clr::none << std::endl;
            std::cout << " - " << clr::info << "Failed: " << clr::error << failed << "/" << testCount << clr::none << std::endl;
        }
    }
private:
    static int passed;
    static int failed;
    static int testCount;
    static bool timed;

    tst();
    ~tst();

    // print specializations

    template <typename T>
    static inline void print(std::vector<T> &v) {
        std::cout << "{";
        for (size_t i = 0; i < v.size(); i++) {
            std::cout << v[i];
            if (i < v.size()-1) {
                std::cout << ", ";
            }
        }
        std::cout << "}";
    }

    static inline void print(std::string &s) {
        std::cout << "\"" << s << "\"";
    }

    template <typename T>
    static inline void print(T &t) {
        std::cout << t;
    }

    struct clr {
        static std::string error;
        static std::string ok;
        static std::string info;
        static std::string header;
        static std::string none;
    };
};

int tst::testCount = 0;
int tst::passed = 0;
int tst::failed = 0;
bool tst::timed = false;

std::string tst::clr::error = "\033[31m";
std::string tst::clr::ok = "\033[32m";
std::string tst::clr::info = "\033[33m";
std::string tst::clr::header = "\033[35m";
std::string tst::clr::none = "\033[0m";

#endif // TST_H
