# SOLID Principles
---

**Single Responsibility Principle:** Basically each class, function etc should have a single responsibility and the concerns needs to be separated.

For example a journal class should only have journal related things, its saving, retrieval etc should be in a different class like persistenceManager.

**Open Close Principle:** Code should be open for extension and closed for modification i.e you should be able to extend the functionality without modifying the existing code but by extending say an existing class.

**Liskov Substitution Principle:** States that one should be able to substitute a derived class at any place where parent class is being used.

If we are not able to do so, then we break this principle and our design is flawed, should find an alternative!!!!

**Interface Segregation Principle:** Don’t create too big interfaces!

Interfaces should be as focused as possible and then create bigger interfaces by inheriting from these smaller interfaces so that one can create focused classes as well as generic bigger classes.

**Dependency Injection Principle:  (Not** something related to dependency injection, its different**)**

Basically, some class shouldn’t depend on another class and process and something related to that class. If we do that if the first class changes, the second class also has to change.

Instead all the first class related processing needs to be done in first class only and if we want to use something from first class we get it into second class via an abstract class whose methods are implemented in first class.

This is dependency inversion.