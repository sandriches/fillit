# fillit
42/fillit
FILLIT is a game wherein a file of randomly generated 'tetriminos' (shapes like those found in the TETRIS game) must be arranged into the smallest square possible.

The idea of this project was to introduce the concept of RECURSION.

An example input file would be as follows:

$> cat sample.fillit
....
##..
.#..
.#..

....
####
....
....

#...
###.
....
....

....
##..
.##.
....

Which would ideally output:
$> ./fillit sample.fillit | cat -e
DDAA$
CDDA$
CCCA$
BBBB$
$>

The letters correspond to the order in which the tetriminos are given.
More information can be found in the PDF file.
