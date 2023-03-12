
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ERR_STATE * ERR_get_state(void)

{
  char *pcVar1;
  int mode;
  ERR_STATE *pEVar2;
  ERR_STATE *dest;
  void *ptr;
  uint uVar3;
  undefined4 *puVar4;
  int in_GS_OFFSET;
  byte bVar5;
  CRYPTO_THREADID local_1a8;
  CRYPTO_THREADID local_1a0 [50];
  int local_10;
  
  bVar5 = 0;
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  mode = 0;
  if (err_fns == (undefined1 *)0x0) {
    CRYPTO_lock(0,9,(char *)0x1,(int)"err.c");
    if (err_fns == (undefined1 *)0x0) {
      err_fns = err_defaults;
    }
    CRYPTO_lock(mode,10,(char *)0x1,(int)"err.c");
  }
  CRYPTO_THREADID_current(&local_1a8);
  CRYPTO_THREADID_cpy(local_1a0,&local_1a8);
  pEVar2 = (ERR_STATE *)(**(code **)(err_fns + 0x1c))(local_1a0);
  if (pEVar2 == (ERR_STATE *)0x0) {
    dest = (ERR_STATE *)CRYPTO_malloc(400,"err.c",0x3fb);
    pEVar2 = (ERR_STATE *)fallback_5560;
    if (dest != (ERR_STATE *)0x0) {
      CRYPTO_THREADID_cpy((CRYPTO_THREADID *)dest,&local_1a8);
      puVar4 = (undefined4 *)((uint)(dest->err_data + 1) & 0xfffffffc);
      dest->err_data[0] = (char *)0x0;
      dest->err_data[0xf] = (char *)0x0;
      dest->top = 0;
      dest->bottom = 0;
      uVar3 = (uint)((int)dest + (200 - (int)puVar4)) >> 2;
      for (; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar4 = 0;
        puVar4 = puVar4 + (uint)bVar5 * -2 + 1;
      }
      dest->err_data_flags[0] = 0;
      dest->err_data_flags[0xf] = 0;
      puVar4 = (undefined4 *)((uint)(dest->err_data_flags + 1) & 0xfffffffc);
      uVar3 = (uint)((int)dest + (0x108 - (int)puVar4)) >> 2;
      for (; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar4 = 0;
        puVar4 = puVar4 + (uint)bVar5 * -2 + 1;
      }
      ptr = (void *)(**(code **)(err_fns + 0x20))(dest);
      pEVar2 = (ERR_STATE *)(**(code **)(err_fns + 0x1c))(dest);
      if (dest == pEVar2) {
        pEVar2 = dest;
        if (ptr != (void *)0x0) {
          if ((*(void **)((int)ptr + 0x88) != (void *)0x0) && ((*(byte *)((int)ptr + 200) & 1) != 0)
             ) {
            CRYPTO_free(*(void **)((int)ptr + 0x88));
            *(undefined4 *)((int)ptr + 0x88) = 0;
          }
          *(undefined4 *)((int)ptr + 200) = 0;
          if ((*(void **)((int)ptr + 0x8c) != (void *)0x0) &&
             ((*(byte *)((int)ptr + 0xcc) & 1) != 0)) {
            CRYPTO_free(*(void **)((int)ptr + 0x8c));
            *(undefined4 *)((int)ptr + 0x8c) = 0;
          }
          *(undefined4 *)((int)ptr + 0xcc) = 0;
          if ((*(void **)((int)ptr + 0x90) != (void *)0x0) &&
             ((*(byte *)((int)ptr + 0xd0) & 1) != 0)) {
            CRYPTO_free(*(void **)((int)ptr + 0x90));
            *(undefined4 *)((int)ptr + 0x90) = 0;
          }
          *(undefined4 *)((int)ptr + 0xd0) = 0;
          if ((*(void **)((int)ptr + 0x94) != (void *)0x0) &&
             ((*(byte *)((int)ptr + 0xd4) & 1) != 0)) {
            CRYPTO_free(*(void **)((int)ptr + 0x94));
            *(undefined4 *)((int)ptr + 0x94) = 0;
          }
          *(undefined4 *)((int)ptr + 0xd4) = 0;
          if ((*(void **)((int)ptr + 0x98) != (void *)0x0) &&
             ((*(byte *)((int)ptr + 0xd8) & 1) != 0)) {
            CRYPTO_free(*(void **)((int)ptr + 0x98));
            *(undefined4 *)((int)ptr + 0x98) = 0;
          }
          *(undefined4 *)((int)ptr + 0xd8) = 0;
          if ((*(void **)((int)ptr + 0x9c) != (void *)0x0) &&
             ((*(byte *)((int)ptr + 0xdc) & 1) != 0)) {
            CRYPTO_free(*(void **)((int)ptr + 0x9c));
            *(undefined4 *)((int)ptr + 0x9c) = 0;
          }
          *(undefined4 *)((int)ptr + 0xdc) = 0;
          if ((*(void **)((int)ptr + 0xa0) != (void *)0x0) &&
             ((*(byte *)((int)ptr + 0xe0) & 1) != 0)) {
            CRYPTO_free(*(void **)((int)ptr + 0xa0));
            *(undefined4 *)((int)ptr + 0xa0) = 0;
          }
          *(undefined4 *)((int)ptr + 0xe0) = 0;
          if ((*(void **)((int)ptr + 0xa4) != (void *)0x0) &&
             ((*(byte *)((int)ptr + 0xe4) & 1) != 0)) {
            CRYPTO_free(*(void **)((int)ptr + 0xa4));
            *(undefined4 *)((int)ptr + 0xa4) = 0;
          }
          *(undefined4 *)((int)ptr + 0xe4) = 0;
          if ((*(void **)((int)ptr + 0xa8) != (void *)0x0) &&
             ((*(byte *)((int)ptr + 0xe8) & 1) != 0)) {
            CRYPTO_free(*(void **)((int)ptr + 0xa8));
            *(undefined4 *)((int)ptr + 0xa8) = 0;
          }
          *(undefined4 *)((int)ptr + 0xe8) = 0;
          if ((*(void **)((int)ptr + 0xac) != (void *)0x0) &&
             ((*(byte *)((int)ptr + 0xec) & 1) != 0)) {
            CRYPTO_free(*(void **)((int)ptr + 0xac));
            *(undefined4 *)((int)ptr + 0xac) = 0;
          }
          *(undefined4 *)((int)ptr + 0xec) = 0;
          if ((*(void **)((int)ptr + 0xb0) != (void *)0x0) &&
             ((*(byte *)((int)ptr + 0xf0) & 1) != 0)) {
            CRYPTO_free(*(void **)((int)ptr + 0xb0));
            *(undefined4 *)((int)ptr + 0xb0) = 0;
          }
          *(undefined4 *)((int)ptr + 0xf0) = 0;
          if ((*(void **)((int)ptr + 0xb4) != (void *)0x0) &&
             ((*(byte *)((int)ptr + 0xf4) & 1) != 0)) {
            CRYPTO_free(*(void **)((int)ptr + 0xb4));
            *(undefined4 *)((int)ptr + 0xb4) = 0;
          }
          *(undefined4 *)((int)ptr + 0xf4) = 0;
          if ((*(void **)((int)ptr + 0xb8) != (void *)0x0) &&
             ((*(byte *)((int)ptr + 0xf8) & 1) != 0)) {
            CRYPTO_free(*(void **)((int)ptr + 0xb8));
            *(undefined4 *)((int)ptr + 0xb8) = 0;
          }
          *(undefined4 *)((int)ptr + 0xf8) = 0;
          if ((*(void **)((int)ptr + 0xbc) != (void *)0x0) &&
             ((*(byte *)((int)ptr + 0xfc) & 1) != 0)) {
            CRYPTO_free(*(void **)((int)ptr + 0xbc));
            *(undefined4 *)((int)ptr + 0xbc) = 0;
          }
          *(undefined4 *)((int)ptr + 0xfc) = 0;
          if ((*(void **)((int)ptr + 0xc0) != (void *)0x0) &&
             ((*(byte *)((int)ptr + 0x100) & 1) != 0)) {
            CRYPTO_free(*(void **)((int)ptr + 0xc0));
            *(undefined4 *)((int)ptr + 0xc0) = 0;
          }
          *(undefined4 *)((int)ptr + 0x100) = 0;
          if ((*(void **)((int)ptr + 0xc4) != (void *)0x0) &&
             ((*(byte *)((int)ptr + 0x104) & 1) != 0)) {
            CRYPTO_free(*(void **)((int)ptr + 0xc4));
            *(undefined4 *)((int)ptr + 0xc4) = 0;
          }
          *(undefined4 *)((int)ptr + 0x104) = 0;
          CRYPTO_free(ptr);
        }
      }
      else {
        if ((dest->err_data[0] != (char *)0x0) && ((*(byte *)dest->err_data_flags & 1) != 0)) {
          CRYPTO_free(dest->err_data[0]);
          dest->err_data[0] = (char *)0x0;
        }
        pcVar1 = dest->err_data[1];
        dest->err_data_flags[0] = 0;
        if ((pcVar1 != (char *)0x0) && ((*(byte *)(dest->err_data_flags + 1) & 1) != 0)) {
          CRYPTO_free(pcVar1);
          dest->err_data[1] = (char *)0x0;
        }
        pcVar1 = dest->err_data[2];
        dest->err_data_flags[1] = 0;
        if ((pcVar1 != (char *)0x0) && ((*(byte *)(dest->err_data_flags + 2) & 1) != 0)) {
          CRYPTO_free(pcVar1);
          dest->err_data[2] = (char *)0x0;
        }
        pcVar1 = dest->err_data[3];
        dest->err_data_flags[2] = 0;
        if ((pcVar1 != (char *)0x0) && ((*(byte *)(dest->err_data_flags + 3) & 1) != 0)) {
          CRYPTO_free(pcVar1);
          dest->err_data[3] = (char *)0x0;
        }
        pcVar1 = dest->err_data[4];
        dest->err_data_flags[3] = 0;
        if ((pcVar1 != (char *)0x0) && ((*(byte *)(dest->err_data_flags + 4) & 1) != 0)) {
          CRYPTO_free(pcVar1);
          dest->err_data[4] = (char *)0x0;
        }
        pcVar1 = dest->err_data[5];
        dest->err_data_flags[4] = 0;
        if ((pcVar1 != (char *)0x0) && ((*(byte *)(dest->err_data_flags + 5) & 1) != 0)) {
          CRYPTO_free(pcVar1);
          dest->err_data[5] = (char *)0x0;
        }
        pcVar1 = dest->err_data[6];
        dest->err_data_flags[5] = 0;
        if ((pcVar1 != (char *)0x0) && ((*(byte *)(dest->err_data_flags + 6) & 1) != 0)) {
          CRYPTO_free(pcVar1);
          dest->err_data[6] = (char *)0x0;
        }
        pcVar1 = dest->err_data[7];
        dest->err_data_flags[6] = 0;
        if ((pcVar1 != (char *)0x0) && ((*(byte *)(dest->err_data_flags + 7) & 1) != 0)) {
          CRYPTO_free(pcVar1);
          dest->err_data[7] = (char *)0x0;
        }
        pcVar1 = dest->err_data[8];
        dest->err_data_flags[7] = 0;
        if ((pcVar1 != (char *)0x0) && ((*(byte *)(dest->err_data_flags + 8) & 1) != 0)) {
          CRYPTO_free(pcVar1);
          dest->err_data[8] = (char *)0x0;
        }
        pcVar1 = dest->err_data[9];
        dest->err_data_flags[8] = 0;
        if ((pcVar1 != (char *)0x0) && ((*(byte *)(dest->err_data_flags + 9) & 1) != 0)) {
          CRYPTO_free(pcVar1);
          dest->err_data[9] = (char *)0x0;
        }
        pcVar1 = dest->err_data[10];
        dest->err_data_flags[9] = 0;
        if ((pcVar1 != (char *)0x0) && ((*(byte *)(dest->err_data_flags + 10) & 1) != 0)) {
          CRYPTO_free(pcVar1);
          dest->err_data[10] = (char *)0x0;
        }
        pcVar1 = dest->err_data[0xb];
        dest->err_data_flags[10] = 0;
        if ((pcVar1 != (char *)0x0) && ((*(byte *)(dest->err_data_flags + 0xb) & 1) != 0)) {
          CRYPTO_free(pcVar1);
          dest->err_data[0xb] = (char *)0x0;
        }
        pcVar1 = dest->err_data[0xc];
        dest->err_data_flags[0xb] = 0;
        if ((pcVar1 != (char *)0x0) && ((*(byte *)(dest->err_data_flags + 0xc) & 1) != 0)) {
          CRYPTO_free(pcVar1);
          dest->err_data[0xc] = (char *)0x0;
        }
        pcVar1 = dest->err_data[0xd];
        dest->err_data_flags[0xc] = 0;
        if ((pcVar1 != (char *)0x0) && ((*(byte *)(dest->err_data_flags + 0xd) & 1) != 0)) {
          CRYPTO_free(pcVar1);
          dest->err_data[0xd] = (char *)0x0;
        }
        pcVar1 = dest->err_data[0xe];
        dest->err_data_flags[0xd] = 0;
        if ((pcVar1 != (char *)0x0) && ((*(byte *)(dest->err_data_flags + 0xe) & 1) != 0)) {
          CRYPTO_free(pcVar1);
          dest->err_data[0xe] = (char *)0x0;
        }
        pcVar1 = dest->err_data[0xf];
        dest->err_data_flags[0xe] = 0;
        if ((pcVar1 != (char *)0x0) && ((*(byte *)(dest->err_data_flags + 0xf) & 1) != 0)) {
          CRYPTO_free(pcVar1);
          dest->err_data[0xf] = (char *)0x0;
        }
        dest->err_data_flags[0xf] = 0;
        CRYPTO_free(dest);
        pEVar2 = (ERR_STATE *)fallback_5560;
      }
    }
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pEVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

