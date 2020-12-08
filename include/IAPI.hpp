#ifndef AVENCO_PC_PELUCHE_HPP_
#define AVENCO_PC_PELUCHE_HPP_

#include "Coordinator.hpp"

namespace APC
{
    class IAPI
    {
    public:
        // Fix all these prototypes
        virtual void getStory(const std::string name) = 0;
        virtual void getMP3(const std::string url) = 0;
        virtual void makeRequest(...) = 0;
    };
}

/* AVENCO_PC_PELUCHE_HPP_ */
