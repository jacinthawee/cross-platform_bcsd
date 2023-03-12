
undefined4
ssl_parse_clienthello_use_srtp_ext
          (_STACK *param_1,undefined *param_2,int param_3,undefined4 *param_4)

{
  undefined **ppuVar1;
  byte *pbVar2;
  _STACK *st;
  int iVar3;
  char **ppcVar4;
  void *pvVar5;
  int iVar6;
  undefined **data;
  undefined **ppuVar7;
  uint uVar8;
  int iVar9;
  _STACK *p_Var10;
  byte *pbVar11;
  
  if (param_3 < 3) {
    iVar3 = 0x13f;
    iVar9 = 0x161;
  }
  else {
    param_3 = param_3 + -2;
    uVar8 = (uint)CONCAT11(*param_2,param_2[1]);
    if ((int)(uVar8 << 0x1f) < 0) {
      iVar3 = 0x14b;
      iVar9 = 0x161;
    }
    else if ((int)uVar8 < param_3) {
      st = sk_new_null();
      pbVar11 = param_2 + 2;
      if (uVar8 != 0) {
        pbVar2 = param_2 + 4;
        do {
          while( true ) {
            pbVar11 = pbVar2;
            uVar8 = uVar8 - 2;
            param_3 = param_3 + -2;
            if (srtp_known_profiles != (undefined *)0x0) break;
LAB_0005fcf0:
            pbVar2 = pbVar11 + 2;
            if (uVar8 == 0) goto LAB_0005fcf6;
          }
          if ((undefined *)(uint)CONCAT11(pbVar11[-2],pbVar11[-1]) == DAT_0018dfb0) {
            data = &srtp_known_profiles;
          }
          else {
            ppuVar7 = &srtp_known_profiles;
            do {
              data = ppuVar7 + 2;
              if (ppuVar7[2] == (undefined *)0x0) goto LAB_0005fcf0;
              ppuVar1 = ppuVar7 + 3;
              ppuVar7 = data;
            } while ((undefined *)(uint)CONCAT11(pbVar11[-2],pbVar11[-1]) != *ppuVar1);
          }
          sk_push(st,data);
          pbVar2 = pbVar11 + 2;
        } while (uVar8 != 0);
      }
LAB_0005fcf6:
      if ((uint)*pbVar11 == param_3 - 1U) {
        p_Var10 = param_1;
        if (((param_1 != (_STACK *)0x0) &&
            (p_Var10 = (_STACK *)param_1[0x13].num, p_Var10 == (_STACK *)0x0)) &&
           (param_1[0xb].sorted != 0)) {
          p_Var10 = *(_STACK **)(param_1[0xb].sorted + 0x1b4);
        }
        iVar9 = 0;
        do {
          iVar3 = sk_num(p_Var10);
          if (iVar3 <= iVar9) {
LAB_0005fd98:
            if (st == (_STACK *)0x0) {
              return 0;
            }
            sk_free(st);
            return 0;
          }
          ppcVar4 = (char **)sk_value(p_Var10,iVar9);
          iVar3 = 0;
          while( true ) {
            iVar6 = sk_num(st);
            if (iVar6 <= iVar3) break;
            pvVar5 = sk_value(st,iVar3);
            iVar3 = iVar3 + 1;
            if (*(char **)((int)pvVar5 + 4) == ppcVar4[1]) {
              param_1[0x13].data = ppcVar4;
              *param_4 = 0;
              goto LAB_0005fd98;
            }
          }
          iVar9 = iVar9 + 1;
        } while( true );
      }
      iVar3 = 0x171;
      iVar9 = 0x160;
    }
    else {
      iVar3 = 0x153;
      iVar9 = 0x161;
    }
  }
  ERR_put_error(0x14,0x136,iVar9,"d1_srtp.c",iVar3);
  *param_4 = 0x32;
  return 1;
}

