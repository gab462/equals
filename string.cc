string_view :: string_view (): data {nullptr}, length {0} {}

string_view :: string_view (const char* s): data {s} {
  this->length = 0;

  while (*s++ != '\0')
    ++this->length;
}

string_view :: string_view (string& s): data {s.data}, length {s.length} {}

string_view :: string_view (string_view s, size_t n): data {s.data}, length {n} {}

auto
string_view :: size () -> size_t {
  return this->length;
}

auto
string_view :: with_null () -> string {
  string s {this->length + 1};

  s.copy (*this);

  s.data[this->length] = '\0';

  return s;
}

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
  assert (this->length >= other.length + offset && "Not enough space");

  for (size_t i = 0; i < other.length; ++i)
    this->data[i + offset] = other.data[i];
}

auto
string :: with_null () -> string {
  string s {this->length + 1};

  s.copy (*this);

  s.data[this->length] = '\0';

  return s;
}

auto
string :: len (string_view s) -> size_t {
  return s.length;
}

auto
string :: to_int (string_view s) -> int {
  auto power = [] (int n, int to) {
    if (to == 0)
      return 1;

    int res = n;

    for (int i = 1; i < to; ++i) {
      res *= n;
    }

    return res;
  };

  // If minus at beginning, exclude from string
  auto number = s.data[0] == '-' ? string_view {s.data + 1, s.length - 1} : s;

  int r = 0;

  for (size_t i = 0; i < number.length; ++i) {
    auto c = number.data[number.length - 1 - i];

    assert (c >= '0' && c <= '9' && "Invalid character");

    r += (c - '0') * power (10, i);
  }

  // If had minus at the beginning, turn negative
  if (s.data != number.data)
    r *= -1;

  return r;
}
