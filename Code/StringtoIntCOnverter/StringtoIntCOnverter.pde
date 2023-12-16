//program to convert string into numerical values
char[] c = {
  'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p',
  'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l',
  'z', 'x', 'c', 'v', 'b', 'n', 'm', ';',
  ',', '.'
};

String[] val = {
  "161", "145", "129", "113", "97", "81", "65", "49", "33", "17",
  "162", "146", "130", "114", "98", "82", "66", "50", "34", 
         "147", "131", "115", "99", "83", "67", "51", "35",
                                                "52", "36"
};

char space = ' ';
String spaceVal = "84";

char newLine = '\n';
String newLineVal = "19";

String s = ".";

ArrayList<String> data = new ArrayList<String>();
ArrayList<String> converted = new ArrayList<String>();

PrintWriter output;

void setup() {

  output = createWriter("convertedText.txt");

  char[] letters = s.toCharArray();

  for (int i = 0; i < letters.length; i++) {
    char c = letters[i];
    data.add(convert(c));
  }
  for (String i : data) {
    output.print(i);
    output.print(',');
  }
  output.println();
  output.print("Length: ");
  output.print(data.size());
  output.flush();
  output.close();
  delay(1000);
  exit();
}

String convert(char cc) {
  String d = "";
  for ( int i = 0; i < c.length; i++) {
    if (c[i] == cc) {
      d = val[i];
    }
    if (cc == ' ') {
      d = spaceVal;
    }
    if (cc == '\n') {
      d = newLineVal;
    }
  }
  return d;
}
