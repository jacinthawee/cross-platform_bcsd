
void int_thread_del_item(void *param_1)

{
  void *ptr;
  _LHASH *p_Var1;
  void *pvVar2;
  int iVar3;
  _LHASH *local_1c [2];
  
  if (err_fns == (undefined1 *)0x0) {
    CRYPTO_lock(9,1,"err.c",0x127);
    if (err_fns == (undefined1 *)0x0) {
      err_fns = &err_defaults;
    }
    CRYPTO_lock(10,1,"err.c",0x12a);
  }
  local_1c[0] = (_LHASH *)(**(code **)(err_fns + 0x14))(0);
  if (local_1c[0] != (_LHASH *)0x0) {
    CRYPTO_lock(9,1,"err.c",0x213);
    ptr = lh_delete(local_1c[0],param_1);
    if (((int_thread_hash_references == 1) && (int_thread_hash != (_LHASH *)0x0)) &&
       (p_Var1 = (_LHASH *)lh_num_items(int_thread_hash), p_Var1 == (_LHASH *)0x0)) {
      lh_free(int_thread_hash);
      int_thread_hash = p_Var1;
    }
    CRYPTO_lock(10,1,"err.c",0x21c);
    (**(code **)(err_fns + 0x18))(local_1c);
    if (ptr != (void *)0x0) {
      iVar3 = 0x10;
      pvVar2 = ptr;
      do {
        while ((*(void **)((int)pvVar2 + 0x88) != (void *)0x0 &&
               (*(int *)((int)pvVar2 + 200) << 0x1f < 0))) {
          CRYPTO_free(*(void **)((int)pvVar2 + 0x88));
          iVar3 = iVar3 + -1;
          *(undefined4 *)((int)pvVar2 + 0x88) = 0;
          *(undefined4 *)((int)pvVar2 + 200) = 0;
          pvVar2 = (void *)((int)pvVar2 + 4);
          if (iVar3 == 0) goto LAB_000a6f62;
        }
        iVar3 = iVar3 + -1;
        *(undefined4 *)((int)pvVar2 + 200) = 0;
        pvVar2 = (void *)((int)pvVar2 + 4);
      } while (iVar3 != 0);
LAB_000a6f62:
      CRYPTO_free(ptr);
    }
  }
  return;
}

