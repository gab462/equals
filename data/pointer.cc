template <typename T>
template <typename ...A>
pointer<T> :: pointer (A... args) {
  this->data = new T {args...};
}

template <typename T>
pointer<T> :: pointer (T obj) {
  this->data = new T {obj};
}

template <typename T>
pointer<T> :: pointer (pointer const& other) {
  this->data = new T {*other.data};
}

template <typename T>
pointer<T> :: ~ pointer () {
  delete this->data;
}

template <typename T> auto
pointer<T> :: operator* () -> T& {
  return *this->data;
}

template <typename T> auto
pointer<T> :: operator= (pointer const& other) -> void {
  *this->data = *other.data;
}
