template <typename T>
template <typename ...A>
vector<T> :: vector (A... values) {
  this->length = sizeof ...(values);

  if (this->length > 0)
    this->data = new T[this->length] {values...};
  else
    this->data = nullptr;
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

template <typename T> auto
vector<T> :: resize (size_t n) -> void {
  if (this->data != nullptr)
    delete [] this->data;

  this->data = new T[n];
  this->length = n;
}
