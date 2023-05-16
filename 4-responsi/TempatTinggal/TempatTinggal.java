class TempatTinggal 
{
    private int luas;
    private double hargaBahanBangunan;
    
    public void setLuas(int luas){
        this.luas = luas;
    }

    public int getLuas(){
        return luas;
    }

    public void setHargaBahanBangunan(double hargaBahanBangunan){
        this.hargaBahanBangunan = hargaBahanBangunan;
    }

    public double getHargaBahanBangunan(){
        return hargaBahanBangunan;
    }

    public double hitungBiayaBangun(){
        return luas * hargaBahanBangunan;
    }
}

class Rumah extends TempatTinggal
{
    public Rumah(int luas, double hargaBahanBangunan)
    {
        super();
        this.setLuas(luas);
        this.setHargaBahanBangunan(hargaBahanBangunan);
    }

    public Rumah(int lebar, int panjang, double hargaBahanBangunan)
    {
        super();
        this.setLuas(lebar * panjang);
        this.setHargaBahanBangunan(hargaBahanBangunan);
    }

    public void setLuas(int lebar, int panjang)
    {
        super.setLuas(lebar * panjang);
    }

    public double hitungBiayaBangun(double biayaOrmas)
    {
        return hitungBiayaBangun() + biayaOrmas;
    }
}

interface Kendaraan
{
    double hitungJarakTempuh();
}

class Karavan extends Rumah implements Kendaraan
{
    private float bensin;
    private float pemakaianBensin;

    public Karavan()
    {
        super(0,0);
        this.setBensin(0);
        this.setPemakaianBensin(0);
    }

    public void setBensin(float bensin)
    {
        this.bensin = bensin;
    }

    public float getBensin()
    {
        return bensin;
    }

    public void setPemakaianBensin(float pemakaianBensin)
    {
        this.pemakaianBensin = pemakaianBensin;
    }

    public float getPemakaianBensin()
    {
        return pemakaianBensin;
    }

    public double hitungBiayaBangun()
    {
        return super.hitungBiayaBangun() * 3;
    }

    public double hitungJarakTempuh()
    {
        return bensin*pemakaianBensin;
    }
}


