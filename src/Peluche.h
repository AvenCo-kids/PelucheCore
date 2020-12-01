#ifndef AVENCO_PC_PELUCHE_H_
#define AVENCO_PC_PELUCHE_H_

#include "Coordinator.h"

namespace APC {
    enum class InputType {SomeInput, AnotherInput};

    class Peluche {
    public:
        Peluche() = default;
        ~Peluche() = default;

    public:
        Peluche& setInputFromUnity(InputType type) noexcept;

    private:
        Coordinator coord_;
        InputType input_;
    };
}


#endif /* AVENCO_PC_PELUCHE_H_ */
