/*
 *  fat_fat_operations.h
 *
 *  Constants/data structures/prototypes for operations on Files Allocation
 *  Table
 *
 *  Copyright (C) 2001 OKTET Ltd., St.-Petersburg, Russia
 *  Author: Eugeny S. Mints <Eugeny.Mints@oktet.ru>
 *
 *  The license and distribution terms for this file may be
 *  found in the file LICENSE in this distribution or at
 *  http://www.rtems.com/license/LICENSE.
 *
 *  @(#) $Id$
 */
#ifndef __DOSFS_FAT_FAT_OPERATIONS_H__
#define __DOSFS_FAT_FAT_OPERATIONS_H__

#include <rtems.h>
#include <rtems/libio_.h>

#include <rtems/bdbuf.h>

#ifdef __cplusplus
extern "C" {
#endif

#include "fat.h"

int
fat_get_fat_cluster(rtems_filesystem_mount_table_entry_t *mt_entry,
                    uint32_t                              cln,
                    uint32_t                             *ret_val);

int
fat_set_fat_cluster(rtems_filesystem_mount_table_entry_t *mt_entry,
                    uint32_t                              cln,
                    uint32_t                              in_val);

int
fat_scan_fat_for_free_clusters(
    rtems_filesystem_mount_table_entry_t *mt_entry,
    uint32_t                             *chain,
    uint32_t                              count,
    uint32_t                             *cls_added,
    uint32_t                             *last_cl
);

int
fat_free_fat_clusters_chain(
    rtems_filesystem_mount_table_entry_t *mt_entry,
    uint32_t                              chain
);

#ifdef __cplusplus
}
#endif

#endif /* __DOSFS_FAT_FAT_OPERATIONS_H__ */
