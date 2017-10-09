/***************************************************************************
 *   Copyright (C) 2016 by Kyle Hayes                                      *
 *   Author Kyle Hayes  kyle.hayes@gmail.com                               *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU Library General Public License as       *
 *   published by the Free Software Foundation; either version 2 of the    *
 *   License, or (at your option) any later version.                       *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU Library General Public License for more details.                  *
 *                                                                         *
 *   You should have received a copy of the GNU Library General Public     *
 *   License along with this program; if not, write to the                 *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/


#ifndef __UTIL__REFCOUNT_H__
#define __UTIL__REFCOUNT_H__ 1

#include <platform.h>


#define rc_make_ref(data, cleanup_func) rc_make_ref_impl(__func__, __LINE__, data, cleanup_func)
extern void *rc_make_ref_impl(const char *func, int line_num, void *data, void (*cleanup_func)(void *));

#define rc_register_cleanup(ref, cleanup_func) rc_register_cleanup_impl(__func__, __LINE__, ref, cleanup_func)
extern int rc_register_cleanup_impl(const char *func, int line_num, void *ref, void (*cleanup_func)(void *));

#define rc_inc(ref) rc_inc_impl(__func__, __LINE__, ref)
extern void *rc_inc_impl(const char *func, int line_num, void *ref);

#define rc_dec(ref) rc_dec_impl(__func__, __LINE__, ref)
extern void *rc_dec_impl(const char *func, int line_num, void *ref);


int refcount_service_init();
void refcount_service_teardown();


#endif
