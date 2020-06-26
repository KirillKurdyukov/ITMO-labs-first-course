import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Random;
import java.util.StringTokenizer;

public class G {

    private static long ans = 0;

    private static class Node {
        long value, prior, size;
        Node left, right;

        Node(long value, long prior) {
            this.value = value;
            this.prior = prior;
            this.size = 1;
        }
    }

    private static class Pair {
        Node a, b;

        Pair(Node a, Node b) {
            this.a = a;
            this.b = b;
        }
    }

    private static long getSize(Node T) {
        if (T == null) {
            return 0;
        }
        return T.size;
    }

    private static void update(Node T) {
        T.size = getSize(T.right) + getSize(T.left) + 1;
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

    private static Pair split(Node A, long k) {
        if (A == null) {
            return new Pair(null, null);
        }
        if (getSize(A.left) < k) {
            Pair p = split(A.right, k - 1 - getSize(A.left));
            A.right = p.a;
            update(A);
            return new Pair(A, p.b);
        } else {
            Pair p = split(A.left, k);
            A.left = p.b;
            update(A);
            return new Pair(p.a, A);
        }
    } //Ok

    private static Node insert(Node A, Node node) {
        A = merge(A, node);
        return A;
    }

    private static Node delete(Node A, long k) {
        Pair p = split(A, k - 1);
        Pair p1 = split(p.b,  1);
        A = merge(p.a, p1.b);
        return A;
    }

    private static Node add(Node A, long k, long val) {
        Pair p = split(A, k);
        A = merge(p.a, new Node(val, new Random().nextInt()));
        A = merge(A, p.b);
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

    private static void print(Node T) {
        if (T.left != null) {
            print(T.left);
        }
        System.out.print(T.value + " ");
        if (T.right != null) {
            print(T.right);
        }
    }

    private static Node lrToBegin(Node T, long l, long r) {
        if (T == null)
            return null;
        Pair p = split(T, l - 1);
        Pair pp = split(p.b, r - l + 1);
        T = merge(pp.a, p.a);
        return merge(T, pp.b);
    }

    public static void main(String[] args) {
        FastReader sc = new FastReader(System.in);
        Node T = null;
        Random r = new Random();
        long n = sc.nextInt();
        long k = sc.nextInt();
        for (int i = 0; i < n; i++) {
            T = insert(T, new Node(i + 1, r.nextInt()));
        }
        for (int i = 0; i < k; i++) {
            long L = sc.nextInt();
            long R = sc.nextInt();
            T = lrToBegin(T, L, R);
        }
        if (T != null) {
            print(T);
        } else
            System.out.println(0);
    }
}