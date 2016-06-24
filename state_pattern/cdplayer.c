#include <stdbool.h>
#include "cdplayer.h"

static const State* pCurrentState;

static const State* ignore(const State *pThis);
static const State* startPlay(const State *pThis);
static const State* stopPlay(const State *pThis);
static const State* pausePlay(const State *pThis);
static const State* resumePlay(const State *pThis);

const State IDLE = {
    ignore,
    startPlay
};

const State PLAY = {
    stopPlay,
    pausePlay
};

const State PAUSE = {
    stopPlay,
    resumePlay
};

void initialize() {
    pCurrentState = &IDLE;
}

void onStop() {
    pCurrentState = pCurrentState->stop(pCurrentState);
}

void onPlayOrPause() {
    pCurrentState = pCurrentState->playOrPause(pCurrentState);
}

static const State* ignore(const State* pThis) {
    printf("ignore\n");
    return pCurrentState;
}

static const State* stopPlay(const State* pThis) {
    printf("stop player\n");
    return &IDLE;
}

static const State* startPlay(const State* pThis) {
    printf("start player\n");
    return &PLAY;
}

static const State* pausePlay(const State* pThis) {
    printf("pause player\n");
    return &PAUSE;
}

static const State* resumePlay(const State* pThis) {
    printf("resume player\n");
    return &PLAY;
}

int main_state_pattern() {
    initialize();
    onPlayOrPause();
    onPlayOrPause();
    onPlayOrPause();
    onStop();

    return 0;
}
