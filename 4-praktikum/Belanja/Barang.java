public class Barang {
    protected String Nama;
    protected int Amount;

    public Barang(String Nama, int Amount) {
        this.Nama = Nama;
        this.Amount = Amount;
    }

    @Override
    public String toString() {
        return String.valueOf(Amount) + ' ' + Nama;
    }

    public static void main(String[] args) {
        Barang x = new Barang("haha", 5);
        System.out.println(x.toString());

        DaftarBelanja list = new DaftarBelanja(3);
        list.belanja("haha", 5);
        list.belanja(2, "haha");
        list.belanja(2, 2, "haha");
        list.belanja("haha");
        list.belanja("haha");
        list.belanja(3, "haha lmaolmao jeand, daihdiah");
        list.belanja(4, "haha");
        list.print();
    }
}
