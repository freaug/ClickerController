byte clockPin[] = {2, 5, 8, 11, 14, 17}; //left
byte latchPin[] = {3, 6, 9, 12, 15, 18}; //middle
byte dataPin[] = {4, 7, 10, 13, 16, 19}; //right
byte tonePin[] = {0, 1};


byte totalCharacters = 0;

byte wordPos = 0;
byte sum = 0;
byte one, two, three, four, five, six = 0; //screen cycle counters
byte data;

bool oneDone, twoDone, threeDone, fourDone, fiveDone, sixDone = false;

byte dataArray[39] = {
  51,  67,  83,  99,  115, 131, 147, 163, 179, 195,
  52,  68,  84,  100, 116, 132, 148, 164, 180, 196,
  53,  69,  85,  101, 117, 133, 149, 165, 181,  
       70,  86,  102, 118, 134, 150, 166, 182, 
                                     167, 183
};

const byte senLen = 128;

byte sentence[senLen] = {
164,183,150,84,118,84,100,183,69,84,84,166,183,116,180,183,133,53,118,84,183,84,150,180,148,117,133,183,116,164,166,84,183,183,183,183,164,183,116,133,164,150,165,183,116,133,53,116,183,164,69,183,69,180,166,84,116,133,164,150,117,183,68,84,183,102,53,150,183,53,181,181,183,100,84,181,53,116,84,183,116,180,180,183,183,183,183,133,180,68,183,85,180,183,132,180,148,183,166,53,150,53,117,84,183,183,183,183,132,180,148,100,183,181,53,102,165,183,180,101,183,116,164,166,84,183,183,183
};

byte val;

void setup() {
  for (int i = 0; i < 6; i++) {
    pinMode(latchPin[i], OUTPUT);
    pinMode(clockPin[i], OUTPUT);
    pinMode(dataPin[i], OUTPUT);
  }
  for (int i = 0; i < 2; i++) {
    pinMode(tonePin[i], OUTPUT);
  }

  val = 0;

  noTone(0);
  noTone(1);

  delay(2000);
}

void loop() {
  switch (val) {
    case 0:
      powerOnAll();
      delay(8000);
      val = 1;
      break;
    case 1:
      scream();
      break;
    case 2:
      eraseAll();
      delay(4000);
      val = 3;
      break;
    case 3:
      printSentenceSameAll(senLen);
      delay(5000);
    case 4:
      eraseAll();
      delay(2000);
      val = 5;
    case 5:
      powerOffAll();
      delay(3000);
      val = 0;
    default:
      break;
  }
}

//

void scream() {
  for (byte i = 0; i < 6; i++) {
    switch (i) {
      case 0:
        data = dataArray[random(39)];
        break;
      case 1:
        data = dataArray[random(39)];
        break;
      case 2:
        data = dataArray[random(39)];
        break;
      case 3:
        data = dataArray[random(39)];
        break;
      case 4:
        data = dataArray[random(39)];
        break;
      case 5:
        data = dataArray[random(39)];
        break;
      default:
        break;
    }

    digitalWrite(latchPin[i], 0);
    shiftOut(dataPin[i], clockPin[i], LSBFIRST, data);
    digitalWrite(latchPin[i], 1);

    tone(tonePin[0], 1500, 4);

    delay(random(75, 150));

    digitalWrite(latchPin[i], 0);
    shiftOut(dataPin[i], clockPin[i], LSBFIRST, 0);
    digitalWrite(latchPin[i], 1);


    tone(tonePin[1], 3300, 5);

    delay(random(75, 150));

    sum++;

    if (sum >= 6) {
      sum = 0;
      wordPos++;
      totalCharacters++;
    }

    if ( wordPos >= senLen) {
      wordPos = 0;
    }


    if (totalCharacters >= 128) {
      totalCharacters = 0;
      return;
    }
  }
}


void printSingle(byte senLen, byte sen[], byte screenNum) {
  for (int i = 0; i < senLen; i++) {
    data = sen[i];

    digitalWrite(latchPin[screenNum], 0);
    shiftOut(dataPin[screenNum], clockPin[screenNum], LSBFIRST, data);
    digitalWrite(latchPin[screenNum], 1);

    tone(tonePin[0], 1500, 4);

    delay(random(75, 150));

    digitalWrite(latchPin[screenNum], 0);
    shiftOut(dataPin[screenNum], clockPin[screenNum], LSBFIRST, 0);
    digitalWrite(latchPin[screenNum], 1);

    tone(tonePin[1], 3300, 5);

    delay(random(75, 150));
  }
}

