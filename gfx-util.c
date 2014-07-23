/*
 * The MIT License (MIT)
 *
 * Copyright © 2014 faith0x7dc
 *
 * Permission to use, copy, modify, distribute, and sell this software and its
 * documentation for any purpose is hereby granted without fee, provided that
 * the above copyright notice appear in all copies and that both that copyright
 * notice and this permission notice appear in supporting documentation, and
 * that the name of the copyright holders not be used in advertising or
 * publicity pertaining to distribution of the software without specific,
 * written prior permission.  The copyright holders make no representations
 * about the suitability of this software for any purpose.  It is provided "as
 * is" without express or implied warranty.
 *
 * THE COPYRIGHT HOLDERS DISCLAIM ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
 * INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO
 * EVENT SHALL THE COPYRIGHT HOLDERS BE LIABLE FOR ANY SPECIAL, INDIRECT OR
 * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,
 * DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
 * OF THIS SOFTWARE.
 */

#include "gfx-util.h"

struct Graphics
{
	GLuint pos;
	GLuint col;
};

struct Graphics *GfxCreate(GLuint pos, GLuint col)
{
	struct Graphics *gfx;

	gfx = (struct Graphics *)malloc(sizeof *gfx);
	if (gfx) {
		gfx->pos = pos;
		gfx->col = col;
	}

	return gfx;
}

void GfxDestroy(struct Graphics *gfx)
{
	if (gfx)
		free(gfx);
}

void GfxDrawRectangle(struct Graphics *gfx, GLfloat x, GLfloat y, GLfloat w, GLfloat h, uint32_t color)
{
	if (!gfx)
		return;

	GLfloat r = ((color >> 16) & 0xff) / 255.0f;
	GLfloat g = ((color >>  8) & 0xff) / 255.0f;
	GLfloat b = ((color      ) & 0xff) / 255.0f;

	GLfloat colors[4][3] = {
		{ r, g, b },
		{ r, g, b },
		{ r, g, b },
		{ r, g, b }
	};

	GLfloat verts[4][2] = {
		{ x,	 y },
		{ x + w, y },
		{ x,	 y + h },
		{ x + w, y + h }
	};

	glVertexAttribPointer(gfx->pos, 2, GL_FLOAT, GL_FALSE, 0, verts);
	glVertexAttribPointer(gfx->col, 3, GL_FLOAT, GL_FALSE, 0, colors);
	glEnableVertexAttribArray(gfx->pos);
	glEnableVertexAttribArray(gfx->col);

	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

	glDisableVertexAttribArray(gfx->pos);
	glDisableVertexAttribArray(gfx->col);
}

