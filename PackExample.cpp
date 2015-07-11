#include "Packable.h"
#include "Properties.h"
#include <fstream>

class Cat : public Packable
{
public:
    Cat()
    {}
    ~Cat()
    {}

    void pack(std::ostream &out);
    void unpack(std::istream &in);

    Property(int, age)
    Property(int, weight)
};

void Cat::pack(std::ostream &out)
{
    pack_write(out, _age);
    pack_write(out, _weight);
}

void Cat::unpack(std::istream &in)
{
    pack_read(in, _age);
    pack_read(in, _weight);
}

Auto_Getter(int, age, Cat)
Auto_Setter(int, age, Cat)

Auto_Getter(int, weight, Cat)
Auto_Setter(int, weight, Cat)

int main(int argc, char const *argv[])
{
    Cat mr;
    mr.set_age(3);
    mr.set_weight(65);
    std::cout << "packing.." << std::endl;
    mr.pack_file("cat.pack");

    Cat kit;
    std::cout << "unpacking.." << std::endl;
    kit.unpack_file("cat.pack");

    std::cout << kit.get_age() << " : " << kit.get_weight() << std::endl;

    // testing creating a object straight from file.
    Cat puss = Packable::create_from_pack<Cat>("cat.pack");
    std::cout << puss.get_age() << " : " << puss.get_weight() << std::endl;

    return 0;
}
