
public class DisjointSets {

    static int[] A;

    public static void main(String[] args) {
        A = new int[] {0,
                // input array contents here, this is an example from HW_3: Q3
                -3, 1, 1, 3, 1, 5, 5, 7, 1, 9, 9, 11, -2, 13, 13, 15
        };

        // input commands here
        printSet();
        System.out.println();
        findSet(8);
        findSet(10);
        //union(8, 16);
        //union(10, 14);
        //findSet(8);
        //findset(10);

        printSet();
        
    }

    public static void makeSet(int x) {
        A[x] = 0;
    }

    public static void union(int x, int y) {
        link(findSet(x), findSet(y));
    }

    public static void link(int x, int y) {
        if (-A[x] > -A[y]) {
            A[y] = x;
        } else {
            if (-A[x] == -A[y]) {
                A[y] = A[y] - 1;
            }
            A[x] = y;
        }
    }

    public static int findSet(int x) {
        if (A[x] <= 0) {
            return x;
        } else {
            // find with path compression
            A[x] = findSet(A[x]);
            return A[x];

            // find without path compression
            // return findSet(A[x]);
        }
    }

    public static void printSet() {
        System.out.print("i:\t\t");
        for (int x = 1; x < A.length; x++) {
            System.out.print("\t" + x);
        }
        System.out.print("\nA[i]:\t");
        for (int x = 1; x < A.length; x++) {
            System.out.print("\t" + A[x]);
        }
        System.out.print("\n");
    }

}