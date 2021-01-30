#ifndef fakePWM
#define fakePWM

void updatePWM();
void initPWM(unsigned int updateTime = 100);
void setPWM(unsigned int port, uint8_t value);

#endif