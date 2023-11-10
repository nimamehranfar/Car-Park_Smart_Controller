#include <SimpleTimer.h>
#include "Timer.h"

SimpleTimer timer;
Timer t;

int p12 ;
int p11 ;
int p10;
int p9 ;
int p8;
int p7 ;
int p6 ;
int p5;
int p4 ;
int p3 ;
int p2;
int p1 ;

void setup() {
  // put your setup code here, to run once:
  pinMode(1, OUTPUT); //1s 0
  pinMode(0, OUTPUT); //1s 1
  pinMode(A4, OUTPUT); //1s 3
  pinMode(A5, OUTPUT); //1s 2

  pinMode(13, INPUT); //tabage1 1
  pinMode(12, INPUT); //tabage1 2
  pinMode(11, INPUT); //tabage1 3
  pinMode(10, INPUT); //tabage1 4
  pinMode(9, INPUT); //tabage2 1
  pinMode(8, INPUT); //tabage2 2
  pinMode(7, INPUT); //tabage2 3
  pinMode(6, INPUT); //tabage2 4
  pinMode(5, INPUT); //tabage3 1
  pinMode(4, INPUT); //tabage3 2
  pinMode(3, INPUT); //tabage3 3
  pinMode(2, INPUT); //tabage3 4

  pinMode(A0, OUTPUT); //1s 7
  pinMode(A1, OUTPUT); //1s 6
  pinMode(A2, OUTPUT); //1s 5
  pinMode(A3, OUTPUT); //1s 4
}

void loop() {

  p12 = digitalRead(2);
  p11 = digitalRead(3);
  p10 = digitalRead(4);
  p9 = digitalRead(5);
  p8 = digitalRead(6);
  p7 = digitalRead(7);
  p6 = digitalRead(8);
  p5 = digitalRead(9);
  p4 = digitalRead(10);
  p3 = digitalRead(11);
  p2 = digitalRead(12);
  p1 = digitalRead(13);

  int ones = 0;


  if (p12 == HIGH) {
    ones++;
  }
  if (p11 == HIGH) {
    ones++;
  }
  if (p10 == HIGH) {
    ones++;
  }
  if (p9 == HIGH) {
    ones++;
  }
  if (p8 == HIGH) {
    ones++;
  }
  if (p7 == HIGH) {
    ones++;
  }
  if (p6 == HIGH) {
    ones++;
  }
  if (p5 == HIGH) {
    ones++;
  }
  if (p4 == HIGH) {
    ones++;
  }
  if (p3 == HIGH) {
    ones++;
  }
  if (p2 == HIGH) {
    ones++;
  }
  if (p1 == HIGH) {
    ones++;
  }


  switch (ones) {
    case 0:
      digitalWrite(A4, LOW); digitalWrite(A5, LOW); digitalWrite(0, LOW); digitalWrite(1, LOW); digitalWrite(A0, LOW); digitalWrite(A1, LOW); digitalWrite(A2, LOW); digitalWrite(A3, LOW);
      break;
    case 1:
      digitalWrite(A4, LOW); digitalWrite(A5, LOW); digitalWrite(0, LOW); digitalWrite(1, HIGH); digitalWrite(A0, LOW); digitalWrite(A1, LOW); digitalWrite(A2, LOW); digitalWrite(A3, LOW);
      break;
    case 2:
      digitalWrite(A4, LOW); digitalWrite(A5, LOW); digitalWrite(0, HIGH); digitalWrite(1, LOW); digitalWrite(A0, LOW); digitalWrite(A1, LOW); digitalWrite(A2, LOW); digitalWrite(A3, LOW);
      break;
    case 3:
      digitalWrite(A4, LOW); digitalWrite(A5, LOW); digitalWrite(0, HIGH); digitalWrite(1, HIGH); digitalWrite(A0, LOW); digitalWrite(A1, LOW); digitalWrite(A2, LOW); digitalWrite(A3, LOW);
      break;
    case 4:
      digitalWrite(A4, LOW); digitalWrite(A5, HIGH); digitalWrite(0, LOW); digitalWrite(1, LOW); digitalWrite(A0, LOW); digitalWrite(A1, LOW); digitalWrite(A2, LOW); digitalWrite(A3, LOW);
      break;
    case 5:
      digitalWrite(A4, LOW); digitalWrite(A5, HIGH); digitalWrite(0, LOW); digitalWrite(1, HIGH); digitalWrite(A0, LOW); digitalWrite(A1, LOW); digitalWrite(A2, LOW); digitalWrite(A3, LOW);
      break;
    case 6:
      digitalWrite(A4, LOW); digitalWrite(A5, HIGH); digitalWrite(0, HIGH); digitalWrite(1, LOW); digitalWrite(A0, LOW); digitalWrite(A1, LOW); digitalWrite(A2, LOW); digitalWrite(A3, LOW);
      break;
    case 7:
      digitalWrite(A4, LOW); digitalWrite(A5, HIGH); digitalWrite(0, HIGH); digitalWrite(1, HIGH); digitalWrite(A0, LOW); digitalWrite(A1, LOW); digitalWrite(A2, LOW); digitalWrite(A3, LOW);
      break;
    case 8:
      digitalWrite(A4, HIGH); digitalWrite(A5, LOW); digitalWrite(0, LOW); digitalWrite(1, LOW); digitalWrite(A0, LOW); digitalWrite(A1, LOW); digitalWrite(A2, LOW); digitalWrite(A3, LOW);
      break;
    case 9:
      digitalWrite(A4, HIGH); digitalWrite(A5, LOW); digitalWrite(0, LOW); digitalWrite(1, HIGH); digitalWrite(A0, LOW); digitalWrite(A1, LOW); digitalWrite(A2, LOW); digitalWrite(A3, LOW);
      break;
    case 10:
      digitalWrite(A4, LOW); digitalWrite(A5, LOW); digitalWrite(0, LOW); digitalWrite(1, LOW); digitalWrite(A0, LOW); digitalWrite(A1, LOW); digitalWrite(A2, LOW); digitalWrite(A3, HIGH);
      break;
    case 11:
      digitalWrite(A4, LOW); digitalWrite(A5, LOW); digitalWrite(0, LOW); digitalWrite(1, HIGH); digitalWrite(A0, LOW); digitalWrite(A1, LOW); digitalWrite(A2, LOW); digitalWrite(A3, HIGH);
      break;
    case 12:
      digitalWrite(A4, LOW); digitalWrite(A5, LOW); digitalWrite(0, HIGH); digitalWrite(1, LOW); digitalWrite(A0, LOW); digitalWrite(A1, LOW); digitalWrite(A2, LOW); digitalWrite(A3, HIGH);
      break;
    case -1:
      digitalWrite(A4, LOW); digitalWrite(A5, LOW); digitalWrite(0, LOW); digitalWrite(1, LOW); digitalWrite(A0, LOW); digitalWrite(A1, LOW); digitalWrite(A2, LOW); digitalWrite(A3, LOW);
      break;
    default:
      digitalWrite(A4, LOW); digitalWrite(A5, LOW); digitalWrite(0, HIGH); digitalWrite(1, LOW); digitalWrite(A0, LOW); digitalWrite(A1, LOW); digitalWrite(A2, LOW); digitalWrite(A3, HIGH);
      break;
  }
  delay(100);



}
