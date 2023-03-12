
_LHASH * engine_table_select(_LHASH **param_1,undefined4 param_2)

{
  _LHASH *p_Var1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  undefined4 local_28 [5];
  
  p_Var1 = *param_1;
  if (p_Var1 != (_LHASH *)0x0) {
    ERR_set_mark();
    CRYPTO_lock(9,0x1e,"eng_table.c",0x103);
    if ((*param_1 == (_LHASH *)0x0) ||
       (local_28[0] = param_2, pvVar2 = lh_retrieve(*param_1,local_28), pvVar2 == (void *)0x0)) {
      p_Var1 = (_LHASH *)0x0;
    }
    else {
      if (((*(int *)((int)pvVar2 + 8) == 0) || (iVar3 = engine_unlocked_init(), iVar3 == 0)) &&
         (iVar3 = *(int *)((int)pvVar2 + 0xc), *(int *)((int)pvVar2 + 0xc) == 0)) {
        do {
          iVar4 = iVar3 + 1;
          p_Var1 = (_LHASH *)sk_value(*(_STACK **)((int)pvVar2 + 4),iVar3);
          if (p_Var1 == (_LHASH *)0x0) goto LAB_00109ef8;
          iVar3 = iVar4;
        } while (((p_Var1->error < 1) && (table_flags << 0x1f < 0)) ||
                (iVar4 = engine_unlocked_init(), iVar4 == 0));
        if ((p_Var1 != *(_LHASH **)((int)pvVar2 + 8)) &&
           (iVar3 = engine_unlocked_init(p_Var1), iVar3 != 0)) {
          if (*(int *)((int)pvVar2 + 8) != 0) {
            engine_unlocked_finish(*(int *)((int)pvVar2 + 8),0);
          }
          *(_LHASH **)((int)pvVar2 + 8) = p_Var1;
        }
      }
      else {
        p_Var1 = *(_LHASH **)((int)pvVar2 + 8);
      }
LAB_00109ef8:
      *(undefined4 *)((int)pvVar2 + 0xc) = 1;
    }
    CRYPTO_lock(10,0x1e,"eng_table.c",0x14a);
    ERR_pop_to_mark();
  }
  return p_Var1;
}

