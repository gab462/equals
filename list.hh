template <typename T> struct list_node;
template <typename T> struct list_iterator;

template <typename T>
struct list {
  list_node<T>* head;
  list_node<T>* tail;
  size_t length;

  list ();
  ~ list ();

  auto begin () -> list_iterator<T>;
  auto end () -> list_iterator<T>;

  auto size () -> size_t;
  auto in (size_t n) -> optional<T>;
  auto node (size_t n) -> optional<list_node<T>*>;
  auto append (T obj) -> void;
  auto insert (size_t n, T obj) -> void;
  auto remove (size_t n) -> void;
};

template <typename T>
struct list_node {
  T data;
  list_node* next;
};

template <typename T>
struct list_iterator {
  list_node<T>* node;

  auto operator++ () -> list_iterator<T>;
  auto operator* () -> T&;
  auto operator!= (list_iterator<T>& other) -> bool;
};
