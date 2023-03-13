
undefined4 ssl_add_clienthello_use_srtp_ext(int param_1,undefined *param_2,int *param_3,int param_4)

{
  int iVar1;
  void *pvVar2;
  undefined *puVar3;
  int iVar4;
  _STACK *p_Var5;
  int iVar6;
  
  if (param_1 == 0) {
    p_Var5 = (_STACK *)0x0;
  }
  else {
    p_Var5 = *(_STACK **)(param_1 + 0x17c);
    if ((p_Var5 == (_STACK *)0x0) && (*(int *)(param_1 + 0xe4) != 0)) {
      p_Var5 = *(_STACK **)(*(int *)(param_1 + 0xe4) + 0x1b4);
    }
  }
  iVar1 = sk_num(p_Var5);
  if (param_2 != (undefined *)0x0) {
    if (iVar1 == 0) {
      iVar6 = 0xff;
      iVar1 = 0x162;
    }
    else {
      iVar6 = iVar1 * 2 + 2;
      if (iVar6 < param_4) {
        *param_2 = (char)((uint)(iVar1 * 2) >> 8);
        param_2[1] = (char)iVar1 * '\x02';
        puVar3 = param_2 + 2;
        if (0 < iVar1) {
          iVar4 = 0;
          do {
            pvVar2 = sk_value(p_Var5,iVar4);
            param_2[iVar4 * 2 + 2] = (char)((uint)*(undefined4 *)((int)pvVar2 + 4) >> 8);
            param_2[iVar4 * 2 + 3] = (char)*(undefined4 *)((int)pvVar2 + 4);
            iVar4 = iVar4 + 1;
          } while (iVar1 != iVar4);
          puVar3 = puVar3 + iVar1 * 2;
        }
        *puVar3 = 0;
        goto LAB_080bbea7;
      }
      iVar6 = 0x105;
      iVar1 = 0x16b;
    }
    ERR_put_error(0x14,0x133,iVar1,"d1_srtp.c",iVar6);
    return 1;
  }
  iVar6 = iVar1 * 2 + 2;
LAB_080bbea7:
  *param_3 = iVar6 + 1;
  return 0;
}

