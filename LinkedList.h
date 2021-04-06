#pragma once


template <typename ItemType>

class LinkedList {
  class Node {
    ItemType item;
    Node* next;
  };
  Node* head;
  int size;

  void insert(int index, const ItemType& item) {

  }

  ItemType remove(int index) {
    return ItemType();
  }

  int find(const ItemType& item) {
    return -1;
  }
};