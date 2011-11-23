all:  blep_demo blep_demo_sync

blep_demo:	blep_table.h reciprocal_table.h blep_demo.c blep.c blep.h
	gcc -std=c99 -I. blep_demo.c blep.c -o blep_demo

blep_demo_sync:	blep_table.h reciprocal_table.h blep_demo_sync.c blep.c blep.h
	gcc -std=c99 -I. blep_demo_sync.c blep.c -o blep_demo_sync

blep_table.h: blep_table.py
	python blep_table.py > blep_table.h

reciprocal_table.h: reciprocal_table.py
	python reciprocal_table.py > reciprocal_table.h
