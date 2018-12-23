
all:
	 gcc -lncurses -O3 -Wall *.c -o davedit  
        
clean:
	   rm -rf davedit core *.o tags



