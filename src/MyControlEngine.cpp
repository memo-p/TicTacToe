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
 
#include "MyControlEngine.h"


MyControlEngine::MyControlEngine(Morpion &m_):m(m_){}

void MyControlEngine::MouseCallback(int button, int state, int x, int y){
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (!m.isIAPlaying()) {
            int divX = 600 / m.getSize();
            int divY = 600 / m.getSize();
            int Xindex = x / divX;
            int Yindex = m.getSize() -1 - y / divY;
            m.joue(Xindex, Yindex);
        }
        
    }
}