compile_all:
	gcc linked_list/*.c -o linked_list/ds.out
	gcc stack/*.c -o stack/ds.out
	gcc queue/*.c -o queue/ds.out

linked_list: linked_list/ds.out
	exec linked_list/ds.out

stack: stack/ds.out
	./stack/ds.out

queue: queue/ds.out
	./queue/ds.out
