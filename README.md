# Experimental

## Purpose

My personal entertainment. Sometimes I just need to prove to myself that my brain still works. So I will add some silly
algorithm in here with a set of test cases to verify that it maybe works.

## Issues

If it works, good. If it doesn't, file a ticket. I may fix it.

## License

[3-Clause BSD](LICENSE)

## Building it

[![Appveyor Linux build status](https://ci.appveyor.com/api/projects/status/pgnil2xid8x9u4ng/branch/master?svg=true)](https://ci.appveyor.com/project/rsandila/experimental/branch/master)


You need premake5: https://premake.github.io/download.html is a good starting point.

Run "premake5 gmake" to get a set of Makefiles. "premake5 xcode4" for XCode or
"premake5 vs2019" for Visual Studio.

I have only tested on:
 1. OS X gmake and XCode.
 2. Windows running Linux for Windows and gmake (NPM should be used to install Moxygen using from Windows using 'npm install moxygen -g' and then used from Linux for Windows)
 3. Windows running Visual Studio 2019
 
## Documentation

You need Doxygen and Moxygen

1. http://www.stack.nl/~dimitri/doxygen/index.html
2. https://github.com/sourcey/moxygen

Run `./makedocs.sh`. This will generate the `Documentation.md` and `html/index.html` containing the documentation.

The markup version is checked into the repository as [Documentation.md](Documentation.md).

## Tests

Run `./bin/64bit/Debug/experimental-tests` for the 64-bit Debug variant of the tests.

## Contents

### singlelinkedlist.hpp

This contains a simple single linked list implementation that basically works as
a stack. There are better single linked lists out there, just take a peek
at STL and Boost. But I wanted to see if I can still write one and get it
relatively bug free.

This list is not fast, it is not thread-safe, it is not fancy. But it seems to
work. Or put another way, I am at this specific time unable to think of a
situation that will break it that does not involve multiple threads.

### sortedlist.hpp

This contains a simple sorted list. It uses std::vector as a base so will not 
perform optimally on big lists. It uses binary search for inserts and for finding
items in the list so that should be mostly efficient. But this was a good experiment
at writing a sorted list and there should be okay code coverage from the unit tests and few bugs.

It is not thread-safe, it is not fancy and will likely not scale to large lists.
