# Prog_labs
Laboratory works on the course "Programming"

# Техническое задание
Разработать иерархию классов, в которой класс СТРОКА является базовым, а классы СТРОКА-ИНДЕНТИФИКАТОР и ДЕСЯТИЧНАЯ_СТРОКА являются производными от него. \

# Базовый класс СТРОКА
Данные-члены класса:\
protected:\
char * pCh - указатель на массив символов\
int len – переменная, хранящая длину строки\
public:\
static int counter – кол-во вызовов конструктора копирования.\
Методы класса (public):\
Stroka() – конструктор по умолчанию.\
Stroka(char ch) – конструктор, принимающий в качестве параметра символ.\
Stroka(const char* s) – конструктор, принимающий в качестве параметра строку.\
Stroka(const Stroka& from) – конструктор копирования.\
~Stroka() – деструктор.\
GetStr() – функция, возвращающая Си-строку, содержимое pCh.\
GetLen() – функция, возвращает длину pCh.\
Show() – функция, выводит содержимое pCh.\
Clean() – функция, очищает строку pCh.

# Класс СТРОКА-ИДЕНТИФИКАТОР
Данные-члены класса:\
Наследованы у базового класса.\
static int counter – кол-во вызовов конструктора копирования.\
Методы класса:\
IdentStr(), IdentStr(char), IdentStr(const char*), IdentStr(const IdentStr&), ~IdentStr(),  – наследованы от базового класса.\
IdenStr(const char*) и IdentStr(char) проверяют pCh. Содержимым pCh могут быть только те символы, которые входят в состав символов-идентификаторов.\
void Find(char) – функция, находит первое вхождение символа в строку.\
IdentStr& operator = (const IdentStr&) - оператор присваивания.\
IdentStr& operator ~ () - оператор реверса строки pCh.\
IdentStr& operator < (const IdentStr&, const IdentStr&) – оператор меньше, сравнивает две строки по коду символов, сравнение ведется до конца меньшей строки. Если символы одинаковые, то меньшей является строка с меньшей длиной.\
IdentStr operator + (const IdentStr&, const IdentStr&) - оператор сложения, образует новую строку путем объединения содержимых двух строк-идентификаторов.\
IdentStr operator + (const IdentStr&, const char*) - оператор сложения, образует новую строку путем объединения содержимых строки-идентификатора и строки.\
IdentStr operator + (const char*, const IdentStr&)\
char&  operator [] (int) - оператор обращения по индексу, возвращает определенный элемент pCh.

# Класс ДЕСЯТИЧНАЯ СТРОКА
Данные-члены класса:\
Наследованы у базового класса.\
static int counter – кол-во вызовов конструктора копирования\
Методы класса:\
DecStr(), DecStr(const char*), DecStr(const DecStr&), ~DecStr(),  – наследованы от базового класса.\
DecStr(const char*) проверяет pCh на наличие недопустимых символов.\
DecStr& operator = (const DecStr&) - оператор присваивания.\
DecStr operator + (const DecStr&, const DecStr&) – оператор сложения.\
DecStr operator + (const DecStr&, int).\
DecStr operator - (const DecStr&, const DecStr&) – оператор вычитания.\
int operator > (const DecStr&, const DecStr&) – оператор проверки на больше.


