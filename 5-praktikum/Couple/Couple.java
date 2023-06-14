class Couple<K, V> {

    private K key;
    private V value;

    public Couple (K key, V value)
    {
        this.key = key;
        this.value = value;
    }

    public K getKey()
    {
        return this.key;
    }

    public V getVal()
    {
        return this.value;
    }

    public void setKey(K newK)
    {
        this.key = newK;
    }

    public void setVal(V newV)
    {
        this.value = newV;
    }

    public boolean isEqual(Couple<K, V> C)
    {
        return C.getKey() == this.key && C.getVal() == this.value;
    }

    public int nearEQ(Couple<K, V> couple)
    {
        if (this.isEqual(couple))
        {
            return 3;
        }
        else
        {
            if (this.key == couple.getKey())
            {
                return 1;
            }
            else if (this.value == couple.getVal())
            {
                return 2;
            }
            else
            {
                return 0;
            }
        }
    }
}
