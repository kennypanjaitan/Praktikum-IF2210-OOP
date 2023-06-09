/**
 * Animal.java
 * [Jelaskan kegunaan class ini]
 * @author 13521023 Kenny Benaya Nathan
 */

public abstract class Animal implements Comparable<Animal> {
    protected int numberOfLegs;
    protected int children = 0;

    public int getNumberOfLegs() {
        return numberOfLegs;
    }

    public int getNumberOfChildren() {
        return children;
    }

    public void increaseChild(int inc) {
        children += inc;
    }

    abstract public int getAnimalPower();

    public int compareTo(Animal a) {
        // compareTo mengembalikan:
        // 0 bila this sama dengan m
        // 1 bila this lebih dari m
        // -1 bila this kurang dari m
        
        if (this.getAnimalPower() == a.getAnimalPower()) {
            return 0;
        }
        else if (this.getAnimalPower() > a.getAnimalPower()) {
            return 1;
        }
        else {
            return -1;
        }

    }

    public static void main(String[] args) {
        Gajah gajah = new Gajah(10, 5);
        Elang elang = new Elang(10);

        gajah.increaseChild(2);
        System.out.println(gajah.getNumberOfChildren());
        System.out.println(gajah.getNumberOfLegs());
        System.out.println(gajah.getAnimalPower());

        elang.increaseChild(2);
        elang.bertelur();
        System.out.println(elang.getNumberOfChildren());
        System.out.println(elang.getJumlahTelur());
        System.out.println(elang.getNumberOfLegs());
        System.out.println(elang.getAnimalPower());
    }
}

