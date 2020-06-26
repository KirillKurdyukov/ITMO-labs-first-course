import java.io.BufferedReader;
        import java.io.InputStream;
        import java.io.InputStreamReader;
        import java.util.Random;
        import java.util.StringTokenizer;

public class H {

    private static long ans = 0;

    private static class Node {
        long value, prior, size;
        boolean revers;
        Node left, right;

        Node(long value, long prior) {
            this.value = value;
            this.prior = prior;
            this.size = 1;
            this.revers = false;
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

    private static void push(Node T) {
        Node temp;
        if (T.revers) {
            temp = T.left;
            T.left = T.right;
            T.right = temp;
        }
        if (T.left != null) {
            T.left.revers = T.revers ^ T.left.revers;
        }
        if (T.right != null) {
            T.right.revers = T.revers ^  T.right.revers;
        }
        T.revers = false;
    }

    private static Node merge(Node A, Node B) {
        if (A == null)
            return B;
        if (B == null)
            return A;
        push(A);
        push(B);
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
        push(A);
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

    private static Node reverse(Node A, long l, long r) {
        Pair p = split(A, l - 1);
        Pair pp = split(p.b, r - l + 1);
        pp.a.revers = !pp.a.revers;
        p.b = merge(pp.a, pp.b);
        return merge(p.a, p.b);
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
        push(T);
        if (T.left != null) {
            print(T.left);
        }
        System.out.print(T.value + " ");
        if (T.right != null) {
            print(T.right);
        }
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
            long l = sc.nextInt();
            long rr = sc.nextInt();
            T = reverse(T, l, rr);
        }
        if (T != null) {
            print(T);
        } else
            System.out.println(0);
    }
}