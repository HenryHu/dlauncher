#ifndef __DLAUNCHER_PLUGIN_H__
#define __DLAUNCHER_PLUGIN_H__

#include "item.h"

#if __cplusplus
extern "C" {
#endif

    typedef struct dl_plugin_s *dl_plugin_t;
    typedef struct dl_plugin_s {
        void *priv;

        const char *name;

        unsigned int item_count;
        unsigned int item_default_sel;
        dl_item_s   *item_entry;

        int (*update)  (dl_plugin_t self, const char *input);
        int (*describe)(dl_plugin_t self, unsigned int index, const char **output_ptr);
    } dl_plugin_s;

    void register_plugin(dl_plugin_t plugin);
    
#if __cplusplus
}
#endif

#endif
