# Lab 01: IDE Intro, Function Runtime Timing

Welcome to the first Data Structures lab of Spring 2020! The goal of this lab will be to set up a functional enviornment and familiarize yourself with the differences in runtime for various functions and provide a basis for the study of various concepts of study in 212. **Be sure to read and follow all instructions unless otherwise specified. Record your answers to the questions in a text document named lab-01.txt** You'll find the table of contents for this lab below.

1. Piazza Setup
2. Gradescope Setup
3. CS50 IDE
    - Setup 
    - Basics 
4. Runtime differences
    - Euler's number (e)
    - Fibonacci Problem 
5. Line Graphs

# Part 1. Piazza Setup 

[Piazza Support Center (students)](https://support.piazza.com/support/solutions/48000185443)

# Part 2. Gradescope Setup

[Gradescope Help (student workflow)](https://www.gradescope.com/help#help-center-section-student-workflow)

# Part 3. CS50 IDE

In this class you will need multiple tools in order to best succeed, including a bash terminal, a text editor with code highlighting, and a debugging interface. These tools, along with many others, are often packed together into what is called an**Integrated Development Environment**, or IDE. In particular we highly recommend using CS50 IDE for this class, since it is lightweight, fairly easy to use, and best supported by the TAs. Thus, we will discuss you two options for how to start using CS50 IDE.

> CS50 IDE is a containerized application that runs on Docker.  Further details on: [Docker containers](https://www.docker.com/resources/what-container).

## 3.1 IDE Options - Online vs Offline

You have two options for how you would like to install/use CS50 IDE, and you need choose only one. The first option is to use a free GitHub account to access the IDE from the internet, and the second is to install Docker to access it locally. Some pros and cons are as follows:

**CS50 IDE Online**

<table>
	<tr><td>+</td><td>Simple and easy setup</td></tr>
	<tr><td>+</td><td>Can be accessed from any computer</td></tr>
	<tr><td>+</td><td>Requires no installation on your system</td></tr>
	<tr><td>+</td><td>Has shown to work more reliably than the offline option</td></tr>
	<tr><td>-</td><td>Requires a (free) GitHub account</td></tr>
	<tr><td>-</td><td>Requires an active internet connection</td></tr>
</table>

**CS50 IDE Offline**

<table>
	<tr><td>+</td><td>Does not require signing up for any service</td></tr>
	<tr><td>+</td><td>Is usable offline</td></tr>
	<tr><td>+</td><td>Uses your own system's resources (better if you have a good computer and you want to write a more complex program)</td></tr>
	<tr><td>-</td><td>Slightly more complex setup</td></tr>
	<tr><td>-</td><td>Requires installation of Docker and (through Docker) the IDE</td></tr>
</table>

### 3.1.1 Online Option - Setup

>Note that the recommended browser for using the online option is [Google Chrome](https://www.google.com/chrome/)

The steps to set up the online version of CS50 IDE are as follows:

1. If you do not already have one, [create an account at github.com](https://www.github.com)
2. An activation email should be sent to the email address used to create your account. Activate your gitHub account using said activation email.
3. Go to [ide.cs50.io](https://ide.cs50.io/), and click "Sign in with GitHub".
4. Log in with you GitHub credentials.
4. Your CS50 IDE will begin to load. This might take a minute if it's your first time accessing CS50 IDE Online, so please be patient.

### 3.1.2 Offline Option - Setup

If you choose to install the offline option (not recommended during this lab session), you can follow the instructions for setup [here](https://cs50.readthedocs.io/ide/offline/#).

### 3.1.3 Other Options
While CS50 IDE is strongly encouraged for this course, some other IDE options are:

- [Visual Studio Code](https://code.visualstudio.com/)
- [CLion](https://www.jetbrains.com/clion/) (Free with student id)
- [QT C++](https://www.qt.io/developers/)

These IDEs may require more effort to learn and may seem less user-friendly at times, but they are much more professional and include many of the tools one may actually use in software production. While not necessary for this class, you may find it beneficial to yourself to spend some time learning one.

## 3.2 Getting Started
Now that your IDE is all set up, take some time and get to know it! Read through [this introduction](https://cs50.readthedocs.io/ide/online/) with your group! 

:white_check_mark: Question 1: Describe some major differences between using a local or online version of the IDE.

:white_check_mark: Question 2: Where are your files stored if using the online version vs the offline version?

:white_check_mark: Question 3: What are the PC and Mac hotkeys to create a new file?

# Part 4. Runtime differences 
The two mathematical equations that will be used in order to display the run time differences between more and less efficient implementations are finding Euler's number (e) and calculating fibonacci numbers. You will be required to record the times of the various versions of both mathematical equations with  https://chart-studio.plot.ly/create/#/ . This is a website that allows you to very easily plot graphs via the input of a CSV file (Comma Seperated Value). Creating this file will be explained later on. 

## 4.1 Eulers Number (e)

### What is Eulers number? 

Euler's number (e), is a mathematical constant that is the base of the natural logarithm. This number is apporoximately equal to 2.71828. This number comes from Leonhard Euler (1707 - 1783). He was a Swiss mathematician, physist, astronomer, geographer, logician, and engineer who made important and influential discoveries in many branches of mathematics. Another interesting fact on Euler is that he lost vision in his right eye early on in his carrer, he blamed it on his tendancy to overwork himself while working on cartography for Petersburg Academy. This didn't stop him because 25 years later, he lost vision in his other eye for the same reason. 

### Euler(e) calculation functions 

**Algorithm 1 for Euler's number**
```c++
long double euler1(int n) {
    long double sum = 0;
    long double fact;
    for (int i = 0 ; i <= n ; i ++) {
        fact = 1;
        for (int j = 2 ; j <= i ; j++) {
            fact *= j;
        }
        sum += (1.0 / fact);
    }

    return sum;
}
```

**Algorithm 2 for Euler's number**

```c++
long double euler2(int n) {
    long double sum = 0;
    long double fact = 1;

    for (int i = 0 ; i <= n ; i++) {
        sum += (1.0 / fact);
        fact *= (i+1);
    }

    return sum;
}
``` 

### Function for Timing

In order to be able to use the clock function you will **need to include ctime** in your program. This will allow for you to input the number you would like to calculate and the algorithm you would like to check. This code will not automatically create a file for you to submit to the plotting website. It is meant to allow you to compare the runtimes for a specific number between algorithms. 

```c++
void time_func(uint16_t n, const char *name) {

    uint64_t val;

    unsigned long c_start, c_end;

    if (! strcmp(name, "euler1")) {
        c_start = std::clock();
        val = euler1(n);
        c_end = std::clock();

    }
    else if (! strcmp(name, "euler2")) {
        c_start = std::clock();
        val = euler2(n);
        c_end = std::clock();

    }
    else{
        std::cout << "Invalid function call" << std::endl;

    }

    float output = 1.0 * (c_end - c_start) / CLOCKS_PER_SEC;
    std::cout << name << " euler(" << n << "):\t";
    std::cout << std::fixed << std::setprecision(4) << output << " Output: " << val << std::endl;
}
```

**Main Function**
```c++
int main(int argc, char**argv) {
    if (argc != 3) {
        std::cout << "Usage: ./euler <n> <alg>\n";
        std::cout << "\t<n>\tn-th term to be calculated\n";
        std::cout << "\t<alg>\talgorithm to be used (euler1 or euler2)\n";
        return 0;
        
    }

    uint16_t n = (uint16_t) atoi(argv[1]);
    time_func(n, argv[2]);
}

``` 
Put the above functions into your ide and answer the questions that follow:

:white_check_mark: Question 4. Play around with some small values of n. What is the first value of n that causes notably slower runtime for euler1?

:white_check_mark: Question 5. What is the first value of n that causes notably slower runtime for euler2?

### Euler Runtime up to X numbers
For this portion of the lab you **need to include the  cstring library**

As a disclaimer the functions euler1 and euler2 will not be changing for this section. However the time_func and main function will. The time_func will only differ slightly as you must change the return type to a float and then return the time output. 

The purpose of this section is to restructure the previous section's handout so that it prints several values and their runtimes to the terminal, in order to see how runtime costs increase.

For example if you enter ./euler 5 euler1, it will calculate and print euler(0) followed by euler(1) up to and including euler(5) and it will also calculate the time required to perform the calculation per value. 

**Function for Timing**
```c++
float time_func(uint16_t n, const char *name) {
    uint64_t val;
    unsigned long c_start, c_end;

    if (! strcmp(name, "euler1")) {
        c_start = std::clock();
        val = euler1(n);
        c_end = std::clock();

    }
    else if (! strcmp(name, "euler2")) {
        c_start = std::clock();
        val = euler2(n);
        c_end = std::clock();

    }
    else{
        std::cout << "Invalid function call" << std::endl;
        return 0;

    }
    
    float output = 1.0 * (c_end - c_start) / CLOCKS_PER_SEC;
    return output;
}

```

**Main Function**

```c++
int main(int argc, char**argv) {
    if (argc != 3) {
        std::cout << "Usage: ./euler <n> <alg>\n";
        std::cout << "\t<n>\tn-th term to be calculated\n";
        std::cout << "\t<alg>\talgorithm to be used (euler1 or euler2)\n";
        return 0;
    }

    uint16_t Max_Number = (uint16_t) atoi(argv[1]);
    
    for (int i = 0; i <= Max_Number; i++){

        float function_time = time_func(i, argv[2]);
        std::cout << argv[2] << "("<< i << ") Runtime took " << std::fixed << std::setprecision(4) << function_time << " Seconds\n";
        
    }

    return 0;
}
```

:white_check_mark: Question 6. Use the above code to compare the two euler functions. Which function is faster? Why is it faster than the other?

## 4.2 Fibonacci 

### What is Fibonacci? 

Fibonacci is a mathematical formula that is used to calculate a number by adding the previous two numbers in order to form the next number. Leonardo Pisano (1170 - 1250) was an italian mathematician who was most famous for his work with the Fibonacci Sequence. Unlike Leonhard Euler, he spent all his time as a mathematician, also unlike Euler, he maintained his vision.

### Fibonacci Runtime for specific numbers 

**Algorithm 1 for Fibonacci**

```c++
uint64_t fib_r(uint16_t n) {
    if (n < 2) {
        return n;

    } 
    else {
        return fib_r(n-1) + fib_r(n-2);

    }
}
```

**Algorithm 2 for Fibonacci**

```c++
uint64_t fib_i(uint16_t n) {

    uint64_t sum;
    uint64_t prev[] = {0, 1};

    if (n < 2) {
        return n;

    }

    for (uint16_t i = 2 ; i <= n ; i++ ) {
        sum = prev[0] + prev[1];
        prev[0] = prev[1];
        prev[1] = sum;

    }
    return sum;
}
``` 

:white_check_mark: Question 7. Which function do you expect to run faster? Why?

**Function for Timing**
In order to be able to use the clock function you will **need to include ctime** in your program. This will allow for you to input the number you would like to calculate and the algorithm you would like to check. This code will not automatically create a file for you to submit to the plotting website. It is meant to allow you to compare the runtimes for a specific number between algorithms. 

```c++
void time_func(uint16_t n, const char *name) {
    uint64_t val;
    unsigned long c_start, c_end;
    if (! strcmp(name, "fib_i")) {
        c_start = std::clock();
        val = fib_i(n);
        c_end = std::clock();

    }
    else if (! strcmp(name, "fib_r")) {
        c_start = std::clock();
        val = fib_r(n);
        c_end = std::clock();

    }
    else{
        std::cout << "Invalid function call" << std::endl;
        return;

    }
    
    float output = 1.0 * (c_end - c_start) / CLOCKS_PER_SEC;
    std::cout << name << " fib(" << n << "):\t";
    std::cout << std::fixed << std::setprecision(4) << output << " Output: " << val << std::endl;
}
```

**Main Function**
```c++
int main(int argc, char**argv) {
    if (argc != 3) {
        std::cout << "Usage: ./fib <n> <alg>\n";
        std::cout << "\t<n>\tn-th term to be calculated\n";
        std::cout << "\t<alg>\talgorithm to be used (fib_r or fib_i)\n";
        return 0;
        
    }

    uint16_t n = (uint16_t) atoi(argv[1]);
    time_func(n, argv[2]);
}

``` 

:white_check_mark: Question 8. Use the above code to compare the two fibonacci functions on similar inputs. Which function was faster? Why do you think it is faster than the other?

### Fibonacci Runtime up to X numbers 

For this portion of the lab you **need to include the fstream and cstring libraries** 

As a disclaimer the functions fib_i and fib_r will not be changing for this section. However the time_func and main function will. The time_func will only differ slightly as you must change the return type to a float and then return the time output. 

The purpose of this section is to restructure the code from the previous section to create a csv file that you will be able to input into the graphing website. This program will create a CSV file that contains the fibonacci number for every number up to your input. 

For example if you enter ./fib 5 fib_r, it will calculate fib(0),fib(1)..ect and it will also calculate the time per value. 

**Function for Timing**
```c++
float time_func(uint16_t n, const char *name) {
uint64_t val;
    unsigned long c_start, c_end;
    if (! strcmp(name, "fib_i")) {
        c_start = std::clock();
        val = fib_i(n);
        c_end = std::clock();

    }
    else if (! strcmp(name, "fib_r")) {
        c_start = std::clock();
        val = fib_r(n);
        c_end = std::clock();

    }
    else{
        std::cout << "Invalid function call" << std::endl;

    }

    float output = 1.0 * (c_end - c_start) / CLOCKS_PER_SEC;;
    return output;
}

```

**Main Function**

```c++
int main(int argc, char**argv) {
    if (argc != 3) {
        std::cout << "Usage: ./fib <n> <alg>\n";
        std::cout << "\t<n>\tn-th term to be calculated\n";
        std::cout << "\t<alg>\talgorithm to be used (fib_r or fib_i)\n";
        return 0;
    }

    uint16_t Max_Number = (uint16_t) atoi(argv[1]);
    std::ofstream myfile;
    
    myfile.open(std::to_string(Max_Number)+ "_" + (char *)argv[2]+".csv");

    myfile << "input" << "," << "time" << '\n';

    for (int i = 0; i <= Max_Number; i++){
        float function_time = time_func(i, argv[2]);
        myfile << i << "," << std::fixed << std::setprecision(4) << function_time<<'\n';
        
    }
    myfile.close();
    return 0;
}

```
 
 The code above can be used to generate a csv for upload to the plot.ly website.
 
 :white_check_mark: Modify the above code to work for the euler functions from the previous program. 

# Part 5. Line Graphs

Once you have the required csv files you will need to go to https://chart-studio.plot.ly/create/#/ . 

Once you're on this website you will click the import button that is located at the top right of the windows browser. You will then click upload and upload the csv file you would like to display. 

After this is complete you will click the trace button. Here you will be able to select what you want to display on your x and y axis. Display input for the x axis and time for the y axis. 

When you're uploading another csv to this website you will repeat the same steps above. 

The final deliverable for this lab will be an image of the graph you make to show the differences in runtime. This will require an account with plot.ly to save the image or alternatively you could use the snipping tool to take a screenshot of your plot.

# What to submit
You should submit your answer document `lab-01.txt` and an image of the plot your group was able to create to gradescope. Make sure to include all of your group members when you submit to gradescope.
