/*
** EPITECH PROJECT, 2020
** PelucheCore
** File description:
** story
*/

#ifndef STORY_HPP_
#define STORY_HPP_

#include <string>
#include <vector>

namespace APC {

    static const char *INPUTNAME[] = {
        "hand_left",
        "hand_right",
        "feet_left",
        "feet_right"
    };

    typedef enum inputName {
        hand_left,
        hand_right,
        feet_left,
        feet_right,
        none
    } inputName_t;

    typedef struct {
        std::string outputName;
        void *params;
    } story_output_t;

    typedef struct {
        std::string inputName;
        story_node_t next;
        bool tp;
        std::string path;
        void *params;
    } story_choice_t;

    typedef struct {
        bool hasScript;
        int waitTime;
        std::vector<story_output_t> output;
        std::vector<story_node_t> node;
    } story_node_t;

    typedef struct {
        std::string _id;
        std::string name;
        story_node_t startPoint;
    } story_t;
}

#endif /* !STORY_HPP_ */