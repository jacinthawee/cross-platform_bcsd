
void int_thread_del_item(void *param_1)

{
  void *pvVar1;
  undefined1 *mode;
  _LHASH *ptr;
  _LHASH *mode_00;
  int in_GS_OFFSET;
  undefined4 uVar2;
  char *pcVar3;
  undefined4 uVar4;
  _LHASH *local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (err_fns == (undefined1 *)0x0) {
    CRYPTO_lock(0,9,(char *)0x1,(int)"err.c");
    mode = err_fns;
    if (err_fns == (undefined1 *)0x0) {
      err_fns = err_defaults;
    }
    CRYPTO_lock((int)mode,10,(char *)0x1,(int)"err.c");
  }
  local_14 = (_LHASH *)(**(code **)(err_fns + 0x14))(0);
  if (local_14 != (_LHASH *)0x0) {
    CRYPTO_lock((int)local_14,9,(char *)0x1,(int)"err.c");
    ptr = (_LHASH *)lh_delete(local_14,param_1);
    mode_00 = ptr;
    if ((int_thread_hash_references == 1) &&
       (mode_00 = int_thread_hash, int_thread_hash != (_LHASH *)0x0)) {
      mode_00 = (_LHASH *)lh_num_items(int_thread_hash);
      if (mode_00 == (_LHASH *)0x0) {
        lh_free(int_thread_hash);
        int_thread_hash = (_LHASH *)0x0;
      }
    }
    uVar4 = 0x21c;
    pcVar3 = "err.c";
    uVar2 = 1;
    CRYPTO_lock((int)mode_00,10,(char *)0x1,(int)"err.c");
    (**(code **)(err_fns + 0x18))(&local_14,uVar2,pcVar3,uVar4);
    if (ptr != (_LHASH *)0x0) {
      if (((void *)ptr[1].num_expands != (void *)0x0) && ((*(byte *)&ptr[2].hash & 1) != 0)) {
        CRYPTO_free((void *)ptr[1].num_expands);
        ptr[1].num_expands = 0;
      }
      pvVar1 = (void *)ptr[1].num_expand_reallocs;
      ptr[2].hash = (LHASH_HASH_FN_TYPE)0x0;
      if ((pvVar1 != (void *)0x0) && ((*(byte *)&ptr[2].num_nodes & 1) != 0)) {
        CRYPTO_free(pvVar1);
        ptr[1].num_expand_reallocs = 0;
      }
      pvVar1 = (void *)ptr[1].num_contracts;
      ptr[2].num_nodes = 0;
      if ((pvVar1 != (void *)0x0) && ((*(byte *)&ptr[2].num_alloc_nodes & 1) != 0)) {
        CRYPTO_free(pvVar1);
        ptr[1].num_contracts = 0;
      }
      pvVar1 = (void *)ptr[1].num_contract_reallocs;
      ptr[2].num_alloc_nodes = 0;
      if ((pvVar1 != (void *)0x0) && ((*(byte *)&ptr[2].p & 1) != 0)) {
        CRYPTO_free(pvVar1);
        ptr[1].num_contract_reallocs = 0;
      }
      pvVar1 = (void *)ptr[1].num_hash_calls;
      ptr[2].p = 0;
      if ((pvVar1 != (void *)0x0) && ((*(byte *)&ptr[2].pmax & 1) != 0)) {
        CRYPTO_free(pvVar1);
        ptr[1].num_hash_calls = 0;
      }
      pvVar1 = (void *)ptr[1].num_comp_calls;
      ptr[2].pmax = 0;
      if ((pvVar1 != (void *)0x0) && ((*(byte *)&ptr[2].up_load & 1) != 0)) {
        CRYPTO_free(pvVar1);
        ptr[1].num_comp_calls = 0;
      }
      pvVar1 = (void *)ptr[1].num_insert;
      ptr[2].up_load = 0;
      if ((pvVar1 != (void *)0x0) && ((*(byte *)&ptr[2].down_load & 1) != 0)) {
        CRYPTO_free(pvVar1);
        ptr[1].num_insert = 0;
      }
      pvVar1 = (void *)ptr[1].num_replace;
      ptr[2].down_load = 0;
      if ((pvVar1 != (void *)0x0) && ((*(byte *)&ptr[2].num_items & 1) != 0)) {
        CRYPTO_free(pvVar1);
        ptr[1].num_replace = 0;
      }
      pvVar1 = (void *)ptr[1].num_delete;
      ptr[2].num_items = 0;
      if ((pvVar1 != (void *)0x0) && ((*(byte *)&ptr[2].num_expands & 1) != 0)) {
        CRYPTO_free(pvVar1);
        ptr[1].num_delete = 0;
      }
      pvVar1 = (void *)ptr[1].num_no_delete;
      ptr[2].num_expands = 0;
      if ((pvVar1 != (void *)0x0) && ((*(byte *)&ptr[2].num_expand_reallocs & 1) != 0)) {
        CRYPTO_free(pvVar1);
        ptr[1].num_no_delete = 0;
      }
      pvVar1 = (void *)ptr[1].num_retrieve;
      ptr[2].num_expand_reallocs = 0;
      if ((pvVar1 != (void *)0x0) && ((*(byte *)&ptr[2].num_contracts & 1) != 0)) {
        CRYPTO_free(pvVar1);
        ptr[1].num_retrieve = 0;
      }
      pvVar1 = (void *)ptr[1].num_retrieve_miss;
      ptr[2].num_contracts = 0;
      if ((pvVar1 != (void *)0x0) && ((*(byte *)&ptr[2].num_contract_reallocs & 1) != 0)) {
        CRYPTO_free(pvVar1);
        ptr[1].num_retrieve_miss = 0;
      }
      pvVar1 = (void *)ptr[1].num_hash_comps;
      ptr[2].num_contract_reallocs = 0;
      if ((pvVar1 != (void *)0x0) && ((*(byte *)&ptr[2].num_hash_calls & 1) != 0)) {
        CRYPTO_free(pvVar1);
        ptr[1].num_hash_comps = 0;
      }
      pvVar1 = (void *)ptr[1].error;
      ptr[2].num_hash_calls = 0;
      if ((pvVar1 != (void *)0x0) && ((*(byte *)&ptr[2].num_comp_calls & 1) != 0)) {
        CRYPTO_free(pvVar1);
        ptr[1].error = 0;
      }
      ptr[2].num_comp_calls = 0;
      if ((ptr[2].b != (LHASH_NODE **)0x0) && ((*(byte *)&ptr[2].num_insert & 1) != 0)) {
        CRYPTO_free(ptr[2].b);
        ptr[2].b = (LHASH_NODE **)0x0;
      }
      ptr[2].num_insert = 0;
      if ((ptr[2].comp != (LHASH_COMP_FN_TYPE)0x0) && ((*(byte *)&ptr[2].num_replace & 1) != 0)) {
        CRYPTO_free(ptr[2].comp);
        ptr[2].comp = (LHASH_COMP_FN_TYPE)0x0;
      }
      ptr[2].num_replace = 0;
      CRYPTO_free(ptr);
    }
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

