template <typename T>
template <typename ...A>
vec<T> :: vec (A... values) {
  this->length = sizeof ...(values);

  if (this->length > 0)
    this->data = new T[this->length] {values...};
  else
    this->data = nullptr;
}

template <typename T>
vec<T> :: vec (vec& other): length {other.length} {
  for (size_t i = 0; i < other.length; ++i) {
    this->data[i] = other.data[i];
  }
}

template <typename T>
vec<T> :: ~ vec () {
  delete[] this->data;
}

template <typename T> auto
vec<T> :: operator[] (size_t n) -> T& {
  return this->data[n];
}

template <typename T> auto
vec<T> :: operator= (vec const& other) -> void {
  this->resize (other.length);

  for (size_t i = 0; i < other.length; ++i) {
    this->data[i] = other.data[i];
  }
}

template <typename T> auto
vec<T> :: begin () -> T* {
  return &this->data[0];
}

template <typename T> auto
vec<T> :: end () -> T* {
  return &this->data[this->length];
}

template <typename T> auto
vec<T> :: size () -> size_t {
  return this->length;
}

template <typename T> auto
vec<T> :: resize (size_t n) -> void {
  T* tmp = new T[n];

  if (this->data != nullptr) {
    auto copied = this->length < n ? this->length : n;

    for (size_t i = 0; i < copied; ++i) {
      tmp[i] = this->data[i];
    }

    delete[] this->data;
  }

  this->data = tmp;
  this->length = n;
}
