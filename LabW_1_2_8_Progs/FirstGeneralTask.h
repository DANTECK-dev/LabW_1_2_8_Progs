﻿#pragma once

/*	
		Создать класс списка IntSetMassive. В данном классе будет храниться список целых чисел
	(однонаправленный список), а также будут определены некоторые операции присущие
	множествам.
		Определить в классе конструкторы (к примеру, инициализация массивом, но оставляет
	только неповторяющиеся элементы), деструктор, необходимые поля. К примеру, в нем должен
	быть указатель на первый элемент, а также количество элементов массива. В данном массиве
	должны быть только неповторяющиеся элементы, так как он имитирует множество.
		Дополнительно перегрузить следующие операции:
		 «+» – добавить число во множество (типа object + item, где item – целое число), добавляет
		только если такого элемента еще нет во множестве;
		 «+» – объединение множеств (типа object1 + object2), возвращает копию множества,
		которое является объединением двух множеств-операндов;
		 «-» – удалить число из множества (типа object - item, где item – целое число)
		 «-» – пересечение множеств (типа object1 - object2);
		 «[]» – возвращает элемент по номеру;
		 int () – приведение к целому, возвращает мощность множества (размер массива).
		Написать программу тестирования, в которой проверяется использование всех
	перегруженных операций.
*/

void firstGeneralTask();