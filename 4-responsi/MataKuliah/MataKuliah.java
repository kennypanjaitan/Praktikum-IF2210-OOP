import java.lang.Comparable;

class MataKuliah implements Comparable<MataKuliah>
{
    // VARIABLE
    private String nama;
    private int kodeJurusan;
    private int tahunPengambilan;
    private float rating;

    // CONSTRUCTOR
    public MataKuliah(String nama, int kodeJurusan, int tahunPengambilan, float rating){
        this.nama = nama;
        this.kodeJurusan = kodeJurusan;
        this.tahunPengambilan = tahunPengambilan;
        this.rating = rating;
    }

    // GETTER
    public String getNama()
    {
        return nama;
    }

    public int getKodeJurusan()
    {
        return kodeJurusan;
    }

    public int getTahunPengambilan()
    {
        return tahunPengambilan;
    }

    public float getRating()
    {
        return rating;
    }

    // METHOD
    public int compareTo(MataKuliah m)
    {
        if (this.kodeJurusan < m.kodeJurusan)
        {
            return -1;
        }
        else if (this.kodeJurusan > m.kodeJurusan)
        {
            return 1;
        }
        else
        {
            if (this.tahunPengambilan < m.tahunPengambilan)
            {
                return -1;
            }
            else if (this.tahunPengambilan > m.tahunPengambilan)
            {
                return 1;
            }
            else
            {
                if (this.rating < m.rating)
                {
                    return -1;
                }
                else if (this.rating > m.rating)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
        }
    }
}
