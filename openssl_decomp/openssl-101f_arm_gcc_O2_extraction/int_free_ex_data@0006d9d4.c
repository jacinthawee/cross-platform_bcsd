
void int_free_ex_data(undefined4 param_1,undefined4 param_2,_STACK **param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *ptr;
  void *pvVar3;
  _STACK *p_Var4;
  int iVar5;
  void **ppvVar6;
  undefined4 *puVar7;
  code *pcVar8;
  undefined4 *puVar9;
  
  iVar1 = def_get_class();
  if (iVar1 != 0) {
    CRYPTO_lock(5,2,"ex_data.c",500);
    iVar2 = sk_num(*(_STACK **)(iVar1 + 4));
    if (iVar2 < 1) {
      CRYPTO_lock(6,2,"ex_data.c",0x1ff);
    }
    else {
      ptr = (undefined4 *)CRYPTO_malloc(iVar2 * 4,"ex_data.c",0x1f8);
      if (ptr == (undefined4 *)0x0) {
        CRYPTO_lock(6,2,"ex_data.c",0x1ff);
        ERR_put_error(0xf,0x6b,0x41,"ex_data.c",0x202);
        return;
      }
      ppvVar6 = (void **)(ptr + -1);
      iVar5 = 0;
      do {
        pvVar3 = sk_value(*(_STACK **)(iVar1 + 4),iVar5);
        iVar5 = iVar5 + 1;
        ppvVar6 = ppvVar6 + 1;
        *ppvVar6 = pvVar3;
      } while (iVar5 != iVar2);
      CRYPTO_lock(6,2,"ex_data.c",0x1ff);
      iVar1 = 0;
      puVar7 = ptr;
      do {
        puVar9 = (undefined4 *)*puVar7;
        if ((puVar9 != (undefined4 *)0x0) && (pcVar8 = (code *)puVar9[3], pcVar8 != (code *)0x0)) {
          p_Var4 = *param_3;
          if (p_Var4 != (_STACK *)0x0) {
            iVar5 = sk_num(p_Var4);
            if (iVar1 < iVar5) {
              p_Var4 = (_STACK *)sk_value(*param_3,iVar1);
              puVar9 = (undefined4 *)*puVar7;
              pcVar8 = (code *)puVar9[3];
            }
            else {
              puVar9 = (undefined4 *)*puVar7;
              p_Var4 = (_STACK *)0x0;
              pcVar8 = (code *)puVar9[3];
            }
          }
          (*pcVar8)(param_2,p_Var4,param_3,iVar1,*puVar9,puVar9[1]);
        }
        iVar1 = iVar1 + 1;
        puVar7 = puVar7 + 1;
      } while (iVar1 != iVar2);
      CRYPTO_free(ptr);
    }
    if (*param_3 != (_STACK *)0x0) {
      sk_free(*param_3);
      *param_3 = (_STACK *)0x0;
    }
  }
  return;
}

