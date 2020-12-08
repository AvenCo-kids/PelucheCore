#ifndef AVENCO_PC_COORDINATOR_HPP_
#define AVENCO_PC_COORDINATOR_HPP_

#include <map>
#include <string>
#include <vector>

namespace APC
{
    class Coordinator
    {
    private:
        using Node = struct node_s {
            char *_mp3path;
            int _timeCode;
            std::pair<bool /*exists*/, std::string /*script*/> _script;
            struct node_s *children;
        };
    public:
        Coordinator() = default;
        ~Coordinator() = default;

        bool getNewStory(void) noexcept;
        void makeChoice(Node *chosen) noexcept;
        bool saveProgress(int pageNumber) const noexcept;
    private:
        char *_storyName;
        Node *_storyHead;
        Node *_curr;
        std::map<std::string /*obj*/, bool /*used*/> _inv;
    };
}

#endif /* AVENCO_PC_COORDINATOR_HPP_ */
