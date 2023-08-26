template <typename T, size_t N> auto
array<T, N> :: begin () -> T* {
  return &this->data[0];
}

template <typename T, size_t N> auto
array<T, N> :: end () -> T* {
  return &this->data[N];
}

template <typename T, size_t N> auto
array<T, N> :: size () -> size_t {
  return N;
}

template <typename T, size_t N> auto
array<T, N> :: operator[] (size_t n) -> T& {
  return this->data[n];
}

template <typename T, size_t N> auto
array<T, N> :: in (size_t n) -> optional<T> {
  if (n >= N)
    return {};

  return this->data[n];
}
