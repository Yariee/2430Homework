Sorting:

The goal of this assignment is to implement the quicksort algorithm to sort a list of records. Each record object contains 3 attributes: [customer, date, product].
The provided code implements the Record class, reads an input file and generates a std::vector of Record objects, and filters out all the shopping records
of a given customer. The code is provided in the files main.cpp, Record.h, Record.cpp, DataMiner.h, and DataMiner.cpp. You are not supposed to modify any of
the files, except for the last one, DataMiner.cpp.


- Your task is to implement the DataMiner::sortRecords() using the quicksort algorithm, and the corresponding partitioner function DataMiner::partition(). 
The implementation of the quicksort algorithm is expected to be in sortRecords(), hence, the sortRecords() function will invoke itself recursively, first on
the left part of the vector (up to the pivotIndex returned by the partition() method), and then on the right part of the vector ( pivotIndex up to right index).

-To partion the vector based on a pivot point, the sortRecords() method should invoke the partition() method. The partition() method is expected to use the value
found at pivotIndex as the pivot Value, implementation for calculating the pivotIndex is provided. The partition() method is then expected to swap elements in
the vector such that all elements smaller than the pivot Value are in the left part of the array (starting from the left index), and all elements larger than 
the pivot Value are to the right of the array (up to the right index). Note, that the index returned as the 'pivotIndex' by the partition() method will typically
not be the pivotIndex calculated at the beginning of this function. 

The sorting should be done based on two criteria: date and product name.
-First, the records are first sorted by the shopping date, earlier dates should show up first before later dates. For example, the date 20210103 should come
before 20210104 and so on.
-Second, records from a given date should be sorted by lexicographical order by the products. So that means "apple" should come before "banana".
This should be achieved with a single sort operation, i.e. do not explicitly sort by date, followed by explicitly sorting by product.

Hint: When you are writing your comparator for your sorting, it may be helpful to use the string.compare() method. You can refer to these documents on the
exact behavior of the string compare function and design your comparator accordingly:
http://www.cplusplus.com/reference/string/string/compare/
