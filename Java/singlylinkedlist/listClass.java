package singlylinkedlist;

public class listClass<E> implements listInterface<E> 
{

    class Node 
    {
        E data;
        Node next;

        public Node(E data) 
        {
            this.data = data;
            this.next = null;
        }
    }

    Node head;

    public listClass() 
    {
        
    };

    public int size()                           // return the number of elements in your list
    {
        int size = 0;
        Node curr = head;

        if(curr == null)
        {
            return size;
        }
        
        size++;

        while(curr.next != null)
        {
            size++;
            curr = curr.next;
        }
        return size;
    };

    public void addFirst(E data)                // insert an element at the beginning of your list
    {
        Node n = new Node(data);
        n.next = head;
        head = n;
    };

    public void addLast(E data)                 // insert an element at the end of your list
    {
        Node n = new Node(data);

        if (head == null) 
        {
            head = n;
        }
        else 
        {
            Node curr = head;
            while (curr.next != null) 
            {
                curr = curr.next;
            }
            curr.next = n;
        }
    };

    public E removeFirst()                      // return and remove the first element
    {
        if (head != null) 
        {
            Node toDelete = head;
            head = head.next;
            return toDelete.data;
        }
        return null;
    };

    public E removeLast()                       // return and remove the last element
    {
        Node curr = head;                       // assign first node to curr
        if (curr == null || curr.next == null)
        {                                       // if there is no first or second (next) node,
            head = null;                        // delete first node
            return curr.data;                   // return deleted data
        }
        Node nextNode = curr.next;              // assign second node to nextNode
        while (curr.next != null)
        {                                       // if the next node exists (always the first time)
            if (nextNode.next == null)
            {                                   // if next node of next node does not exist,
                curr.next = null;               // delete the next node
            }
            curr = nextNode;                    // go to next node
            nextNode = nextNode.next;           // go to next next node
        }
        return curr.data;                       // return deleted data
    };

    public E getFirst()                         // return the first element (but don't remove it)
    {
        if (head != null)
        {
            return head.data;
        }
        return null;
    };

    public E getLast()                          // return the last element (but don't remove it)
    {
        Node curr = head;                       // assign first node to curr
        if (curr == null)
        {
            return null;
        }
        else if(curr.next == null)
        {
            return curr.data;
        }
        Node nextNode = curr.next;              // assign second node to nextNode
        while (curr.next != null)               // if the next node exists (always the first time)
        {                                       
            if (nextNode.next == null)
            {                                   // if next node of next node does not exist,
                return curr.next.data;          // return the data of the next node
            }
            curr = nextNode;                    // go to next node
            nextNode = nextNode.next;           // go to next next node
        }
        return null;
    };
}
