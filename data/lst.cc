template <typename T>
lst<T> :: lst (): head {nullptr}, tail {nullptr}, length {0} {}

template <typename T>
lst<T> :: ~ lst () {
  while (this->length > 0) {
    this->remove (0); // FIXME: slow
  }
}

template <typename T> auto
lst<T> :: operator[] (size_t n) -> T& {
  auto elem = this->node (n);

  assert (elem != nullptr);

  return elem->data;
}

template <typename T> auto
lst<T> :: begin () -> lst_iter<T> {
  return lst_iter<T> {this->head};
}

template <typename T> auto
lst<T> :: end () -> lst_iter<T> {
  return lst_iter<T> {nullptr};
}

template <typename T> auto
lst<T> :: size () -> size_t {
  return this->length;
}

template <typename T> auto
lst<T> :: node (size_t n) -> lst_node<T>* {
  auto elem = this->head;

  while (n-- > 0) {
    elem = elem->next;

    if (elem == nullptr)
      return nullptr;
  }

  return elem;
}

template <typename T> auto
lst<T> :: append (T obj) -> T& {
  if (this->length == 0) {
    this->head = new lst_node<T> {obj, nullptr};
    this->tail = this->head;
  } else {
    this->tail->next = new lst_node<T> {obj, nullptr};
    this->tail = this->tail->next;
  }

  ++this->length;

  return this->tail->data;
}

template <typename T> auto
lst<T> :: insert (size_t n, T obj) -> T& {
  if (n == 0) {
    this->head = new lst_node<T> {obj, this->head};

    return this->head->data;
  }

  auto elem = this->node (n - 1);

  assert (elem != nullptr);

  elem->next = new lst_node<T> {obj, elem->next};

  ++this->length;

  return elem->next->data;
}

template <typename T> auto
lst<T> :: remove (size_t n) -> void {
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

  assert (elem != nullptr);
  assert (elem->next != nullptr);

  auto removed = elem->next;

  elem->next = removed->next;

  delete removed;

  --this->length;
}

template <typename T> auto
lst_iter<T> :: operator++ () -> lst_iter<T> {
  this->node = this->node->next;

  return *this;
}

template <typename T> auto
lst_iter<T> :: operator* () -> T& {
  return this->node->data;
}

template <typename T> auto
lst_iter<T> :: operator!= (lst_iter<T> const& other) -> bool {
  return this->node != other.node;
}
