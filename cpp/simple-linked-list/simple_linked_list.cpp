#include "simple_linked_list.h"

#include <initializer_list>
#include <algorithm>
#include <iterator>
#include <stdexcept>

namespace simple_linked_list {

List::List(std::initializer_list<int> values) {
    std::for_each(
        std::rbegin(values),
        std::rend(values),
        [this](int v) { push(v); }
    );
}

List::List(List&& other) noexcept
    : head(std::move(other.head)),
      current_size(other.current_size)
{
    other.current_size = 0;
}

List &List::operator=(List&& other) noexcept {
    if (this == &other) {
        return *this;
    }

    current_size = other.current_size;
    head = std::move(other.head);
    other.current_size = 0;
    return *this;
}

List::~List() noexcept {
    // Guard against stack overflow!
    while (head)
        head = std::move(head->next);
}

std::size_t List::size() const noexcept {
    return current_size;
}

void List::push(int entry) {
    auto element = std::make_unique<Element>(entry);
    head.swap(element);
    head->next = std::move(element);
    current_size += 1;
}

int List::pop() {
    if (!head)
        throw std::out_of_range("Can't pop from an empty list!");

    const auto val = head->data;
    head = std::move(head->next);
    current_size -= 1;
    return val;
}

void List::reverse() noexcept {
    std::unique_ptr<Element> reversed{nullptr};
    while (head) {
        auto elem = std::move(head);
        head = std::move(elem->next);
        elem->next = std::move(reversed);
        reversed = std::move(elem);
    }
    head = std::move(reversed);
}

bool List::empty() const noexcept {
   return size() == 0;
}

const int &List::front() const {
    if (!head)
        throw std::out_of_range("Can't look at front of an empty list!");

    return head->data;
}

void List::clear() noexcept {
    while (head) {
        head = std::move(head->next);
    }
    current_size = 0;
}

}  // namespace simple_linked_list
