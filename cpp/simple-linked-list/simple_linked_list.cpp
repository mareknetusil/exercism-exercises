#include "simple_linked_list.h"

#include <stdexcept>

namespace simple_linked_list {

std::size_t List::size() const {
    return current_size;
}

void List::push(int entry) {
    auto element = std::make_unique<Element>(entry);
    head.swap(element);
    head->next = std::move(element);
    current_size += 1;
}

int List::pop() {
    if (current_size == 0)
        throw std::out_of_range("Can't pop from an empty list!");

    const auto val = head->data;
    head = std::move(head->next);
    current_size -= 1;
    return val;
}

void List::reverse() {
    std::unique_ptr<Element> reversed{nullptr};
    while (head) {
        auto elem = std::move(head);
        head = std::move(elem->next);
        elem->next = std::move(reversed);
        reversed = std::move(elem);
    }
    head = std::move(reversed);
}

List::~List() {
}

}  // namespace simple_linked_list
