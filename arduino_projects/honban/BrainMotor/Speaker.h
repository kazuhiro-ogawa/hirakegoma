#pragma once

typedef enum{
  STATUS_WAIT = 0,
  STATUS_FULLWAIT = 1
}mode;

class Speaker{
  private :
    const int BEAT = 150;
    int preferenceMelody = 0;
    int speaker;
    int melody_1[9] = {3136,2960,2489,1760,1661,2637,3322,4186};
    int melody_2[];
    int melody_3[];

  public :
    Speaker(int spakerPin);
    void playMelody(int modeState);
    void setPreferenceMelody(int melodyNum);
};
