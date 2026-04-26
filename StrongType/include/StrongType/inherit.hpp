#pragma once

namespace StrongType::inherit {
	template<class... Ts>
	struct inherit_default : public Ts... {};

	template<class... Ts>
	struct inherit_all : public Ts... { using Ts::Ts...; };
}