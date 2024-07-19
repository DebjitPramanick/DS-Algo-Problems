package DS_Problems.Graph;

import java.util.Map;
import java.util.Queue;
import java.util.Stack;
import java.util.LinkedList;
import java.util.List;

public class Toposort {

    static Map<Integer, List<Integer>> adjList;

    public static void main(String[] args) {
        Graph graph = new Graph(5, 7, true);
        graph.display();
        adjList = graph.getGraph();
        topoSort(5);
        topoSortRec(5);
    }

    static void topoSort(int nodes) {
        int[] indegree = new int[nodes + 1];
        Queue<Integer> q = new LinkedList<>();

        for (int node = 1; node <= nodes; node++) {
            for (Integer neighbor : adjList.get(node)) {
                indegree[neighbor]++;
            }
        }

        for (int node = 1; node <= nodes; node++) {
            if (indegree[node] == 0) {
                q.add(node);
            }
        }

        while (!q.isEmpty()) {
            int node = q.poll();
            System.out.print(node + " ");

            for (Integer neighbor : adjList.get(node)) {
                indegree[neighbor]--;

                if (indegree[neighbor] == 0) {
                    q.add(neighbor);
                }
            }
        }
        System.out.println("");
    }

    static void topoSortRec(int nodes) {
        boolean[] vis = new boolean[nodes + 1];
        Stack<Integer> s = new Stack<>();
        for (int node = 1; node <= nodes; node++) {
            if (!vis[node]) {
                topoSortRecHelper(node, vis, s);
            }
        }

        while (!s.isEmpty()) {
            System.out.print(s.pop() + " ");
        }
        System.out.println("");
    }

    static void topoSortRecHelper(int node, boolean[] vis, Stack<Integer> s) {
        vis[node] = true;

        for (Integer neighbor : adjList.get(node)) {
            if (!vis[neighbor]) {
                topoSortRecHelper(neighbor, vis, s);
            }
        }

        s.push(node);
    }
}
