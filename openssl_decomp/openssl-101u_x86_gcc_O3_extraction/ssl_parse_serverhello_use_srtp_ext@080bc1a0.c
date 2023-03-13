
undefined4
ssl_parse_serverhello_use_srtp_ext(int param_1,short *param_2,int param_3,undefined4 *param_4)

{
  ushort uVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  _STACK *p_Var5;
  
  if (param_3 == 5) {
    if (*param_2 == 0x200) {
      uVar1 = param_2[1];
      if (*(char *)(param_2 + 2) != '\0') {
        ERR_put_error(0x14,0x137,0x160,"d1_srtp.c",0x19e);
        *param_4 = 0x2f;
        return 1;
      }
      if ((param_1 == 0) ||
         ((p_Var5 = *(_STACK **)(param_1 + 0x17c), p_Var5 == (_STACK *)0x0 &&
          ((*(int *)(param_1 + 0xe4) == 0 ||
           (p_Var5 = *(_STACK **)(*(int *)(param_1 + 0xe4) + 0x1b4), p_Var5 == (_STACK *)0x0)))))) {
        iVar3 = 0x1a8;
        iVar4 = 0x167;
      }
      else {
        for (iVar4 = 0; iVar3 = sk_num(p_Var5), iVar4 < iVar3; iVar4 = iVar4 + 1) {
          pvVar2 = sk_value(p_Var5,iVar4);
          if ((uint)(ushort)(uVar1 << 8 | uVar1 >> 8) == *(uint *)((int)pvVar2 + 4)) {
            *(void **)(param_1 + 0x180) = pvVar2;
            *param_4 = 0;
            return 0;
          }
        }
        iVar3 = 0x1bc;
        iVar4 = 0x161;
      }
    }
    else {
      iVar3 = 0x196;
      iVar4 = 0x161;
    }
  }
  else {
    iVar3 = 0x18e;
    iVar4 = 0x161;
  }
  ERR_put_error(0x14,0x137,iVar4,"d1_srtp.c",iVar3);
  *param_4 = 0x32;
  return 1;
}

