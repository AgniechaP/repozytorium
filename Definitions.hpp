#ifndef DEFINITIONS_HPP
#define DEFINITIONS_HPP
#define SCREEN_WIDTH 665
#define SCREEN_HEIGHT 890

//EKRAN STARTOWY
#define SPLASH_SCREEN_TIME 3.0
#define SPLASH_BACKGROUND_FILEPATH "year2.png"
#define SPLASH_SOUND_EFFECT_FILEPATH "won.wav"
//MAIN MENU
#define MAIN_MENU_BACKGROUND_FILEPATH "backgroundForest.png"
#define GAME_TITLE_FILEPATH "zwierzakowo.png"
#define LATAJACA_KROWA_BUTTON_FILEPATH "latajaca_krowa.png"
//LATAJACA KROWA GRA
#define KROWA_BACKGROUND_FILEPATH "backgroundColorGrass.png"
#define GAME_OVER_BACKGROUND_FILEPATH "backgroundForest.png"
#define GAME_OVER_TITLE "game_over_title.png"
#define CLOUD_UP_FILEPATH "cloudup.png"
#define CLOUD_DOWN_FILEPATH "cloud.png"
#define CLOUD_SPEED 200.0f
#define CLOUD_FREQUENCY 3.0f
#define COW_FILEPATH "cow.png"
#define COW_STATE_STILL 1
#define COW_STATE_FALLING 2
#define COW_STATE_FLYING 3
#define GRAVITY 350.0f
#define COW_SPEED 350.0f
#define FLYING_DURATION 0.25f
#define SCORING_CLOUD_FILEPATH "InvisibleScoringCloud.png"
enum GameStates {
  eReady,
  ePlaying,
  eGameOver
};

#define WHITE_SPPED 1500.0f
#define FONT_FILEPATH "arial.ttf"
#define TIME_TO_GAMEOVER 1.5f
#endif // DEFINITIONS_HPP
