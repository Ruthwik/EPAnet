#Introduction
This project deals with the implementation of Modified Ford-Fulkerson Algorithm. The implementation includes the changing of link flows to meet the demands of destination. Here the demands of the intermediate nodes are neglected which is included in the future work. 

#EPAnet 
[EPAnet](https://en.wikipedia.org/wiki/EPANET) provides extensions to the programmers to run their own simulations.This helps to customize the functions and working of EPAnet according to their own needs and after modifications the programmers can produce dynamic link library (DLL). The Toolkit DLL file is named EPANET2.DLL and is distributed with EPANET. The Toolkit provides a series of functions that allow programmers to customize the use of EPANET’s hydraulic and water quality solution engine to their own applications.

#Ford–Fulkerson algorithm
[Ford–Fulkerson](https://en.wikipedia.org/wiki/Ford%E2%80%93Fulkerson_algorithm) algorithm is used in a flow network to compute the maximum
flow. It is based on residual networks and augmenting paths
####Pseudo Code for Ford–Fulkerson algorithm
1 Flows are initialized to 0.
2 Find augmenting path.
3 send flow along the path
4 repeat until there are no more augmenting paths

#Modified Ford Fulkerson Algorithm
In Modified Ford Fulkerson Algorithm the flow of the links are changed to meet
the demands of the destinations. Instead of increasing all links flows this modified
Ford Fulkerson efficiently increases the like flows and the cost of changing the link
flows reduces
####Pseudo Code for Modified Ford Fulkerson
Step i: Find the Demand of the Destination
Step ii: If the max flow capacity is less than demand than return demand can be
achieved without modification of any link capacity otherwise follow the steps from 1 to 4.
1. Find all the augmenting paths
2. Select the smallest Capacity among all augmenting paths

#Implementation
This project is developed using [Dev-C++](http://www.bloodshed.net/devcpp.html).

#Conclusion
In this project the cost for increasing the flow is calculated for a given varying demand of the destination node. It performs much more efficiently than changing the flow of every link. It selectively increases the flow of the link minimizing the changes.
