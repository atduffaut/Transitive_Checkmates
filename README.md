This is a QT application that allows the user to visualize the path from any username in the input chess database (Jan2013 was used as the base case from https://database.lichess.org/)
to the top player that they have transitively beaten in that database (usually the top player overall in the database). To transitively beat someone means to beat them through another
player, I.E if user1 beats user2, and user2 beats user3, this counts as user1 transitively beating user3.
The goal was to give chess players an ego boost because most users are not more than 3-5 games away from beating the top player in the database, and it is fun to see the path from
a searched user to that top player.
C++ was used mainly to parse the data, create the graph, and search the shortest path using graph algorithms.
This project was submitted to MLH's Hackfit hackathon.
