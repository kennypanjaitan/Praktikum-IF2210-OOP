/**
 * Elang.java
 * [Jelaskan kegunaan class ini]
 * @author 13521023 Kenny Benaya Nathan
 */

 public class Elang extends Animal {
    private int basePower;
    private int jumlahTelur;

    public Elang(int basePower) {
        this.basePower = basePower;
        this.jumlahTelur = 0;
        this.numberOfLegs = 2;
    }

    public int getJumlahTelur() {
        return jumlahTelur;
    }

    public void bertelur() {
        jumlahTelur++;
    }

    @Override
    public int getAnimalPower() {
        return basePower * children - jumlahTelur;
    }
 }
 