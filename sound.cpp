//#include <SDL_mixer.h>
//#include "sound.h"
//#include <string>
//
//
//
////SoundEffect::SoundEffect() : chunk(nullptr) {}
//
//SoundEffect::~SoundEffect() {
//    if (chunk != nullptr) {
//        Mix_FreeChunk(chunk);
//    }
//}
//
//bool SoundEffect::Load(std::string path) {
//    chunk = Mix_LoadWAV(path.c_str());
//    if (chunk == nullptr) {
//        printf("Failed to load sound effect! SDL_mixer Error: %s\n", Mix_GetError());
//        return false;
//    }
//    return true;
//}
//
//void SoundEffect::Play() {
//    Mix_PlayChannel(-1, chunk, 0);
//}
//
//void SoundEffect::Stop() {
//    Mix_HaltChannel(-1);
//}
