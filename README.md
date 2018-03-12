# Experimental

## Purpose

My personal entertainment. Sometimes I just need to prove to myself that my brain still works. So I will add some silly
algorithm in here with a set of test cases to verify that it maybe works.

## Issues

If it works, good. If it doesn't, file a ticket. I may fix it.

## License

[3-Clause BSD](blob/master/LICENSE)

## Building it

You need premake5: https://premake.github.io/download.html is a good starting point.

Run "premake5 gmake" to get a set of Makefiles. "premake5 xcode4" for XCode or
"premake5 vs2015" for Visual Studio.

I have only tested on OS X with gmake and XCode.

## documentation

You need Doxygen and Moxygen

1. http://www.stack.nl/~dimitri/doxygen/index.html
2. https://github.com/sourcey/moxygen

Run `./makedcs.sh`. This will generate the `Documentation.md` and `html/index.html` containing the documentation.

The markup version is checked into the repository as [Documentation.md](blob/master/Documentation.md).

## Contents

### singlelinkedlist.hpp

This contains a simple single linked list implementation that basically works as
a stack. There are better single linked lists out there, just take a peek
at STL and Boost. But I wanted to see if I can still write one and get it
relatively bug free.

This list is not fast, it is not thread-safe, it is not fancy. But it seems to
work. Or put another way, I am at this specific time unable to think of a
situation that will break it that does not involve multiple threads.
