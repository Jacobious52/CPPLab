// Yucky macro utils for the lazy

#pragma once

#ifdef NULL
#undef NULL
#endif
#define NULL 0

#define loop(__LOOP_VAR__, __LOOP_START__, __LOOP_END__) for (int __LOOP_VAR__ = __LOOP_START__; __LOOP_VAR__ < __LOOP_END__; ++__LOOP_VAR__)

#define loopi(__LOOP_START__, __LOOP_END__) loop(i, __LOOP_START__, __LOOP_END__)
#define loopj(__LOOP_START__, __LOOP_END__) loop(j, __LOOP_START__, __LOOP_END__)

#define loopij(__LOOP_START_I__, __LOOP_END_I__, __LOOP_START_J__, __LOOP_END_J__) loopi(__LOOP_START_I__, __LOOP_END_I__) loopj(__LOOP_START_J__, __LOOP_END_J__)

#define printi(__PRINT_INT__) printf("%d\n", __PRINT_INT__)
