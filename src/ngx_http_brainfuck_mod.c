#include <ngx_config.h>
#include <ngx_core.h>
#include <ngx_http.h>

typedef struct {
  ngx_http_complex_value_t file_path;
} ngx_http_brainfuck_loc_conf_t;

static char *ngx_http_brainfuck(ngx_conf_t *cf, ngx_command_t *cmd,
    void *conf);

static ngx_command_t ngx_http_brainfuck_commands[] = {
  { ngx_string("brainfuck"),
    NGX_HTTP_LOC_CONF|NGX_CONF_NOARGS,
    ngx_http_brainfuck,
    NGX_HTTP_LOC_CONF_OFFSET,
    offsetof(ngx_http_brainfuck_loc_conf_t, file_path),
    NULL
  },

  ngx_null_command
};

static ngx_http_module_t  ngx_http_brainfuck_mod_ctx = {
  NULL,                          /* preconfiguration */
  NULL,                          /* postconfiguration */

  NULL,                          /* create main configuration */
  NULL,                          /* init main configuration */

  NULL,                          /* create server configuration */
  NULL,                          /* merge server configuration */

  NULL,                          /* create location configuration */
  NULL                           /* merge location configuration */
};

ngx_module_t  ngx_http_brainfuck_mod = {
  NGX_MODULE_V1,
  &ngx_http_brainfuck_mod_ctx, /* module context */
  ngx_http_brainfuck_commands,   /* module directives */
  NGX_HTTP_MODULE,               /* module type */
  NULL,                          /* init master */
  NULL,                          /* init module */
  NULL,                          /* init process */
  NULL,                          /* init thread */
  NULL,                          /* exit thread */
  NULL,                          /* exit process */
  NULL,                          /* exit master */
  NGX_MODULE_V1_PADDING
};

static ngx_str_t  ngx_http_html_type = ngx_string("text/html");

static ngx_int_t
ngx_http_brainfuck_handler(ngx_http_request_t *r)
{
  /* e.g) ngx_http_send_response
   * http://antoine.bonavita.free.fr/nginx_mod_dev_en.html
   * ngx_http_script_run
   * */

  ngx_http_complex_value_t cv;

  ngx_memzero(&cv, sizeof (ngx_http_complex_value_t));

  cv.value.len = NULL;
  cv.value.data = NULL;

  return ngx_http_send_response(r, NGX_HTTP_OK, &ngx_http_html_type, &cv);
}

static char *
ngx_http_brainfuck(ngx_conf_t *cf, ngx_command_t *cmd, void *conf)
{
  return NGX_CONF_OK;
}
