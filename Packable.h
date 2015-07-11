#pragma once

#include <iostream>
#include <fstream>

class Packable
{
public:
    virtual void pack(std::ostream &out) = 0;
    virtual void unpack(std::istream &in) = 0;

    template <typename T>
    static T create_from_pack(const char *name)
    {
        T packed_obj;
        packed_obj.unpack_file(name);
        return packed_obj;
    }

    template <typename T>
    inline void pack_write(std::ostream &out, T const &obj)
    {
        out.write(reinterpret_cast<char const *>(&obj), sizeof(T));
    }

    template <typename T>
    inline void pack_read(std::istream &in, T &obj)
    {
        in.read(reinterpret_cast<char *>(&obj), sizeof(T));
    }

    void pack_file(const char *name)
    {
        std::ofstream file(name, std::ios::binary);
        pack(file);
        file.close();
    }

    void unpack_file(const char *name)
    {
        std::ifstream file(name, std::ios::binary);
        unpack(file);
        file.close();
    }
};
