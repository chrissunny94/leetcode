/****************
*    * Do not modify this starter code. *       *
* * Your code should be added at the bottom. *  *
*        * Thank you and good luck! *           *
****************/

#include <iostream>
using namespace std;
#include <iostream>
#include <string>
using namespace std;

// YOU WILL NEED TO CALL THIS FUNCTION
// Function for taking a string and creating a "checksum" in ASCII
// Reminder: The input string should be more than just the "command"
//           Review problem description for more info
unsigned char checksum(string input) {
  unsigned char accumulated = 0;
  for(char& c : input) {
    accumulated += c;
  }
  return (accumulated % 26) + 'A';
}

// Required output format
const string MSG_HEADER = "ZOOX";

const string MSG_LEFT = "LEFT";
const string MSG_RIGHT = "RIGHT";
const string MSG_FORWARD = "FORWARD";
const string MSG_BEEP = "BEEP";

const string OUTPUT_LEFT = "L";
const string OUTPUT_RIGHT = "R";
const string OUTPUT_FORWARD = "F";
const string OUTPUT_BEEP = "!";

// You should not need to call this function
// Util used by execute_packet_command(...)
void execute_command(string cmd, int repeat) {
  for (int i = 0; i < repeat; i++) {
    cout << cmd;
  }
}

// YOU WILL NEED TO CALL THIS FUNCTION
// Provide the content of the command packet as inputs.
// cmd should be the command string from the packet
// repeat should be the repeat byte from the packet
void execute_packet_command(string cmd, int repeat) {
  if (cmd.compare(MSG_LEFT) == 0) {
    execute_command(OUTPUT_LEFT, repeat);
  }
  if (cmd.compare(MSG_RIGHT) == 0) {
    execute_command(OUTPUT_RIGHT, repeat);
  }
  if (cmd.compare(MSG_FORWARD) == 0) {
    execute_command(OUTPUT_FORWARD, repeat);
  }
  if (cmd.compare(MSG_BEEP) == 0) {
    execute_command(OUTPUT_BEEP, repeat);
  }
}

// Required prototype and main
bool Parse(char c){
    //cout<<'\n'<<c;    
    if (c=='Z')
        return true;
    else return false;
}
int main() {
  string input;
  cin >> input;
  //cout << "Cmd: "<<input;
//   char* char_arr = input.c_str(); 
//   for(char& c : input) {
//     parse(c);
//   }

// for(std::string::iterator it = input.begin(); it != input.end(); ++it) {
//     //Parse(*it);
//     if(Parse(*it)){
//         int length = int(*it+4);
//         cout<<"\nLENGTH:"<<length<<"  ::\n";
//     }

// }
  for (int i = 0; i < input.length(); i++) {
		//cout << input[i]; 
        //parse(&input[i].c_str());
        if(Parse(input[i])){
            int length = int((input[i+4]) - '0');
            cout<<"\nLENGTH:"<<length<<"  ::\n";
            string command = input.substr(i+5 ,i+4+length );
            cout<<"\nCOMMAND:"<<command;
            string repeat_count = input.substr(i+5+length ,i+5+length+1 );
            cout<<"\nREPEAT:"<<repeat_count;
        }
        //cout<<"\n"<<checksum(input);
  }
  return 0;
}

/****************/
// ------ Do not modify above this line ----------
// ----------- Add your code below ---------------
/****************/