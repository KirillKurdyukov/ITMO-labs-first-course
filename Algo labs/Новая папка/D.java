import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Random;
import java.util.StringTokenizer;

public class D {

    private static long ans = 0;

    private static class Node {
        long sum;
        long value, prior;
        Node left, right;

        Node(long value, long prior) {
            this.value = value;
            this.prior = prior;
            this.sum = value;
        }
    }

    private static class Pair {
        Node a, b;

        Pair(Node a, Node b) {
            this.a = a;
            this.b = b;
        }
    }

    private static long getSum(Node T) {
        if (T == null) {
            return 0;
        }
        return T.sum;
    }

    private static void update(Node T) {
        T.sum = getSum(T.right) + getSum(T.left) + T.value;
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

    private static Node sumLtoR(Node A, long l, long r) {
        Pair L = split(A, l);
        Pair R = split(L.b, r + 1);
        ans = getSum(R.a);
        L.b = merge(R.a, R.b);
        A = merge(L.a, L.b);
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

    private static Node next(Node A, long x) {
        if (A == null) {
            return null;
        }
        if (A.value <= x) {
            return next(A.right, x);
        } else {
            if (next(A.left, x) != null)
                return next(A.left, x);
            else
                return A;
        }
    }

    private static Node prev(Node A, long x) {
        if (A == null) {
            return null;
        }
        if (A.value >= x) {
            return prev(A.left, x);
        } else {
            if (prev(A.right, x) != null) {
                return prev(A.right, x);
            } else
                return A;
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
        boolean haveIterator = false;
        long n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            temp = sc.next();
            switch (temp) {
                case "+":
                    if (haveIterator) {
                        T = insert(T, new Node(((sc.nextInt() + ans) % 1000000000), r.nextInt()));
                        haveIterator = false;
                    } else
                        T = insert(T, new Node(sc.nextInt(), r.nextInt()));
                    break;
                case "?":
                    T = sumLtoR(T, sc.nextInt(), sc.nextInt());
                    System.out.println(ans);
                    haveIterator = true;
                    break;
            }
        }
    }
}