class MyQueue {
    Stack<Integer> input;
    Stack<Integer> output;

    public MyQueue() {
        input = new Stack<>();
        output = new Stack<>();
    }

    public void push(int x) {
        // only push the new item when the order is maintained as precondition to push
        while (!output.isEmpty()) {
            input.push(output.pop());
        }
        input.push(x);
    }

    public int pop() {
        // all contents of input -> output as a precondition to pop
        while (!input.isEmpty()) {
            output.push(input.pop());
        }

        return output.pop();
    }

    public int peek() {
        // all contents of input -> output as a precondition to pop
        while (!input.isEmpty()) {
            output.push(input.pop());
        }

        return output.peek();
    }

    public boolean empty() {
        return input.isEmpty() && output.isEmpty();
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */