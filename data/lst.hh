template <typename T> struct lst_node;
template <typename T> struct lst_iter;

template <typename T>
struct lst {
  lst_node<T>* head;
  lst_node<T>* tail;
  size_t length;

  lst ();
  ~ lst ();

  auto operator[] (size_t n) -> T&;

  auto begin () -> lst_iter<T>;
  auto end () -> lst_iter<T>;

  auto size () -> size_t;
  auto node (size_t n) -> lst_node<T>*;
  auto append (T obj) -> T&;
  auto insert (size_t n, T obj) -> T&;
  auto remove (size_t n) -> void;
};

template <typename T>
struct lst_node {
  T data;
  lst_node<T>* next;
};

template <typename T>
struct lst_iter {
  lst_node<T>* node;

  auto operator++ () -> lst_iter<T>;
  auto operator* () -> T&;
  auto operator!= (lst_iter<T> const& other) -> bool;
};
