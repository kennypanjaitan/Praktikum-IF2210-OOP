public class CreditCard implements IPaymentMethod {
    public static final double defaultLimit = 2500;
    public static final double defaultInterest = 0.0005;

    private double monthlyBalance;
    private double monthlyLimit;
    private double unpaidBalance;
    private double dailyInterest;

    // TODO
    // Default constructor, inisialisasi monthlyBalance dan unpaidBalance menjadi 0
    // Inisialisasi monthlyLimit dan dailyInterest menjadi defaultLimit dan defaultInterest
    public CreditCard() {
        monthlyBalance = 0;
        unpaidBalance = 0;
        monthlyLimit = defaultLimit;
        dailyInterest = defaultInterest;
    }

    // TODO
    // inisialisasi monthlyBalance dan unpaidBalance menjadi 0
    // Inisialisasi monthlyLimit dan dailyInterest sesuai parameter
    public CreditCard(double limit, double interest) {
        monthlyBalance = 0;
        unpaidBalance = 0;
        monthlyLimit = limit;
        dailyInterest = interest;  
    }

    // TODO
    // Getter
    public double getMonthlyBalance() {
        return monthlyBalance;
    }
    public double getMonthlyLimit() {
        return monthlyLimit;
    }
    public double getUnpaidBalance() {
        return unpaidBalance;
    }
    public double getDailyInterest() {
        return dailyInterest;
    }

    // TODO
    // Memindahkan monthlyBalance ke unpaidBalance
    // I.S. sembarang
    // F.S.
    // unpaidBalance = unpaidBalance awal + monthlyBalance awal
    // monthlyBalance = 0
    public void endBillingCycle() {
        unpaidBalance += monthlyBalance;
        monthlyBalance = 0;
    }

    // TODO
    // Menerapkan dailyInterest terhadap unpaidBalance
    // I.S. sembarang
    // F.S. unpaidBalance = unpaidBalance + unpaidBalance * dailyInterest
    public void applyInterest() {
        unpaidBalance += (unpaidBalance * dailyInterest);
    }

    // TODO
    // Melakukan pembayaran dengan kartu kredit
    // Apabila monthlyBalance + price melebihi monthlyLimit, 
    // mengembalikan false dan semua atribut sesuai kondisi awal
    // Apabila tidak melebihi monthlyLimit, price ditambahkan ke monthlyBalance dan mengembalikan true
    @Override
    public boolean pay(double price) {
        if ((monthlyBalance + price) > monthlyLimit) {
            return false;
        }
        else {
            monthlyBalance += price;
            return true;
        }
    }

    // TODO
    // Mencicil/melunaskan kartu kredit
    // Apabila amount melebih monthlyBalance + unpaidBalance, mengembalikan false dan
    // semua atribut sesuai kondisi awal
    // Apabila amount tidak melebihi monthlyBalance + unpaidBalance,
    // melunaskan monthlyBalance terlebih dahulu kemudian unpaidBalance
    // Contoh:
    // I.S.
    // monthlyBalance = 50
    // unpaidBalance = 50

    // payOffBalance(49)

    // F.S.
    // monthlyBalance = 1
    // unpaidBalance = 50

    // I.S.
    // monthlyBalance = 50
    // unpaidBalance = 50

    // payOffBalance(75)

    // F.S.
    // monthlyBalance = 0
    // unpaidBalance = 25
    public boolean payOffBalance(double amount) {
        if (amount > (monthlyBalance + unpaidBalance)) {
            return false;
        }
        else {
            double remain;
            remain = amount - monthlyBalance;
            monthlyBalance -= amount;
            if (monthlyBalance < 0) {
                monthlyBalance = 0;
            }

            amount = remain;
            
            if (amount > 0) {
                unpaidBalance -= amount;
            }
            return true;
        }
    }

    // public static void main(String[] args) {
    //     CreditCard c = new CreditCard(10, 20);
    //     c.pay(10);
    //     c.applyInterest();
    //     c.endBillingCycle();
    //     c.pay(10);
    //     System.out.println(c.getMonthlyBalance());
    //     System.out.println(c.getUnpaidBalance());
    //     c.payOffBalance(21);
    //     System.out.println(c.getMonthlyBalance());
    //     System.out.println(c.getUnpaidBalance());
    // }
} 