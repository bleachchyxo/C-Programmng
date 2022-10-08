-C Language notes-

* Standard script body:
-------------------------------------------------
    #include <stdio.h>

    int main(){

            printf("Hello World!\n");
            return 0;

    }
-------------------------------------------------

"\n" = new line
"\t" = tab


* Strings
-------------------------------------------------
    #include <stdio.h>

    int main(){

           printf("%s World!\n", "Hello");
           return 0;

    }
-------------------------------------------------

The "%s" works as a place holder that will be filled by the "Hello" before the ",". So the output must be "Hello World!".
You can use as many placeholders as you want:

-------------------------------------------------
    printf("%s %s", "Hello", "World");
-------------------------------------------------

Output:

    Hello World

* Digits

In order to print digits we must add "%d" that stands for digit:
-------------------------------------------------
        #include <stdio.h>

       int main(){

               printf("%s ate %d hotdogs", "Chuxo", 9);
               return 0;
                
       }
-------------------------------------------------

Notice how the nine isn't between "quotation marks", this is because just strings are put into them.

* Float Numbers

We can do the same with floating numbers by adding "%f", this means decimal numbers and by adding an extra number after the "f" means
how many decimals you want to appear:

-------------------------------------------------

    printf("%f", 3.141516); = 3.141516

    printf("%2f", 3.141516); =
