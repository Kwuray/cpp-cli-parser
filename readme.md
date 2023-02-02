# C++ CLI parser

## Guide

### Creating the Main Object
To use the utility, you need to create the main object "CliParser":
```
CliParser::CliParser(bool enableArgs = false);
```
The constructor takes a boolean parameter that indicates whether or not it should take into account the "simple" arguments, that is, those that do not start with either a single dash or a double dash.

If this parameter is "false," then all simple arguments are rejected, which triggers an error.

### Adding Options
An option has several characteristics; it can be short or long, and may or may not require a value, and be optional or not. This gives rise to several types:
```
enum optionType {
  OPTION_SHORT,
  OPTION_SHORT_VALUE,
  OPTION_LONG,
  OPTION_LONG_VALUE,
  OPTION_SHORT_LONG,
  OPTION_SHORT_LONG_VALUE
};
```

To add an option, there is only one function with 3 variations:
```
//add short option
void CliParser::addOption(char shortOption, bool optional, bool value);

//add long option
void CliParser::addOption(string longOption, bool optional, bool value);

//add short and long option
void CliParser::addOption(char shortOption, string longOption, bool optional, bool value);
```

### Configuring Triggers
When all the options have been created, it is now necessary to define the functions that will be triggered when the tool encounters an option. There are 4. By default, they return "false":
```
//trigger short option - no value
bool CliParser::triggerOption(char option);

//trigger short option - value
bool CliParser::triggerOption(char option, string value);

//trigger long option - no value
bool CliParser::triggerOption(string option);

//trigger long option - value
bool CliParser::triggerOption(string option, string value);
```

For example, to set the trigger on short options without value (aka "flags"):
```
//trigger short option - no value
bool CliParser::triggerOption(char option) {
  switch (option) {
    case 'c':
      /*do something...*/
      return true;
    case 'a':
      /*do something...*/
      return true;
    default:
      return false;
  }
}
```

### Starting the Tool
We can now analyze the arguments using this function:
```
bool CliParser::parse(int argc, char const *argv[]);
```

At the slightest error, this function returns "false".

### Extracting Simple Arguments
If when creating the CliParser object, the constructor parameter is "true," then simple arguments are stored in an attribute:
```
vector<string> arguments{};
```
You can access it at any time using this function:
```
vector<string>* CliParser::getArguments();
```
### add hint
The hint message is added when you return "false" in a trigger function. This way, the message will be displayed automatically.
```
CliParser::setHint(string hint);
```
