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
 

#include "Morpion.h"

Morpion::Morpion(IA* p1,IA* p2,int size_, int victorySize_):
    GameState(CROIX),
    size(size_),
    victorySize(victorySize_),
    fini(false),
    nbActivated(0),
    IAPlaying(false){
    players[0] = p1;
    players[1] = p2;
    for (int i=0; i < size; i++) {
        cases.emplace_back();
        for (int j = 0; j < size; j++) {
            cases[i].emplace_back(i,j,size);
        }
    }
        if (players[0] != nullptr) {
            players[0]->setSize(size);
            players[0]->setVictorySize(victorySize);
        }
        if (players[1] != nullptr) {
            players[1]->setSize(size);
            players[1]->setVictorySize(victorySize);
        }
}

void Morpion::joue(int x,int y){
    if (!fini) {
        if (cases[x][y].getValue() == VIDE) {
            cases[x][y].setValue(GameState);
            if (GameState == CROIX) {
                GameState = ROND;
            }else{
                GameState = CROIX;
            }
            
            //test de fin de partie.
            nbActivated++;
            testFin(x,y);
            std::vector<int>* state = getState();
            if (players[0] != nullptr) {
                players[0]->joue(state,x,y);
            }
            if (players[1] != nullptr) {
                players[1]->joue(state,x,y);
            }
            
        }
    }else{
        restart();
    }
    
}

void Morpion::draw(){
    for (int i = 0; i < cases.size(); i++) {
        for (int j = 0; j < cases[i].size(); j++) {
            cases[i][j].draw();
        }
    }
    if (fini) {
        GraphicPrimitives::drawText2D("Partie finie", 0.f, 0.f, 0.f, 0.f, 0.f);
    }
}

//x,y sont les coordonnée du dernier point coché
void Morpion::testFin(int x,int y){
    
    //pour les dessiner
    std::vector<int> winX;
    std::vector<int> winY;
    
    int value = cases[x][y].getValue();
    
    //test Horizontal:
    int nbCons = 1; //celui sur lequel on est :)
    int tmpX = x-1;
    int tmpY = y;
    while (tmpX >= 0 && cases[tmpX][tmpY].getValue() == value) {
        winX.push_back(tmpX);
        winY.push_back(tmpY);
        nbCons++;
        tmpX--;
    }
    
    tmpX = x+1;
    tmpY = y;
    while (tmpX < size && cases[tmpX][tmpY].getValue() == value) {
        winX.push_back(tmpX);
        winY.push_back(tmpY);
        nbCons++;
        tmpX++;
    }
    
    if (nbCons >= victorySize) {
        winX.push_back(x);
        winY.push_back(y);
        finGagnante(winX, winY);
        return;
    }
    winX.clear();
    winY.clear();
    
    //test verticale:
    nbCons = 1; //celui sur lequel on est :)
    tmpX = x;
    tmpY = y-1;
    while (tmpY >= 0 && cases[tmpX][tmpY].getValue() == value) {
        winX.push_back(tmpX);
        winY.push_back(tmpY);
        nbCons++;
        tmpY--;
    }
    
    tmpX = x;
    tmpY = y+1;
    while (tmpY < size && cases[tmpX][tmpY].getValue() == value) {
        winX.push_back(tmpX);
        winY.push_back(tmpY);
        nbCons++;
        tmpY++;
    }
    if (nbCons >= victorySize) {
        winX.push_back(x);
        winY.push_back(y);
        finGagnante(winX, winY);
        return;
    }
    winX.clear();
    winY.clear();
    
    //test diag1:
    nbCons = 1; //celui sur lequel on est :)
    tmpX = x-1;
    tmpY = y-1;
    while (tmpY >= 0 && tmpX >= 0 && cases[tmpX][tmpY].getValue() == value) {
        winX.push_back(tmpX);
        winY.push_back(tmpY);
        nbCons++;
        tmpY--;
        tmpX--;
    }
    
    tmpX = x+1;
    tmpY = y+1;
    while (tmpY < size && tmpX < size && cases[tmpX][tmpY].getValue() == value) {
        winX.push_back(tmpX);
        winY.push_back(tmpY);
        nbCons++;
        tmpY++;
        tmpX++;
    }
    if (nbCons >= victorySize) {
        winX.push_back(x);
        winY.push_back(y);
        finGagnante(winX, winY);
        return;
    }
    winX.clear();
    winY.clear();
    
    //test diag1:
    nbCons = 1; //celui sur lequel on est :)
    tmpX = x+1;
    tmpY = y-1;
    while (tmpY >= 0 && tmpX < size && cases[tmpX][tmpY].getValue() == value) {
        winX.push_back(tmpX);
        winY.push_back(tmpY);
        nbCons++;
        tmpY--;
        tmpX++;
    }
    
    tmpX = x-1;
    tmpY = y+1;
    while (tmpY < size && tmpX >= 0 && cases[tmpX][tmpY].getValue() == value) {
        winX.push_back(tmpX);
        winY.push_back(tmpY);
        nbCons++;
        tmpY++;
        tmpX--;
    }
    if (nbCons >= victorySize) {
        winX.push_back(x);
        winY.push_back(y);
        finGagnante(winX, winY);
        return;
    }
    winX.clear();
    winY.clear();
    
    if (nbActivated == cases.size() * cases[0].size()) {
        finEgal();
    }
    
}

void  Morpion::finGagnante(std::vector<int> &x,std::vector<int>&y){
    for (int i=0; i < x.size(); i++) {
        cases[x[i]][y[i]].setValue(cases[x[i]][y[i]].getValue() +1);
    }
    fini = true;
    
}
void  Morpion::finEgal(){
    fini = true;
}

void Morpion::restart(){
    for (int i = 0; i < cases.size(); i++) {
        for (int j = 0; j < cases[i].size(); j++) {
            cases[i][j].setValue(VIDE);
            fini = false;
            GameState = CROIX;
            nbActivated = 0;
        }
    }
}

std::vector<int>* Morpion::getState(){
    std::vector<int>* retour = new std::vector<int>;
    for (int i = 0; i < cases.size(); i++) {
        for (int j = 0; j < cases[i].size(); j++) {
            retour->push_back(cases[i][j].getValue());
        }
    }
    retour->push_back(GameState);
    return retour;
}

void Morpion::tick(){
    if (!fini) {
        if (!IAPlaying && players[nbActivated%2] != nullptr) {
            s.start();
            IAPlaying = true;
            std::vector<int>* state = getState();
            coup = players[nbActivated%2]->play(state);
            delete state;
//            std::cout << coup[0]<< " " << coup[1]<<"a\n";
        }
    }
    if (IAPlaying) {
        s.stop();
        if (s.elapsed_ms() > 500) {
            joue(coup[0], coup[1]);
            IAPlaying = false;
        }
    }
}


int Morpion::getSize(){
    return size;
}

bool Morpion::isIAPlaying(){
    return IAPlaying;
}






