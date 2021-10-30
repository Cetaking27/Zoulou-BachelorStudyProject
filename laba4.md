---
# Front matter
title: "Отчёт по лабораторной работе 4"
author: "Аба Альфонс НПМ-02-18"

# Generic otions
lang: ru-RU
toc-title: "Содержание"

# Bibliography
bibliography: bib/cite.bib
csl: pandoc/csl/gost-r-7-0-5-2008-numeric.csl

# Pdf output format
toc: true # Table of contents
toc_depth: 2
lof: true # List of figures
lot: true # List of tables
fontsize: 12pt
linestretch: 1.5
papersize: a4
documentclass: scrreprt
## I18n
polyglossia-lang:
  name: russian
  options:
	- spelling=modern
	- babelshorthands=true
polyglossia-otherlangs:
  name: english
### Fonts
mainfont: PT Serif
romanfont: PT Serif
sansfont: PT Sans
monofont: PT Mono
mainfontoptions: Ligatures=TeX
romanfontoptions: Ligatures=TeX
sansfontoptions: Ligatures=TeX,Scale=MatchLowercase
monofontoptions: Scale=MatchLowercase,Scale=0.9
## Biblatex
biblatex: true
biblio-style: "gost-numeric"
biblatexoptions:
  - parentracker=true
  - backend=biber
  - hyperref=auto
  - language=auto
  - autolang=other*
  - citestyle=gost-numeric
## Misc options
indent: true
header-includes:
  - \linepenalty=10 # the penalty added to the badness of each line within a paragraph (no associated penalty node) Increasing the value makes tex try to have fewer lines in the paragraph.
  - \interlinepenalty=0 # value of the penalty (node) added after each line of a paragraph.
  - \hyphenpenalty=50 # the penalty for line breaking at an automatically inserted hyphen
  - \exhyphenpenalty=50 # the penalty for line breaking at an explicit hyphen
  - \binoppenalty=700 # the penalty for breaking a line at a binary operator
  - \relpenalty=500 # the penalty for breaking a line at a relation
  - \clubpenalty=150 # extra penalty for breaking after first line of a paragraph
  - \widowpenalty=150 # extra penalty for breaking before last line of a paragraph
  - \displaywidowpenalty=50 # extra penalty for breaking before last line before a display math
  - \brokenpenalty=100 # extra penalty for page breaking after a hyphenated line
  - \predisplaypenalty=10000 # penalty for breaking before a display
  - \postdisplaypenalty=0 # penalty for breaking after a display
  - \floatingpenalty = 20000 # penalty for splitting an insertion (can only be split footnote in standard LaTeX)
  - \raggedbottom # or \flushbottom
  - \usepackage{float} # keep figures where there are in the text
  - \floatplacement{figure}{H} # keep figures where there are in the text
---

# Цель работы

Получение практических навыков работы в консоли с расширенным атрибутами файлов.


# Выполнение лабораторной работы

1. В установленной при выполнении предыдущей лабораторной работы
операционной системе определим расширеные атрибуты:

* su root - переход в уч. запись

 определим расширенные атрибуты файла через командой lsattr /home/guest/dir1/file1 :

[Рисунок 1](Images/lab4-1.png){ #fig:001 width=70% }

2. Установите командой :

chmod 600 file1 - [Рисунок 2](Images/lab4-3.png){ #fig:001 width=70% } мы получили отказ от чтение и запись для владельца файла.

3. Установим на файл расширенный атрибут a :
 
для этого используем chattr +a /home/guest/dir1/file1 [Рисунок 3](Images/lab4-4.png){ #fig:002 width=70% } мы на это тоже получили отказ.

4. вход уч. запись через su  :

Попробуем еще установить расширенный атрибут a на файл с помошью chattr +a /home/guest/dir1/file1 - [Рисунок 4](Images/lab4-5.png){ #fig:003 width=70% } на этот раз нам удалось установить от имени суперпользователя.

5. проверяем правильность установления атрибута:

для этого используем lsattr /home/guest/dir1/file1 - [Рисунок 5](Images/lab4-6.png){ #fig:004 width=70% }.

6. Выполняем дозапись в файл :

запишем в файле слово «test» с помошью echo "test" /home/guest/dir1/file1 - [Рисунок 6](Images/lab4-7.png){ #fig:001 width=70% }.

После этого выполняем чтение файла file1 командой с помошью :

 с помошью  cat /home/guest/dir1/file1 - [Рисунок 7](Images/lab4-8.png){ #fig:005 width=70% }. 

7. Попробуем удалить файл file1  :

echo "abcd" > /home/guest/dirl/file1 - [Рисунок 8](Images/lab4-9.png){ #fig:006 width=70% } на это мы получили отказ.

  Попробуем переименовать файл.

echo "abcd" > /home/guest/dirl/file1 - [Рисунок 9](Images/lab4-9.png){ #fig:007 width=70% } на это тоже самое мы получили отказ. 

8. Попробуем установить на файл file1 права:

с помошью командой chmod 000 file1 - [Рисунок 10](Images/lab4-10.png){ #fig:008 width=70% } на это тоже самое мы получили отказ. 

9. Снимаем расширенный атрибут a с файла от суперпользователя

 для этого используем chattr -a /home/guest/dir1/file1 - [Рисунок 11](Images/lab4-11.png){ #fig:009 width=70% }.

 Повторяем операции, которые нам ранее не удавалось выполнить и все проходит успешно - [Рисунок 12](Images/lab4-12.png){ #fig:01 width=70% }.

10. Повторяем ваши действия по шагам, заменив атрибут «a» атрибутом «i».

мы заметили что при снижении рсширешнный все действии которые мы не смогли выпольнить мы сможем без не какого трудность выпольнить - [Рисунок 13](Images/lab4-13.png){ #fig:011 width=70% }

# Выводы

В ходе выяполнения работы я преобрел практические навыки работы в консоли сс расширенными атрибутами файлов, закрепл теоретические основы дискреционного разграничения доступа в современных системах с открытым кодом на базе OC Linux.
