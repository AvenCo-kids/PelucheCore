//
// Created by quentin on 01/12/2020.
//

#include "Peluche.h"

namespace APC {
    Peluche& Peluche::setInputFromUnity(InputType type) noexcept {
        input_ = type;
        return *this;
    }
}