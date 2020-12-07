/*
** EPITECH PROJECT, 2020
** sound
** File description:
** Sound
*/

#pragma once

#include <iostream>

#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Music.hpp>

namespace APC
{

    /// @Sound class manage the sound
    class Sound final
    {

    public:
        Sound(const std::string &path, bool repeat = false);
        ~Sound() noexcept = default;

        bool setSound(const std::string &path, bool repeat = false);
        bool isPlaying();

        void play();
        void stop();
        void pause();

    private:
        bool error();

    private:
        sf::Music _mus;
    };

} // namespace APC
