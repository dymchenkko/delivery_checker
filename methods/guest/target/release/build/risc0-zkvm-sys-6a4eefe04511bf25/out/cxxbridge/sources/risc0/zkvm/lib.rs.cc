#include "risc0/zkvm/prove/method_id.h"
#include <cstddef>
#include <cstring>
#include <exception>
#include <memory>
#include <new>
#include <string>
#include <type_traits>
#include <utility>

namespace rust {
inline namespace cxxbridge1 {
// #include "rust/cxx.h"

#ifndef CXXBRIDGE1_IS_COMPLETE
#define CXXBRIDGE1_IS_COMPLETE
namespace detail {
namespace {
template <typename T, typename = std::size_t>
struct is_complete : std::false_type {};
template <typename T>
struct is_complete<T, decltype(sizeof(T))> : std::true_type {};
} // namespace
} // namespace detail
#endif // CXXBRIDGE1_IS_COMPLETE

namespace {
namespace repr {
struct PtrLen final {
  void *ptr;
  ::std::size_t len;
};
} // namespace repr

template <bool> struct deleter_if {
  template <typename T> void operator()(T *) {}
};

template <> struct deleter_if<true> {
  template <typename T> void operator()(T *ptr) { ptr->~T(); }
};
} // namespace
} // namespace cxxbridge1

namespace behavior {
class missing {};
missing trycatch(...);

template <typename Try, typename Fail>
static typename ::std::enable_if<
    ::std::is_same<decltype(trycatch(::std::declval<Try>(), ::std::declval<Fail>())),
                 missing>::value>::type
trycatch(Try &&func, Fail &&fail) noexcept try {
  func();
} catch (const ::std::exception &e) {
  fail(e.what());
}
} // namespace behavior
} // namespace rust

extern "C" {
const char *cxxbridge1$exception(const char *, ::std::size_t);
} // extern "C"

namespace risc0 {
  namespace rust {
    using MethodID = ::risc0::rust::MethodID;
  }
}

namespace risc0 {
namespace rust {
extern "C" {
::rust::repr::PtrLen risc0$rust$cxxbridge1$new_method_id(const ::std::string &elf_path, ::risc0::rust::MethodID **return$) noexcept {
  ::std::unique_ptr<::risc0::rust::MethodID> (*new_method_id$)(const ::std::string &) = ::risc0::rust::new_method_id;
  ::rust::repr::PtrLen throw$;
  ::rust::behavior::trycatch(
      [&] {
        new (return$) ::risc0::rust::MethodID *(new_method_id$(elf_path).release());
        throw$.ptr = nullptr;
      },
      [&](const char *catch$) noexcept {
        throw$.len = ::std::strlen(catch$);
        throw$.ptr = const_cast<char *>(::cxxbridge1$exception(catch$, throw$.len));
      });
  return throw$;
}

::rust::repr::PtrLen risc0$rust$cxxbridge1$MethodID$write(const ::risc0::rust::MethodID &self, const ::std::string &filename) noexcept {
  void (::risc0::rust::MethodID::*write$)(const ::std::string &) const = &::risc0::rust::MethodID::write;
  ::rust::repr::PtrLen throw$;
  ::rust::behavior::trycatch(
      [&] {
        (self.*write$)(filename);
        throw$.ptr = nullptr;
      },
      [&](const char *catch$) noexcept {
        throw$.len = ::std::strlen(catch$);
        throw$.ptr = const_cast<char *>(::cxxbridge1$exception(catch$, throw$.len));
      });
  return throw$;
}
} // extern "C"
} // namespace rust
} // namespace risc0

extern "C" {
static_assert(::rust::detail::is_complete<::risc0::rust::MethodID>::value, "definition of MethodID is required");
static_assert(sizeof(::std::unique_ptr<::risc0::rust::MethodID>) == sizeof(void *), "");
static_assert(alignof(::std::unique_ptr<::risc0::rust::MethodID>) == alignof(void *), "");
void cxxbridge1$unique_ptr$risc0$rust$MethodID$null(::std::unique_ptr<::risc0::rust::MethodID> *ptr) noexcept {
  ::new (ptr) ::std::unique_ptr<::risc0::rust::MethodID>();
}
void cxxbridge1$unique_ptr$risc0$rust$MethodID$raw(::std::unique_ptr<::risc0::rust::MethodID> *ptr, ::risc0::rust::MethodID *raw) noexcept {
  ::new (ptr) ::std::unique_ptr<::risc0::rust::MethodID>(raw);
}
const ::risc0::rust::MethodID *cxxbridge1$unique_ptr$risc0$rust$MethodID$get(const ::std::unique_ptr<::risc0::rust::MethodID>& ptr) noexcept {
  return ptr.get();
}
::risc0::rust::MethodID *cxxbridge1$unique_ptr$risc0$rust$MethodID$release(::std::unique_ptr<::risc0::rust::MethodID>& ptr) noexcept {
  return ptr.release();
}
void cxxbridge1$unique_ptr$risc0$rust$MethodID$drop(::std::unique_ptr<::risc0::rust::MethodID> *ptr) noexcept {
  ::rust::deleter_if<::rust::detail::is_complete<::risc0::rust::MethodID>::value>{}(ptr);
}
} // extern "C"
