# Overview

> This repository contains a program designed to find the next larger number
using the same digits as the given input number. The program is particularly
tailored for long long integers.


## Features

> Input : Accepts long long integers as input.

> Digit Rearrangement: Reorganizes the digits to form the next larger number.

> Efficiency: Optimized to handle large numbers efficiently.

## How to Use
Prerequisites:

> Ensure you have a C++ compiler installed on your system.

## Running the Program

Execute the compiled program with the input number:

`/Bigger-Number-with-the-dame-digits <input_number>`

## For example:
### INPUT
```1234```
### OUTPUT
```2134```
## Algorithm

> Identify the Pivot: Traverse the number from right to left to find the first digit that is smaller than the digit next to it.

> Find the Successor: From the right end, find the smallest digit larger than the pivot and swap them.

> Sort the Suffix: Reverse the digits to the right of the pivot to get the smallest possible sequence.

## CodeWars task example: [codewars](https://www.codewars.com/kata/55983863da40caa2c900004e)


## License
`This project is licensed under the MIT License. See the LICENSE file for details.`
## Contributions
`Contributions are welcome! If you have suggestions for improvements or find any bugs, please open an issue or submit a pull request.`

### Thank you for using this program! I hope it helps you find the next larger number with ease.



![image](https://github.com/Faysi505/Bigger-Number-with-the-dame-digits/assets/156437626/70999c7c-d3e1-475f-bd38-37d61025a104)
