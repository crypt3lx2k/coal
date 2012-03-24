/*
 * coal - An object oriented general purpose library for GNU-C
 * Copyright (C) 2012 Truls Edvard Stokke
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <coal/core/implementation.h>

#include <coal/util/iterator.h>
#include <coal/util/TreeSet/TreeSet_iterator.rep>

static void TreeSet_iterator_slideLeft (var _self, struct binary_node * node) {
  class(TreeSet_iterator) * self = _self;

  while (node != NULL) {
    utility_stack_push(&self->nodes, node);
    node = node->l;
  }
}

var TreeSet_iterator_constructor (var _self, va_list * app) {
  class(TreeSet_iterator) * self = _self;
  struct binary_node * node;

  node = va_arg(*app, struct binary_node *);
  utility_stack_init(&self->nodes, 1);

  TreeSet_iterator_slideLeft(_self, node);

  return _self;
}

var TreeSet_iterator_destructor (var _self) {
  class(TreeSet_iterator) * self = _self;

  utility_stack_clear(&self->nodes);

  return _self;
}

bool TreeSet_iterator_hasNext (const var _self) {
  const class(TreeSet_iterator) * self = _self;

  return !utility_stack_is_empty(&self->nodes);
}

var TreeSet_iterator_next (var _self) {
  class(TreeSet_iterator) * self = _self;
  struct binary_node * node;

  node = utility_stack_pop(&self->nodes);
  TreeSet_iterator_slideLeft(_self, node->r);

  return node->e;
}

SETUP_CLASS_DESCRIPTION(coal_util_TreeSet_iterator,
			coal_util_iterator(),
			LIBRARY_STR ".util.TreeSet.iterator",
			coal_lang_object(),
			sizeof(class(TreeSet_iterator)),
			INHERIT_METHOD,
			TreeSet_iterator_constructor,
			TreeSet_iterator_destructor,
			INHERIT_METHOD,
			INHERIT_METHOD,
			INHERIT_METHOD,
			TreeSet_iterator_hasNext,
			TreeSet_iterator_next);
