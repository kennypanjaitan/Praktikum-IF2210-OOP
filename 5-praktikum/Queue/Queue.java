import java.util.ArrayList;

public class Queue<T> {

  private ArrayList <T> data;

  private int lastElmIdx, size;

  private final static int DEFAULT_QUEUE_SIZE = 500;



//Instantiate dengan size default

  public Queue() {
    this.data = new ArrayList<T>(DEFAULT_QUEUE_SIZE);
    this.lastElmIdx = -1;
    this.size = DEFAULT_QUEUE_SIZE;
  }

//Instantiate dengan size = n

  public Queue(int n) 
  {
    this.data = new ArrayList<T>(n);
    this.lastElmIdx = -1;
    this.size = n;
  }

//Copy queue

  public Queue(final Queue <T> q)
  {
    this.data = q.data;
    this.lastElmIdx = q.lastElmIdx;
    this.size = q.size;
  }

  public void push(T t)
  {
    if (!this.isFull())
    {
      this.data.add(t);
      this.lastElmIdx = this.data.lastIndexOf(t);
    }
  }

  public T pop()
  {
    if (!this.isEmpty())
    {
      this.lastElmIdx--;
      return this.data.remove(0);
    }
    return null;
  }

  public boolean isEmpty()
  {
    return this.data.isEmpty();
  }

  public boolean isFull()
  {
    return this.lastElmIdx == (this.size - 1);
  }

  public static void main(String[] args) {
    Queue<Integer> q = new Queue<Integer>(5);
    for (int i = 0; i < q.size; i++)
    {
      q.push(i);
      System.out.println(q.isFull());
    }
    // Queue<Integer> r = new Queue<Integer>(q);
    for (int i = 0; i < q.size; i++)
    {
      System.out.println(q.pop());
      System.out.println(q.isEmpty());
    }

  }

}