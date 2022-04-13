class Solution {
    List<Integer> l = new ArrayList<>();

    public List<Integer> preorder(Node root) {
        if (root == null)
            return l;
        l.add(root.val);

        for (Node child : root.children)
            l = preorder(child);
        return l;
    }
}