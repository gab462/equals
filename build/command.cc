command :: command (): program {nullptr}, args {} {}

template <typename ...A>
command :: command (const char* c, A... a): program {c}, args {c, a..., nullptr} {}

auto
command :: execute () -> void {
  // Any way other than const_cast?
  execvp (program, const_cast<char* const*>(args.data));
}
