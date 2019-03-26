/* public domain */

#include <pulse/pulseaudio.h>
#include <errno.h>

int pa_context_connect(pa_context* c, const char* server, pa_context_flags_t flags, const pa_spawn_api* api) {
    return -1;
}

void pa_context_disconnect(pa_context* c) { }

int pa_context_errno(pa_context* c) { return ENODEV; }

pa_context_state_t pa_context_get_state(pa_context* c) { return PA_CONTEXT_FAILED; }

pa_context* pa_context_new(pa_mainloop_api* api, const char* name) { return NULL; }

pa_operation* pa_context_set_sink_input_mute(
    pa_context* c,
    uint32_t idx,
    int mute,
    pa_context_success_cb_t cb,
    void* userdata) {
    return NULL;
}

pa_operation* pa_context_set_sink_input_volume(
    pa_context* c,
    uint32_t idx,
    const pa_cvolume* vol,
    pa_context_success_cb_t cb,
    void* userdata) {
    return NULL;
}

pa_operation* pa_context_set_source_mute_by_index(
    pa_context* c,
    uint32_t idx,
    int mute,
    pa_context_success_cb_t cb,
    void* userdata) {
    return NULL;
}

pa_operation* pa_context_set_source_volume_by_index(
    pa_context* c,
    uint32_t idx,
    const pa_cvolume* volume,
    pa_context_success_cb_t cb,
    void* userdata) {
    return NULL;
}


void pa_context_set_state_callback(
   pa_context* c,
   pa_context_notify_cb_t cb,
   void* userdata) { } 

void pa_context_unref(pa_context *c) { }

pa_cvolume* pa_cvolume_init(pa_cvolume *a) { return NULL; }

void pa_operation_unref (pa_operation* o) { }

int pa_stream_connect_playback(
    pa_stream* s,
    const char* dev,
    const pa_buffer_attr* attr,
    pa_stream_flags_t flags,
    const pa_cvolume* volume,
    pa_stream* sync_stream) { return -1; }

int pa_stream_connect_record(
    pa_stream* s,
    const char* dev,
    const pa_buffer_attr* attr,
    pa_stream_flags_t   flags) { return -1; }

pa_operation* pa_stream_cork(
    pa_stream* s,
    int b,
    pa_stream_success_cb_t cb,
    void* userdata) { return NULL; }

int pa_stream_drop(pa_stream *p) { return -1; }

uint32_t pa_stream_get_device_index(pa_stream* s) { return PA_INVALID_INDEX; }

uint32_t pa_stream_get_index(pa_stream* s) { return PA_INVALID_INDEX; }

pa_stream_state_t pa_stream_get_state(pa_stream* p) { return PA_STREAM_FAILED; }

int pa_stream_is_corked(pa_stream *s) { return -1; }

pa_stream* pa_stream_new(
    pa_context* c,
    const char* name,
    const pa_sample_spec* ss,
    const pa_channel_map* map) {
    return NULL;
}

int pa_stream_peek(
    pa_stream* p,
    const void** data,
    size_t* nbytes) {
    return -1;
}


void pa_stream_set_read_callback(
    pa_stream* p,
    pa_stream_request_cb_t cb,
    void* userdata) { }


void pa_stream_set_state_callback(
    pa_stream* s,
    pa_stream_notify_cb_t cb,
    void* userdata) { }

void pa_stream_set_write_callback(
    pa_stream* p,
    pa_stream_request_cb_t cb,
    void* userdata) { }

void pa_stream_unref(pa_stream* s) { }

size_t pa_stream_writable_size(pa_stream* p) { return 0; }

int pa_stream_write(
    pa_stream* p,
    const void* data,
    size_t nbytes,
    pa_free_cb_t free_cb,
    int64_t offset,
    pa_seek_mode_t seek) {
    return -1;
}

const char* pa_strerror(int error) { return "Using headless implementation"; }

void pa_threaded_mainloop_free(pa_threaded_mainloop* m) { }

pa_mainloop_api* pa_threaded_mainloop_get_api(pa_threaded_mainloop *m) { return NULL; }

void pa_threaded_mainloop_lock(pa_threaded_mainloop *m) { }

pa_threaded_mainloop* pa_threaded_mainloop_new(void) { return NULL; }

void pa_threaded_mainloop_signal(pa_threaded_mainloop *m, int wait_for_accept) { }

int pa_threaded_mainloop_start(pa_threaded_mainloop *m) { return -1; }

void pa_threaded_mainloop_stop(pa_threaded_mainloop *m) { }

void pa_threaded_mainloop_unlock(pa_threaded_mainloop *m) { }

void pa_threaded_mainloop_wait(pa_threaded_mainloop *m) { }

size_t pa_usec_to_bytes(pa_usec_t t, const pa_sample_spec *spec) { return 1; }




