import java.util.Objects;

public class DaftarBelanja{
    private Barang[] listBelanja;
    private int counter;

    public DaftarBelanja(int Max) {
        listBelanja = new Barang[Max];
        counter = 0;
    }

    public Barang[] getList() {
        return listBelanja;
    }
    
    public int getCounter() {
        return counter;
    }

    public void belanja(int lorong, String keterangan) {
        if (counter == 0) {
            Barang newBarang = new Barang(keterangan + " (lorong " + lorong + ")", 1);
            listBelanja[0] = newBarang;
        }
        else {
            Boolean flag = false;
            for (int i = 0; i < counter; i++) {
                if (Objects.equals(listBelanja[i].Nama, keterangan + " (lorong " + lorong + ")")) {
                    listBelanja[i].Amount++;
                    flag = true;
                    break;
                }
            }
    
            if (!flag && counter < listBelanja.length) {
                Barang newBarang = new Barang(keterangan + " (lorong " + lorong + ")", 1);
                listBelanja[counter] = newBarang;
            } else { return; }
        }

        counter++;
    }

    public void belanja(int lorong, int qty,  String keterangan) {
        if (counter == 0) {
            Barang newBarang = new Barang(keterangan + " (lorong " + lorong + ")", qty);
            listBelanja[0] = newBarang;
        }
        else {
            Boolean flag = false;
            for (int i = 0; i < counter; i++) {
                if (Objects.equals(listBelanja[i].Nama, (keterangan + " (lorong " + lorong + ")"))) {
                    listBelanja[i].Amount += qty;
                    flag = true;
                    break;
                }
            }
    
            if (!flag && counter < listBelanja.length) {
                Barang newBarang = new Barang(keterangan + " (lorong " + lorong + ")", qty);
                listBelanja[counter] = newBarang;
            } else { return; } 
        }

        counter++;
    }

    public void belanja(String barang) {
        if (counter == 0) {
            Barang newBarang = new Barang(barang, 1);
            listBelanja[0] = newBarang;
        }
        else {
            Boolean flag = false;
            for (int i = 0; i < counter; i++) {
                if (Objects.equals(listBelanja[i].Nama, barang)) {
                    listBelanja[i].Amount++;
                    flag = true;
                    break;
                }
            }
    
            if (!flag && counter < listBelanja.length) {
                Barang newBarang = new Barang(barang, 1);
                listBelanja[counter] = newBarang;
            } else { return; }
        }

        counter++;
    }

    public void belanja(String barang, int qty) {
        if (counter == 0) {
            Barang newBarang = new Barang(barang, qty);
            listBelanja[0] = newBarang;
        }
        else {
            Boolean flag = false;
            for (int i = 0; i < counter; i++) {
                if (Objects.equals(listBelanja[i].Nama, barang)) {
                    listBelanja[i].Amount += qty;
                    flag = true;
                    break;
                }
            }
            if (!flag && counter < listBelanja.length) {
                Barang newBarang = new Barang(barang, qty);
                listBelanja[counter] = newBarang;
            } else { return; }
        }

        counter++;
    }

    public void print() {
        for (int i = 1; i <= counter; i++) {
            System.out.println(i + ". " + listBelanja[i-1].toString());
        }
    }
}
