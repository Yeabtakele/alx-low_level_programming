## 0x18. C - Dynamic libraries
libdynamic.so
A dynamic library file containing all the functions listed in the header file main.h

1-create_dynamic_lib.sh
A shell script that creates a dynamic library called liball.so from all the .c files in the current directory.

100-operations.so
A dynamic lirary that contains C functions that can be called from Python.

101-make_me_win.sh
A shell script that creates a dynamic library to be used to alter the jackpot program.

	Here is some of te documentation:
	``` /* Giga Millions program                                                                                    
	* Players may pick six numbers from two separate pools of numbers:                                                
	* - five different numbers from 1 to 75 and                                                                       
	* - one number from 1 to 15                                                                                       
	* You win the jackpot by matching all six winning numbers in a drawing.                                           
	* Your chances to win the jackpot is 1 in 258,890,850                                                             
	*                                                                                                                 
	* usage: ./gm n1 n2 n3 n4 n5 bonus ```

