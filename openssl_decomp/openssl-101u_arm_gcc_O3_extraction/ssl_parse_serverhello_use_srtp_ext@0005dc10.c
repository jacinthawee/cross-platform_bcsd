
undefined4
ssl_parse_serverhello_use_srtp_ext(int param_1,undefined *param_2,int param_3,undefined4 *param_4)

{
  undefined uVar1;
  undefined uVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  _STACK *p_Var6;
  
  if (param_3 == 5) {
    if (CONCAT11(*param_2,param_2[1]) == 2) {
      uVar1 = param_2[2];
      uVar2 = param_2[3];
      if (param_2[4] != '\0') {
        ERR_put_error(0x14,0x137,0x160,"d1_srtp.c",0x19e);
        *param_4 = 0x2f;
        return 1;
      }
      if ((param_1 != 0) &&
         ((p_Var6 = *(_STACK **)(param_1 + 0x17c), p_Var6 != (_STACK *)0x0 ||
          ((*(int *)(param_1 + 0xe4) != 0 &&
           (p_Var6 = *(_STACK **)(*(int *)(param_1 + 0xe4) + 0x1b4), p_Var6 != (_STACK *)0x0)))))) {
        iVar5 = 0;
        do {
          iVar4 = sk_num(p_Var6);
          if (iVar4 <= iVar5) {
            ERR_put_error(0x14,0x137,0x161,"d1_srtp.c",0x1bc);
            *param_4 = 0x32;
            return 1;
          }
          pvVar3 = sk_value(p_Var6,iVar5);
          iVar5 = iVar5 + 1;
        } while (*(uint *)((int)pvVar3 + 4) != (uint)CONCAT11(uVar1,uVar2));
        *(void **)(param_1 + 0x180) = pvVar3;
        *param_4 = 0;
        return 0;
      }
      ERR_put_error(0x14,0x137,0x167,"d1_srtp.c",0x1a8);
      *param_4 = 0x32;
      return 1;
    }
    iVar5 = 0x196;
  }
  else {
    iVar5 = 0x18e;
  }
  ERR_put_error(0x14,0x137,0x161,"d1_srtp.c",iVar5);
  *param_4 = 0x32;
  return 1;
}

