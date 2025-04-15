all:
	g++ -Wall Graph.cpp GraphTests.cpp -o graph-tests
	g++ -Wall Graph.cpp BetterPriorityQueue.cpp BPQTests.cpp -o bpq-tests
	g++ -Wall Graph.cpp BetterPriorityQueue.cpp Dijkstra.cpp DijkstraTests.cpp -o dijkstra

run-graph:
	./graph-tests

run-bpq:
	./bpq-tests

run-dijkstra:
	./dijkstra

try: all run-dijkstra