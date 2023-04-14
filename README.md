# Objektinis

# v1.0

### New
- Fixed wrong output for time test results (v0.5 has wrong timetable).
- Added new version of list sort:
    - **Version 1:** main vector with data sorts into two new vectors *'smart'* and *'stupid'*.
    - **Version 2:** from main vector sorts stupid students into new vector, while smart students are kept in original vector.
- Created upgradedVector.cpp that uses algorithms std::partition and std::stable_partition to make program faster.

### Results

| *updatedVector.cpp* | **1000**   | **10000**  | **100000** | **1000000** | **10000000** |
|-------------------|--------|--------|--------|---------|----------|
| Read              | 0.0238 | 0.2338 | 2.3239 | 23.194  | 247.4994 |
| Sorted            | 0.0013 | 0.0106 | 0.1071 | 1.1229  | 9.5105   |
| Strategy 1        | 0.0004 | 0.0038 | 0.0452 | 0.4743  | 4.9205   |
| Strategy 2        | 0.0003 | 0.0033 | 0.0409 | 0.4087  | 4.3699   |

| *vector.cpp* | **1000**   | **10000**  | **100000** | **1000000** | **10000000** |
|------------|--------|--------|----------|---------|----------|
| Read       | 0.0232 | 0.2288 | 2.3541   | 23.1762 | 238.3179 |
| Sorted     | 0.0013 | 0.0111 | 0.1113   | 1.155   | 9.4263   |
| Strategy 1 | 0.0007 | 0.0075 | 0.0794   | 0.7134  | 7.2391   |
| Strategy 2 | 0.0286 | 2.8049 | 296.1546 | -       | -        |

| *list.cpp*   | **1000**   | **10000**  | **100000** | **1000000** | **10000000** |
|------------|---------|---------|---------|---------|----------|
| Read       | 0.0261  | 0.2556  | 2.5078  | 26.4518 | 269.0197 |
| Sorted     | 0.0001  | 0.0016  | 0.024   | 0.5897  | 8.9396   |
| Strategy 1 | 0.0014  | 0.0147  | 0.1802  | 1.971   | 36.3856  |
| Strategy 2 | 0.00006 | 0.00044 | 0.01436 | 0.15363 | 1.371    |

| *deque.cpp*  | **1000**   | **10000**  | **100000** | **1000000** | **10000000** |
|------------|--------|--------|--------|---------|----------|
| Read       | 0.0288 | 0.2867 | 2.8377 | 29.1334 | 310.3281 |
| Sorted     | 0.0024 | 0.0222 | 0.2358 | 2.4938  | 23.7652  |
| Strategy 1 | 0.0018 | 0.0191 | 0.2031 | 2.0939  | 22.0431  |
| Strategy 2 | 0.0004 | 0.0035 | 0.0406 | 0.4356  | 4.2891   |


***Note: upgradedVector.cpp is not compared to others because it uses separate algorithms.***

#### Speed
- The fastest way to sort list into two groups is by using *list* type container combined with **Strategy 2**.
- The slowest results were using *vector* type container combined with **Strategy 2**. This result shoud have occured due to constant use of *erase* while deleting stupid students from main vector after moving them to new vector *'stupid'*.

#### Memory
- **Strategy 1** should appear as the most memory consuming way for sorting data, but it is difficult to measure difference while sorting data, since large part of the memory goes to reading and storing data into container.

# v0.5
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

#### Results

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

# v0.3
### Updates
- All functions separated into different **cpp** files. Files are stored in _"functions"_ folder.
- **Struct Student** moved to header file _"Student.h"_.
- **#include** of all functions stored in header file _"Functions.h"_.
- **Header files** moved to _"headers"_ folder.
- Now grade cannot be 0.
- Added new exceptions in file reading function _"GatherFileData"_.
- _Notes.md_ moved to _"ReadOnly"_ folder.

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

# v0.1
This version has two subversions: with C array (_carray.cpp_) and with Vector type array (_vector.cpp_).
***Vector subversion will be used for further development.***
Both solutions supported by _Mylib.h_.

