C = arm-linux-gnueabihf-gcc

all:
	$C -I ./inc src/*.c -o teste.bin -lpthread
	scp teste.bin root@192.168.7.2:	

clean:
	rm -rf teste.bin