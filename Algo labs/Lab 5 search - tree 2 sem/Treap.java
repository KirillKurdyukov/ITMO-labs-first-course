import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Random;
import java.util.StringTokenizer;

public class Treap {

    private static class Node {
        int value, prior;
        Node left, right;
        Node (int value, int prior) {
            this.value = value;
            this.prior = prior;
        }
    }

    private static class Pair {
        Node a, b;
        Pair (Node a, Node b) {
            this.a = a;
            this.b = b;
        }
    }

    private static Node merge(Node A, Node B) {
        if (A == null)
            return B;
        if (B == null)
            return A;
        if (A.prior > B.prior) {
            A.right = merge(A.right, B);
            return A;
        } else {
            B.left = merge(A, B.left);
            return B;
        }
    } //Ok

    private static Pair split(Node A, int val) {
        if (A == null) {
            return new Pair(null, null);
        }
        if (A.value < val) {
            Pair p = split(A.right, val);
            A.right = p.a;
            return new Pair(A, p.b);
        } else {
            Pair p = split(A.left, val);
            A.left = p.b;
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

    private static Node delete(Node A, int x) {
        Pair p = split(A, x);
        Pair p1 = split(p.b, x + 1);
        A = merge(p.a, p1.b);
        return A;
    }

    private static boolean exists(Node A, int x) {
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

    private static Node next(Node A, int x) {
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

    private static Node prev(Node A, int x) {
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

        int nextInt() {
            return Integer.parseInt(next());
        }
    }

    public static void main (String[] args) {
        FastReader sc = new FastReader(System.in);
        Node T = null;
        String temp;
        Random r = new Random();
        while ((temp = sc.next()) != null) {
            int val = Integer.parseInt(sc.next());
            switch (temp) {
                case "insert":
                    T = insert(T, new Node(val, r.nextInt()));
                    break;
                case "delete":
                    T = delete(T, val);
                    break;
                case "exists":
                    System.out.println(exists(T, val));
                    break;
                case "next":
                    if (next(T, val) == null)
                        System.out.println("none");
                    else {
                        System.out.println(next(T, val).value);
                    }
                    break;
                case "prev":
                    if (prev(T, val) == null)
                        System.out.println("none");
                    else
                        System.out.println(prev(T, val).value);
                    break;
            }
        }
    }
}
