#include "Packable.h"
#include <cmath>

class Vec2f : public Packable
{
public:
    Vec2f()
        : _x(0), _y(0)
        {}

    Vec2f(float x, float y)
        : _x(x), _y(y)
        {}
    ~Vec2f()
    {}

    bool pack(std::ostream &out)
    {
        pack_write(out, _x);
        pack_write(out, _y);
        return true;
    }

    bool unpack(std::istream &in)
    {
        pack_read(in, _x);
        pack_read(in, _y);
        return true;
    }

    /**
     * @brief Get/Set _x
     * @details Don't ever do get set methods like this
     *          Should be get_x() set_x(). (I'm just lazy and wanted to see if it'd work)
     */
    float X() const
    {
        return _x;
    }
    void X(float x)
    {
        _x = x;
    }

    float Y() const
    {
        return _y;
    }
    void Y(float y)
    {
        _y = y;
    }

    void print()
    {
        std::cout << "(" << _x << ", " << _y << ")" << std::endl;
    }

private:
    float _x;
    float _y;
};

int main(int argc, char const *argv[])
{
    Vec2f a(2.1, 5.3);
    a.pack_file("a.pack");

    Vec2f b;
    a.unpack_file("a.pack");
    a.print();

    // testing Backpack stack allocated
    // create
    int length = 100;
    Vec2f *verts = new Vec2f[length];
    for (int i = 0; i < length; ++i)
    {
        Vec2f v((float)i*sinf(i), (float)i*cosf(i));
        //Vec2f v(i, i*100);
        v.print();
        verts[i] = v;
    }

    // save
    Backpack<Vec2f> bp(verts, length);
    bp.pack_file("verts.pack");

    // clear verts
    delete[] verts;
    verts = nullptr;

    int new_length = Backpack<Vec2f>::length_from_file("verts.pack");
    Vec2f *new_verts = new Vec2f[new_length];
    // load
    Backpack<Vec2f> new_bp(new_verts, new_length);
    new_bp.unpack_file("verts.pack");

    std::cout << "printing loaded.." << std::endl;
    for (int i = 0; i < length; ++i)
    {
        new_verts[i].print();
    }

    delete[] new_verts;
    new_verts = nullptr;

    // loading from vector
    std::vector<Vec2f> old_v = new_bp.vector();
    std::cout << "printing loaded vec.." << std::endl;
    for (int i = 0; i < length; ++i)
    {
        old_v[i].print();
    }

    old_v.push_back(Vec2f(1, 1));
    old_v.push_back(Vec2f(3, 3));

    Backpack<Vec2f> larger_pack = Backpack<Vec2f>::backpack_from_vector(old_v);
    larger_pack.pack_file("verts.pack");

    std::vector<Vec2f> new_v;
    Backpack<Vec2f> last("verts.pack");
    last.unpack_file("verts.pack");
    new_v = last.vector();
    std::cout << "printing loaded vec 2.." << std::endl;
    for (int i = 0; i < new_v.size(); ++i)
    {
        new_v[i].print();
    }

    return 0;
}
