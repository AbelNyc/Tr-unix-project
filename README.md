# Tr-final-project
Implemented a clone of command in UNIX which is a command line utility for translating or deleting characters. It supports a range of transformations including uppercase to lowercase, squeezing repeating characters, deleting specific characters and basic find and replace.
his project, you’ll re-implement some standard unix utilities. In particular, you’ll make clones (perhaps with some missing or different functionality) of wc,sort,uniq,shuf and tr.

More about basic C++ data structures.
Functions and arguments.
A bit more about the unix shell.

What tr actually does: The tr command has some subtleties. Here is some instructive output of the system’s tr command which might help you understand them:

$ echo "cba" | tr "abc" "def"
fed
$ echo "hello there" | tr "el" "ar"
harro thara
One thing to watch out for is the -c option. Think of it this way: characters in the first set will be preserved, and all others will be translated. The tricky thing is that the translation table will start at character 0, and have a few “holes” for the characters that are to be preserved. An example:

$ echo -e "\x00hello there" | tr -c 'el\n' 'xyz'
xzellzzzzeze
Notice how the 0 character \x00 was translated to a x, which happens to be the first character of the second set. Now see if you can make sense of this one:

$ echo -e "\x00hello there" | tr -c 'el\n' 'A-Z0-9'
A9ell9599e9e
The translation table is A,B,C,...,Z,0,1,2,...,9. The space character has ascii value 32. You might think that it should have been mapped to the item at index 32 in the table, but the careful observer will see that it actually mapped to 5, which is index 31. So what’s going on? The list of characters to be translated has some holes in it. In particular it is missing the newline, which would have been at index 10. This effectively moves space back one index to 31. Here’s a more complicated example:

$ echo -e "hello there" | tr -c 'el\n' '\0-\377'
felllqfeoe
$ echo -e "hello there" | tr -c 'el\n' '\0-\377' | xxd
00000000: 6665 6c6c 6c1f 7166 656f 650a            felll.qfeoe.
The translation table is just all characters in order (ascii value 0 to 255). You can see that the space was translated to 31,3 the ‘h’ was translated to ‘f’, which is two indexes behind, as there are now two holes in the input list, and ‘r’ mapped to ‘o’, which is 3 indexes behind, since the index of ‘r’ is after all three characters that we’re leaving out.
