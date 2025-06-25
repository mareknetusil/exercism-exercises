#pragma once

#include <cstddef>
#include <initializer_list>
#include <memory>

namespace simple_linked_list {

class List {
   public:
    List() = default;
    List(std::initializer_list<int> values);
    ~List();

    List(const List&) = delete;
    List& operator=(const List&) = delete;

    List(List&&);
    List& operator=(List&&);

    std::size_t size() const;
    void push(int entry);
    int pop();
    void reverse();

    // Additional expected stack (linked-list) interface.
    bool empty() const;
    const int &front() const;
    void clear();

   private:
    struct Element {
        Element(int data) : data{data} {};
        int data{};
        std::unique_ptr<Element> next{nullptr};
    };

    std::unique_ptr<Element> head{nullptr};
    std::size_t current_size{0};
};

}  // namespace simple_linked_list
