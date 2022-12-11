#include "SoundManager.h"
#include <iostream>

using namespace sf;
using namespace gm;
using namespace std;

SoundManager::SoundManager() {
    loadSound();
}

void SoundManager::loadSound() {

    if (!sfxBuffer.loadFromFile("blip.wav")) {
        cout << "Error loading sfx!" << endl;
        return;
    }

    sfx.setBuffer(sfxBuffer);
}

void SoundManager::playSFX() {
    sfx.play();
}

SoundManager::~SoundManager() {

}