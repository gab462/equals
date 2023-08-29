string_view :: string_view (): ptr {nullptr}, length {0} {}

string_view :: string_view (const char* s): ptr {s} {
  this->length = 0;

  while (*s++ != '\0')
    ++this->length;
}

string_view :: string_view (string& s): ptr {s.data}, length {s.length} {}

string_view :: string_view (string_view s, size_t n): ptr {s.ptr}, length {n} {}

string_view :: string_view (const char* s, size_t n): ptr {s}, length {n} {}

auto
string_view :: size () -> size_t {
  return this->length;
}

auto
string_view :: operator== (string_view other) -> bool {
  if (this->length != other.length)
    return false;

  for (size_t i = 0; i < this->length; ++i) {
    if (this->ptr[i] != other.ptr[i])
      return false;
  }

  return true;
}

auto
string_view :: contains (string_view other) -> bool {
  size_t match = 0;

  for (size_t i = 0; i < this->length; ++i) {
    if (this->ptr[i] == other.ptr[match]) {
      ++match;
    } else {
      match = this->ptr[i] == other.ptr[0] ? 1 : 0;
    }

    if (match == other.length)
      return true;
  }

  return false;
}

auto
string_view :: split (char sep) -> list<string_view> {
  size_t start = 0;
  list<string_view> res;

  for (size_t i = 0; i < this->length; ++i) {
    if (this->ptr[i] == sep) {
      res.append ({this->ptr + start, i - start});
      start = i + 1;
    }

    if (i + 1 == this->length) {
      res.append ({this->ptr + start, this->length - start});
    }
  }

  return res;
}

auto
string_view :: trim () -> string_view {
  if (this->length == 0)
    return {this->ptr, this->length};

  auto is_whitespace = [](char c) {
    return c == ' ' || c == '\t' || c == '\n';
  };

  size_t left;

  for (size_t i = 0; i < this->length; ++i) {
    if (!is_whitespace (this->ptr[i])) {
      left = i;
      break;
    }
  }

  if (left == this->length) // All whitespace
    return {this->ptr, 0};

  size_t right;

  for (size_t i = 0; i < this->length; ++i) {
    if (!is_whitespace (this->ptr[this->length - 1 - i])) {
      right = i;
      break;
    }
  }

  return {this->ptr + left, this->length - left - right};
}

auto
string_view :: append (string_view other) -> string {
  string s {this->length + other.length};

  s.copy (*this);
  s.copy (other, this->length);

  return s;
}

auto
string_view :: with_null () -> string {
  string s {this->length + 1};

  s.copy (*this);

  s.data[this->length] = '\0';

  return s;
}

auto
string_view :: to_int () -> int {
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
  auto number = this->ptr[0] == '-' ? string_view {this->ptr + 1, this->length - 1} : *this;

  int r = 0;

  for (size_t i = 0; i < number.length; ++i) {
    auto c = number.ptr[number.length - 1 - i];

    assert (c >= '0' && c <= '9' && "Invalid character");

    r += (c - '0') * power (10, i);
  }

  // If had minus at the beginning, turn negative
  if (this->ptr != number.ptr)
    r *= -1;

  return r;
}

string :: string (const char *s): string_view {s} {
  this->data = new char[this->length];
  this->ptr = this->data;
  this->copy (s);
}

string :: string (string& other): string_view {other} {
  this->data = new char[other.length];
  this->ptr = this->data;

  this->copy (other);
}

string :: string (string_view other): string_view {other} {
  this->data = new char[other.length];
  this->ptr = this->data;

  this->copy (other);
}

string :: string (size_t n) {
  this->data = new char[n];
  this->ptr = this->data;
  this->length = n;
}

string :: ~ string () {
  delete this->data;
}

auto
string :: copy (string_view other, size_t offset) -> void {
  assert (this->length >= other.length + offset && "Not enough space");

  for (size_t i = 0; i < other.length; ++i)
    this->data[i + offset] = other.ptr[i];
}
