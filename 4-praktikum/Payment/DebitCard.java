class DebitCard implements IPaymentMethod {
    private double balance;

    // TODO
    // Inisialisasi balance menjadi 0
    public DebitCard() {
        balance = 0;
    }

    // TODO
    // Getter
    public double getBalance() {
        return balance;
    }

    // TODO
    // Menambahkan amount ke balance
    // Mengembalikan true
    public boolean deposit(double amount) {
        balance += amount;
        return true;
    }

    // TODO
    // Mengurangi amount dari balance
    // Mengembalikan false apabila amount melebihi balance
    public boolean withdraw(double amount) {
        if (balance < amount) {
            return false;
        }
        else {
            balance -= amount;
            return true;
        }
    }
    // TODO
    // Mengurangi amount dari balance
    // Mengembalikan false apabila amount melebihi balance
    @Override
    public boolean pay(double price) {
        if (balance < price) {
            return false;
        }
        else {
            balance -= price;
            return true;
        }       
    }

    // public static void main(String[] args) {
    //     DebitCard dc = new DebitCard();
    //     System.out.println(dc.getBalance());
    //     dc.deposit(10);
    //     System.out.println(dc.getBalance());
    //     dc.withdraw(5);
    //     System.out.println(dc.getBalance());
    //     dc.pay(5);
    //     System.out.println(dc.getBalance());
    //     dc.deposit(1);
    //     System.out.println(dc.getBalance());
    //     dc.withdraw(2);
    //     System.out.println(dc.getBalance());
    //     dc.pay(2);
    //     System.out.println(dc.getBalance());
    // }
}