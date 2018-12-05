#ifndef __HMAP_H
#define __HMAP_H

#include <stdlib.h>


template <class KeyType>
using hashFn = size_t (*) (const KeyType&, size_t);

template <class KeyType, class ValType>
struct TableElement
{
  KeyType key;
  ValType value;
  TableElement<KeyType,ValType> *next;
  TableElement (const KeyType& k, const ValType &v, TableElement<KeyType,ValType> *n=nullptr):
     key(k), value(v), next(n){}

};
/*
template <class KeyType, class ValType>
class HashMapIterator
{
public:
  HashMapIterator (TableElement<KeyType,ValType> **, size_t);

  KeyType operator * ();
  //++it;
  HashMapIterator<KeyType,ValType>& operator ++ ();

  bool operator == (const HashMapIterator<KeyType,ValType>&) const;
  bool operator != (const HashMapIterator<KeyType,ValType>&) const;

private:

  TableElement<KeyType,ValType> ** table;
  size_t tsize;

  size_t elementIndex;
  TableElement<KeyType,ValType> *element;

};

*/
template <class KeyType, class ValType>
class HashMap
{
public:
  HashMap (size_t ts, hashFn<KeyType>);

  void update (const KeyType&, const ValType&);
  bool hasKey (const KeyType&) const;
  ValType get (const KeyType&) const;
  void remove (const KeyType&);

private:
  size_t tsize;
  hashFn<KeyType> hashfn;
  TableElement<KeyType,ValType> **table;

  TableElement<KeyType,ValType> *locate (const KeyType&) const;
};



#endif
