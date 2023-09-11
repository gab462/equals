str_view :: str_view (): ptr {nullptr}, length {0} {}

str_view :: str_view (const char* s): ptr {s} {
  this->length = 0;

  while (*s++ != '\0')
    ++this->length;
}

str_view :: str_view (str& s): ptr {s.data}, length {s.length} {}

str_view :: str_view (str_view s, size_t n): ptr {s.ptr}, length {n} {}

str_view :: str_view (const char* s, size_t n): ptr {s}, length {n} {}

auto
str_view :: operator== (str_view other) -> bool {
  if (this->length != other.length)
    return false;

  for (size_t i = 0; i < this->length; ++i) {
    if (this->ptr[i] != other.ptr[i])
      return false;
  }

  return true;
}

auto
str_view :: size () -> size_t {
  return this->length;
}

auto
str_view :: contains (str_view other) -> bool {
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
str_view :: split (char sep) -> lst<str_view> {
  size_t start = 0;
  lst<str_view> res;

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
str_view :: trim () -> str_view {
  if (this->length == 0)
    return *this;

  auto is_whitespace = [] (char c) {
    return c == ' ' || c == '\t' || c == '\n';
  };

  int left = -1;

  for (size_t i = 0; i < this->length; ++i) {
    if (!is_whitespace (this->ptr[i])) {
      left = i;
      break;
    }
  }

  if (left == -1) // All whitespace
    return {this->ptr, 0};

  size_t right = 0;

  for (size_t i = 0; i < this->length; ++i) {
    if (!is_whitespace (this->ptr[this->length - 1 - i])) {
      right = i;
      break;
    }
  }

  return {this->ptr + left, this->length - left - right};
}

auto
str_view :: append (str_view other) -> str {
  str s {this->length + other.length};

  s.copy (*this);
  s.copy (other, this->length);

  return s;
}

auto
str_view :: with_null () -> str {
  str s {this->length + 1};

  s.copy (*this);

  s.data[this->length] = '\0';

  return s;
}

auto
str_view :: to_int () -> int {
  auto power = [] (int n, int to) {
    if (to == 0)
      return 1;

    int res = n;

    for (int i = 1; i < to; ++i) {
      res *= n;
    }

    return res;
  };

  // If minus at beginning, exclude from str
  auto number = this->ptr[0] == '-' ? str_view {this->ptr + 1, this->length - 1} : *this;

  int r = 0;

  for (size_t i = 0; i < number.length; ++i) {
    auto c = number.ptr[number.length - 1 - i];

    assert (c >= '0' && c <= '9');

    r += (c - '0') * power (10, i);
  }

  // If had minus at the beginning, turn negative
  if (this->ptr != number.ptr)
    r *= -1;

  return r;
}

str :: str (const char *s): str_view {s} {
  this->data = new char[this->length];
  this->ptr = this->data;
  this->copy (s);
}

str :: str (str& other): str_view {other} {
  // Copy data instead of pointer
  this->data = new char[other.length];
  this->ptr = this->data;

  this->copy (other);
}

str :: str (str_view other): str_view {other} {
  this->data = new char[other.length];
  this->ptr = this->data;

  this->copy (other);
}

str :: str (size_t n) {
  this->data = new char[n];
  this->ptr = this->data;
  this->length = n;
}

str :: ~ str () {
  delete[] this->data;
}

auto
str :: operator= (str const& other) -> void {
  delete[] this->data;

  this->length = other.length;
  this->data = new char[other.length];

  this->copy (other);
}

auto
str :: copy (str_view other, size_t offset) -> void {
  assert (this->length >= other.length + offset);

  for (size_t i = 0; i < other.length; ++i)
    this->data[i + offset] = other.ptr[i];
}
