#include "Plush.hpp"

namespace APC
{
    Plush& Plush::setInputFromUnity(InputType type) noexcept {
        _input = type;
        return *this;
    }
}
