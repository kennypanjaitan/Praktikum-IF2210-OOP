/**
 * Gajah.java
 * [Jelaskan kegunaan class ini]
 * @author 13521023 Kenny Benaya Nathan
 */

 public class Gajah extends Animal {
    private int basePower;
    private int age;

    public Gajah(int basePower, int age) {
        this.basePower = basePower;
        this.age = age;
        this.numberOfLegs = 4;
    }

    public int getAge() {
        return age;
    }

    @Override
    public int getAnimalPower() {
        return 3 * (basePower + age + children);
    }
 }
 