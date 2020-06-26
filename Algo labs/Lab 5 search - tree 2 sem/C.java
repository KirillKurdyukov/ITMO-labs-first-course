import java.io.BufferedReader;
        import java.io.InputStream;
        import java.io.InputStreamReader;
        import java.util.ArrayList;
        import java.util.Random;
        import java.util.StringTokenizer;

public class C {

    private static class Node {
        long value, prior, size, amountZero;
        Node left, right;

        Node(long value, long prior) {
            this.value = value;
            this.prior = prior;
            this.size = 1;
            if (value == 0) {
                this.amountZero = 1;
            } else {
                this.amountZero = 0;
            }
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

    private static long getAmountZero(Node T) {
        if (T == null) {
            return 0;
        }
        return T.amountZero;
    }

    private static void update(Node T) {
        T.size = getSize(T.right) + getSize(T.left) + 1;
        if(T.value == 0) {
            T.amountZero = getAmountZero(T.left) + getAmountZero(T.right)  + 1;
        } else {
            T.amountZero = getAmountZero(T.left) + getAmountZero(T.right);
        }
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

    private static Node deleteZero(Node T) {
        if (T == null) {
            return null;
        }
        if (getAmountZero(T.left) != 0) {
            T.left = deleteZero(T.left);
            update(T);
            return T;
        }
        if (T.value == 0) {
            T = merge(T.left, T.right);
            return T;
        } else {
            T.right = deleteZero(T.right);
            update(T);
            return T;
        }
    }

    private static Node add(Node A, long k, Node Node) {
        Pair p = split(A, k - 1);
        Pair pp = split(p.b, 1);
        if (pp.a.value == 0) {
            A = merge(Node, pp.b);
            A = merge(p.a, A);
        } else {
            if (getAmountZero(pp.b) == 0) {
                A = merge(pp.a, pp.b);
                A = merge(Node, A);
                A = merge(p.a, A);
            } else {
                A = merge(pp.a, deleteZero(pp.b));
                A = merge(Node, A);
                A = merge(p.a, A);
            }
        }
        return A;
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

    private static void print(Node T, ArrayList<Long> answer) {
        if (T.left != null) {
            print(T.left, answer);
        }
        answer.add(T.value);
        if (T.right != null) {
            print(T.right, answer);
        }
    }

    public static void main(String[] args) {
        FastReader sc = new FastReader(System.in);
        Node T = null;
        Random r = new Random();
        long n = sc.nextInt();
        long m = sc.nextInt();
        for (int i = 0; i < m; i++) {
            T = insert(T, new Node(0, r.nextInt()));
        }
        for (int i = 0; i < n; i++) {
            long L = sc.nextInt();
            T = add(T, L, new Node(i + 1, r.nextInt()));
        }
        ArrayList<Long> answer = new ArrayList<>();
        if (T != null) {
            print(T, answer);
        } else
            System.out.println(0);
        int answerSize = 0;
        for(int i = answer.size() - 1; i >= 0; i--) {
            if (answer.get(i) != 0 && answerSize < i) {
                answerSize = i;
            }
        }
        System.out.println(answerSize + 1);
        for(int i = 0; i <= answerSize; i++) {
            System.out.print(answer.get(i) + " ");
        }
    }
}