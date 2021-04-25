#include <bits/stdc++.h>
#include <cstring>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

struct Tranzitie {
    int x, y;
    char c;
};

struct Stare {
    vector<Tranzitie> tranzitii;
    bool eFinala;
};

Stare stari[101];
vector<int> drum;

bool DFA(char *cuvant, int stare_init)
{
    int p=0;
    int ok=0;
    drum.clear();
    while (p<strlen(cuvant))
    {
        ok =0;
        for (auto tranzitie:stari[stare_init].tranzitii)
        {
            if (tranzitie.c == cuvant[p])
            {
                ok = 1;
                p++;
                drum.push_back(stare_init);
                stare_init = tranzitie.y;
                break;
            }

        }
        if(ok == 0)
            return 0;
    }
    if(stari[stare_init].eFinala == 1)
    {
        drum.push_back(stare_init);
        return 1;
    }
    return 0;
}

int main()
{
    int nr_stari, nr_tranzitii, nr_stari_finale, stare_init, nr_cuv;
    fin >> nr_stari >> nr_tranzitii;
    for (int i=1; i <= nr_tranzitii; i++)
    {
        int tranzitie_x,tranzitie_y;
        char tranzitie_c;
        fin >> tranzitie_x >> tranzitie_y >> tranzitie_c;
        Tranzitie T;
        T.x = tranzitie_x;
        T.y = tranzitie_y;
        T.c = tranzitie_c;
        stari[T.x].tranzitii.push_back(T);
    }



    fin >> stare_init ;
    fin >> nr_stari_finale;
    for (int i=0; i< nr_stari_finale; i++)
    {
        int str;
        fin >> str;
        stari[str].eFinala = 1;
    }
    fin >> nr_cuv;
    for (int i=0; i< nr_cuv; i++)
    {

        char cuv[101];
        fin >> cuv;
        if (DFA(cuv, stare_init) == 1)
        {
            fout<<"DA"<<'\n';
            for (int j = 0; j < drum.size(); j++)
            {
                fout << drum[j] << " ";
            }
            fout<<'\n';
        }
        else
            {
            fout<<"NU\n";
        }

    }
    return 0;
}
