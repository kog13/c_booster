![alt tag](/c_booster/asset/c_booster_logo.png?raw=true "Kognizant Source")

# C Booster

*Please note this repo is for PERSONAL learning and experimentation 
right now. I add things here and there when I have time and the interest.
This is NOT for PRODUCTION use.*

A collection of generic C data structures and algorithms.

Data structures provide building blocks for more robust C applications. Headers
and implementations are designed to be easy to use as well as read so that they
can be used as tools for re-learning implementations.

Alongside the data structures are helper methods that provide common
algorithms and access patterns. Examples include removing duplicates from 
containers or common iterators and comparators.

## Considerations

Data structures, access patterns, and algorithms are all designed to be as
generic as possible. This means opting for more parameter overhead in the
interest of reuse.

When it comes to space / speed considersations, these data structures opt for
speed over space. This means that some data structures may have extra
members so that the running times can be improved.

## Install

Installation of the library can be done by calling:

    make install

## Usage

Once installed, the C Booster library can be used by including:

    #include <c_booster.h>

## Library Contents

### Data Structures

- ChainedHashTable
- DoublyLinkedList
- LinkedList (ForwardList)
- Queue
- Stack

### Algorithms

- Sort

### Directory Structure

```
├── c_booster/
│   ├── README.md
│   ├── Makefile
│   ├── asset
│   ├── include
│   ├── src
│   ├── test
```

## Tests

Tests require the Check C unit testing framework to be installed.

On OSX + Homebrew this can be done by typing:

    brew install check

Tests can then be run with:

    make test
