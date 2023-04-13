import java.util.*;

public class Main {

    public static final int INT_MIN = Integer.MIN_VALUE;

    static class Node {
        int id;
        Set<Node> next;
        int val;

        public Node(int id, int val) {
            this.id = id;
            this.next = new HashSet<>();
            this.val = val;
        }
    }

    static Map<Integer, Node> nodes = new HashMap<>();
    static List<Node> rootNodes = new ArrayList<>();
    static int res = INT_MIN;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int nLine = sc.nextInt();
        for (int i = 0; i < nLine; i++) {
            int id = sc.nextInt();
            int parent = sc.nextInt();
            int val = sc.nextInt();
            nodes.put(id, new Node(id, val));
        }
        for (int id : nodes.keySet()) {
            Node node = nodes.get(id);
            if (node.parent == -1) {
                rootNodes.add(node);
            } else {
                Node parent = nodes.get(node.parent);
                parent.next.add(node);
            }
        }
        for (Node node : rootNodes) {
            dfs(node, 0);
        }
        System.out.println(res);
    }

    public static void dfs(Node root, int grade) {
        grade = Math.max(0, grade + root.val);
        res = Math.max(grade, res);
        for (Node node : root.next) {
            dfs(node, grade);
        }
    }
}