## Важно  
> Makefile не должно быть пробелов в вызове команды, только Tab
## [Инфа](http://khpi-iip.mipk.kharkiv.edu/library/extent/os/ruprog/p10.html)

## [Инфа2](https://habr.com/ru/post/111691/)

### сдать новый файл
> Создать и записать в содранный файл число строк из первого

``` Makefile
all:	faleNew.txt

report.txt: fale1.txt
	wc -l fale1.txt > faleNew.txt

```
Пример сборки двух файлов и создание бинарных файлов.   
``` Makefile
all:	work # цель проекта

work:	main.o fraction.o
	g++ main.o fraction.o  -o work

main.o:	main.cpp
	g++ -c main.cpp

fraction.o: fraction.cpp
	g++ -c fraction.cpp

clean:
	rm -rf *.o work
```
Сборка без создания бананников и использование переменных
объявление переменной CC=g++, вызов $(CC) - где СС переменная, а $()- форма вызова .
Где:    
> -o <файл>                Записать результат в <файл>.
> -c                       Компиляция и сборка, но без компоновки.

При выполнении этой команды вместо $< будет подставлено имя .c-файла, а вместо $@ – имя соответствующего .o-файла.

ункция $(patsubst A, B, C) ищет в C шаблон A и заменяет его на B.


### Запуск gdb
- make debug
- в Makefale  прописать где - gdb.config файл конфигурации
gdb

```
run           # Запускаем программу
bt            # Печатаем данные о текущем положении (в какой строке ошибка)
quit          # Выходим
```

``` Makefile
debug: work
	gdb -x gdb.config work
```


### примеры не удалось запустить чтобы создавало .o в другом каталоге
```Makefile
# Это комментарий, который говорит, что переменная CC указывает компилятор, используемый для сборки
CC=g++
#Это еще один комментарий. Он поясняет, что в переменной CFLAGS лежат флаги, которые передаются компилятору
CFLAGS=-c -Wall
all:	work

work: main.o fraction.o
	$(CC) main.o fraction.o  -o work

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

factorial.o: fraction.cpp
	$(CC) $(CFLAGS) fraction.cpp

clean:
	rm -rf *.o work

```
$@ Имя цели обрабатываемого правила   
> OBJECTS=$(SOURCES:.cpp=.o) - сделать с файлами .о
> OBJECTS=$(SOURCES) - сделать с файлами без .о

``` Makefile
CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.cpp  fraction.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=work

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
```

## Запуск Emacs в новом окне   
- команда mintty emacs
~~~ Makefile
SRC := main.cpp overload.cpp overload.h
....
cod:  $(SRC)
	mintty emacs $(SRC)
~~~
