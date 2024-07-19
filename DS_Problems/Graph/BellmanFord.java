package DS_Problems.Graph;

import java.util.ArrayList;
import java.util.List;

/**
 * Bellman-Ford is a single source shortest path algorithm that determines the
 * shortest path between a given source vertex and every other vertex in a
 * graph. This algorithm can be used on both weighted and unweighted graphs.
 * 
 * Principal of Relaxation:
 * 
 * 1. It states that for the graph having N vertices, all the edges should be
 * relaxed N-1 times to compute the single source shortest path.
 * 
 * 2. In order to detect whether a negative cycle exists or not, relax all the
 * edge one more time and if the shortest distance for any node reduces then we
 * can say that a negative cycle exists. In short if we relax the edges N times,
 * and there is any change in the shortest distance of any node between the
 * N-1th and Nth relaxation than a negative cycle exists, otherwise not exist.
 * 
 */
public class BellmanFord {
    static List<Tuple> edges = new ArrayList<>();

    public static void main(String[] args) {
        edges.add(new Tuple(1, 2, 3));
        edges.add(new Tuple(2, 3, 1));
        edges.add(new Tuple(3, 4, -2));
        edges.add(new Tuple(4, 1, 4));
        edges.add(new Tuple(4, 5, 1));

        findShortestPaths(1, 5);
    }

    public static void findShortestPaths(int src, int nNodes) {
        int[] dist = new int[nNodes + 1];

        for (int i = 1; i <= nNodes; i++) {
            dist[i] = Integer.MAX_VALUE;
        }

        dist[src] = 0;

        for (int i = 1; i <= nNodes - 1; i++) {
            for (Tuple edge : edges) {
                if (dist[edge.from] + edge.weight < dist[edge.to]) {
                    dist[edge.to] = dist[edge.from] + edge.weight;
                }
            }
        }

        boolean hasNegativeEdge = false;

        for (Tuple edge : edges) {
            if (dist[edge.from] + edge.weight < dist[edge.to]) {
                hasNegativeEdge = true;
                break;
            }
        }

        if (!hasNegativeEdge) {
            for (int i = 1; i <= nNodes; i++) {
                System.out.println("Shortest path from: " + src + " to: " + i + " is: " + dist[i]);
            }
        }
    }
}

class Tuple {
    public int from;
    public int to;
    public int weight;

    public Tuple(int from, int to, int weight) {
        this.from = from;
        this.to = to;
        this.weight = weight;
    }
}