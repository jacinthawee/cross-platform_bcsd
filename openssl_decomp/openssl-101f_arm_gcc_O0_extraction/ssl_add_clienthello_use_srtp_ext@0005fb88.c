
undefined4
ssl_add_clienthello_use_srtp_ext(_STACK *param_1,undefined *param_2,int *param_3,int param_4)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  undefined *puVar4;
  _STACK *p_Var5;
  int iVar6;
  undefined *puVar7;
  
  p_Var5 = param_1;
  if (((param_1 != (_STACK *)0x0) && (p_Var5 = (_STACK *)param_1[0x13].num, p_Var5 == (_STACK *)0x0)
      ) && (param_1[0xb].sorted != 0)) {
    p_Var5 = *(_STACK **)(param_1[0xb].sorted + 0x1b4);
  }
  iVar1 = sk_num(p_Var5);
  if (param_2 == (undefined *)0x0) {
    iVar6 = (iVar1 + 1) * 2;
  }
  else {
    if (iVar1 == 0) {
      ERR_put_error(0x14,0x133,0x162,"d1_srtp.c",0x116);
      return 1;
    }
    iVar6 = (iVar1 + 1) * 2;
    if (param_4 <= iVar6) {
      ERR_put_error(0x14,0x133,0x16b,"d1_srtp.c",0x11c);
      return 1;
    }
    puVar7 = param_2 + 2;
    param_2[1] = (char)(iVar1 << 1);
    *param_2 = (char)((uint)(iVar6 + -2) >> 8);
    if (0 < iVar1) {
      iVar3 = 0;
      puVar4 = param_2 + 4;
      do {
        pvVar2 = sk_value(p_Var5,iVar3);
        iVar3 = iVar3 + 1;
        puVar4[-2] = (char)((uint)*(undefined4 *)((int)pvVar2 + 4) >> 8);
        puVar4[-1] = (char)*(undefined4 *)((int)pvVar2 + 4);
        puVar4 = puVar4 + 2;
      } while (iVar3 != iVar1);
      puVar7 = puVar7 + iVar3 * 2;
    }
    *puVar7 = 0;
  }
  *param_3 = iVar6 + 1;
  return 0;
}

