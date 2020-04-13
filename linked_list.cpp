//
// Created by Daniela Cauti on 4/11/20.
//

#include "linked_list.h"
#include <iostream>

utec::first::linked_list_t::linked_list_t(const utec::linked_list_t &other) {

}

utec::linked_list_t &utec::first::linked_list_t::operator=(const utec::linked_list_t &other) {

    // TO DO
    head_ = other.head_;
    tail_ = other.tail_;
    size_ = other.size_;
    return *this;
}

utec::first::linked_list_t::linked_list_t(utec::linked_list_t &&other) noexcept {

}

utec::linked_list_t &utec::first::linked_list_t::operator=(utec::linked_list_t &&other) noexcept {

    // TO DO
    for(int i = 0; i < size_; ++i) {
        pop_front();
    }
    head_ = nullptr;
    size_ = 0;

    size_=other.size_;
    head_=other.head_;
    tail_=other.tail_;
    other.size_=0;
    other.head_=nullptr;
    other.tail_= nullptr;
    return *this;
}

utec::first::linked_list_t::~linked_list_t() {
    for(int i = 0; i < size_; ++i) {
        linked_list_t().pop_front();
    }
    size_ = 0;
    delete head_;
    delete tail_;
}

void utec::first::linked_list_t::push_front(int value) {

    /*
    auto node = new node_t{value, head_}
    head_ = node;
    */
    head_ = new node_t{value, head_};
    if (tail_ == nullptr)
        tail_ = head_;
    size_++;

}

void utec::first::linked_list_t::push_back(int value) {

    node_t* node= new node_t{value, tail_};
    tail_->next_ = node;
    tail_ = node;
    if(head_ == nullptr)
        head_ = tail_;
    size_++;
}

void utec::first::linked_list_t::insert(size_t index, int value) {

    node_t* temp = new node_t();
    node_t* temp2 = head_;
    temp->value_ = value;
    if(index == 0) {
        head_= new node_t{value, head_};
    }
    else {
        for (int i = 0; i < index; i++){
            temp2 = temp2->next_;
        }
        temp->next_ = temp2;
        temp2 = head_;
        for (int i = 0; i < index - 1; i++){
            temp2 = temp2->next_;
        }
        temp2->next_ = temp;}
    size_++;
}

void utec::first::linked_list_t::pop_front() {
    if (head_ == tail_) {
        delete head_;
        head_ = tail_ = nullptr;
        size_ = 0;
    }
    else {
        auto next = head_->next_;
        delete head_;
        head_ = next;
        size_--;
    }
}

void utec::first::linked_list_t::pop_back() {

    if (tail_ == head_) {
        delete[] tail_;
        tail_ = head_ = nullptr;
        size_ = 0;
    }
    else {
        node_t* next = head_;
        while (next->next_ != tail_) {
            next = next->next_;
        }
        delete[] tail_;
        tail_ = next;
        tail_->next_ = nullptr;
        size_--;
    }
}

void utec::first::linked_list_t::erase(size_t index) {
    struct node_t* temp = head_;
    int i;
    for(i = 0; i < index - 2; i++)
        temp = temp->next_;

    struct node_t* temp2 = temp->next_;
    temp->next_ = temp2->next_;
    delete temp2;
    size_--;
}

int &utec::first::linked_list_t::item(size_t index) {
    auto actual = head_;
    while (index--)
        actual = actual->next_;
    return actual->value_;
}

const int &utec::first::linked_list_t::item(size_t index) const {
    auto actual = head_;
    while (index--)
        actual = actual->next_;
    return actual->value_;
}

size_t utec::first::linked_list_t::size() const {
    return size_;
}
