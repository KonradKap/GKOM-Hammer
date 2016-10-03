 /*
  * GameConstants.h
  *
  * 3.09.2016 r.
  *
  * Memotosh
  *
  */

#pragma once

constexpr int TARGET_FPS  = 60;
constexpr double TARGET_FPMS = TARGET_FPS / 1000.;
constexpr double FRAME_TIME_SEC = 1. / TARGET_FPS;
constexpr int FRAME_TIME_MSEC = 1 / TARGET_FPMS;

constexpr int WINDOW_X = 800;
constexpr int WINDOW_Y = 640;
constexpr char GAME_TITLE[] = "Kappa";
