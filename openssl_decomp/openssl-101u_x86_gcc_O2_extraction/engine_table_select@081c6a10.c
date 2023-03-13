
_LHASH * engine_table_select(_LHASH **param_1,undefined4 param_2)

{
  _LHASH *p_Var1;
  int mode;
  _LHASH *p_Var2;
  _LHASH *p_Var3;
  _LHASH *p_Var4;
  _LHASH *lh;
  int in_GS_OFFSET;
  undefined4 *data;
  char *pcVar5;
  undefined4 uVar6;
  undefined4 local_20 [4];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (*param_1 == (_LHASH *)0x0) {
    p_Var4 = (_LHASH *)0x0;
    goto LAB_081c6abf;
  }
  mode = ERR_set_mark();
  uVar6 = 0x103;
  pcVar5 = "eng_table.c";
  CRYPTO_lock(mode,9,(char *)0x1e,(int)"eng_table.c");
  lh = *param_1;
  if (lh == (_LHASH *)0x0) {
LAB_081c6aa0:
    p_Var4 = (_LHASH *)0x0;
  }
  else {
    local_20[0] = param_2;
    data = local_20;
    p_Var2 = (_LHASH *)lh_retrieve(lh,data);
    lh = p_Var2;
    if (p_Var2 == (_LHASH *)0x0) goto LAB_081c6aa0;
    if (((p_Var2->hash == (LHASH_HASH_FN_TYPE)0x0) ||
        (p_Var3 = (_LHASH *)engine_unlocked_init(p_Var2->hash,data,pcVar5,uVar6),
        p_Var3 == (_LHASH *)0x0)) && (p_Var3 = (_LHASH *)0x0, p_Var2->num_nodes == 0)) {
      do {
        p_Var1 = (_LHASH *)((int)&p_Var3->b + 1);
        p_Var4 = (_LHASH *)sk_value((_STACK *)p_Var2->comp,(int)p_Var3);
        lh = p_Var4;
        if (p_Var4 == (_LHASH *)0x0) goto LAB_081c6a93;
        p_Var3 = p_Var1;
      } while (((p_Var4->error < 1) && (((byte)table_flags & 1) != 0)) ||
              (lh = (_LHASH *)engine_unlocked_init(p_Var4), lh == (_LHASH *)0x0));
      if ((p_Var4 != (_LHASH *)p_Var2->hash) &&
         (lh = (_LHASH *)engine_unlocked_init(p_Var4), lh != (_LHASH *)0x0)) {
        lh = (_LHASH *)p_Var2->hash;
        if (lh != (_LHASH *)0x0) {
          lh = (_LHASH *)engine_unlocked_finish(lh,0);
        }
        p_Var2->hash = (LHASH_HASH_FN_TYPE)p_Var4;
      }
    }
    else {
      p_Var4 = (_LHASH *)p_Var2->hash;
      lh = p_Var3;
    }
LAB_081c6a93:
    p_Var2->num_nodes = 1;
  }
  CRYPTO_lock((int)lh,10,(char *)0x1e,(int)"eng_table.c");
  ERR_pop_to_mark();
LAB_081c6abf:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return p_Var4;
}

