/**
 * Kompleks
 */
public class Kompleks {
    private static int n_kompleks = 0;
    private int real;
    private int imaginer;

    public Kompleks() {
        this.real = 0;
        this.imaginer = 0;
        n_kompleks++;
    }

    public Kompleks(int real, int imaginer) {
        this.real = real;
        this.imaginer = imaginer;
        n_kompleks++;
    }

    public int getReal() {
        return this.real;
    }

    public int getImaginer() {
        return this.imaginer;
    }

    public void setReal(int real) {
        this.real = real;
    }

    public void setImaginer(int imaginer) {
        this.imaginer = imaginer;
    }

    public Kompleks plus(Kompleks k) {
        return new Kompleks(this.real + k.real, this.imaginer + k.imaginer);
    }

    public Kompleks minus(Kompleks k) {
        return new Kompleks(this.real - k.real, this.imaginer - k.imaginer);
    }

    public Kompleks multiply(Kompleks k) {
        return new Kompleks(this.real * k.real - this.imaginer * k.imaginer, this.real * k.imaginer + this.imaginer * k.real);
    }

    public Kompleks multiply(int x) {
        return new Kompleks(this.real * x, this.imaginer * x);
    }

    public static int countKompleksInstance() {
        return n_kompleks;
    }

    public void print() 
    {
        if (this.real != 0) 
        {
            System.out.print(this.real);
        }
    
        if (this.imaginer > 0 && this.real != 0) 
        {
            System.out.print("+");
        }
    
        if (this.imaginer != 0) 
        {
            System.out.print(this.imaginer + "i");
        }
    
        if (this.real == 0 && this.imaginer == 0) 
        {
            System.out.print("0");
        }
    
        System.out.println();
    }
}