all: driver

# can not compile separately
driver: driver.cc dynQueue.cc dynQueue.h
	g++ driver.cc -o driver

clean:
	rm *.o
	rm driver
