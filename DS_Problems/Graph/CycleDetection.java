package DS_Problems.Graph;

import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;

public class CycleDetection {
    static Map<Integer, List<Integer>> dgList;
    static Map<Integer, List<Integer>> udgList;

    public static void main(String[] args) {
        Graph directedGraph = new Graph(6, 8, true);
        Graph unDirectedGraph = new Graph(6, 4, false);

        dgList = directedGraph.getGraph();
        udgList = unDirectedGraph.getGraph();

        directedGraph.display();
        unDirectedGraph.display();

        System.err.println("Has cycle DG: " + hasCycleDG(6));
        System.err.println("Has cycle DG (TopoSort): " + hasCycleUsingTopoSort(6));
        System.err.println("Has cycle UDG: " + hasCycleUDG(6));
    }

    static boolean hasCycleDG(int nodes) {
        boolean[] vis = new boolean[nodes + 1];
        boolean[] recStack = new boolean[nodes + 1];

        for (int node = 1; node <= nodes; node++) {
            if (!vis[node]) {
                if (hasCycleDGHelper(node, vis, recStack))
                    return true;
            }
        }
        return false;
    }

    static boolean hasCycleDGHelper(int node, boolean[] vis, boolean[] recStack) {
        vis[node] = true;
        recStack[node] = true;

        for (Integer neighbor : dgList.get(node)) {
            if (!vis[neighbor] && hasCycleDGHelper(neighbor, vis, recStack)) {
                return true;
            } else if (recStack[neighbor]) {
                return true;
            }
        }

        recStack[node] = false;
        return false;
    }

    static boolean hasCycleUDG(int nodes) {
        Queue<int[]> q = new LinkedList<>();

        boolean[] vis = new boolean[nodes + 1];
        q.add(new int[] { 1, -1 });
        vis[1] = true;

        while (!q.isEmpty()) {
            int[] entry = q.poll();
            int node = entry[0];
            int parent = entry[1];

            for (Integer neighbor : udgList.get(node)) {
                if (!vis[neighbor]) {
                    q.add(new int[] { neighbor, node });
                    vis[neighbor] = true;
                } else if (neighbor == parent) {
                    return true;
                }
            }

        }

        return false;
    }

    static boolean hasCycleUsingTopoSort(int nodes) {
        int[] indegree = new int[nodes + 1];
        Queue<Integer> q = new LinkedList<>();

        for (int node = 1; node <= nodes; node++) {
            for (Integer neighbor : dgList.get(node)) {
                indegree[neighbor]++;
            }
        }

        for (int node = 1; node <= nodes; node++) {
            if (indegree[node] == 0) {
                q.add(node);
            }
        }

        int count = 0;

        while (!q.isEmpty()) {
            int node = q.poll();
            count++;

            for (Integer neighbor : dgList.get(node)) {
                indegree[neighbor]--;

                if (indegree[neighbor] == 0) {
                    q.add(neighbor);
                }
            }
        }

        return count != nodes;
    }

}
