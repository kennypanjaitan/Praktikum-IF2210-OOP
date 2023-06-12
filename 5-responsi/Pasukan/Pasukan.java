import java.util.List;

public class Pasukan <T extends List<Integer>> {
    private T list;
    private int n;

    public Pasukan(T list, int n) {
        this.list = list;
        this.n = n;
    }

    public void reset() {
        list.clear();
        for (int i = 0; i < n; i++) {
            list.add(0);
        }
    }

    public long get(int idx) {
        reset();
        long start = Util.getTime();
        int val = list.get(idx);
        long finish = Util.getTime();
        return finish - start;
    }

    public long del(int idx, int t) {
        reset();
        long start = Util.getTime();
        for (int i = t - 1; i >= 0; i--) {
            list.remove(idx);
        }
        long finish = Util.getTime();
        return finish - start;
    }
}
