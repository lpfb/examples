# Listing python installed packages
```sh
pip<version> freeze
```
Where:
- version: could be, for example, 2.7 or 3

# Uninstalling a python package
```sh
sudo pip<version> uninstall <package name>
```

# Using Cython

To compile a python code or even a Cython code with annotate enabled to visualize improvement points, you need to:
```sh
cython -a <python/code code>.py/pyx
```

Cython extension pyx

# Using Python debuger on terminal

To run the debuger you need to type on terminal:
```sh
python3 -m pdb <module name>.py arg1 ... argn
```

Main commands:
- Run : run python program until the end
- unt/until: Continue execution until the line with a number greater than the current one is reached. With a line number argument, continue execution until a line with a number greater or equal to that is reached.
    - unt/until: runs and stops on next line
    - unt/until <line number>: runs until <line number> and stops
- b :
    - b : list all active break points
    - b <line number>: insert a break point at <line number> of current file
    - b <file name>:<line number>: insert a break point at <line number> of the <file name>
- s/step : Execute the current line, stop at the first possible occasion (either in a function that is called or on the next line in the current function).
- n/next : Continue execution until the next line in the current function is reached or it returns.
- r/return : Continue execution until the current function returns.
- c/continue : Continue execution, only stop when a breakpoint is encountered.
- l/list :
    - l/list : List source code for the current file. Without arguments, list 11 lines around the current line or continue the previous listing. With . as argument, list 11 lines around the current line. With one argument, list 11 lines around at that line. With two arguments, list the given range; if the second argument is less than the first, it is interpreted as a count.
- l/longlist : list all source code of the current file
- a/args : Print the argument list of the current function
- alias: Create an alias called name that executes command. Can be used to print variables results, for example.
    Example:
        alias teste print("pd data: ", show_pd_data, "Tamanho: ", tamanho_amostra)
        Now, typing teste on pdb prompt will execute the above print and show variables show_pd_data and tamanho_amostra value
- q : exit from python debuguer
- Variable value:
    To see a current variable value, just type its name no pdb debuger and press enter
        
