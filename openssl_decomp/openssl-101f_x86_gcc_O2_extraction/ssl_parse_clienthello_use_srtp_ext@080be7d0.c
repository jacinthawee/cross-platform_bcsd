
undefined4
ssl_parse_clienthello_use_srtp_ext(int param_1,ushort *param_2,int param_3,undefined4 *param_4)

{
  uint uVar1;
  ushort uVar2;
  int *data;
  _STACK *st;
  int iVar3;
  void *pvVar4;
  void *pvVar5;
  int iVar6;
  _STACK *p_Var7;
  uint uVar8;
  int local_20;
  
  if (param_3 < 3) {
    iVar6 = 0x13f;
    iVar3 = 0x161;
  }
  else {
    param_3 = param_3 + -2;
    uVar2 = *param_2 >> 8;
    uVar8 = (uint)(ushort)(*param_2 << 8 | uVar2);
    if ((uVar2 & 1) == 0) {
      if ((int)uVar8 < param_3) {
        st = sk_new_null();
        param_2 = param_2 + 1;
LAB_080be810:
        if (uVar8 != 0) {
          while( true ) {
            uVar2 = *param_2;
            param_2 = param_2 + 1;
            uVar8 = uVar8 - 2;
            param_3 = param_3 + -2;
            if (srtp_known_profiles._0_4_ == 0) break;
            data = (int *)srtp_known_profiles;
            uVar1 = srtp_known_profiles._4_4_;
            while ((ushort)(uVar2 << 8 | uVar2 >> 8) != uVar1) {
              if (data[2] == 0) goto LAB_080be810;
              uVar1 = data[3];
              data = data + 2;
            }
            sk_push(st,data);
            if (uVar8 == 0) goto LAB_080be85f;
          }
          goto LAB_080be810;
        }
LAB_080be85f:
        if ((uint)*(byte *)param_2 == param_3 - 1U) {
          if (param_1 == 0) {
            p_Var7 = (_STACK *)0x0;
          }
          else {
            p_Var7 = *(_STACK **)(param_1 + 0x17c);
            if ((p_Var7 == (_STACK *)0x0) && (*(int *)(param_1 + 0xe4) != 0)) {
              p_Var7 = *(_STACK **)(*(int *)(param_1 + 0xe4) + 0x1b4);
            }
          }
          local_20 = 0;
          do {
            iVar3 = sk_num(p_Var7);
            if (iVar3 <= local_20) {
LAB_080be94f:
              if (st == (_STACK *)0x0) {
                return 0;
              }
              sk_free(st);
              return 0;
            }
            pvVar4 = sk_value(p_Var7,local_20);
            for (iVar3 = 0; iVar6 = sk_num(st), iVar3 < iVar6; iVar3 = iVar3 + 1) {
              pvVar5 = sk_value(st,iVar3);
              if (*(int *)((int)pvVar5 + 4) == *(int *)((int)pvVar4 + 4)) {
                *(void **)(param_1 + 0x180) = pvVar4;
                *param_4 = 0;
                goto LAB_080be94f;
              }
            }
            local_20 = local_20 + 1;
          } while( true );
        }
        iVar6 = 0x171;
        iVar3 = 0x160;
      }
      else {
        iVar6 = 0x153;
        iVar3 = 0x161;
      }
    }
    else {
      iVar6 = 0x14b;
      iVar3 = 0x161;
    }
  }
  ERR_put_error(0x14,0x136,iVar3,"d1_srtp.c",iVar6);
  *param_4 = 0x32;
  return 1;
}

