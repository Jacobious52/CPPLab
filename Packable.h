/**
 * Easy Serialization for C++ objects
 * Copyright ç 2015 Jacob Gonzalez
 */

#pragma once

#include <vector>
#include <iostream>
#include <fstream>

/**
 * @brief Base Class for Serializable objects
 * @details Derive and override pack and unpack
 *          Used mainly for single class saving
 *          For bundling many classes use BackPack
 */
class Packable
{
public:
    /**
     * @brief pack object to stream
     *
     * @param out outstream to write to
     */
    virtual bool pack(std::ostream &out) = 0;
    /**
     * @brief unpack object to stream
     *
     * @param in insteam to read from
     */
    virtual bool unpack(std::istream &in) = 0;

    /**
     * @brief create a static object from pack
     * @details needs type checking
     *
     * @param name filename of packed object
     * @tparam T must derrive from packable
     * @return object unpacked
     */
    template <typename T>
    static T create_from_pack(const char *name)
    {
        T packed_obj;
        packed_obj.unpack_file(name);
        return packed_obj;
    }

    /**
     * @brief Creates a packable pointer from pack file
     * @details needs to have checking for non packable type
     *
     * @param name filename of pack
     * @return pointer to packable
     */
    template <typename T>
    static T *create_new_from_pack(const char *name)
    {
        T *packed_obj = new T();
        packed_obj->unpack_file(name);
        return packed_obj;
    }

    template <typename T>
    static inline void pack_write(std::ostream &out, T const &obj)
    {
        out.write(reinterpret_cast<char const *>(&obj), sizeof(T));
    }

    template <typename T>
    static inline void pack_read(std::istream &in, T &obj)
    {
        in.read(reinterpret_cast<char *>(&obj), sizeof(T));
    }

    template <typename T>
    static inline void pack_write(std::ostream &out, T const &obj, std::size_t len)
    {
        out.write(reinterpret_cast<char const *>(&obj), sizeof(T)*len);
    }

    template <typename T>
    static inline void pack_read(std::istream &in, T &obj, std::size_t len)
    {
        in.read(reinterpret_cast<char *>(&obj), sizeof(T)*len);
    }

    bool pack_file(const char *name)
    {
        std::ofstream file(name, std::ios::binary);
        bool worked = pack(file);
        file.close();
        return worked;
    }

    bool unpack_file(const char *name)
    {
        std::ifstream file(name, std::ios::binary);
        bool worked = unpack(file);
        file.close();
        return worked;
    }
};

/**
 * @brief Contain for array of Packable objects of 1 type
 *
 * @tparam T Type of packable object
 */
template <typename T>
class Backpack : public Packable
{
public:
    Backpack(T *items, int length)
        : _length(length)
    {
        _items = items;
    }

    Backpack(const char *name)
    {
        _length = length_from_file(name);
        _items = new T[_length];
    }

    ~Backpack()
    {
        _items = nullptr;
    }

    /**
     * @brief Create a filled backpack with populatated vector
     *
     * @param v filled vector
     *
     * @return filled backpack read for packing
     */
    static Backpack backpack_from_vector(std::vector<T> v)
    {
        Backpack bp(&v[0], v.size());
        return bp;
    }

    std::vector<T> vector()
    {
        std::vector<T> v;
        v.assign(items(), items()+length());
        return v;
    }

    static int length_from_file(const char *name)
    {
        std::ifstream file(name, std::ios::binary);

        int ver;
        pack_read(file, ver);
        if (ver != version())
        {
            std::cout << "Incorrect file version: " << ver << ". Should be: " << version() << std::endl;
            return -1;
        }

        int len;
        pack_read(file, len);
        return len;
    }

    bool pack(std::ostream &out)
    {
        pack_write(out, version());
        pack_write(out, length());
        for (int i = 0; i < length(); ++i)
        {
            _items[i].pack(out);
        }
        return true;
    }

    bool unpack(std::istream &in)
    {
        int ver;
        pack_read(in, ver);
        if (ver != version())
        {
            std::cout << "Incorrect file version: " << ver << ". Should be: " << version() << std::endl;
            return false;
        }

        int len;
        pack_read(in, len);
        if (len != length())
        {
            std::cout << "Incorrect file length: " << len << ". Expected: " << length() << std::endl;
            return false;
        }

        for (int i = 0; i < length(); ++i)
        {
            _items[i].unpack(in);
        }

        return true;
    }

    static int version()
    {
        return 1;
    }

    int length() const
    {
        return _length;
    }

    T *items() const
    {
        return _items;
    }

private:
    T *_items;
    int _length;
};
