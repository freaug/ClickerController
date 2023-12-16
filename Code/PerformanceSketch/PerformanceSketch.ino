int clockPin[] = {2, 5, 8, 11, A5};  //right
int latchPin[] = {3, 6, 9, 12, A4}; //left
int dataPin[] = {4, 7, 10, 13, A3}; //middle

byte powerVal[] = {128, 64, 32, 16};
byte clearVal[] = {8, 4, 2, 1};

byte data;

byte dataArray[31] = {
  161,  145,  129,  113,  97,   81,   65,   49,   33,   17,
  162,  146,  130,  114,  98,   82,   66,   50,   34,   18,
  163,  147,  131,  115,  99,   83,   67,   51,   35,   19,
  68
};

const int lineOneLen = 63;

byte lineOne[lineOneLen] = {
  97, 82, 129, 113, 129, 84, 145, 162, 146, 84, 162, 84,
  115, 113, 33, 146, 146, 145, 162, 34, 50, 84, 83, 81,
  84, 51, 81, 84, 130, 33, 113, 51, 84, 113, 33, 33, 51,
  84, 51, 81, 84, 114, 49, 113, 146, 97, 84, 81, 129, 162,
  113, 84, 33, 114, 84, 115, 33, 34, 34, 129, 98, 129, 36
};

const int lineTwoLen = 75;

byte lineTwo[lineTwoLen] = {
  97, 82, 129, 84, 115, 113, 33, 146, 146, 145, 162, 34, 50,
  84, 145, 33, 65, 34, 130, 84, 115, 82, 49, 113, 17, 84, 146,
  129, 99, 129, 67, 84, 97, 49, 51, 129, 146, 84, 97, 33, 84,
  34, 129, 97, 84, 81, 33, 65, 84, 50, 67, 33, 145, 84, 49, 97,
  84, 145, 162, 146, 84, 146, 162, 114, 129, 84, 97, 33, 84, 115,
  113, 33, 146, 146, 36
};

const int lineThreeLen = 50;

byte lineThree[lineThreeLen] = {
  49, 97, 84, 145, 33, 65, 34, 130, 84, 115, 82, 49, 113, 17,
  84, 33, 67, 129, 84, 97, 49, 51, 129, 84, 129, 99, 129, 113,
  81, 84, 146, 129, 115, 33, 67, 130, 52, 84, 146, 129, 99, 129,
  67, 84, 97, 49, 51, 129, 146, 36
};

const int lineFourLen = 34;

byte lineFour[lineFourLen] = {
  114, 33, 34, 34, 33, 145, 129, 130, 84, 83, 81, 84, 33, 67,
  129, 84, 51, 49, 67, 65, 97, 129, 84, 33, 114, 84, 146, 49,
  34, 129, 67, 115, 129, 36
};

const int chirpLen = 5;

byte chirp[chirpLen] = {
  115, 82, 49, 113, 17
};

byte dot = 36;

byte val; // the state of the machine

byte del = 18;

void setup() {
  for (int i = 0; i < 5; i++) {
    pinMode(latchPin[i], OUTPUT);
    pinMode(clockPin[i], OUTPUT);
    pinMode(dataPin[i], OUTPUT);
  }

  val = 0;

  delay(1000);
}

