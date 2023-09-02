template <typename T>
optional<T> :: optional (T obj): ok {true}, data {obj} {}

template <typename T>
optional<T> :: optional (): ok {false}, data {} {}

template <typename T> auto
optional<T> :: operator* () -> T& {
  assert (this->ok);

  return this->data;
}