void printSentenceSameAll(byte senLen) {
  for (int i = 0; i < 6; i++) {
    switch (i) {
      case 0:
        data = sentence[wordPos];
        break;
      case 1:
        data = sentence[wordPos];
        break;
      case 2:
        data = sentence[wordPos];
        break;
      case 3:
        data = sentence[wordPos];
        break;
      case 4:
        data = sentence[wordPos];
        break;
      case 5:
        data = sentence[wordPos];
        break;
      default:
        break;
    }

    digitalWrite(latchPin[i], 0);
    shiftOut(dataPin[i], clockPin[i], LSBFIRST, data);
    digitalWrite(latchPin[i], 1);

    tone(tonePin[0], 1500, 4);

    delay(random(75, 150));

    digitalWrite(latchPin[i], 0);
    shiftOut(dataPin[i], clockPin[i], LSBFIRST, 0);
    digitalWrite(latchPin[i], 1);


    tone(tonePin[1], 3300, 5);

    delay(random(75, 150));

    sum++;

    if (sum >= 6) {
      sum = 0;
      wordPos++;
      totalCharacters++;
    }

    if ( wordPos >= senLen) {
      wordPos = 0;
    }


    if (totalCharacters >= 128) {
      totalCharacters = 0;
      val = 4;
    }
  }
}

void powerOnOne(byte screenNum) {
  digitalWrite(latchPin[screenNum], 0);
  shiftOut(dataPin[screenNum], clockPin[screenNum], LSBFIRST, 17);
  digitalWrite(latchPin[screenNum], 1);

  delay(750);

  digitalWrite(latchPin[screenNum], 0);
  shiftOut(dataPin[screenNum], clockPin[screenNum], LSBFIRST, 0);
  digitalWrite(latchPin[screenNum], 1);

  delay(100);

}

void powerOnAll() {
  for (int i = 0; i < 6; i++) {
    digitalWrite(latchPin[i], 0);
    shiftOut(dataPin[i], clockPin[i], LSBFIRST, 17);
    digitalWrite(latchPin[i], 1);

    delay(750);

    digitalWrite(latchPin[i], 0);
    shiftOut(dataPin[i], clockPin[i], LSBFIRST, 0);
    digitalWrite(latchPin[i], 1);

    delay(100);
  }
}

void powerOffOne(byte screenNum) {
  digitalWrite(latchPin[screenNum], 0);
  shiftOut(dataPin[screenNum], clockPin[screenNum], LSBFIRST, 17);
  digitalWrite(latchPin[screenNum], 1);

  delay(1200);

  digitalWrite(latchPin[screenNum], 0);
  shiftOut(dataPin[screenNum], clockPin[screenNum], LSBFIRST, 0);
  digitalWrite(latchPin[screenNum], 1);

  delay(100);

}

void powerOffAll() {
  for (int i = 0; i < 6; i++) {
    digitalWrite(latchPin[i], 0);
    shiftOut(dataPin[i], clockPin[i], LSBFIRST, 17);
    digitalWrite(latchPin[i], 1);

    delay(1200);

    digitalWrite(latchPin[i], 0);
    shiftOut(dataPin[i], clockPin[i], LSBFIRST, 0);
    digitalWrite(latchPin[i], 1);

    delay(100);
  }
}

void eraseOne(byte screenNum) {
  digitalWrite(latchPin[screenNum], 0);
  shiftOut(dataPin[screenNum], clockPin[screenNum], LSBFIRST, 34);
  digitalWrite(latchPin[screenNum], 1);

  delay(250);

  digitalWrite(latchPin[screenNum], 0);
  shiftOut(dataPin[screenNum], clockPin[screenNum], LSBFIRST, 0);
  digitalWrite(latchPin[screenNum], 1);

  delay(100);

}

void eraseAll() {
  for (int i = 0; i < 6; i++) {
    digitalWrite(latchPin[i], 0);
    shiftOut(dataPin[i], clockPin[i], LSBFIRST, 34);
    digitalWrite(latchPin[i], 1);

    delay(250);

    digitalWrite(latchPin[i], 0);
    shiftOut(dataPin[i], clockPin[i], LSBFIRST, 0);
    digitalWrite(latchPin[i], 1);

    delay(100);

  }
}
