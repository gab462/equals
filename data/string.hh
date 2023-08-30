struct string;

struct string_view {
  const char* ptr;
  size_t length;

  string_view ();
  string_view (const char* s);
  string_view (string& s);
  string_view (string_view s, size_t n);
  string_view (const char* s, size_t n);

  auto size () -> size_t;
  auto operator== (string_view other) -> bool;
  auto contains (string_view other) -> bool;
  auto split (char sep) -> list<string_view>;
  auto trim () -> string_view;
  auto append (string_view other) -> string;
  auto with_null () -> string;

  auto to_int () -> int;
  // static auto from_int (int s) -> string;
};

struct string: string_view {
  char *data;

  string (const char* s);
  string (string& other);
  string (string_view other);
  string (size_t n);
  ~ string ();

  auto copy (string_view src, size_t offset = 0) -> void;
};
