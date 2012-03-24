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

#include <stdlib.h>

#include <coal/core/implementation.h>

#include <coal/util/collection.h>
#include <coal/util/AbstractCollection.h>

#include <coal/util/BinaryTreeSet.h>
#include <coal/util/BinaryTreeSet/BinaryTreeSet.rep>
#include <coal/util/BinaryTreeSet/BinaryTreeSet_iterator.rep>

/* node routines */

static struct binary_node * allocate_node (var elem) {
  struct binary_node * node;

  node = coal_core_malloc(sizeof(struct binary_node));

  node->l = NULL;
  node->r = NULL;
  node->e = elem;

  return node;
}

static void deallocate_node (struct binary_node * node) {
  if (node == NULL)
    return;

  coal_del(node->e);
  free(node);
}

static void deallocate_node_r (struct binary_node * node) {
  if (node == NULL)
    return;

  deallocate_node_r(node->l);
  deallocate_node_r(node->r);
  deallocate_node(node);
}

static int size_node_r (struct binary_node * node) {
  return node != NULL ?
    size_node_r(node->l) +
    size_node_r(node->r) + 1 : 0;
}

static struct binary_node * find_min (struct binary_node * node) {
  while (node->l != NULL)
    node = node->l;

  return node;
}

static struct binary_node * remove_node (var object, struct binary_node * node) {
  int c;

  if (node == NULL)
    return node;

  c = coal_lang_cmp(object, node->e);

  if (c < 0) {
    node->l = remove_node(object, node->l);
  } else if (c > 0) {
    node->r = remove_node(object, node->r);
  } else if (node->l != NULL && node->r != NULL) {
    node->e = coal_acquire(find_min(node)->e);
    remove_node(node->e, node->r);
  } else {
    node = node->l != NULL ? node->l : node->r;
  }

  return node;
}

/* override lang.object methods */

var BinaryTreeSet_constructor (var _self, va_list * app __attribute__ ((unused))) {
  class(BinaryTreeSet) * self = _self;

  self->root = NULL;

  return _self;
}

var BinaryTreeSet_destructor (var _self) {
  class(BinaryTreeSet) * self = _self;

  deallocate_node_r(self->root);
  self->root = NULL;

  return _self;
}

/* lang.iterable methods */

var BinaryTreeSet_iterator (const var _self) {
  const class(BinaryTreeSet) * self = _self;

  return coal_new(coal_util_BinaryTreeSet_iterator(),
		  self->root);
}

/* util.collection methods */

bool BinaryTreeSet_add (var _self, var object) {
  class(BinaryTreeSet) * self = _self;
  struct binary_node * current = self->root;

  while (current != NULL) {
    int c = coal_lang_cmp(object, current->e);

    if (c < 0) {
      if (current->l == NULL) {
	current->l = allocate_node(object);
	return true;
      } else {
	current = current->l;
      }
    } else if (c > 0) {
      if (current->r == NULL) {
	current->r = allocate_node(object);
	return true;
      } else {
	current = current->r;
      }
    } else {
      return false;
    }
  }

  self->root = allocate_node(object);
  return true;
}

void BinaryTreeSet_clear (var _self) {
  (void) BinaryTreeSet_destructor(_self);
}

bool BinaryTreeSet_contains (const var _self, const var object) {
  const class(BinaryTreeSet) * self = _self;
  struct binary_node * current = self->root;

  while (current != NULL) {
    int c = coal_lang_cmp(object, current->e);

    if (c < 0)
      current = current->l;
    else if (c > 0)
      current = current->r;
    else
      return true;
  }

  return false;
}

bool BinaryTreeSet_isEmpty (const var _self) {
  const class(BinaryTreeSet) * self = _self;

  return self->root == NULL;
}

bool BinaryTreeSet_remove (var _self, var object) {
  class(BinaryTreeSet) * self = _self;
  struct binary_node * current = self->root;

  while (current != NULL) {
    int c = coal_lang_cmp(object, current->e);

    if (c < 0)
      current = current->l;
    else if (c > 0)
      current = current->r;
    else {
      remove_node(object, current);
      return true;
    }
  }

  return false;
}

int BinaryTreeSet_size (const var _self) {
  const class(BinaryTreeSet) * self = _self;

  return size_node_r(self->root);
}

SETUP_CLASS_DESCRIPTION(coal_util_BinaryTreeSet,
			coal_util_collection(),
			LIBRARY_STR ".util.BinaryTreeSet",
			coal_util_AbstractCollection(),
			sizeof(class(BinaryTreeSet)),
			/* object */
			INHERIT_METHOD,
			BinaryTreeSet_constructor,
			BinaryTreeSet_destructor,
			INHERIT_METHOD,
			INHERIT_METHOD,
			INHERIT_METHOD,
			/* iterable */
			BinaryTreeSet_iterator,
			/* collection */
			BinaryTreeSet_add,
			BinaryTreeSet_clear,
			BinaryTreeSet_contains,
			BinaryTreeSet_isEmpty,
			BinaryTreeSet_remove,
			BinaryTreeSet_size);	
