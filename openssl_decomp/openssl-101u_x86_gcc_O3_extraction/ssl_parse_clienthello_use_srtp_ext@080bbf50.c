
undefined4
ssl_parse_clienthello_use_srtp_ext(int param_1,ushort *param_2,int param_3,undefined4 *param_4)

{
  ushort uVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  _STACK *p_Var5;
  uint local_28;
  ushort *local_24;
  int local_20;
  
  if (param_3 < 3) {
    iVar4 = 0x126;
    iVar2 = 0x161;
  }
  else {
    local_20 = param_3 + -2;
    uVar1 = *param_2 >> 8;
    local_28 = (uint)(ushort)(*param_2 << 8 | uVar1);
    if ((uVar1 & 1) == 0) {
      if ((int)local_28 < local_20) {
        if (param_1 == 0) {
          p_Var5 = (_STACK *)0x0;
        }
        else {
          p_Var5 = *(_STACK **)(param_1 + 0x17c);
          if ((p_Var5 == (_STACK *)0x0) && (*(int *)(param_1 + 0xe4) != 0)) {
            p_Var5 = *(_STACK **)(*(int *)(param_1 + 0xe4) + 0x1b4);
          }
        }
        local_24 = param_2 + 1;
        *(undefined4 *)(param_1 + 0x180) = 0;
        iVar2 = sk_num(p_Var5);
LAB_080bbfd8:
        if (local_28 != 0) {
          while( true ) {
            uVar1 = *local_24;
            local_28 = local_28 - 2;
            local_24 = local_24 + 1;
            local_20 = local_20 + -2;
            if (iVar2 < 1) break;
            iVar4 = 0;
            while (pvVar3 = sk_value(p_Var5,iVar4),
                  (uint)(ushort)(uVar1 << 8 | uVar1 >> 8) != *(uint *)((int)pvVar3 + 4)) {
              iVar4 = iVar4 + 1;
              if (iVar4 == iVar2) goto LAB_080bbfd8;
            }
            *(void **)(param_1 + 0x180) = pvVar3;
            iVar2 = iVar4;
            if (local_28 == 0) goto LAB_080bc041;
          }
          goto LAB_080bbfd8;
        }
LAB_080bc041:
        if ((uint)*(byte *)local_24 == local_20 - 1U) {
          return 0;
        }
        iVar4 = 0x162;
        iVar2 = 0x160;
      }
      else {
        iVar4 = 0x13a;
        iVar2 = 0x161;
      }
    }
    else {
      iVar4 = 0x132;
      iVar2 = 0x161;
    }
  }
  ERR_put_error(0x14,0x136,iVar2,"d1_srtp.c",iVar4);
  *param_4 = 0x32;
  return 1;
}

