#ifndef AVENCO_PC_COORDINATOR_HPP_
#define AVENCO_PC_COORDINATOR_HPP_

#include <map>
#include <string>
#include <vector>
#include "story.hpp"

namespace APC
{
    class Coordinator
    {
    public:
        Coordinator() = default;
        ~Coordinator() = default;

        void startStory(story_t *story);
        void makeChoice(inputName_t input) noexcept;
    private:
        story_t *_story;
        story_node_t *_curr;
    };
}

#endif /* AVENCO_PC_COORDINATOR_HPP_ */
