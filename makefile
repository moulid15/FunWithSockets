pro: problem1.c
	gcc problem1.c -o pro -lbluetooth
pro2: pro2.c
	gcc pro2.c -o pro2 -lbluetooth
server: server.c
	gcc server.c -o server -lbluetooth
