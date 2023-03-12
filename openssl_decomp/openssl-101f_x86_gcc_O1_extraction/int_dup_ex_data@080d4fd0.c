
undefined4 int_dup_ex_data(undefined4 param_1,_STACK **param_2,_STACK **param_3)

{
  int iVar1;
  int iVar2;
  int mode;
  void *ptr;
  void *mode_00;
  int iVar3;
  _STACK *p_Var4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int in_GS_OFFSET;
  void *local_3c;
  void *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (*param_3 != (_STACK *)0x0) {
    uVar6 = 0;
    iVar1 = def_get_class();
    if (iVar1 == 0) goto LAB_080d51aa;
    CRYPTO_lock(iVar1,5,(char *)0x2,(int)"ex_data.c");
    iVar2 = sk_num(*(_STACK **)(iVar1 + 4));
    mode = sk_num(*param_3);
    if (iVar2 <= mode) {
      mode = iVar2;
    }
    if (mode < 1) {
      uVar6 = 1;
      CRYPTO_lock(mode,6,(char *)0x2,(int)"ex_data.c");
      goto LAB_080d51aa;
    }
    ptr = CRYPTO_malloc(mode << 2,"ex_data.c",0x1d0);
    if (ptr == (void *)0x0) {
      CRYPTO_lock(0,6,(char *)0x2,(int)"ex_data.c");
      ERR_put_error(0xf,0x6a,0x41,"ex_data.c",0x1da);
      goto LAB_080d51aa;
    }
    iVar2 = 0;
    do {
      mode_00 = sk_value(*(_STACK **)(iVar1 + 4),iVar2);
      *(void **)((int)ptr + iVar2 * 4) = mode_00;
      iVar2 = iVar2 + 1;
    } while (iVar2 != mode);
    iVar1 = 0;
    CRYPTO_lock((int)mode_00,6,(char *)0x2,(int)"ex_data.c");
    do {
      if ((*param_3 == (_STACK *)0x0) || (iVar2 = sk_num(*param_3), iVar2 <= iVar1)) {
        local_24 = (void *)0x0;
        puVar5 = *(undefined4 **)((int)ptr + iVar1 * 4);
        if (puVar5 != (undefined4 *)0x0) goto LAB_080d5101;
LAB_080d5215:
        p_Var4 = *param_2;
        local_3c = local_24;
        if (p_Var4 != (_STACK *)0x0) goto LAB_080d5132;
LAB_080d5228:
        local_3c = local_24;
        p_Var4 = sk_new_null();
        *param_2 = p_Var4;
        if (p_Var4 != (_STACK *)0x0) goto LAB_080d5132;
        iVar2 = 0x25d;
LAB_080d5176:
        ERR_put_error(0xf,0x66,0x41,"ex_data.c",iVar2);
      }
      else {
        local_24 = sk_value(*param_3,iVar1);
        puVar5 = *(undefined4 **)((int)ptr + iVar1 * 4);
        if (puVar5 == (undefined4 *)0x0) goto LAB_080d5215;
LAB_080d5101:
        if ((code *)puVar5[4] != (code *)0x0) {
          (*(code *)puVar5[4])(param_2,param_3,&local_24,iVar1,*puVar5,puVar5[1]);
        }
        p_Var4 = *param_2;
        local_3c = local_24;
        if (p_Var4 == (_STACK *)0x0) goto LAB_080d5228;
LAB_080d5132:
        for (iVar2 = sk_num(p_Var4); iVar2 <= iVar1; iVar2 = iVar2 + 1) {
          iVar3 = sk_push(*param_2,(void *)0x0);
          if (iVar3 == 0) {
            iVar2 = 0x267;
            goto LAB_080d5176;
          }
        }
        sk_set(*param_2,iVar1,local_3c);
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < mode);
    CRYPTO_free(ptr);
  }
  uVar6 = 1;
LAB_080d51aa:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar6;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

