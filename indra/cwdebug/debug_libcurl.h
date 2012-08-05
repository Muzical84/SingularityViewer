#ifndef DEBUG_LIBCURL
#define DEBUG_LIBCURL

#ifdef DEBUG_CURLIO

#include <curl/curl.h>
#include "debug.h"

extern "C" {

extern CWD_API void debug_curl_easy_cleanup(CURL* handle);
extern CWD_API CURL* debug_curl_easy_duphandle(CURL* handle);
extern CWD_API char* debug_curl_easy_escape(CURL* curl, char* url, int length);
extern CWD_API CURLcode debug_curl_easy_getinfo(CURL* curl, CURLINFO info, ...);
extern CWD_API CURL* debug_curl_easy_init(void);
extern CWD_API CURLcode debug_curl_easy_pause(CURL* handle, int bitmask);
extern CWD_API CURLcode debug_curl_easy_perform(CURL* handle);
extern CWD_API void debug_curl_easy_reset(CURL* handle);
extern CWD_API CURLcode debug_curl_easy_setopt(CURL* handle, CURLoption option, ...);
extern CWD_API char const* debug_curl_easy_strerror(CURLcode errornum);
extern CWD_API char* debug_curl_easy_unescape(CURL* curl, char* url, int inlength, int* outlength); 
extern CWD_API void debug_curl_free(char* ptr);
extern CWD_API time_t debug_curl_getdate(char const* datestring, time_t* now);
extern CWD_API void debug_curl_global_cleanup(void);
extern CWD_API CURLcode debug_curl_global_init(long flags);
extern CWD_API CURLMcode debug_curl_multi_add_handle(CURLM* multi_handle, CURL* easy_handle); 
extern CWD_API CURLMcode debug_curl_multi_assign(CURLM* multi_handle, curl_socket_t sockfd, void* sockptr);
extern CWD_API CURLMcode debug_curl_multi_cleanup(CURLM* multi_handle);
extern CWD_API CURLMsg* debug_curl_multi_info_read(CURLM* multi_handle, int* msgs_in_queue);
extern CWD_API CURLM* debug_curl_multi_init(void);
extern CWD_API CURLMcode debug_curl_multi_remove_handle(CURLM* multi_handle, CURL* easy_handle);
extern CWD_API CURLMcode debug_curl_multi_setopt(CURLM* multi_handle, CURLMoption option, ...);
extern CWD_API CURLMcode debug_curl_multi_socket_action(CURLM* multi_handle, curl_socket_t sockfd, int ev_bitmask, int* running_handles);
extern CWD_API char const* debug_curl_multi_strerror(CURLMcode errornum);
extern CWD_API struct curl_slist* debug_curl_slist_append(struct curl_slist* list, char const* string);
extern CWD_API void debug_curl_slist_free_all(struct curl_slist* list);
extern CWD_API char* debug_curl_unescape(char const* url, int length);
extern CWD_API char* debug_curl_version(void);

}

#ifndef COMPILING_DEBUG_LIBCURL_CC

#ifdef curl_easy_setopt
#undef curl_easy_setopt
#undef curl_easy_getinfo
#undef curl_multi_setopt
#endif

#define curl_easy_cleanup(handle) debug_curl_easy_cleanup(handle)
#define curl_easy_duphandle(handle) debug_curl_easy_duphandle(handle)
#define curl_easy_escape(curl, url, length) debug_curl_easy_escape(curl, url, length)
#define curl_easy_getinfo(curl, info, param) debug_curl_easy_getinfo(curl, info, param)
#define curl_easy_init() debug_curl_easy_init()
#define curl_easy_pause(handle, bitmask) debug_curl_easy_pause(handle, bitmask)
#define curl_easy_perform(handle) debug_curl_easy_perform(handle)
#define curl_easy_reset(handle) debug_curl_easy_reset(handle)
#define curl_easy_setopt(handle, option, param) debug_curl_easy_setopt(handle, option, param)
#define curl_easy_strerror(errornum) debug_curl_easy_strerror(errornum)
#define curl_easy_unescape(curl, url, inlength, outlength)  debug_curl_easy_unescape(curl, url, inlength, outlength) 
#define curl_free(ptr) debug_curl_free(ptr)
#define curl_getdate(datestring, now) debug_curl_getdate(datestring, now)
#define curl_global_cleanup() debug_curl_global_cleanup()
#define curl_global_init(flags) debug_curl_global_init(flags)
#define curl_multi_add_handle(multi_handle, easy_handle)  debug_curl_multi_add_handle(multi_handle, easy_handle) 
#define curl_multi_assign(multi_handle, sockfd, sockptr) debug_curl_multi_assign(multi_handle, sockfd, sockptr)
#define curl_multi_cleanup(multi_handle) debug_curl_multi_cleanup(multi_handle)
#define curl_multi_info_read(multi_handle, msgs_in_queue) debug_curl_multi_info_read(multi_handle, msgs_in_queue)
#define curl_multi_init() debug_curl_multi_init()
#define curl_multi_remove_handle(multi_handle, easy_handle) debug_curl_multi_remove_handle(multi_handle, easy_handle)
#define curl_multi_setopt(multi_handle, option, param) debug_curl_multi_setopt(multi_handle, option, param)
#define curl_multi_socket_action(multi_handle, sockfd, ev_bitmask, running_handles) debug_curl_multi_socket_action(multi_handle, sockfd, ev_bitmask, running_handles)
#define curl_multi_strerror(errornum) debug_curl_multi_strerror(errornum)
#define curl_slist_append(list, string) debug_curl_slist_append(list, string)
#define curl_slist_free_all(list) debug_curl_slist_free_all(list)
#define curl_unescape(url, length) debug_curl_unescape(url, length)
#define curl_version() debug_curl_version()

#endif // !COMPILING_DEBUG_LIBCURL_CC

#endif // DEBUG_CURLIO

#endif // DEBUG_LIBCURL
