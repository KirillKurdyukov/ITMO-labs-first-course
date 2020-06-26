import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Random;
import java.util.StringTokenizer;

public class E {

    private static long ans = 0;

    private static class Node {
        long numberOfPeaks;
        long value, prior;
        Node left, right;

        Node(long value, long prior) {
            this.value = value;
            this.prior = prior;
            this.numberOfPeaks = 1;
        }
    }

    private static class Pair {
        Node a, b;

        Pair(Node a, Node b) {
            this.a = a;
            this.b = b;
        }
    }

    private static long getNumberOfPeaks(Node T) {
        if (T == null) {
            return 0;
        }
        return T.numberOfPeaks;
    }

    private static void update(Node T) {
        T.numberOfPeaks = getNumberOfPeaks(T.right) + getNumberOfPeaks(T.left) + 1;
    }

    private static Node merge(Node A, Node B) {
        if (A == null)
            return B;
        if (B == null)
            return A;
        if (A.prior > B.prior) {
            A.right = merge(A.right, B);
            update(A);
            return A;
        } else {
            B.left = merge(A, B.left);
            update(B);
            return B;
        }
    } //Ok

    private static Pair split(Node A, long val) {
        if (A == null) {
            return new Pair(null, null);
        }
        if (A.value < val) {
            Pair p = split(A.right, val);
            A.right = p.a;
            update(A);
            return new Pair(A, p.b);
        } else {
            Pair p = split(A.left, val);
            A.left = p.b;
            update(A);
            return new Pair(p.a, A);
        }
    } //Ok

    private static Node insert(Node A, Node node) {
        if (exists(A, node.value)) {
            return A;
        }
        Pair p = split(A, node.value);
        p.a = merge(p.a, node);
        A = merge(p.a, p.b);
        return A;
    }

    private static Node delete(Node A, long x) {
        Pair p = split(A, x);
        Pair p1 = split(p.b, x + 1);
        A = merge(p.a, p1.b);
        return A;
    }

    private static boolean exists(Node A, long x) {
        if (A == null)
            return false;
        if (A.value == x)
            return true;
        if (A.value > x) {
            return exists(A.left, x);
        } else {
            return exists(A.right, x);
        }
    }

    private static long someMaximum(Node T, long k) {
        if (T.numberOfPeaks - getNumberOfPeaks(T.left) == k) {
            return T.value;
        } else if (getNumberOfPeaks(T.right) >= k) {
            return someMaximum(T.right, k);
        } else {
            return someMaximum(T.left, k - 1 - getNumberOfPeaks(T.right));
        }
    }

    private static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        FastReader(InputStream input) {
            br = new BufferedReader(new InputStreamReader(input));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (Exception e) {
                    return null;
                }
            }
            return st.nextToken();
        }

        long nextInt() {
            return Long.parseLong(next());
        }
    }

    public static void main(String[] args) {
        FastReader sc = new FastReader(System.in);
        Node T = null;
        String temp;
        Random r = new Random();
        long n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            temp = sc.next();
            switch (temp) {
                case "1":
                    T = insert(T, new Node(sc.nextInt(), r.nextInt()));
                    break;
                case "+1":
                    T = insert(T, new Node(sc.nextInt(), r.nextInt()));
                    break;
                case "-1":
                    T = delete(T, sc.nextInt());
                    break;
                case "0":
                    assert T != null;
                    System.out.println(someMaximum(T, sc.nextInt()));
            }
        }
    }
}