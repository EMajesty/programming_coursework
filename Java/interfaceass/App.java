/*
 *  Lassi Laitinen 2020
 */

public class App {

    interface IntStack {
        void push(int item);
        int pop();
    }
    interface OpenStack extends IntStack {
        int ReadItem();
    }
    static class FixedStack implements OpenStack {
        private int stack[];
        private int pos;

        FixedStack(int size) {
            stack = new int[size];
            pos = -1;
        }

        @Override
        public void push(int item) {
            if(pos==stack.length-1) {
                System.out.println("Stack is full");
            } else {
                stack[++pos] = item;
            }

        }

        @Override
        public int pop() {
            if(pos < 0) {
                System.out.println("Stack underflow");
                return 0;
            } else {
                return stack[pos--];
            }
        }

        @Override
        public int ReadItem() {
            return stack[pos];
        }
    
        
    }
    public static void main(String[] args) throws Exception {
        OpenStack stack = new FixedStack(9);

        stack.push(3);
        stack.push(2);
        stack.push(123);
        stack.push(355);

        System.out.println(stack.pop());

        System.out.println(stack.ReadItem());
    }
}
