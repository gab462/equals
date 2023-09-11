template <typename T, size_t N> auto
arr<T, N> :: operator[] (size_t n) -> T& {
  return this->data[n];
}

template <typename T, size_t N> auto
arr<T, N> :: begin () -> T* {
  return &this->data[0];
}

template <typename T, size_t N> auto
arr<T, N> :: end () -> T* {
  return &this->data[N];
}

template <typename T, size_t N> auto
arr<T, N> :: size () -> size_t {
  return N;
}
