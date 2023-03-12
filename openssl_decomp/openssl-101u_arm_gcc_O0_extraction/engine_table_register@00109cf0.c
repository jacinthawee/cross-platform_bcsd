
_STACK * engine_table_register
                   (_LHASH **param_1,undefined4 param_2,void *param_3,undefined4 *param_4,
                   int param_5,int param_6)

{
  undefined4 *ptr;
  int iVar1;
  _LHASH *p_Var2;
  _STACK *p_Var3;
  undefined4 local_38 [5];
  
  CRYPTO_lock(9,0x1e,"eng_table.c",0x8a);
  if (*param_1 == (_LHASH *)0x0) {
    p_Var2 = lh_new(engine_pile_LHASH_HASH + 1,engine_pile_LHASH_COMP + 1);
    if (p_Var2 == (_LHASH *)0x0) {
LAB_00109dba:
      p_Var3 = (_STACK *)0x0;
      goto LAB_00109dbc;
    }
    *param_1 = p_Var2;
    engine_cleanup_add_first(param_2);
  }
  if (param_5 != 0) {
    do {
      while( true ) {
        local_38[0] = *param_4;
        ptr = (undefined4 *)lh_retrieve(*param_1,local_38);
        if (ptr == (undefined4 *)0x0) {
          ptr = (undefined4 *)CRYPTO_malloc(0x10,"eng_table.c",0x96);
          if (ptr == (undefined4 *)0x0) goto LAB_00109dba;
          ptr[3] = 1;
          *ptr = *param_4;
          p_Var3 = sk_new_null();
          ptr[1] = p_Var3;
          if (p_Var3 == (_STACK *)0x0) {
            CRYPTO_free(ptr);
            goto LAB_00109dbc;
          }
          ptr[2] = 0;
          lh_insert(*param_1,ptr);
        }
        sk_delete_ptr((_STACK *)ptr[1],param_3);
        iVar1 = sk_push((_STACK *)ptr[1],param_3);
        if (iVar1 == 0) goto LAB_00109dba;
        ptr[3] = 0;
        if (param_6 == 0) break;
        p_Var3 = (_STACK *)engine_unlocked_init(param_3);
        if (p_Var3 == (_STACK *)0x0) {
          ERR_put_error(0x26,0xb8,0x6d,"eng_table.c",0xaf);
          goto LAB_00109dbc;
        }
        if (ptr[2] != 0) {
          engine_unlocked_finish(ptr[2],0);
        }
        param_5 = param_5 + -1;
        ptr[2] = param_3;
        ptr[3] = 1;
        param_4 = param_4 + 1;
        if (param_5 == 0) goto LAB_00109d7e;
      }
      param_5 = param_5 + -1;
      param_4 = param_4 + 1;
    } while (param_5 != 0);
  }
LAB_00109d7e:
  p_Var3 = (_STACK *)0x1;
LAB_00109dbc:
  CRYPTO_lock(10,0x1e,"eng_table.c",0xbb);
  return p_Var3;
}

