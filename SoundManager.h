#ifndef SOUND_MANAGER_H
#define SOUND_MANAGER_H

/* SFML Includes             *
 * Add to every SFML project */
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

using namespace sf;

namespace gm {
    class SoundManager
    {
    private:
        Sound sfx;
        SoundBuffer sfxBuffer;
    public:
        // Constructor
        SoundManager();

        void loadSound();

        void playSFX();

        // Destructor
        ~SoundManager();


    };
}

#endif