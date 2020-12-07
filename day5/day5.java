package day5;

import java.io.File;
import java.util.*;
import java.io.FileNotFoundException;

public class day5 {
    public static void main(String[] args) {
        Scanner reader;
        try {
            // Part 1, create Data Structures for Part 2
            File file = new File("C:\\Users\\ArceusDrago\\Desktop\\advent\\day5\\day5.txt");
            reader = new Scanner(file);
            int highest = Integer.MIN_VALUE;
            Set<Integer> ids = new HashSet<>();
            while (reader.hasNextLine()) {
                String line = reader.nextLine();
                int row = findRow(line, 0, 0, 127);
                int col = findCol(line, 7, 0, 7);
                ids.add(row * 8 + col);
                highest = Integer.max(highest, row * 8 + col);
            }
            System.out.println(highest);


        } catch (FileNotFoundException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        } finally {
            if (reader != null) reader.close();
        }
    }

    private static int findRow(String line, int i, int head, int tail) {
        if (line.charAt(i) == 'F') {
            tail = head + ((tail - head) / 2);
        } else if (line.charAt(i) == 'B') {
            head = head + ((tail - head) / 2) + 1;
        }

        if (head == tail) return head;
        return findRow(line, i + 1, head, tail);
    }

    private static int findCol(String line, int i, int head, int tail) {
        if (line.charAt(i) == 'L') {
            tail = head + ((tail - head) / 2);
        } else if (line.charAt(i) == 'R') {
            head = head + ((tail - head) / 2) + 1;
        }

        if (head == tail) return head;
        return findCol(line, i + 1, head, tail);
    }
}