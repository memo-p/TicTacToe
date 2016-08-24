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
 
#ifndef __CPPTP3EXO3__Morpion__
#define __CPPTP3EXO3__Morpion__

#include <iostream>
#include "Case.h"
#include "IA.h"
#include "Stopwatch.h"


class Morpion {
    
    std::vector<std::vector<Case> > cases;
    int GameState;
    bool fini;
    int nbActivated;
    
    IA* players[2];
    bool IAPlaying;
    int * coup;
    Stopwatch s;
    
    int size;
    int victorySize;
    
public:
    Morpion(IA* p1,IA* p2,int size_ = 3, int victorySize_ = 3);
    
    void joue(int x,int y);
    
    void draw();
    
    void testFin(int x,int y);
    
    void finGagnante(std::vector<int> &x,std::vector<int>&y);
    void finEgal();
    void restart();
    
    std::vector<int>* getState();
    
    void tick();
    
    int getSize();
    
    bool isIAPlaying();
};

#endif /* defined(__CPPTP3EXO3__Morpion__) */
