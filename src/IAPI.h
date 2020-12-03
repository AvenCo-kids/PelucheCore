#ifndef AVENCO_PC_PELUCHE_H_
#define AVENCO_PC_PELUCHE_H_

#include "Coordinator.h"

namespace APC {
    class IAPI {
    public:
        // Fix all these prototypes
        virtual void getStory(std::string const name) = 0;
        virtual void getMP3(std::string const url) = 0;
        virtual void makeRequest(...) = 0;
    };
}

