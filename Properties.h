
#pragma once

#define Property(TYPE, NAME) public: \
                                TYPE get_##NAME() const; \
                                void set_##NAME(TYPE NAME); \
                            private: \
                                TYPE _##NAME;

#define Getter(TYPE, NAME, CLASS) TYPE CLASS::get_##NAME() const
#define Setter(TYPE, NAME, CLASS) void CLASS::set_##NAME(TYPE NAME)

#define Auto_Getter(TYPE, NAME, CLASS) TYPE CLASS::get_##NAME() const \
                                       { \
                                            return _##NAME; \
                                       }

#define Auto_Setter(TYPE, NAME, CLASS) void CLASS::set_##NAME(TYPE NAME) \
                                       { \
                                         _##NAME = NAME; \
                                       }
