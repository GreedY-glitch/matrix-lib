// metaprogramming C++


// The simpliest implementation of is_const
template <typename _Type> struct is_const : std::false_type {};
template <typename _Type> struct is_const<const _Type> : std::true_type {};

// The simpliest implementation of is_pointer
template <typename _Type> struct is_pointer : std::false_type {};
template <typename _Type> struct is_pointer<_Type*> : std::true_type {};