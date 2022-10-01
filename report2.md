---
# Front matter
title: "Отчёт по лабораторной работе №1"
subtitle: "Язык разметки Маrkdwon"
author: "Аба Альфонс НФИмд 02-22"

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

Научиться оформлять отчёты с помощью легковесного языка разметки Markdown.
Пример оформление отчёты о работе с git с помощью легковесного языка разметки Markdown.

# Теоретические сведения

## Системы контроля версий. Общие понятия

Системы контроля версий (Version Control System, VCS) применяются при работе нескольких человек над одним проектом. Обычно основное дерево проекта хранится в локальном
другими словами Система контроля версий (Version Control System, VCS) представляет собой программное обеспечение, которое позволяет отслеживать изменения в документах, при необходимости производить их откат, определять, кто и когда внес исправления и т.п. В статье рассмотрены виды VCS, принципы их работы, а также приведены примеры программных продуктов.

### Централизованные и распределенные системы контроля версий
1. Централизованные системы контроля версий : 
оно представляют собой приложения типа клиент-сервер, когда репозиторий проекта существует в единственном экземпляре и хранится на сервере. Доступ к нему осуществлялся через специальное клиентское приложение. В качестве примеров таких программных продуктов можно привести CVS, Subversion.

2. Распределенные системы контроля версий (Distributed Version Control System, DVCS) : 
оно позволяют хранить репозиторий (его копию) у каждого разработчика, работающего с данной системой. При этом можно выделить центральный репозиторий (условно), в который будут отправляться изменения из локальных и, с ним же эти локальные репозитории будут синхронизироваться. При работе с такой системой, пользователи периодически синхронизируют свои локальные репозитории с центральным и работают непосредственно со своей локальной копией. После внесения достаточного количества изменений в локальную копию они (изменения) отправляются на сервер. При этом сервер, чаще всего, выбирается условно, т.к. в большинстве DVCS нет такого понятия как “выделенный сервер с центральным репозиторием”. Две наиболее известные DVCS – это Git и Mercurial.

# Выполнение работы

Наша работа связанна с изучением классических VCS наиболее известны CVS напимер Git.
Система контроля версий Git представляет собой набор программ командной строки. Доступ к ним можно получить из терминала посредством ввода команды git с различными опциям. Благодаря тому, что Git является распределённой системой контроля версий, резервную
копию локального хранилища можно сделать простым копированием или архивацией.
следовательно выпольнили следующие пуктов :
- Создать базовую конфигурацию для работы с git.
- Создать ключ SSH.
- Создать ключ PGP.
- Настроить подписи git.
- Зарегистрироваться на Github.
- Создать локальный каталог для выполнения заданий по предмету.

## Последовательность выполнения работы
1. Создание базовых конфигурации для работы с git:
Я создал учетную запись на https://github.com. и после этого установил gh в Fedora Linux через команду "sudo dnf install gh".

![учётная запись](image/1.1.png){ #fig:001 width=70% height=70%}

![установка gh ](image/1.png){ #fig:002 width=70% height=70%}

С помошью команды  git config --global user.name "Name Surname" и git config --global user.email "work@mail", я выпонил базовую настроику чтобы задать имя и email владельца репозитория .

![имя и email владельца репозитория](image/2.png){ #fig:003 width=70% height=70%}

настроил utf-8 в выводе сообщений git а также настроил верификацию и подписание коммитов git

![настроика](image/2.png){ #fig:004 width=70% height=70%}

2. Создание ключи ssh и  ключи pgp
я создал по алгоритму rsa с ключём размером 4096 бит и также по алгоритму ed25519, и генерировал ключ с помощью команд "gpg --full-generate-key".

![генерация ключи ssh ](image/3.png){ #fig:005 width=70% height=70%}

![генерация ключи ssh ](image/4.png){ #fig:006 width=70% height=70%}

![генерация ключи PGP](image/5.png){ #fig:007 width=70% height=70%}

![генерация ключи PGP](image/6.png){ #fig:008 width=70% height=70%}

3. Добавление PGP ключа в GitHub
Выводил список ключей и копировал отпечаток приватного ключа через команд "gpg --list-secret-keys --keyid-format LONG" после этого я скопировал его в буфер обмена с помошью "gpg --armor --export"

![Дабавление PGP](image/7.png){ #fig:009 width=70% height=70%}

![Дабавление PGP](image/7_1.png){ #fig:010 width=70% height=70%}

![Дабавление PGP](image/8.png){ #fig:011 width=70% height=70%}

4. Шаблон для рабочего пространства
создал шаблон рабочего пространства "операционные системы" и также его репозитория.

Настроил каталог курса, перешел в каталог курса с помошью командой "cd ~/work/study/2021-2022/"Операционные системы"/os-intro" и так же удалил  лишние файлы. 

В конце отправал файл на север через 
"git add . 
git commit -am 'feat(main): make course structure'
git push
" 

# Выводы

Изучили оформлять отчёты с помощью легковесного языка разметки Markdown.

# Список литературы{.unnumbered}

1. [pandoc](https://pandoc.org/)
2. [pandoc-crossref](https://github.com/lierdakil/pandoc-crossref/releases)
