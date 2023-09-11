template <typename T>
template <typename ...A>
ptr<T> :: ptr (A... args) {
  this->data = new T {args...};
}

template <typename T>
ptr<T> :: ptr (T obj) {
  this->data = new T {obj};
}

template <typename T>
ptr<T> :: ptr (ptr const& other) {
  this->data = new T {*other.data};
}

template <typename T>
ptr<T> :: ~ ptr () {
  delete this->data;
}

template <typename T> auto
ptr<T> :: operator* () -> T& {
  return *this->data;
}

template <typename T> auto
ptr<T> :: operator= (ptr const& other) -> void {
  *this->data = *other.data;
}
