/*
** EPITECH PROJECT, 2020
** sound
** File description:
** Sound
*/

#include "Sound.hpp"

namespace APC
{

    /* CTOR & DTOR */

    Sound::Sound(const std::string &path, bool repeat) { setSound(path, repeat); }

    /* PUBLIC METHODS */

    bool Sound::setSound(const std::string &path, bool repeat)
    {
        if (!_mus.openFromFile(path.c_str()))
            return error();
        if (repeat)
            _mus.setLoop(repeat);
        return true;
    }

    void Sound::play()
    {
        std::cout << _mus.getVolume() << std::endl;
        _mus.play();
    }

    void Sound::stop() { _mus.stop(); }

    void Sound::pause() { _mus.pause(); }

    bool Sound::error()
    {
        std::cerr << "\033m[ERROR] [AudiOut] [Sound]"
                  << " File doesn't exist\033[0m" << std::endl;
        return false;
    }

    bool Sound::isPlaying()
    {
        if (_mus.getStatus() == 0)
            return false;
        return true;
    }

} // namespace APC
