/* Copyright 2015 Samsung Electronics Co., Ltd.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/* Copyright Joyent, Inc. and other Node contributors. All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#ifndef __uv__async_header__
#define __uv__async_header__

#ifndef __uv_header__
#error Please include with uv.h
#endif


#ifdef __cplusplus
extern "C" {
#endif

//-----------------------------------------------------------------------------

#define ACCESS_ONCE(type, var)                                                \
  (*(volatile type*) &(var))


//-----------------------------------------------------------------------------

struct uv_async_s {
  UV_HANDLE_FIELDS
  UV_ASYNC_PRIVATE_FIELDS
};

int uv_async_init(uv_loop_t*, uv_async_t* async, uv_async_cb async_cb);
int uv_async_send(uv_async_t* async);
int uv_async_deinit(uv_loop_t* loop, uv_async_t* handle);


//-----------------------------------------------------------------------------

struct uv__io_s {
  uv__io_cb cb;
  void* pending_queue[2];
  void* watcher_queue[2];
  unsigned int pevents; /* Pending event mask i.e. mask at next tick. */
  unsigned int events;  /* Current event mask. */
  int fd;
  UV_IO_PRIVATE_PLATFORM_FIELDS
};


struct uv__async {
  uv__async_cb cb;
  uv__io_t io_watcher;
  int wfd;
};


void uv__async_send(struct uv__async* wa);
void uv__async_init(struct uv__async* wa);
int uv__async_start(uv_loop_t* loop, struct uv__async* wa, uv__async_cb cb);
void uv__async_stop(uv_loop_t* loop, struct uv__async* wa);
#if defined(__TUV_RAW__)
void uv__async_check(uv_loop_t* loop);
#endif

void uv__async_close(uv_async_t* handle);
int uv__async_make_pending(int* pending);

void uv__io_init(uv__io_t* w, uv__io_cb cb, int fd);
void uv__io_start(uv_loop_t* loop, uv__io_t* w, unsigned int events);
void uv__io_stop(uv_loop_t* loop, uv__io_t* w, unsigned int events);
void uv__io_close(uv_loop_t* loop, uv__io_t* w);

void uv__io_feed(uv_loop_t* loop, uv__io_t* w);
int uv__io_active(const uv__io_t* w, unsigned int events);
void uv__io_poll(uv_loop_t* loop, int timeout); /* in milliseconds or -1 */

//-----------------------------------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif // __uv__async_header__
