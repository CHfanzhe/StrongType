### CHFazhe's StrongType: CHFazhe的强类型实现 🤔

[ENGLISH](https://github.com/CHfanzhe/StrongType/blob/master/StrongType%20_ENGLISH.md)

本库提供了 两个包装器 wrapper wrapper_auto (位于StrongType::命名空间下) wrapper_auto 是在wrapper的基础上添加了自动包装使其更接近于其他的强类型库. 🤔

wrapper 需求3个模板 ***typename _Inherit_T, typename _Tag, template<typename> typename... _Skills***

- _Inherit_T
	
	- _Inherit_T是wrapper会继承的类型, 并且, wrapper会使用using _Inherit_T::_Inherit_T 再额外继承 _Inherit_T 的一些东西.
	_Inherit_T 只接受本库提供的三种继承(inherit.hpp) *** inherit_store   inherit_default   inherit_all ***
		
		- inherit_store   这通常只储存 不继承 _Inherit_T 类型.
		
		- inherit_default   这会继承 _Inherit_T 类型, 但是不使用 using _Inherit_T::_Inherit_T 进行额外的继承.

		- inherit_all   这会继承 _Inherit_T 类型, 会使用 using _Inherit_T::_Inherit_T 进行额外的继承.
		
- _Tag
	
	- _Tag 是wrapper为标签提供的专用的占位符 不继承占位符
	
- _Skills

	- _Skills 是wrapper的技能列表 本库提供的wrapper的专用技能表位于命名空间 *StrongType::modifier* 下,
	 并且您还可以使用本库提供的宏***StrongType_MakeSkill(TYPE,NAME) 其等价与 template<typename> NAME = TYPE***
	 这个能使某些类型支持被当作技能使用. wrapper 会继承技能 但是不会使用using再额外继承.

## 使用

```cpp
	using addable_int = StrongType::wrapper_auto<int, struct MyTag, StrongType::modifier::addable>;
	
	addable_int a(1234567890);
```

# 后记

感激您的阅读 👍