#ifndef SOUND_H
#define SOUND_H
#include "basefunc.h"
#include <bits/stdc++.h>
#define FREQ 44100
#define CHUNK_SIZE 2040

using Theme=std::map<std::string,Mix_Chunk*>;
using
class SoundEffect()
{
public:
    SoundEffect();
    ~SoundEffect();
    bool Load(std::string path);
    void Play();
    void Stop();
private:
    SoundEffect();
    MusicTheme m
};
#endif // SOUND_H
