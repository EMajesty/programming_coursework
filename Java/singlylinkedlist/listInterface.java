package singlylinkedlist;

public interface listInterface<E> {
    int size(); // return the number of elements in your list

    void addFirst(E data); // insert an element at the beginning of your list

    void addLast(E data); // insert an element at the end of your list

    E removeFirst(); // return and remove the first element

    E removeLast(); // return and remove the last element

    E getFirst(); // return the first element (but don't remove it)

    E getLast(); // return the last element (but don't remove it)
}
