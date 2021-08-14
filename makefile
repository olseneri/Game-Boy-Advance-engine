basic:
	arm-none-eabi-g++ -std=c++20 crt0.s example.cpp abstract_register_manipulation.cpp -mcpu=arm7tdmi -nostartfiles -T lnkscript -o $@ #compile the binary

all: basic
	arm-none-eabi-objcopy -O binary $^ $@	#strip the binary
	./ht.pl -clo $@.gba $@	#format the binary
	rm -f $^ $ 
	rm -f $@

clean:
	rm -rf $^ $^.gba $@.sav