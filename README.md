# Objektinis

#0.1
This version has two subversions: with C array (_carray.cpp_) and with Vector type array (_vector.cpp_).
***Vector subversion will be used for further development.***
Both solutions supported by _Mylib.h_.

#v0.2
##Updates
- Updated _"Mylib.h"_.
- **Struct Student** now has variables for both average and median final grades.
- Moved Local variables to Global:
    - _vector<Student> Group_.
    - _Student temp_.
- Output shows both **FinalMedian** and **FinalAverage** columns.
##New
- Added file reading functions:
    - _GatherFileData_.
    - _CountRows_.
    - _CountColumns_.
- Added Global variable _finaltype_. User now chooses one type of final grade for all subjects.
- All subjects now sorted by their names. Added functions for sorting:
    - _Compare_.
    - _sort_ (int main).