% BubbleSort in prolog

bubble_sort([],Sorted) :- 
	Sorted = [].
bubble_sort([X], Sorted) :- 
	Sorted = [X].
bubble_sort(Terms, Sorted) :-
	bubble(Terms, Terms), Sorted = Terms ;
	bubble(Terms, Partials), bubble_sort(Partials, Sorted).

bubble([], Bubbled) :- Bubbled = [].
bubble([X], Bubbled) :- Bubbled = [X].
bubble([X,Y|Terms], [Y|Bubbled]) :-
	Y < X, bubble([X|Terms], Bubbled).
bubble([X,Y|Terms], [X|Bubbled]) :-
	X =< Y, bubble([Y|Terms], Bubbled).
