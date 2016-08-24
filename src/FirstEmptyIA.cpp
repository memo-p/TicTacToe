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
 

#include "FirstEmptyIA.h"

FirstEmptyIA::FirstEmptyIA(int couleur_):IA(couleur_){}

int * FirstEmptyIA::play(std::vector<int> * gameState){
    int * retour = new int[2];
    int plc = -1;
    for (int i=0; i < gameState->size(); i++) {
        if ((*gameState)[i] == VIDE) {
            plc = i;
        }
    }
    retour[0] = plc / size;
    retour[1] = plc % size;
    
    return retour;
}