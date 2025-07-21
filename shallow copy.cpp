Shallow copy -
Shallow Copy stores the references of objects to the original memory address.  
Shallow Copy reflects changes made to the new/copied object in the original object.
Shallow Copy stores the copy of the original object and points the references to the objects.
A shallow copy is faster.

Deep copy - 
Deep copy stores copies of the object's value.
Deep copy doesn't reflect changes made to the new/copied object in the original object.
Deep copy stores the copy of the original object and recursively copies the objects as well.
Deep copy is comparatively slower.

Can constructor be made private ?
ctor = constructor
dtor = distructor

Yes it can be made private. 

why would we even need to make a constructor private ?
this is if we do not want someone to make an object of a class directly 

if class box is privte you cannot make a object for it but if i make another class called box factory and in the first box function 
i declare friend box factory 

Friend keyword in c++ ...just theory not really iused in real world applications 
- used to share the information of a class that was previously hidden.
- for example the private members of a class are hidden from every other class and cannot be modified except through getter and setter
similarly the protected members are hidden from all classes other than child class 
