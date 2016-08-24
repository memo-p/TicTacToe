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
 

#ifndef __CPPTP3EXO3__MyControlEngine__
#define __CPPTP3EXO3__MyControlEngine__

#include <iostream>

#include "ControlEngine.h"

#include "Morpion.h"


class MyControlEngine:public ControlEngine {
    
    Morpion &m;
    
public:
    
    MyControlEngine(Morpion &m_);
    
    virtual void MouseCallback(int button, int state, int x, int y);
};

#endif /* defined(__CPPTP3EXO3__MyControlEngine__) */
