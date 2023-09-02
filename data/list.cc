template <typename T>
list<T> :: list (): head {nullptr}, tail {nullptr}, length {0} {}

template <typename T>
list<T> :: ~ list () {
  while (this->length > 0) {
    this->remove (0); // FIXME: slow
  }
}

template <typename T> auto
list<T> :: operator[] (size_t n) -> T& {
  auto elem = this->node (n);

  assert (elem.ok);

  auto nd = *elem;

  return nd->data;
}

template <typename T> auto
list<T> :: begin () -> list_iterator<T> {
  return list_iterator<T> {this->head};
}

template <typename T> auto
list<T> :: end () -> list_iterator<T> {
  return list_iterator<T> {nullptr};
}

template <typename T> auto
list<T> :: size () -> size_t {
  return this->length;
}

template <typename T> auto
list<T> :: in (size_t n) -> optional<T> {
  auto elem = this->node (n);

  if (elem.ok == false)
    return {};

  auto nd = *elem;

  return nd.data;
}

template <typename T> auto
list<T> :: node (size_t n) -> optional<list_node<T>*> {
  auto elem = this->head;

  while (n-- > 0) {
    elem = elem->next;

    if (elem == nullptr)
      return {};
  }

  return elem;
}

template <typename T> auto
list<T> :: append (T obj) -> T& {
  if (this->length == 0) {
    this->head = new list_node<T> {obj, nullptr};
    this->tail = this->head;
  } else {
    this->tail->next = new list_node<T> {obj, nullptr};
    this->tail = this->tail->next;
  }

  ++this->length;

  return this->tail->data;
}

template <typename T> auto
list<T> :: insert (size_t n, T obj) -> T& {
  if (n == 0) {
    this->head = new list_node<T> {obj, this->head};

    return this->head->data;
  }

  auto elem = this->node (n - 1);

  assert (elem.ok);

  auto nd = *elem;

  nd->next = new list_node<T> {obj, nd->next};

  ++this->length;

  return nd->next->data;
}

template <typename T> auto
list<T> :: remove (size_t n) -> void {
  assert (this->length > 0);

  if (n == 0) {
    auto nd = this->head;

    if (this->length == 1) {
      this->head = nullptr;
      this->tail = nullptr;
    } else {
      this->head = this->head->next;
    }

    delete nd;

    --this->length;

    return;
  }

  auto elem = this->node (n - 1);

  assert (elem.ok);

  auto nd = *elem;

  assert (nd->next != nullptr);

  auto removed = nd->next;

  nd->next = removed->next;

  delete removed;

  --this->length;
}

template <typename T> auto
list_iterator<T> :: operator++ () -> list_iterator<T> {
  this->node = this->node->next;

  return *this;
}

template <typename T> auto
list_iterator<T> :: operator* () -> T& {
  return this->node->data;
}

template <typename T> auto
list_iterator<T> :: operator!= (list_iterator<T> const& other) -> bool {
  return this->node != other.node;
}
