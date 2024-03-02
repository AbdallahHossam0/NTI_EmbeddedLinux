# Bash Script

## Scripts
usually scripts are used to automate the routines 

## There is many scripting language:
- CAPL (usually used with CANeo)
- Java script
- Make (to automate the compilation process)
- Bash
- Python 

> You can use C, C++, and other languages for automation, but they are compile-based languages that need recompilation after each edit, otherwise those interpreter-based languages are compiled while they are executed 


## Bash Script
to define a bash file, you need to write the shebang header on it
> #!/bin/bash 

or you will need to run it as python using the bash interpreter 
> bash MyBashScript

Note: adduser is a perl script that uses to automate the process of creating a new user, it on usr/sbin as it edits the system [system binary]


- Comments in bash start with #
- Assign the value directly:
> country=Egypt #No spaces **The naming convention is similar to C**
- to acess a variable value use $ before var name
> $country
- to read input from user 
> read -p "Enter your name" var
- command line args
> script -flag arg1 arg2 \
---$0----$1---$2----$3

- to print on the termainal 
> echo "message" or echo $var

- Conditional statements
    - if
```bash
if [[condition]]
then
    statements
elif [[conditions]]
then
    statements
else
    statements
fi

```


- switch case
```bash
case $var in 
fady)
statements
;; #break
oamr)
statements 
;; 
*) # default
statements
;;
esac
```

- Conditions
> [[ -e / -f / -a file ]] => to check the existance of a file \
[[ -r / -w / -x / -s / -g / -t file ]] to check read / write / execute / set user id / set group id / sticky bit \

- var conditions 
> if [[ "$var" == value ]] \
if [ "$var" -eq value ] you can use -eq -gt -ge -lt -le, -nlt means not less than and so on ...

- Arithmatic conditions 
> if(( 7 >= 5 ))

> if [ -z "$var" ] => checks if var == 0

- for and => -a in [], && in [[]], for or -o in [], || in [[]]


- while 

```bash 
while [ condition ]
do
statements
((i += 1))
i = $[$i + 1]
done
```

- for 

``` bash
for((i = 0; i <= 5; ++i))
do
statement
done
```
```bash
for var in range
----------------------------------
for var in {1..5}
do
statements
done
----------------------------------
for file in /etc/*
do 
    if [ "file" -eq /etc/passwd ]
    then 
        echo "file exists"
    fi
done
----------------------------------
if [ 10 -eq 10 ];then
echo "Equal"
fi
----------------------------------
if [ 'Geeks' == 'Geeks' ];
then
    echo "same" #output
else
    echo "not same"
fi
----------------------------------
```

## Examples

``` bash
if [ $a -gt 60 -a $b -lt 100 ]
-------------------------------------------
#!/bin/bash

echo "Please enter a number: "
read num

if [ $num -gt 0 ]; then
  echo "$num is positive"
elif [ $num -lt 0 ]; then
  echo "$num is negative"
else
  echo "$num is zero"
fi
-------------------------------------------
#!/bin/bash
i=1
while [[ $i -le 10 ]] ; do
   echo "$i"
  (( i += 1 ))
done
-------------------------------------------
#!/bin/bash

for i in {1..5}
do
    echo $i
done
-------------------------------------------
fruit="apple"

case $fruit in
    "apple")
        echo "This is a red fruit."
        ;;
    "banana")
        echo "This is a yellow fruit."
        ;;
    "orange")
        echo "This is an orange fruit."
        ;;
    *)
        echo "Unknown fruit."
        ;;
esac
-------------------------------------------
#!/bin/bash

# A hello world bash function
hello_world () {
  echo "Hello World!"
}

# Invoking the hello_world function
hello_world
-------------------------------------------
#!/bin/bash
greet () {
  echo "Hello $1 $2"
}

greet "John" "Doe" 
-------------------------------------------
#!/bin/bash

read -p "Give me a number: " number
if [ $number -gt 10 ];
then
  echo "Your number is greater than 10."
fi
-------------------------------------------
#!/bin/bash         
Age=17
if [ "$Age" -ge 18 ]; then
    echo "You can vote"
else
    echo "You cannot vote"    
fi
-------------------------------------------
Name="SATYAJIT GHOSH"
Age=20

echo "The name is $Name and Age is $Age"
-------------------------------------------
#!/bin/bash

var1="Apple" #global variable
myfun(){
    local var2="Banana" #local variable
    var3="Cherry" #global variable
    echo "The name of first fruit is $var1"
    echo "The name of second fruit is $var2"
}
myfun #calling function

echo "The name of first fruit is $var1"
#trying to access local variable
echo "The name of second fruit is $var2"
echo "The name of third fruit is $var3"
-------------------------------------------
echo "Enter filename"
read filename

if [ -e $filename ]
then
echo "$filename is exits on the directory"
cat $filename
else
    cat > $filename
    echo "File created"
fi
-------------------------------------------
#!/bin/bash
#It is a function
myFunction () {
echo Hello World from GeeksforGeeks
}

#function call
myFunction 
-------------------------------------------
-------------------------------------------
-------------------------------------------
```

