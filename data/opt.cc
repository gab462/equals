template <typename T>
opt<T> :: opt (T obj): ok {true}, data {obj} {}

template <typename T>
opt<T> :: opt (): ok {false}, data {} {}

template <typename T> auto
opt<T> :: operator* () -> T& {
  assert (this->ok);

  return this->data;
}
