#include <stdio.h>
#include "ngx_config.h"
#include "ngx_conf_file.h"
#include "nginx.h"
#include "ngx_core.h"
#include "ngx_string.h"
#include "ngx_palloc.h"
#include "ngx_log.h"

volatile ngx_cycle_t *ngx_cycle;

static ngx_log_t        ngx_log;
static ngx_open_file_t  ngx_log_file;

void ngx_log_error_core(ngx_uint_t level, ngx_log_t *log, ngx_err_t err,
			const char *fmt, ...)
{
}

void dump_pool(ngx_pool_t* pool)  
{
    while (pool)  
    {  
	printf("pool = %p\n", pool);  
        printf("  .d\n");  
        printf("    .last = %p\n", pool->d.last);  
        printf("    .end = %p\n", pool->d.end);  
        printf("    .next = %p\n", pool->d.next);  
        printf("    .failed = %lu\n", pool->d.failed);  
        printf("  .max = %lu\n", pool->max);  
        printf("  .current = %p\n", pool->current);  
        printf("  .chain = %p\n", pool->chain);  
        printf("  .large = %p\n", pool->large);  
        printf("  .cleanup = %p\n", pool->cleanup);  
        printf("  .log = %p\n", pool->log);  
        printf("available pool memory = %ld\n\n", pool->d.end - pool->d.last);  
        pool = pool->d.next;  
    }  
}  
  
int main()  
{
    ngx_pool_t *pool;

    ngx_log_file.fd = ngx_stderr;
    
    ngx_log.file = &ngx_log_file;
    ngx_log.log_level = NGX_LOG_NOTICE;

    printf("--------------------------------\n");
    printf("create a new pool:\n");
    printf("--------------------------------\n");
    pool = ngx_create_pool(1024, &ngx_log);
    dump_pool(pool);
  
    printf("--------------------------------\n");
    printf("alloc block 1 from the pool:\n");
    printf("--------------------------------\n");
    ngx_palloc(pool, 512);
    dump_pool(pool);

    printf("--------------------------------\n");
    printf("alloc block 2 from the pool:\n");
    printf("--------------------------------\n");
    ngx_palloc(pool, 512);
    dump_pool(pool);

    printf("--------------------------------\n");
    printf("alloc block 3 from the pool :\n");
    printf("--------------------------------\n");
    ngx_palloc(pool, 512);
    dump_pool(pool);

    ngx_destroy_pool(pool);
    return 0;
}
