### CHFazhe's StrongType: CHFazhe's Strongly-Typed Implementation 🤔

This library provides two wrappers: `wrapper` and `wrapper_auto` (located under the `StrongType::` namespace). `wrapper_auto` builds upon `wrapper` by adding automatic wrapping, making it closer to other strongly-typed libraries. 🤔

`wrapper` requires three template parameters: ***typename _Inherit_T, typename _Tag, template<typename> typename... _Skills***

- _Inherit_T
	
	- `_Inherit_T` is the type that `wrapper` will inherit from. Additionally, `wrapper` uses `using _Inherit_T::_Inherit_T` to further inherit some members from `_Inherit_T`.
	`_Inherit_T` only accepts the three inheritance types provided by this library (in `inherit.hpp`): ***inherit_store   inherit_default   inherit_all***
		
		- `inherit_store` — This typically only stores the `_Inherit_T` type without inheriting from it.
		
		- `inherit_default` — This inherits from the `_Inherit_T` type but does not use `using _Inherit_T::_Inherit_T` for additional inheritance.

		- `inherit_all` — This inherits from the `_Inherit_T` type and also uses `using _Inherit_T::_Inherit_T` for additional inheritance.
		
- _Tag
	
	- `_Tag` is a dedicated placeholder provided by `wrapper` for labeling purposes; the placeholder itself is not inherited.
	
- _Skills

	- `_Skills` is the list of skills for the wrapper. The dedicated skill set provided by this library for `wrapper` is located under the namespace `StrongType::modifier`.
	 You can also use the macro provided by this library: ***StrongType_MakeSkill(TYPE, NAME), which is equivalent to template\<typename\> using NAME = TYPE***
	 This allows certain types to be used as skills. `wrapper` inherits from the skills but does not use `using` for additional inheritance.

## Usage

```cpp
	using addable_int = StrongType::wrapper_auto<int, struct MyTag, StrongType::modifier::addable>;
	
	addable_int a(1234567890);
```

# Afterword

Thank you for reading! 👍
