#ifndef AVENCO_PC_COORDINATOR_HPP_
#define AVENCO_PC_COORDINATOR_HPP_

#include <vector>
#include <string>

namespace APC {

    class Coordinator {
    private:
        using Node = struct node_s {
            char *_mp3; // TODO: find appropriate way to store
            std::vector<std::string> _annotations; // TODO: find appropriate way to store
            struct node_s *children;
        };
    public:
        Coordinator() = default;
        ~Coordinator() = default;

    public:
        bool getNewStory() noexcept;
        void makeChoice() noexcept;
        bool saveProgress() const noexcept;

    private:
        Node *_storyHead;
        Node *_curr;
        // some sort of inventory
    };
}

#endif /* AVENCO_PC_COORDINATOR_HPP_ */
