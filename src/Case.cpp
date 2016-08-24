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
 
#include "Case.h"

Case::Case(int x_,int y_,int size):
    value(VIDE),
    x(x_*(2.0f/size)-1.0f),
    y(y_*(2.0f/size)-1.0f),
    width(2.0f/size),
    height(2.0f/size)
    {}

void Case::setValue(int newValue){
    value = newValue;
}
int Case::getValue(){
    return value;
}


void Case::draw(){
    GraphicPrimitives::drawFillRect2D(x, y, width, height, 1.0f, 1.0f, 1.0f);
    GraphicPrimitives::drawOutlinedRect2D(x, y, width, height, 0.0f, 0.0f, 0.0f);
    if (value == CROIX) {
        GraphicPrimitives::drawLine2D(x, y, x+width, y+height, 0.0f, 0.0f, 0.0f);
        GraphicPrimitives::drawLine2D(x+width, y, x, y+height, 0.0f, 0.0f, 0.0f);
    }else if (value == CROIXWIN) {
        GraphicPrimitives::drawLine2D(x, y, x+width, y+height, 1.0f, 0.0f, 0.0f);
        GraphicPrimitives::drawLine2D(x+width, y, x, y+height, 1.0f, 0.0f, 0.0f);
    }else if (value == ROND){
        GraphicPrimitives::drawOutlinedRect2D(x+width/4, y+height/4, width/2, height/2, 0.0f, 0.0f, 0.0f);
    }else if (value == RONDWIN){
        GraphicPrimitives::drawOutlinedRect2D(x+width/4, y+height/4, width/2, height/2, 1.0f, 0.0f, 0.0f);
    }
}