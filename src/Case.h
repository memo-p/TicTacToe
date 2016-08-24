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
 

#ifndef __CPPTP3EXO3__Case__
#define __CPPTP3EXO3__Case__

#include <iostream>
#include "GraphicPrimitives.h"

#define VIDE 0
#define CROIX 1
#define CROIXWIN 2
#define ROND 3
#define RONDWIN 4

class Case {
    int value;
    float x,y,width,height;
public:
    Case(int x_,int y_,int size);
    
    void setValue(int newValue);
    int getValue();
    void draw();
};


#endif /* defined(__CPPTP3EXO3__Case__) */
