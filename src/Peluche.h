#ifndef AVENCO_PC_PELUCHE_H_
#define AVENCO_PC_PELUCHE_H_

#include "Coordinator.h"

namespace APC {
    enum class InputType {SomeInput, AnotherInput};

    class Peluche {
        // Will need at least 2 threads to run peluche & server (so the API can ping us)
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
