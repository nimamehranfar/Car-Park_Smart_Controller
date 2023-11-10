#include <SimpleTimer.h>
#include "Timer.h"

SimpleTimer timer;
Timer t;

int enter = 0;
int exit_park = 0;
int pay = 0;

int parked = 0;
int next_park = 0;
int park_time_exit = 0;
int payment_amount = 0;
bool parking[12];
int parking_time[12];
int enter_door_open = 0;
int enter_door_timer = 0;
int exit_door = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(1, INPUT); //exit
  pinMode(0, INPUT); //enter
  pinMode(A1, INPUT); //pay

  pinMode(13, OUTPUT); //tabage1 1
  pinMode(12, OUTPUT); //tabage1 2
  pinMode(11, OUTPUT); //tabage1 3
  pinMode(10, OUTPUT); //tabage1 4
  pinMode(9, OUTPUT); //tabage2 1
  pinMode(8, OUTPUT); //tabage2 2
  pinMode(7, OUTPUT); //tabage2 3
  pinMode(6, OUTPUT); //tabage2 4
  pinMode(5, OUTPUT); //tabage3 1
  pinMode(4, OUTPUT); //tabage3 2
  pinMode(3, OUTPUT); //tabage3 3
  pinMode(2, OUTPUT); //tabage3 4

  pinMode(A0, OUTPUT); //door
  pinMode(A2, OUTPUT); //payment
  pinMode(A3, OUTPUT); //time bit2
  pinMode(A4, OUTPUT); //time bit1
  pinMode(A5, OUTPUT); //time bit0

  for (int i = 0; i < 12; i++) {
    parking[i] = false;
  }
}

void loop() {

  enter = digitalRead(0);
  exit_park = digitalRead(1);
  pay = digitalRead(A1);

  if (enter == HIGH && parked < 12) {
    parking[next_park] = true;
    parking_time[next_park] = millis();
    next_park++;
    if (next_park == 12) {
      next_park = 0;
    }
    parked++;
    enter_door_open = 1;
    enter_door_timer = millis();
    digitalWrite(A0, HIGH);
    delay(500);

  }
  else if (exit_park == HIGH && parked != 0) {
    for (int i = 0; i < 12; i++) {
      if (parking[i] == true) {
        parking[i] = false;
        parked--;
        park_time_exit = (int) ((millis() - parking_time[i]) / 5000);
        if (park_time_exit > 2) {
          payment_amount = 1;
        }
        else {
          payment_amount = 0;
        }
        exit_door = 1;
        digitalWrite(A0, HIGH);
        break;
      }
    }
    delay(500);
  }
  else if (pay == HIGH && exit_door == 1) {
    exit_door = 0;
    payment_amount = 0;
    park_time_exit = 0;
    digitalWrite(A0, LOW);
    delay(500);
  }


  if (enter_door_timer - millis() > 15000 && enter_door_open == 1) {
    enter_door_open = 0;
    enter_door_timer = 0;
    digitalWrite(A0, LOW);
  }


  if (payment_amount == 1) {
    digitalWrite(A2, HIGH);
  }
  else {
    digitalWrite(A2, LOW);
  }


  switch (park_time_exit) {
    case 0:
      digitalWrite(A3, LOW); digitalWrite(A4, LOW); digitalWrite(A5, LOW);
      break;
    case 1:
      digitalWrite(A3, LOW); digitalWrite(A4, LOW); digitalWrite(A5, HIGH);
      break;
    case 2:
      digitalWrite(A3, LOW); digitalWrite(A4, HIGH); digitalWrite(A5, LOW);
      break;
    case 3:
      digitalWrite(A3, LOW); digitalWrite(A4, HIGH); digitalWrite(A5, HIGH);
      break;
    case 4:
      digitalWrite(A3, HIGH); digitalWrite(A4, LOW); digitalWrite(A5, LOW);
      break;
    case 5:
      digitalWrite(A3, HIGH); digitalWrite(A4, LOW); digitalWrite(A5, HIGH);
      break;
    case 6:
      digitalWrite(A3, HIGH); digitalWrite(A4, HIGH); digitalWrite(A5, LOW);
      break;
    case 7:
      digitalWrite(A3, HIGH); digitalWrite(A4, HIGH); digitalWrite(A5, HIGH);
      break;
    case 8:
      digitalWrite(A3, HIGH); digitalWrite(A4, HIGH); digitalWrite(A5, HIGH);
      break;
    case -1:
      digitalWrite(A3, LOW); digitalWrite(A4, LOW); digitalWrite(A5, LOW);
      break;
    default:
      digitalWrite(A3, HIGH); digitalWrite(A4, HIGH); digitalWrite(A5, HIGH);
      break;
  }


  for (int i = 0; i < 12; i++) {
    if (parking[i] == true) {
      digitalWrite(i + 2, HIGH);
    }
    else {
      digitalWrite(i + 2, LOW);
    }
  }


}