//need to make single function to type and then delete
void loop() {
  switch (val) {
    //power up
    case 0:
      power();
      val = 1;
      delay(500);
    //type story
    case 1:
      printSingle(lineOneLen, lineOne, 0, 150, 10);
      val = 2;
      delay(3000);
      break;
    case 2:
      clearScreen(0);
      val = 3;
      break;
    case 3:
      printSingle(lineTwoLen, lineTwo, 1, 150, 10);
      val = 4;
      delay(3000);
      break;
    case 4:
      clearScreen(1);
      val = 5;
      break;
    case 5:
      printSingle(lineThreeLen, lineThree, 2, 150, 10);
      val = 6;
      delay(3000);
      break;
    case 6:
      clearScreen(2);
      val = 7;
      break;
    case 7:
      printSingle(lineFourLen, lineFour, 3, 150, 10);
      val = 8;
      delay(3000);
      break;
    case 8:
      clearScreen(3);
      val = 9;
      break;
    case 9:
      delay(5000);
      val = 10;
      break;
    //type seven chirps
    case 10: //1 print
      printSingle(chirpLen, chirp, 0, 75, 925);
      val = 11;
      break;
    case 11: //1 clear
      clearScreen(0);
      val = 12;
      break;
    case 12: //2 print
      printSingle(chirpLen, chirp, 1, 75, 925);
      val = 13;
      break;
    case 13: //2 clear
      clearScreen(1);
      val = 14;
      break;
    case 14: //3 print
      printSingle(chirpLen, chirp, 2, 75, 925);
      val = 15;
      break;
    case 15: //3 clear
      clearScreen(2);
      val = 16;
      break;
    case 16: //4 print
      printSingle(chirpLen, chirp, 3, 75, 925);
      val = 17;
      break;
    case 17: //4 clear
      clearScreen(3);
      val = 18;
      break;
    case 18: //5 print
      printSingle(chirpLen, chirp, 0, 75, 925);
      val = 19;
      break;
    case 19: // 5 clear
      clearScreen(0);
      val = 20;
      break;
    case 20: // 6 print
      printSingle(chirpLen, chirp, 1, 75, 925);
      val = 21;
      break;
    case 21: // 6 clear
      clearScreen(1);
      val = 22;
      break;
    case 22: // 7 print
      printSingle(chirpLen, chirp, 2, 75, 925);
      val = 23;
      break;
    case 23: //7 clear
      clearScreen(2);
      val = 24;
      break;
    case 24: // print dots
      printAllDots();
      break;
    case 25:
      clearAll();
      val = 10;
      break;
    default:
      break;
  }
}

void printAllDots() {
  static byte total;
  for (int i = 0; i < 4; i++) {
    data = dot;

    digitalWrite(latchPin[i], 0);
    shiftOut(dataPin[i], clockPin[i], LSBFIRST, data);
    digitalWrite(latchPin[i], 1);

    delay(200);

    digitalWrite(latchPin[i], 0);
    shiftOut(dataPin[i], clockPin[i], LSBFIRST, 0);
    digitalWrite(latchPin[i], 1);

    delay(800);
  }
  total++;
  if (total > 60) {
    total = 0;
    val = 25;
  }
}

void printSingle(byte senLen, byte sen[], byte screenNum, byte type, byte del) {
  for (int i = 0; i < senLen; i++) {
    data = sen[i];

    digitalWrite(latchPin[screenNum], 0);
    shiftOut(dataPin[screenNum], clockPin[screenNum], LSBFIRST, data);
    digitalWrite(latchPin[screenNum], 1);

    delay(type);

    digitalWrite(latchPin[screenNum], 0);
    shiftOut(dataPin[screenNum], clockPin[screenNum], LSBFIRST, 0);
    digitalWrite(latchPin[screenNum], 1);

    delay(del);
  }
}

void clearScreen(byte screenNum) {
  digitalWrite(latchPin[4], 0);
  shiftOut(dataPin[4], clockPin[4], LSBFIRST, clearVal[screenNum]);
  digitalWrite(latchPin[4], 1);

  delay(500);

  digitalWrite(latchPin[4], 0);
  shiftOut(dataPin[4], clockPin[4], LSBFIRST, 0);
  digitalWrite(latchPin[4], 1);

  delay(500);
}

void clearAll() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(latchPin[4], 0);
    shiftOut(dataPin[4], clockPin[4], LSBFIRST, clearVal[i]);
    digitalWrite(latchPin[4], 1);

    delay(500);

    digitalWrite(latchPin[4], 0);
    shiftOut(dataPin[4], clockPin[4], LSBFIRST, 0);
    digitalWrite(latchPin[4], 1);

    delay(500);
  }
}

void power() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(latchPin[4], 0);
    shiftOut(dataPin[4], clockPin[4], LSBFIRST, powerVal[i]);
    digitalWrite(latchPin[4], 1);

    delay(900);

    digitalWrite(latchPin[4], 0);
    shiftOut(dataPin[4], clockPin[4], LSBFIRST, 0);
    digitalWrite(latchPin[4], 1);

    delay(100);
  }
}
