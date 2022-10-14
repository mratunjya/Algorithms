// Implement B Plus Tree

import java.util.*;

public class BPlusTree {
    private int order;
    private int minKeys;
    private int maxKeys;
    private BPlusNode root;
    private BPlusNode leafHead;

    public BPlusTree(int order) {
        this.order = order;
        this.minKeys = order - 1;
        this.maxKeys = 2 * order - 1;
        this.root = new BPlusNode(true);
        this.leafHead = root;
    }

    public void insert(int key, int value) {
        BPlusNode leaf = findLeaf(key);
        leaf.insert(key, value);
        if (leaf.isOverflow()) {
            split(leaf);
        }
    }

    public void delete(int key) {
        BPlusNode leaf = findLeaf(key);
        leaf.delete(key);
        if (leaf.isUnderflow()) {
            merge(leaf);
        }
    }

    public int search(int key) {
        BPlusNode leaf = findLeaf(key);
        return leaf.search(key);
    }

    private BPlusNode findLeaf(int key) {
        BPlusNode node = root;
        while (!node.isLeaf()) {
            node = node.getChild(key);
        }
        return node;
    }

    private void split(BPlusNode node) {
        BPlusNode left = node;
        BPlusNode right = new BPlusNode(node.isLeaf());
        int mid = (maxKeys + 1) / 2;
        for (int i = mid; i <= maxKeys; i++) {
            right.insert(left.getKey(i), left.getValue(i));
            left.delete(left.getKey(i));
        }
        if (!node.isLeaf()) {
            for (int i = mid; i <= maxKeys + 1; i++) {
                right.setChild(left.getChild(i), i - mid);
                left.setChild(null, i);
            }
        }
        if (node == root) {
            root = new BPlusNode(false);
            root.setChild(left, 0);
            root.setChild(right, 1);
            root.insert(right.getKey(0), right.getValue(0));
        } else {
            BPlusNode parent = node.getParent();
            parent.insert(right.getKey(0), right.getValue(0));
            parent.setChild(right, parent.getKeyIndex(right.getKey(0)) + 1);
            if (parent.isOverflow()) {
                split(parent);
            }
        }
        if (node.isLeaf()) {
            right.setNext(node.getNext());
            node.setNext(right);
            if (right.getNext() == null) {
                leafHead = right;
            }
        }
    }

    private void merge(BPlusNode node) {
        if (node == root) {
            if (node.getKeySize() == 0) {
                root = node.getChild(0);
                root.setParent(null);
            }
            return;
        }
        BPlusNode parent = node.getParent();
        int index = parent.getKeyIndex(node.getKey(0));
        BPlusNode left = (index == 0) ? null : parent.getChild(index - 1);
        BPlusNode right = (index == parent.getKeySize()) ? null : parent.getChild(index + 1);
        if (left != null && left.getKeySize() > minKeys) {
            node.insert(parent.getKey(index - 1), parent.getValue(index - 1));
            parent.insert(left.getKey(left.getKeySize() - 1), left.getValue(left.getKeySize() - 1));
            left.delete(left.getKey(left.getKeySize() - 1));
            if (!node.isLeaf()) {
                node.setChild(left.getChild(left.getKeySize()), node.getKeySize());
                left.setChild(null, left.getKeySize());
            }
        } else if (right != null && right.getKeySize() > minKeys) {
            node.insert(parent.getKey(index), parent.getValue(index));
            parent.insert(right.getKey(0), right.getValue(0));
            right.delete(right.getKey(0));
            if (!node.isLeaf()) {
                node.setChild(right.getChild(0), node.getKeySize() + 1);
                right.setChild(null, 0);
            }
        } else {
            if (left != null) {
                node = left;
                index--;
            }
            node.insert(parent.getKey(index), parent.getValue(index));
            for (int i = 0; i < right.getKeySize(); i++) {
                node.insert(right.getKey(i), right.getValue(i));
            }
            if (!node.isLeaf()) {
                for (int i = 0; i <= right.getKeySize(); i++) {
                    node.setChild(right.getChild(i), node.getKeySize() + i);
                }
            }
            parent.delete(parent.getKey(index));
            parent.setChild(null, index + 1);
            if (parent.isUnderflow()) {
                merge(parent);
            }
        }
    }

    public void printTree() {
        Queue<BPlusNode> queue = new LinkedList<BPlusNode>();
        queue.offer(root);
        while (!queue.isEmpty()) {
            BPlusNode node = queue.poll();
            node.printNode();
            if (!node.isLeaf()) {
                for (int i = 0; i <= node.getKeySize(); i++) {
                    queue.offer(node.getChild(i));
                }
            }
        }
    }

    public void printLeaves() {
        BPlusNode node = leafHead;
        while (node != null) {
            node.printNode();
            node = node.getNext();
        }
    }

    public static void main(String[] args) {
        BPlusTree tree = new BPlusTree(3);
        tree.insert(1, 1);
        tree.insert(2, 2);
        tree.insert(3, 3);
        tree.insert(4, 4);
        tree.insert(5, 5);
        tree.insert(6, 6);
        tree.insert(7, 7);
        tree.insert(8, 8);
        tree.insert(9, 9);
        tree.insert(10, 10);
        tree.insert(11, 11);
        tree.insert(12, 12);
        tree.insert(13, 13);
        tree.insert(14, 14);
        tree.insert(15, 15);
        tree.insert(16, 16);
        tree.insert(17, 17);
        tree.insert(18, 18);
        tree.insert(19, 19);
        tree.insert(20, 20);
        tree.insert(21, 21);
        tree.insert(22, 22);
        tree.insert(23, 23);
        tree.insert(24, 24);
        tree.insert(25, 25);
        tree.insert(26, 26);
        tree.insert(27, 27);
        tree.insert(28, 28);
        tree.insert(29, 29);
        tree.insert(30, 30);
        tree.insert(31, 31);
        tree.insert(32, 32);
        tree.insert(33, 33);
        tree.insert(34, 34);
        tree.insert(35, 35);
        tree.insert(36, 36);
        tree.insert(37, 37);
        tree.insert(38, 38);
        tree.insert(39, 39);
        tree.insert(40, 40);
        tree.insert(41, 41);
        tree.insert(42, 42);
        tree.insert(43, 43);
        tree.insert(44, 44);
        tree.insert(45, 45);
        tree.insert(46, 46);
        tree.insert(47, 47);
        tree.insert(48, 48);
        tree.insert(49, 49);
        tree.insert(50, 50);
        tree.insert(51, 51);
        tree.insert(52, 52);
        tree.insert(53, 53);

        tree.printTree();
        System.out.println();
        tree.printLeaves();
    }
}