
undefined4 * int_new_ex_data(undefined4 param_1,undefined4 param_2,_STACK **param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *ptr;
  void *pvVar3;
  int iVar4;
  _STACK *p_Var5;
  int iVar6;
  void **ppvVar7;
  code *pcVar8;
  undefined4 *puVar9;
  
  puVar1 = (undefined4 *)def_get_class();
  ptr = puVar1;
  if (puVar1 != (undefined4 *)0x0) {
    iVar6 = 0;
    *param_3 = (_STACK *)0x0;
    CRYPTO_lock(5,2,"ex_data.c",0x1aa);
    iVar2 = sk_num((_STACK *)puVar1[1]);
    if (iVar2 < 1) {
      CRYPTO_lock(6,2,"ex_data.c",0x1b4);
      return (undefined4 *)0x1;
    }
    ptr = (undefined4 *)CRYPTO_malloc(iVar2 * 4,"ex_data.c",0x1ad);
    if (ptr == (undefined4 *)0x0) {
      CRYPTO_lock(6,2,"ex_data.c",0x1b4);
      ERR_put_error(0xf,0x6c,0x41,"ex_data.c",0x1b6);
    }
    else {
      ppvVar7 = (void **)(ptr + -1);
      do {
        pvVar3 = sk_value((_STACK *)puVar1[1],iVar6);
        iVar6 = iVar6 + 1;
        ppvVar7 = ppvVar7 + 1;
        *ppvVar7 = pvVar3;
      } while (iVar6 != iVar2);
      CRYPTO_lock(6,2,"ex_data.c",0x1b4);
      iVar6 = 0;
      puVar1 = ptr;
      do {
        puVar9 = (undefined4 *)*puVar1;
        if ((puVar9 != (undefined4 *)0x0) && (pcVar8 = (code *)puVar9[2], pcVar8 != (code *)0x0)) {
          p_Var5 = *param_3;
          if (p_Var5 != (_STACK *)0x0) {
            iVar4 = sk_num(p_Var5);
            if (iVar6 < iVar4) {
              p_Var5 = (_STACK *)sk_value(*param_3,iVar6);
              puVar9 = (undefined4 *)*puVar1;
              pcVar8 = (code *)puVar9[2];
            }
            else {
              puVar9 = (undefined4 *)*puVar1;
              p_Var5 = (_STACK *)0x0;
              pcVar8 = (code *)puVar9[2];
            }
          }
          (*pcVar8)(param_2,p_Var5,param_3,iVar6,*puVar9,puVar9[1]);
        }
        iVar6 = iVar6 + 1;
        puVar1 = puVar1 + 1;
      } while (iVar6 != iVar2);
      CRYPTO_free(ptr);
      ptr = (undefined4 *)0x1;
    }
  }
  return ptr;
}

