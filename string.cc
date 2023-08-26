string_view :: string_view (const char* s): data {s} {
  this->length = 0;

  while (*s++ != '\0')
    ++length;
}

string_view :: string_view (string& s): data {s.data}, length {s.length} {}

string_view :: string_view (string& s, size_t n): data {s.data}, length {n} {}

string :: string (const char *s) {
  size_t n = this->len (s);

  this->data = new char[n];
  this->copy (s);
  this->length = n;
}

string :: string (string& other): length {other.length} {
  this->data = new char[other.length];

  this->copy (other);
}

string :: string (string_view other): length {other.length} {
  this->data = new char[other.length];

  this->copy (other);
}

string :: string (size_t n): length {n} {
  this->data = new char[n];
}

string :: ~ string () {
  delete this->data;
}

auto
string :: size () -> size_t {
  return this->length;
}

auto
string :: append (string_view other) -> string {
  string s {this->length + other.length};

  s.copy (*this);
  s.copy (other, this->length);

  return s;
}

auto
string :: copy (string_view other, size_t offset) -> void {
  for (size_t i = offset; i < other.length + offset; ++i)
    this->data[i] = other.data[i - offset];
}

auto
string :: len (string_view s) -> size_t {
  return s.length;
}
