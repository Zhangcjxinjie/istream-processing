#include <iostream>
#include <fstream>
#include <string>
using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::ifstream;
using std::string;
using std::getline;

/*
 * Before running the program take a look at the following two pages:
 * --> getline:    http://cplusplus.com/reference/string/string/getline/
 * --> operator>>: http://cplusplus.com/reference/string/string/operator%3E%3E/
 * 1. When does the getline function stop reading from the input stream?
 *  the getline() will read the whole line which means it is stop at "\n"
 * 2. When does the operator>> stop reading from the input stream?
 *  the >> will read a word which means it will stop at a space" ".
 */

int main() {
    /*
     * When you run the program,
     * try the following names:
     * not-here.txt
     * --> The program should respond:
     *     Unable to open not-here.txt
     * --> 3. Any idea why the output is shown in a different color?
     *because we use cerr to print the code so it is in the different color.
     * data.txt
     * 4. Was it able to open it? Any idea why?
     *no we can not open it . because the data.txt do not have a path to open it .
     * the program do not know where to find the file.
     * ../data.txt
     * This time the program must've been able to open the file
     * 5. Why do you think that is? A hint: where is the program running from?
     * because the program is running in the same file so we can open the ../data.txt.
     * the the ../ is the path of the file .
     */

    string filename;
    cout << "Please input file name: ";
    cin >> filename;

    ifstream input;
    string string1, string2;

    input.open(filename);
    if (input.fail()){
        cerr << "Unable to open " << filename << endl;
        return 1;
    }
    /*
     * Notice in this part of the program that we are reading from the file
     * first by using the stream extraction operator >>
     * and then using the function getline
     * Notice the output.
     * input << string1;   getline(input, string2);
     * string1 = An
     * string2 =

     * 6. Why do you think the output looks like that?
     *because the << will read the first word which is "An" but there is an "/n" left in the first line
     * the getline will read the first line but there is only an "/n" so the getline do not read anything.
     */
    input >> string1;
    getline(input, string2);
    cout << "input << string1;   getline(input, string2);" << endl;
    cout << "string1 = " << string1 << endl;
    cout << "string2 = " << string2 << endl;

    input.close(); // to reset
    input.open(filename);
    // Just in case
    if (input.fail()){
        cerr << "Unable to open " << filename << endl;
        return 1;
    }
    /*
     * Now the program is reading from the file but this time
     * first by using getline and then by using the stream operator >>
     * Is it different from the output you saw from the previous code?
     * 7. Why is that?
     * the getline read the firstline so it read "An/n"and store the An in string1.
     * then the >> will read the next word which is "Amazing".
     */
    getline(input, string1);
    input >> string2;
    cout << "getline(input, string2);   input << string1;" << endl;
    cout << "string1 = " << string1 << endl;
    cout << "string2 = " << string2 << endl;

    input.close();

    return 0;
}
