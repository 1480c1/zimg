#pragma once

#ifdef ZIMG_X86

#ifndef ZIMG_RESIZE_RESIZE_IMPL_X86_H_
#define ZIMG_RESIZE_RESIZE_IMPL_X86_H_

#include "resize_impl.h"

namespace zimg {;
namespace resize {;

ResizeImpl *create_resize_impl_x86(const EvaluatedFilter &filter_h, const EvaluatedFilter &filter_v);

} // namespace resize
} // namespace zimg

#endif // ZIMG_RESIZE_RESIZE_IMPL_X86_H_

#endif // ZIMG_X86