template <typename T>
optional<T> :: optional (T obj): ok {true}, data {obj} {}

template <typename T>
optional<T> :: optional (): ok {false} {}

template <typename T> auto
optional<T> :: operator* () -> T& {
  if (this->ok == false)
    assert (false && "Trying to access empty optional");

  return this->data;
}
