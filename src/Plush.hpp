#ifndef AVENCO_PC_PELUCHE_HPP_
#define AVENCO_PC_PELUCHE_HPP_

#include "Coordinator.hpp"

namespace APC
{
    enum class InputType {SomeInput, AnotherInput};

    class Plush
    { // need at least 2 threads to run plush & server (so the API can ping us)
    public:
        Plush() = default;
        ~Plush() = default;

        Plush& setInputFromUnity(InputType type) noexcept;
    private:
        Coordinator _coord;
        InputType _input;
    };
}


#endif /* AVENCO_PC_PLUSH_HPP_ */
