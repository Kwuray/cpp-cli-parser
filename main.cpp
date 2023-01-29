#include "parser.h"

//trigger short option - no value
bool CliParser::triggerOption(char option) {
  switch (option) {
    case 'c':
      printf("Class argument !\n");
      return true;
    case 'a':
      printf("Attribute argument !\n");
      return true;
    default:
      return false;
  }
}

//trigger short option - value
bool CliParser::triggerOption(char option, string value) {
  switch (option) {
    case 'c':
      printf("Class argument ! with value\n");
      return value == "class";
    case 'a':
      printf("Attribute argument ! with value\n");
      return value == "attr";
    default:
      return false;
  }
}

//trigger long option - no value
bool CliParser::triggerOption(string option) {
  return true;
}

//trigger long option - value
bool CliParser::triggerOption(string option, string value) {
  return true;
}

int main(int argc, char const *argv[]) {
  CliParser parser{};
  parser.addOption('c', "classe", false, false);
  parser.addOption('a', "attr", "classe", true, false);
  parser.parse(argc, argv);
  return 0;
}
