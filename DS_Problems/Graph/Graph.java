package DS_Problems.Graph;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Random;

public class Graph {
    private Map<Integer, List<Integer>> graph = new HashMap<>();

    public Graph(int nodes, int edges, boolean isDirected) {
        int curEdge = 1;

        for (int node = 1; node <= nodes; node++) {
            graph.put(node, new ArrayList<>());
        }

        while (curEdge <= edges) {
            Random ran = new Random();
            int par = ran.nextInt(nodes) + 1;
            int neighbor = ran.nextInt(nodes) + 1;
            if (par == neighbor) {
                continue;
            }
            if (isDirected) {
                createUnidirectionalEdge(par, neighbor);
            } else {
                createBidirectionalEdge(par, neighbor);
            }

            System.out.println("Created edge between: " + par + " - " + neighbor);

            curEdge++;
        }
    }

    public void createBidirectionalEdge(int node, int neighbor) {
        List<Integer> parList = graph.get(node);
        List<Integer> neighborList = graph.get(neighbor);
        if (parList.contains(neighbor) || neighborList.contains(node)) {
            return;
        }
        parList.add(neighbor);
        neighborList.add(node);
        graph.put(node, parList);
        graph.put(neighbor, neighborList);
    }

    public void createUnidirectionalEdge(int node, int neighbor) {
        List<Integer> parList = graph.get(node);
        List<Integer> neighborList = graph.get(neighbor);
        if (parList.contains(neighbor) || neighborList.contains(node)) {
            return;
        }
        parList.add(neighbor);
        graph.put(node, parList);
    }

    public Map<Integer, List<Integer>> getGraph() {
        return this.graph;
    }

    public void display() {
        for (Entry<Integer, List<Integer>> entry : graph.entrySet()) {
            System.out.print(entry.getKey() + " -> ");
            for (Integer neighbor : entry.getValue()) {
                System.out.print(neighbor + ", ");
            }
            System.out.println("");
        }
    }

}
