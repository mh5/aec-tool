/*
 * Copyright (C) M. Helmy Hemeda, 2015
 *
 * This file is part of aec-tool.
 * 
 * aec-tool is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * aec-tool is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with aec-tool.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef FILE_RENDER_H
#define FILE_RENDER_H

#include <string.h>

#include <Magick++.h>

using namespace Magick;

class c_render
{
	Image *p_image;

	int CHAR_WIDTH;
	int CHAR_HEIGHT;

	const int NUM_ROWS;
	const int NUM_COLS;

	const int VERTICAL_MARGIN;
	const int HORIZONTAL_MARGIN;

	char const *p_font_family;
	char const *p_font_bold;
	char const *p_font_italic;
	char const *p_font_bold_italic;

	int DESCENT;

public:
	int row;
	int col;
	Color bg;
	Color fg;
	bool bold;
	bool italic;
	DecorationType decoration;

	c_render(int num_rows, int num_cols,
		char const *p_font_family,
		char const *p_font_bold,
		char const *p_font_italic,
		char const *p_font_bold_italic,
		int font_size,
		Color bg, Color fg,
		int vertical_margin, int horizontal_margin);

	void put_str(char const *p_str);

	void write(char const *p_str);
};
#endif