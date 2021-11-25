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
- spelling = modern
- babelshorthands = true
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
  - \binoppenalty=600 # the penalty for breaking a line at a binary operator
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

Развить навыки администрирования ОС Linux. Получить первое практическое знакомство с технологией SELinux.
Проверить работу SELinx на практике совместно с веб-сервером
Apache.


# Выполнение лабораторной работы

1. Подготовка лабораторного стенда и методические
рекомендации


* Проверка статус рабочий сервер SELinux удается работать :

 определим с помошью sesatus и gentaforce проверим она работает в режиме inforcing :

  ![Рисунок 1](Images/lab6-1.png){ #fig:001 width=60% }

 Мы увидели что она не в режиме еnforcing а permissive так что мы сможем настройк его с помощью  : SELINUX=enforcing

  ![Рисунок 2](Images/lab6-2.png){ #fig:001 width=60% }

2. Вход в систему с полученными учётными данными :

 проверим если все работает хорошо в нужне режиме с помощью команд getenforce и sestatus.

 Найдим веб-сервер Apache в списке процессов, определим его контекст безопасности:
 для этого используем ps auxZ | grep httpd или ps auxZ | grep httpd 

  ![Рисунок 3](Images/lab6-3.png){ #fig:002 width=60% } 

мы убедились что все  работает как укажанно.

3. Посмотрим текущее состояние переключателей SELinux для Apache с помощью команды sestatus    -bigrep httpd.
  а так посмотрим все статистику по политике с помощью команды seinfo.

  ![Рисунок 4](Images/lab6-4.png){ #fig:003 width=60% } 

4. Определим тип файлов и поддиректорий, находящихся в директории :
  для этого используем ls -lZ /var/www :

  ![Рисунок 5](Images/lab6-5.png){ #fig:004 width=60% } 

   так как у нас нет такые поддиректории,мы нечего не нашли и нам необходимо его создать и повторить еще раз.

  ![Рисунок 6](Images/lab6-6.png){ #fig:005 width=60% }.

  на этот раз нам удалось и мы так же определили тип файлов, находящихся в директории: /var/www/html.

5. Создание программу от имени суперпользователя 

   и в нем пишем этот код как на ресупке.

  ![Рисунок 7](Images/lab6-7.png){ #fig:0005 width=60% }.

6. Проверка контекста созданного вами файла :

  записанно в файле слово «test» 

  ![Рисунок 8](Images/lab6-8.png){ #fig:006 width=60% }.

После этого Обратимся к файлу через веб-сервер, введя в браузере адрес :

  ![Рисунок 9](Images/lab6-9.png){ #fig:007 width=60% }. 

7. Проверим контекст файла можно командой ls -Z:

  ls -Z /var/www/html/test.html

  ![Рисунок 10](Images/lab6-10.png){ #fig:008 width=60% } 

  мы получили первую часть контекста.

8. Изменение контекста файла /var/www/html/test.html с httpd_sys_content_t 

  с помошью командой chcon -t samba_share_t /var/www/html/test.html
  и проверим этого с помошью ls -Z /var/www/html/test.html

  ![Рисунок 11](Images/lab6-11.png){ #fig:010 width=60% } 

9. Анализ ситуацию :

 для этого используем tail /var/log/messages
  
  ![Рисунок 11](Images/lab6-11.png){ #fig:011 width=60% }.

  ![Рисунок 12](Images/lab6-12.png){ #fig:012 width=60% }.

  ![Рисунок 13](Images/lab6-13.png){ #fig:0013 width=60% }

10. Запускаем веб-сервер Apache на прослушивание ТСР-порта 81 (а не 80, как рекомендует IANA и прописано в /etc/services)..

  ![Рисунок 14](Images/lab6-15.png){ #fig:013 width=60% }

  перезапуск веб-сервера Apache прозошел собой потому что если apache не было установлен из репозиториев

11. Проанализируйте лог-файлы: 

  для этого используем tail -nl /var/log/messages и в конце вернулся контекст 
  httpd_sys_cоntent__t к файлу /var/www/html/ test.html:

  ![Рисунок 16](Images/lab6-16.png){ #fig:014 width=60% }

12. Удаляем файл /var/www/html/test.html: 

  rm /var/www/html/test.html

  ![Рисунок 17](Images/lab6-17.png){ #fig:015 width=60% }

# Выводы

В ходе выяполнения работы я получил первое практическое знакомство с технологией SELinux1.
Преобрел работу SELinx на практике совместно с веб-сервером Apache.
и намного рашерил мой рабочий способ дискреционного разграничения доступа в современных системах с открытым кодом на базе OC Linux.

# Список литературы
1. https://github.com/lierdakil/pandoc-crossref/releases
2. https://yandex.ru/search/?clid=2285101&text=centos+%C3%B9nj+xnj&lr=213 
3. https://github.com/yamadharma/academic-laboratory-report-template 
4. https://www.virtualbox.org/