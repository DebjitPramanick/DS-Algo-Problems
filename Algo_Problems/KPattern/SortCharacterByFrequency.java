package Algo_Problems.KPattern;

import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;

public class SortCharacterByFrequency {
    public static void main(String[] args) {
        String s = "cccaaa";
        solve(s);
    }

    static void solve(String s) {
        Map<Character, Integer> mp = new HashMap<>();
        PriorityQueue<Map.Entry<Character, Integer>> pq = new PriorityQueue<>((a, b) -> b.getValue() - a.getValue());

        for (char c : s.toCharArray()) {
            mp.put(c, mp.getOrDefault(c, 0) + 1);
        }

        pq.addAll(mp.entrySet());

        StringBuilder result = new StringBuilder();
        while (!pq.isEmpty()) {
            Map.Entry<Character, Integer> entry = pq.poll();
            result.append(String.valueOf(entry.getKey()).repeat(entry.getValue()));
        }

        System.out.println(result.toString());
    }
}
