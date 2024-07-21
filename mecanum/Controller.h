#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <esp_now.h>
#include <WiFi.h>
#include <cstdint> // For uint8_t

typedef struct structController {
  bool connected;
  int dir;
} structController;

extern structController controller;

void InitESPNOW();
void OnDataRecv(const esp_now_recv_info *info, const uint8_t *incomingData, int len);

#endif