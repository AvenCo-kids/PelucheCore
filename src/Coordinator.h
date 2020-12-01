#ifndef AVENCO_PC_COORDINATOR_H_
#define AVENCO_PC_COORDINATOR_H_

#include <vector>
#include <string>

namespace APC {

    class Coordinator {
    private:
        using Node = struct node_s {
            char *mp3_; // TODO: find appropriate way to store
            std::vector<std::string> annotations_; // TODO: find appropriate way to store
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
        Node *storyHead_;
        Node *curr_;
        // some sort of inventory
    };
}

#endif /* AVENCO_PC_COORDINATOR_H_ */
