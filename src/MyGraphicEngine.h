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
 

#ifndef __CPPTP3EXO3__MyGraphicEngine__
#define __CPPTP3EXO3__MyGraphicEngine__

#include <iostream>
#include "GraphicEngine.h"
#include "Morpion.h"

class MyGraphicEngine:public GraphicEngine {
    
    Morpion &m;
    
public:
    
    MyGraphicEngine(Morpion &m_);
    
    virtual void Draw();
};

#endif /* defined(__CPPTP3EXO3__MyGraphicEngine__) */
