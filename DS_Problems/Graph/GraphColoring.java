package DS_Problems.Graph;

import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;

public class GraphColoring {
    static Map<Integer, List<Integer>> adjList;

    public static void main(String[] args) {
        Graph graph = new Graph(5, 6, false);
        adjList = graph.getGraph();
        graph.display();
        System.out.println("Is Bipartite: " + isBipartite(5));
        System.out.println("chromatic number is: " + getChromaticNumber(5));
        System.out.println("Is m coloring possible: " + isMColoringPossible(5, 2));
    }

    public static boolean isBipartite(int nodes) {
        Queue<Integer> q = new LinkedList<>();
        int[] colors = new int[nodes + 1];
        q.add(1);
        colors[1] = 0;

        while (!q.isEmpty()) {
            int entry = q.poll();
            int node = entry;
            int color = colors[node];

            for (Integer neighbor : adjList.get(node)) {
                if (colors[neighbor] == 0) {
                    q.add(neighbor);
                    colors[neighbor] = 3 - color;
                } else if (colors[neighbor] == color) {
                    return false;
                }
            }
        }

        return true;
    }

    public static int getChromaticNumber(int nodes) {
        int[] colors = new int[nodes + 1];

        boolean[] existingColors = new boolean[nodes + 1];
        int chromaticNumber = 0;

        for (int node = 1; node <= nodes; node++) {
            for (Integer neighbor : adjList.get(node)) {
                if (colors[neighbor] != 0) {
                    existingColors[colors[neighbor]] = true;
                }
            }

            int color;
            for (color = 1; color <= nodes; color++) {
                if (!existingColors[color]) {
                    break;
                }
            }

            colors[node] = color;
            chromaticNumber = Math.max(chromaticNumber, color);

            for (Integer neighbor : adjList.get(node)) {
                if (colors[neighbor] != 0) {
                    existingColors[colors[neighbor]] = false;
                }
            }
        }

        return chromaticNumber;
    }

    public static boolean isMColoringPossible(int nodes, int m) {
        boolean[] existingColors = new boolean[m + 1];
        int[] colors = new int[nodes + 1];
        boolean isPossible = true;

        for (int i = 1; i <= nodes; i++) {
            for (Integer neighbor : adjList.get(i)) {
                if (colors[neighbor] != 0) {
                    existingColors[colors[neighbor]] = true;
                }
            }

            int cr = 1;
            for (cr = 1; cr <= m; cr++) {
                if (!existingColors[cr]) {
                    break;
                }
            }

            if (cr > m) {
                isPossible = false;
                break;
            }

            colors[i] = cr;

            for (Integer neighbor : adjList.get(i)) {
                if (colors[neighbor] != 0) {
                    existingColors[colors[neighbor]] = false;
                }
            }
        }

        return isPossible;

    }
}
