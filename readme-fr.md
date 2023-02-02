# C++ CLI parser

## Guide de fonctionnement

### Instantiation de l'objet principal
Afin d'utiliser l'utilitaire, il convient de créer l'objet principal "CliParser" :
```
CliParser::CliParser(bool enableArgs = false);
```
Le constructeur prend en paramètre un booléen qui indique si oui ou non il doit prendre en compte les arguments "simple". C'est à dire ceux qui ne commencent ni par un simple tiret ni par un double tiret

Si ce paramètre vaut "faux", alors tous les arguments simples sont rejetés, ce qui déclenche une erreur.

### Ajout d'option
Une option a plusieurs caractéristiques, elle peut être courte ou longue, et peut nécessiter ou non une valeur, et être optionnelle ou non. Ainsi, se dégage plusieurs types :
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

Pour ajouter une option, il existe une seule fonction avec 3 variantes :
```
//add short option
void CliParser::addOption(char shortOption, bool optional, bool value);

//add long option
void CliParser::addOption(string longOption, bool optional, bool value);

//add short and long option
void CliParser::addOption(char shortOption, string longOption, bool optional, bool value);
```

### Configuration des "triggers"
Lorsque toutes les options ont été crées, il faut maintenant définir les fonctions qui vont se déclencher lorsque l'outil rencontre une option. Il y en a 4. Par défaut, elles renvoient "false" :
```
//trigger short option - no value
bool CliParser::triggerOption(CliParser *parser, char option);

//trigger short option - value
bool CliParser::triggerOption(CliParser *parser, char option, string value);

//trigger long option - no value
bool CliParser::triggerOption(CliParser *parser, string option);

//trigger long option - value
bool CliParser::triggerOption(CliParser *parser, string option, string value);
```

Par exemple, pour définir le déclencheur sur les options courtes sans valeur (aka les "flags") :
```
//trigger short option - no value
bool CliParser::triggerOption(CliParser *parser, char option) {
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

### Démarrage de l'outil
Nous pouvons désormais analyser les arguments à l'aide de cette fonction :
```
bool CliParser::parse(int argc, char const *argv[]);
```

A la moindre erreur, cette fonction renvoie "false".

### Extraire les arguments simple
Si lors de la création de l'objet CliParser, le paramètre du constructeur vaut "true", les arguments simples sont stocké dans un attribut :
```
vector<string> arguments{};
```
Vous pouvez y accéder à tout moment à l'aide de cette fonction :
```
vector<string>* CliParser::getArguments();
```

### Messages d'aide
Le message d'aide s'ajoute lorsque vous allez retourner "false" lors d'une fonction trigger. Ainsi, ce message sera affiché automatiquement.
```
CliParser::setHint(string hint);
```
