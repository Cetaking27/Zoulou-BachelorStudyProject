---
## Front matter
lang: ru-RU
title: Structural approach to the deep learning method
author: |Аба Альфонс НПМ-02-18
	Leonid A. Sevastianov\inst{1,3}
	\and
	Anton L. Sevastianov\inst{1}
	\and
	Edik A. Ayrjan\inst{2}
	\and
	Anna V. Korolkova\inst{1}
	\and
	Dmitry S. Kulyabov\inst{1,2}
	\and
	Imrikh Pokorny\inst{4}
institute: |
	\inst{1}RUDN University, Moscow, Russian Federation
	\and
	\inst{2}LIT JINR, Dubna, Russian Federation
	\and
	\inst{3}BLTP JINR, Dubna, Russian Federation
	\and
	\inst{4}Technical University of Košice, Košice, Slovakia
date: NEC--2019, 30 September -- 4 October, 2019 Budva, Montenegro

## Formatting
toc: false
slide_level: 2
theme: metropolis
header-includes: 
 - \metroset{progressbar=frametitle,sectionpage=progressbar,numbering=fraction}
 - '\makeatletter'
 - '\beamer@ignorenonframefalse'
 - '\makeatother'
aspectratio: 43
section-titles: true
---


# Цели и задачи работы

## Цель лабораторной работы

Изучение механизмов изменения идентификаторов, применения
SetUID- и Sticky-битов. Получение практических навыков работы в консоли с дополнительными атрибутами. Рассмотрение работы механизма
смены идентификатора процессов пользователей, а также влияние бита
Sticky на запись и удаление файлов.1
.
# Процесс выполнения лабораторной работы

## Подготовка лабораторного стенда :

![Информация о установка gcc с помошбю yum install gcc и gcc -v для проверки](Images/lab5-2.png){ #fig:001 width=70% }

## Компилирование программ:

![комманды для компиляторы](Images/lab5-3.png){ #fig:002 width=70% }

##  Создание программы :
##  Создание 1 программу simpleid.c:

![вход в систему и создание программу simpleid.c](Images/lab5-5.png){ #fig:003 width=70% }

![компилировка программу simpleid.c](Images/lab5-6.png){ #fig:004 width=70% }

##  Создание 2 программу simpleid2.c:

![создание программу simpleid2.c ](Images/lab5-9.png){ #fig:005 width=70% }

![компилировка программу simpleid2.c ](Images/lab5-10.png){ #fig:006 width=70% }

##  Создание 3 программу readfile.c:

![создание программу readfile.c](Images/lab5-16.png){ #fig:007 width=70% }

![компилировка программу readfile.c](Images/lab5-17.png){ #fig:008 width=70% }

## Исследование Sticky-бита

![Снятие расширенный атрибутов с директории](Images/lab5-22.png){ #fig:009 width=70% }

## Права и разрешённые действия

![Максимальные права для совершения операций](Images/lab5-27.png){ #fig:010 width=70% }

# Выводы по проделанной работе

## Вывод

В ходе выполнения лабораторной работы были получены навыки работы с установлением gcc и работа над нем а также  атрибутами файлов и сведения о разграничении доступа сзвянно с SetGID-бита и Sticky-бита .

## {.standout}

Wer's nicht glaubt, bezahlt einen Taler
