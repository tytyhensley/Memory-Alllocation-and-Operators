# Memory-Alllocation-and-Operators
The objective of this homework is to familiarize the students with object oriented
programming in C++ and have them practice memory allocation and operators overloading.
To this end, let us define the class Set to represent the set of integers. This class should have
the following attributes and member functions:
1. **MaxCard**:  The maximal cardinality of the set
2. **Elems**:  An integer array containing all the elements of the set
3. **Card**: The effective number of element in the set
4. **Default constructor**
5. **One  constructor with one argument: the maximal cardinality of the set**
6. **One  destructor**
7. **AddElem**  Add a new element to the set
8. **RmvElem**: remove one element from the list (by shifting the other elements)
9. **Member**: Verify if a given element is member of the set
10. **Copy**: copy one set in another
11. **Equal**: verify the equality of two sets
12. **Intersect**: compute the intersection of two sets
13. **Union**: compute the union of two sets
14. **Print**: display the set, use the mathematics notation

**Step 1**
Write the class set with the above functions, and in a test function, diversify the declaration of
instances of the class Set. Experiment the calls to all the functions defined.

**Step 2**
Add the following member functions:
1. Copy constructor
2. Assignment operator

**Step 3**
Add the following operators as member functions or as friend functions:
1. *operator &:* verify if a given integer is a member of the set
2. *operator ==:* verify the equality of two sets
3. *operator!=:* verify the inequality of two sets
4. *operator* * : compute the intersection of two sets
5. *operator +*: compute the union of two sets
6. *operator -*: compute the difference of two sets
7. *operator <=*: verify the inclusion of one set inside another
8. *operator <<*: display the content of a set
9. operator >> input the content of a set
