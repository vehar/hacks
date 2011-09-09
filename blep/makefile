blep_demo:	blep_table.h blep_demo.c blep.c blep.h
	gcc -std=c99 -I. blep_demo.c blep.c -o blep_demo

blep_table.h: blep_table.py
	python blep_table.py > blep_table.h
