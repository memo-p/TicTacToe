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
 
#include <iostream>
#include "Engine.h"
#include "Case.h"
#include "MyGraphicEngine.h"
#include "MyControlEngine.h"
#include "FirstEmptyIA.h"
#include "MyGameEngine.h"


int main(int argc, char * argv[])
{
    
    
    Engine e(argc, argv,600,600);
    
    Morpion m(new FirstEmptyIA(CROIX),nullptr, 3, 3);
    
    MyGraphicEngine ge(m);
    MyControlEngine ce(m);
    MyGameEngine gme(m);
    
    e.setControlEngine(&ce);
    e.setGraphicEngine(&ge);
    e.setGameEngine(&gme);
    e.start();
    return 0;
}

