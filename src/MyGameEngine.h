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
 

#ifndef __CPPTP3EXO3__MyGameEngine__
#define __CPPTP3EXO3__MyGameEngine__

#include <iostream>
#include "GameEngine.h"
#include "Morpion.h"

class MyGameEngine:public GameEngine {
    Morpion &m;
    
public:
    MyGameEngine(Morpion &m_);
    virtual void idle() override;
};

#endif /* defined(__CPPTP3EXO3__MyGameEngine__) */
