/*
 * Copyright 2014 Google Inc.
 * Copyright 2015 Xamarin Inc.
 * Copyright 2017 Microsoft Corporation. All rights reserved.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkSVGCanvas.h"

#ifdef ESY_SKIA_SVG
#include "SkSVGDOM.h"
#include "SkSVGNode.h"
#endif

#include "sk_svg.h"

#include "sk_types_priv.h"

//////////////////////////////////////////////////////////////////////////////////////////////////

sk_canvas_t* sk_svgcanvas_create(const sk_rect_t* bounds, sk_xmlwriter_t* writer) {
    return ToCanvas(SkSVGCanvas::Make(*AsRect(bounds), AsXMLWriter(writer)).release());
}

#ifdef ESY_SKIA_SVG
void sk_svgdom_render(sk_svgdom_t *svgdom, sk_canvas_t *canvas) {
    AsSVGDOM(svgdom)->render(AsCanvas(canvas));
}

void sk_svgdom_set_container_size(sk_svgdom_t *svgdom, float width, float height) {
    AsSVGDOM(svgdom)->setContainerSize(SkSize::Make(width, height));
}

float sk_svgdom_get_container_width(sk_svgdom_t *svgdom) {
    return AsSVGDOM(svgdom)->containerSize().width();
}

float sk_svgdom_get_container_height(sk_svgdom_t *svgdom) {
    return AsSVGDOM(svgdom)->containerSize().height();
}

sk_svgdom_t *sk_svgdom_create_from_stream(sk_stream_t *stream) {
    std::unique_ptr<SkStream> skstream(AsStream(stream));
    return ToSVGDOM(SkSVGDOM::MakeFromStream(*skstream).release());
}
#endif
