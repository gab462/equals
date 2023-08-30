template <typename T>
optional<T> :: optional (T obj): ok {true}, data {obj} {}

template <typename T>
optional<T> :: optional (): ok {false} {}

template <typename T> auto
optional<T> :: operator* () -> T& {
  assert (this->ok && "Trying to access empty optional");

  return this->data;
}
