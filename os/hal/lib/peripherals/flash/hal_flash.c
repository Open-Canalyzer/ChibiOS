/*
    N25Q128 Flash Driver - Copyright (C) 2016 Giovanni Di Sirio

    This file is part of ChibiOS.

    ChibiOS is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    ChibiOS is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/**
 * @file    hal_flash.c
 * @brief   Generic flash driver class code.
 *
 * @addtogroup HAL_FLASH
 * @{
 */

#include "hal.h"

#include "hal_flash.h"

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Waits until the current erase operation is finished.
 *
 * @param[in] devp      pointer to a @p BaseFlash object
 * @param[in] cb        polling callback or @p NULL
 */
flash_error_t flashWaitErase(BaseFlash *devp) {

  while (true) {
    flash_error_t err;
    uint32_t msec;

    /* Checking operation state.*/
    err = flashQueryErase(devp, &msec);
    if (err != FLASH_BUSY_ERASING) {
      return err;
    }

    /* Interval because nice waiting.*/
    osalThreadSleepMilliseconds(msec);
  }
}

/**
 * @brief   Returns the offset of a sector.
 */
flash_offset_t flashGetSectorOffset(BaseFlash *devp,
                                    flash_sector_t sector) {
  flash_offset_t offset;
  const flash_descriptor_t *descriptor = flashGetDescriptor(devp);

  osalDbgAssert(sector < descriptor->sectors_count, "invalid sector");

  if (descriptor->sectors != NULL) {
    offset = descriptor->sectors[sector].offset;
  }
  else {
    offset = (flash_offset_t)sector * (flash_offset_t)descriptor->sectors_size;
  }

  return offset;
}

/**
 * @brief   Returns the size of a sector.
 */
uint32_t flashGetSectorSize(BaseFlash *devp,
                            flash_sector_t sector) {
  uint32_t size;
  const flash_descriptor_t *descriptor = flashGetDescriptor(devp);

  osalDbgAssert(sector < descriptor->sectors_count, "invalid sector");

  if (descriptor->sectors != NULL) {
    size = descriptor->sectors[sector].size;
  }
  else {
    size = descriptor->sectors_size;
  }

  return size;
}

/** @} */
