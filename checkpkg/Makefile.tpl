all:
	@rm -f lcheck
	@make lcheck	
	@./libcheck
	@./appcheck

lcheck:	lcheck.c
	@echo Compiling WFDB library test application ...
	@$(CC) $(CFLAGS) lcheck.c -o $@ $(LDFLAGS) && echo " Succeeded"

clean:
	rm -f *~ lcheck