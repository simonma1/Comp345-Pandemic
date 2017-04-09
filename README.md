# Comp345-Pandemic Assignment 3 (Jad Malek, 26345018)
Member of Team Orangutans  

This is Part 3 of the assignment, Game Statistics Decorator Observer Patterns. There is no specific driver but when I add observers
in the Board.cpp (for the default Board constructor), I have added both a GameStatsObserver (recording the 4 indicated statistics)and then can dynamically decorate said 
observer as much as is desired. I made two decorators - one for the percentage of cities that players have infected and one for the 
percentage of resources that a player has. 