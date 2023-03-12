
undefined4
engine_table_register
          (_LHASH **param_1,undefined4 param_2,LHASH_HASH_FN_TYPE param_3,int *param_4,int param_5,
          _LHASH *param_6)

{
  _LHASH *mode;
  _LHASH *ptr;
  int in_GS_OFFSET;
  code *pcVar1;
  char *pcVar2;
  undefined4 uVar3;
  int local_30 [4];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  mode = (_LHASH *)0x0;
  uVar3 = 0x87;
  pcVar2 = "eng_table.c";
  CRYPTO_lock(0,9,(char *)0x1e,(int)"eng_table.c");
  if (*param_1 == (_LHASH *)0x0) {
    pcVar1 = engine_pile_LHASH_COMP;
    mode = lh_new(engine_pile_LHASH_HASH,engine_pile_LHASH_COMP);
    if (mode == (_LHASH *)0x0) {
LAB_081c79b0:
      uVar3 = 0;
      goto LAB_081c79b2;
    }
    *param_1 = mode;
    mode = (_LHASH *)engine_cleanup_add_first(param_2,pcVar1,pcVar2,uVar3);
  }
  if (param_5 != 0) {
    do {
      while( true ) {
        local_30[0] = *param_4;
        ptr = (_LHASH *)lh_retrieve(*param_1,local_30);
        if (ptr == (_LHASH *)0x0) {
          ptr = (_LHASH *)CRYPTO_malloc(0x10,"eng_table.c",0x95);
          mode = ptr;
          if (ptr == (_LHASH *)0x0) goto LAB_081c79b0;
          ptr->num_nodes = 1;
          ptr->b = (LHASH_NODE **)*param_4;
          mode = (_LHASH *)sk_new_null();
          ptr->comp = (LHASH_COMP_FN_TYPE)mode;
          if (mode == (_LHASH *)0x0) {
            CRYPTO_free(ptr);
            goto LAB_081c79b0;
          }
          ptr->hash = (LHASH_HASH_FN_TYPE)0x0;
          lh_insert(*param_1,ptr);
        }
        sk_delete_ptr((_STACK *)ptr->comp,param_3);
        mode = (_LHASH *)sk_push((_STACK *)ptr->comp,param_3);
        if (mode == (_LHASH *)0x0) goto LAB_081c79b0;
        ptr->num_nodes = 0;
        if (param_6 == (_LHASH *)0x0) break;
        mode = (_LHASH *)engine_unlocked_init(param_3);
        if (mode == (_LHASH *)0x0) {
          uVar3 = 0;
          ERR_put_error(0x26,0xb8,0x6d,"eng_table.c",0xae);
          goto LAB_081c79b2;
        }
        mode = (_LHASH *)ptr->hash;
        if (mode != (_LHASH *)0x0) {
          mode = (_LHASH *)engine_unlocked_finish(mode,0);
        }
        param_4 = param_4 + 1;
        param_5 = param_5 + -1;
        ptr->hash = param_3;
        ptr->num_nodes = 1;
        if (param_5 == 0) goto LAB_081c793e;
      }
      param_4 = param_4 + 1;
      param_5 = param_5 + -1;
      mode = param_6;
    } while (param_5 != 0);
  }
LAB_081c793e:
  uVar3 = 1;
LAB_081c79b2:
  CRYPTO_lock((int)mode,10,(char *)0x1e,(int)"eng_table.c");
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3;
}

