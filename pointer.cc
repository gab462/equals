template <typename T>
pointer<T> :: pointer (T obj) {
  this->data = new T {obj};
}

template <typename T>
pointer<T> :: ~ pointer () {
  delete this->data;
}

template <typename T> auto
pointer<T> :: operator* () -> T& {
  return *this->data;
}
