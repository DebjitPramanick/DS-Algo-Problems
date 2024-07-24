package DS_Problems.Graph;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Stack;

/*
Steps:

1. Sort all the nodes in order of finishing time -> Toposort
2. Transpose the graph
3. DFS traversal according to the finishing time
*/

/*
Time complexity -> O(N+E)
Space Complexity -> O(N+E)+O(N)+O(N)
*/

public class Kosaraju {
    static Map<Integer, List<Integer>> graph = new HashMap<>();

    public static void main(String[] args) {
        int[][] edges = {
                { 3, 2 },
                { 2, 1 },
                { 1, 3 },
                { 2, 4 },
        };

        for (int i = 0; i < edges.length; i++) {
            int from = edges[i][0];
            int to = edges[i][1];
            List<Integer> newItemsForFrom = graph.getOrDefault(from, new ArrayList<>());
            newItemsForFrom.add(to);
            graph.put(from, newItemsForFrom);
        }

        int nodes = 4;
        findStronglyConnectedComponents(nodes);
    }

    public static void findStronglyConnectedComponents(int nodes) {
        boolean[] vis = new boolean[nodes + 1];
        Stack<Integer> s = new Stack<>();
        for (int node = 1; node <= nodes; node++) {
            if (!vis[node]) {
                topoSort(node, vis, s);
            }
        }
        Map<Integer, List<Integer>> transpose = new HashMap<>();

        for (int node = 1; node <= nodes; node++) {
            vis[node] = false;
            for (Integer neighbor : graph.getOrDefault(node, new ArrayList<>())) {
                List<Integer> newItems = transpose.getOrDefault(neighbor, new ArrayList<>());
                newItems.add(node);
                transpose.put(neighbor, newItems);
            }
        }

        while (!s.isEmpty()) {
            int node = s.pop();
            if (!vis[node]) {
                System.out.print("SCC: ");
                reverseDFS(node, vis, transpose);
                System.out.println("");
            }
        }

    }

    private static void topoSort(int node, boolean[] vis, Stack<Integer> s) {
        vis[node] = true;

        for (Integer neighbor : graph.getOrDefault(node, new ArrayList<>())) {
            if (!vis[neighbor]) {
                topoSort(neighbor, vis, s);
            }
        }

        s.add(node);
    }

    private static void reverseDFS(int node, boolean[] vis, Map<Integer, List<Integer>> transpose) {
        vis[node] = true;
        System.out.print(node + " ");

        for (Integer neighbor : transpose.getOrDefault(node, new ArrayList<>())) {
            if (!vis[neighbor]) {
                reverseDFS(neighbor, vis, transpose);
            }
        }
    }
}
