template <typename T>
vector<T> :: vector (size_t n): length {n} {
  this->data = new T[n];
}

template <typename T>
template <typename B, typename ...A>
vector<T> :: vector (B v1, B v2, A... rest) {
  this->length = sizeof ...(rest) + 2;
  this->data = new T[this->length] {v1, v2, rest...};
}

template <typename T>
vector<T> :: ~ vector () {
  delete [] this->data;
}

template <typename T> auto
vector<T> :: begin () -> T* {
  return &this->data[0];
}

template <typename T> auto
vector<T> :: end () -> T* {
  return &this->data[this->length];
}

template <typename T> auto
vector<T> :: size () -> size_t {
  return this->length;
}

template <typename T> auto
vector<T> :: operator[] (size_t n) -> T& {
  return this->data[n];
}

template <typename T> auto
vector<T> :: in (size_t n) -> optional<T> {
  if (n >= this->length)
    return {};

  return this->data[n];
}
