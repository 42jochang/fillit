# [42] Fillit

The first group project for 42 Cadets, as well as the second overall project at the time of completion. Given an assortment of tetrominoes, find and output the smallest square they will fit in. Recursive backtracking was used to check each block for a fit in a naive fashion, expanding the board until it finds a valid solution.

### Possible Optimization

Because this was written very early on, many possible aspects can be improved. Keeping smarter track of the space used would slightly increase used space with the benefit of significantly lower run time on certain edge cases. Flag handling could be added to create color and other block types. Various hardcoded checks could maintain their speed while being rewritten more elegantly.

## Final Score

100/100

## Usage

### Compilation

Compiler:

```
clang-6.0
```

Dependencies:

```
libft
```

### Execution

How to run:

```
./fillit [file_name]
```

## Example

```
./fillit case/case08
AAABC..DD
FFABCCCD.
HFBBEEEDG
HFOOE.GGG
HHPOOIIIJ
RPPMMNIJJ
RPMMKNNLJ
RSSKKKNLL
RSSQQQQL.
```

## Norme

This project is coded in accordance with the school's norms. A full copy of the norm can be found [here](https://github.com/MagicHatJo/-42-Norm/blob/master/norme.en.pdf).

## Team

JoChang
MMarcink
