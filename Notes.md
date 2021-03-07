## Pseudocode
```
Sort all intervals given order so I1 <= I2 <= I3 ... <= In
Use this order for:
Initially, h <-- 0
For j= 1 to n, do:
    If (some interval is compatible with some color Ci):
        assign the color k to it
    Else:
        assign
    EndIf
EndFor
```

## Notes

* Time complexity = O(n(log n))
* Max colors = Max(Intersection of intervals)







### Resources
* [Interval Partitioning ( Greedy Algorithm ) - Algorithms](https://www.youtube.com/watch?v=i_G8hZYcKnI)
* [Algorithms Lecture 17: Greedy Algorithms, Room Scheduling Problem (Interval Graph Coloring)](https://www.youtube.com/watch?v=X3szwLDn0fE)
* [Algebra I #12.3b, What is an Interval Graph, Interval Graph word problem](https://www.youtube.com/watch?v=xtimIa0QWgg)
