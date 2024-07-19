package DS_Problems.Graph;

import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;

public class Traversal {
    static Map<Integer, List<Integer>> adjList;

    public static void main(String[] args) {
        Graph graph = new Graph(4, 4, false);
        graph.display();
        adjList = graph.getGraph();
        bfsTraversal(4);
        dfsTraversal(4);
    }

    public static void bfsTraversal(int nodes) {
        Queue<Integer> q = new LinkedList<>();
        int[] visited = new int[nodes + 1];
        q.add(1);
        visited[1] = 1;
        System.out.println("\nBFS: ");
        while (!q.isEmpty()) {
            int node = q.poll();
            System.out.print(node + " ");
            for (Integer neighbor : adjList.get(node)) {
                if (visited[neighbor] != 1) {
                    q.add(neighbor);
                    visited[neighbor] = 1;
                }
            }
        }
    }

    public static void dfsTraversal(int nodes) {
        int[] visited = new int[nodes + 1];
        System.out.println("\nDFS: ");
        for (int node = 1; node <= nodes; node++) {
            if (visited[node] != 1) {
                dfsTraversalRec(node, visited);
            }
        }
    }

    public static void dfsTraversalRec(int node, int[] visited) {
        visited[node] = 1;
        System.out.print(node + " ");
        for (Integer neighbor : adjList.get(node)) {
            if (visited[neighbor] != 1) {
                dfsTraversalRec(neighbor, visited);
            }
        }
    }
}