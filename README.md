# Objektinis

# v0.1
This version has two subversions: with C array (_carray.cpp_) and with Vector type array (_vector.cpp_).
***Vector subversion will be used for further development.***
Both solutions supported by _Mylib.h_.

# v0.2
### Updates
- Updated _"Mylib.h"_.
- **Struct Student** now has variables for both average and median final grades.
- Moved Local variables to Global:
    - _vector<Student> Group_.
    - _Student temp_.
- Output shows both **FinalMedian** and **FinalAverage** columns.
### New
- Added file reading functions:
    - _GatherFileData_.
    - _CountRows_.
    - _CountColumns_.
- Added Global variable _finaltype_. User now chooses one type of final grade for all subjects.
- All subjects now sorted by their names. Added functions for sorting:
    - _Compare_.
    - _sort_ (int main).

# v0.3
### Updates
- All functions separated into different **cpp** files. Files are stored in _"functions"_ folder.
- **Struct Student** moved to header file _"Student.h"_.
- **#include** of all functions stored in header file _"Functions.h"_.
- **Header files** moved to _"headers"_ folder.
- Now grade cannot be 0.
- Added new exceptions in file reading function _"GatherFileData"_.
- _Notes.md_ moved to _"ReadOnly"_ folder.

# v0.4
### Updates
- Some functions now separated into new cpp files.
- Updated *"Mylib.h"*.
- Global variable _finaltype_ is now in *"Answers.h"*.

### New
- Added new **file generator**, which uses buffer.
- Added new **struct Answers** in header file *"Answers.h"*, for storing settings.
- New function Settings now allows to choose how to work with data.
- _"Datatype3"_ function allows to generate new files and use them to sort students into two groups: _smart_ and _stupid_.
