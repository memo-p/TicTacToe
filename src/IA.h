/*
 * Copyright (C) 2016 Guillaume Perez
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; If not, see <http://www.gnu.org/licenses/>.
*/
 

#ifndef CPPTP3EXO3_IA_h
#define CPPTP3EXO3_IA_h

#include <iostream>
#include "Case.h"

class IA {
    
public:
    
    int couleur;
    
    IA(int couleur_):couleur(couleur_){}
    
    virtual int * play(std::vector<int> * gameState) = 0;
    
    virtual void setSize(int size_) = 0;
    virtual void setVictorySize(int victorySize_) = 0;
    virtual void joue(std::vector<int> * gameState,int x,int y){}
    
};



#endif
