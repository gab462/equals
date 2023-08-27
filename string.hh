struct string;

struct string_view {
  const char* data;
  size_t length;

  string_view ();
  string_view (const char* s);
  string_view (string& s);
  string_view (string_view s, size_t n);
};

struct string {
  char* data;
  size_t length;

  string (const char* s);
  string (string& other);
  string (string_view other);
  string (size_t n);
  ~ string ();

  auto size () -> size_t;
  auto append (string_view other) -> string;
  auto copy (string_view src, size_t offset = 0) -> void;
  // auto split (char sep) -> list<string_view>;

  static auto len (string_view s) -> size_t;
  static auto to_int (string_view s) -> int;
  // static auto from_int (int s) -> string;
};
