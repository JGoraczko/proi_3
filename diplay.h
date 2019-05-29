//
// Created by jakub on 29.05.19.
//

#ifndef PROI_3_DIPLAY_H
#define PROI_3_DIPLAY_H




ostream& operator<<(ostream& strumien, Board p){
    strumien << "   ";
    for(int j = 0; j < p.getSize()[1]; ++j)
        strumien << char(j + 'A') << " ";
    strumien << endl;
    for(int i = 0; i < p.getSize()[0]; ++i)
    {
        strumien << i + 1 <<": ";
        for(int j = 0; j < p.getSize()[1]; ++j)
        {
            array<int, 2> pom;
            pom[0] = i;
            pom[1] = j;
            if(p.whoStands(pom))
                strumien << p.whoStands(pom)->getSymbol() << " ";
            else
                strumien << ". ";
        }
        strumien << endl;
    }
    strumien << endl;
    return strumien;
}
ostream& operator<<(ostream& strumien, Move r){
    strumien << r.getWho()->getSymbol() << " z " << char (r.getWho()->getPosition()[1] + 'A');
    strumien << r.getWho()->getPosition()[0] + 1 << " na ";
    strumien << char (r.getWhere()[1] + 'A') <<  r.getWhere()[0] + 1;
    return strumien;
}

#endif //PROI_3_DIPLAY_H
