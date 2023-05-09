#include <iostream>
#include "sekretaris.h"

using namespace std;

Sekretaris::Sekretaris() 
{
    this->energi = ENERGI_MAX;
    this->tinta = KERTAS_DEFAULT;
    this->kertas = TINTA_DEFAULT;
    this->memoLength = 0;
    this->memo = new Memo[100];
}

Sekretaris::Sekretaris(int kertas, int tinta) 
{
    this->energi = ENERGI_MAX;
    this->tinta = tinta;
    this->kertas = kertas;
    this->memoLength = 0;
    this->memo = new Memo[100];
}

Sekretaris::~Sekretaris() 
{
    delete [] memo;
}

void Sekretaris::buatMemo(string pesan, string untuk) 
{
    try 
    {
		Memo temp(pesan, untuk);
		memo[memoLength] = temp;
		pakaiKertas();
		pakaiTinta(pesan.length());
		pakaiEnergi();
		memoLength++;
		cout << "Memo [" << memoLength << "] untuk " << untuk << " berhasil dibuat" << endl;
	} 
	catch (KertasHabisException e) 
    {
		cout << e.what() << ", segera isi kertas" << endl; 
	}
	catch (TintaKurangException e) 
    {
		batalPakaiKertas();
		cout << e.what() << ", segera isi tinta" << endl;
	} 
	catch (EnergiHabisException e) 
    {
		batalPakaiKertas();
		batalPakaiTinta(pesan.length());
		cout << e.what() << ", segera istirahat" << endl;
	}
}

void Sekretaris::pakaiKertas() 
{
    if (kertas == 0) 
    {
        throw KertasHabisException();
    }
    kertas--;
}

void Sekretaris::pakaiTinta(int jumlah) 
{
    if (tinta < jumlah) 
    {
        throw TintaKurangException();
    }
    tinta -= jumlah;
}

void Sekretaris::pakaiEnergi() 
{
    if (energi == 0) 
    {
        throw EnergiHabisException();
    }
    energi--;
}

void Sekretaris::batalPakaiKertas() 
{
    kertas++;
}

void Sekretaris::batalPakaiTinta(int jumlah) 
{
    tinta += jumlah;
}

void Sekretaris::batalPakaiEnergi() 
{
    energi++;
}

void Sekretaris::isiKertas(int jumlah) 
{
    kertas += jumlah;
}

void Sekretaris::isiTinta(int jumlah) 
{
    tinta += jumlah;
}

void Sekretaris::istirahat() 
{
    energi = ENERGI_MAX;
}

void Sekretaris::printStatus() 
{
    cout << "Status" << endl;
    cout << "  Energi : " << energi << endl;
    cout << "  Tinta : " << tinta << endl;
    cout << "  Kertas : " << kertas << endl;
    cout << "  Memo : " << memoLength << endl;
    
    for (int i = 0; i < memoLength; i++) 
    {
        cout << "    Memo [" << i + 1 << "]" << endl;
        cout << "      Pesan : " << memo[i].getPesan() << endl;
        cout << "      Untuk : " << memo[i].getUntuk() << endl;
    }
}