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
- Time measured is seconds.
    
|                    | 1'000  | 10'000 | 100'000 | 1'000'000 | 10'000'00 |
|--------------------|--------|--------|---------|-----------|-----------|
| Created            | 0,0057 | 0,0403 | 0,4077  | 4,1532    | 44,9614   |
| Read and<br>sorted | 0,0384 | 0,3523 | 3,4296  | 32,8797   | 284,6534  |
| Smart.txt and Stupid.txt created     | 322,9005                        |
| Program duration                     | 372,5057                        |

# v0.4
### Changes
- vector.cpp now renamed into main.cpp.
- updated Student.h.

### New
- Added new structs in _LiStudent.h_ (for **list<>**) and _DeStudent.h_ (for **deque<>**).
- Added new files:
    - _vector.cpp_ for **vector<>** type container solution.
    - _list.cpp_ for **list<>** type container solution.
    - _deque.cpp_ for **deque<>** type container solution.
- **Warning:** files should be genereated in _main.cpp_ for new version functionality.

### Testing
#### System parameters
- CPU: 2.60GHz, 2592 Mhz, 6 Core(s), 12 Logical Processor(s); 
- RAM: 32.0 GB;
- SSD: 476 GB;

### Results

| **Vector.cpp**                  | 1'000      | 10'000      | 100'000      | 1'000'000      | 10'000'000       |
|---------------------------------|------------|-------------|--------------|----------------|------------------|
| Read                            | 0,0269     | 0,3142      | 2,5572       | 25,7897        | 257,5104         |
| Sorted ascending                | 0,02691503 | 0,314212285 | 2,5572105175 | 25,78971183987 | 257,510412114209 |
| Sorted into<br>smart and stupid | 0,0269746  | 0,31428923  | 2,557279714  | 25,7897680189  | 257,51047859882  |

| **List.cpp**                    | 1'000      | 10'000      | 100'000      | 1'000'000      | 10'000'000       |
|---------------------------------|------------|-------------|--------------|----------------|------------------|
| Read                            | 0,0349     | 0,3384      | 3,6570       | 32,6085        | 293,0656         |
| Sorted ascending                | 0,0349166  | 0,33841988  | 3,657032371  | 32,6085599479  | 293,06568878951  |
| Sorted into<br>smart and stupid | 0,03492989 | 0,338423192 | 3,6570217720 | 32,60852124705 | 293,065619850090 |

| **Deque.cpp**                   | 1'000       | 10'000      | 100'000      | 1'000'000      | 10'000'000       |
|---------------------------------|-------------|-------------|--------------|----------------|------------------|
| Read                            | 0,0318      | 0,3459      | 3,3893       | 35,5437        | 320,6025         |
| Sorted ascending                | 0,0318277   | 0,345924721 | 3,3893246941 | 35,54373045912 | 320,602525238340 |
| Sorted into<br>smart and stupid | 0,038182024 | 0,345921990 | 3,3893215488 | 35,54372514330 | 320,602523622130 |
