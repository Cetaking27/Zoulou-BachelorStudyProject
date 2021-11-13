---
# Front matter
title: "Отчёт по лабораторной работе 3"
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

Получение практических навыков работы в консоли с атрибутами файлов, закрепление теоретических основ дискреционного разграничения доступа в современных системах с открытым кодом на базе OC Linux.


# Выполнение лабораторной работы

1. В установленной при выполнении предыдущей лабораторной работы
операционной системе создаём учётную запись пользователя guest (используем учётную запись администратора):

* su root - переход в уч. запись
* useradd guest - создание записи

 создадим учётную запись пользователей guest:

[Рисунок 1](Images/1.png){ #fig:001 width=70% }

2. Зададим пароль для пользователя guest:

passwd guest - [Рисунок 2](Images/2.png){ #fig:001 width=70% }

3. Создадим аналогично второго пользователей guest2:
 
[Рисунок 3](Images/3.png){ #fig:001 width=70% }.

4. Добавляем пользователя guest2 в группу guest :

gpasswd -a guest2 guest - [Рисунок 4](Images/4.png){ #fig:001 width=70% }.

5. Ocуществляем вход в систему от двух пользователей на двух разных консолях:

guest на первой консол и guest2 на второй - [Рисунок 5](Images/5.png){ #fig:001 width=70% }.


6. Определим директорию для обоих ползольвателей:

pwd - [Рисунок 6](Images/6.png){ #fig:001 width=70% }. директория ялвляется одной и тоже самой с приглашениям командной строки.

7. Уточним и Определим имя нашего пользователя, его группу, кто входят в нее и каким группам принадлежит он:

whoami - [Рисунок 7](Images/7.png){ #fig:001 width=70% }. Uid и gid те же, что и при применении команды id.

    Определим в какие группу входят польователи guest b guest 2 :

groups guest и groups guest2 -  [Рисунок 8](Images/8.png){ #fig:001 width=70% } 

[Рисунок 8-1](Images/8-1.png){ #fig:001 width=70% }. Uid и gid те же, что и при применении команды id

8. Сравним информацию с содержимым файла :

cat /etc/group - [Рисунок 9](Images/9.png){ #fig:001 width=70% }
ls -l /home/ - [Рисунок 10](Images/10.png){ #fig:001 width=70% }. Список поддиректорий получить удалось.

9. Выпольняем  регистрацию пользователя guest от имени guest2 в группе guest:

newgrp guest - [Рисунок 11](Images/11.png){ #fig:001 width=70% }

10. Изменим права директории от имени пользователи guest2:

/home/guest - [Рисунок 12](Images/12.png){ #fig:001 width=70% }.

    Разрешаем все действия для пользователей группы 
 
chmod g+rwx /home/guest - [Рисунок 12](Images/12.png){ #fig:001 width=70% }

11. Создадим в домашней директории поддиректорию dir1 командой2 b в нем создадим file1
mkdir dir1 - [Рисунок 13](Images/13.png){ #fig:001 width=70% }.

    Определим командами ls -l и lsattr, какие права доступа и расширенные атрибуты были выставлены на директорию dir1

[Рисунок 14](Images/14.png){ #fig:001 width=70% }.

    Cнимаем с директории /// все атрибуты :

chmod 000 dir1 - [Рисунок 15](Images/15.png){ #fig:001 width=70% }

12. Снимем с директории dir1 все атрибуты командой

chmod 000 dir1 - [Рисунок 16](Images/16.png){ #fig:001 width=70% }.

Проверим с её помощью правильность выполнения команды ls -l - [Рисунок 17](Images/17.png){ #fig:001 width=70% }.

13. Попытаемся создать в директории dir1 файл file1 командой

echo "test" > /home/guest/dir1/file1 - [Рисунок 18](Images/18.png){ #fig:001 width=70% }.

Мы получили допуск в выполнении операции по созданию файла, так как с директории dir1 были сняты все атрибуты.

Оценим, как сообщение об ошибке не отразилось на создании файла командой

14. Проверяем от пользователи guest2

ls -l /home/guest/dir1 - [Рисунок 19](Images/19.png){ #fig:001 width=70% }. Файл не находится в директории dir1.

14. Заполняем таблицу 3.1:

[Рисунок 1-1](Images/1-1.png){ #fig:001 width=70% }, [Рисунок 1-2](Images/1-2.png){ #fig:001 width=70% }, [Рисунок 1-3](Images/1-3.png){ #fig:001 width=70% }, [Рисунок 1-4](Images/1-4.png){ #fig:001 width=70% },[Рисунок 22](Images/22.pn#fig:001 width=70% }.

15. Сравнение таблицу 2.1 и 3.1

[Рисунок 2-1](Images/24.png){ #fig:001 width=70% }.

# Выводы

В ходе выяполнения работы я преобрел практические навыки работы в консоли с атрибутами файлов для групп пользователей, закрепл 
теоретические основы дискреционного разграничения доступа в современных системах с открытым кодом на базе OC Linux.
