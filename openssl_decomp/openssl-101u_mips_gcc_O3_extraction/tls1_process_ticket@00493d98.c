
undefined4
tls1_process_ticket(SSL *param_1,int param_2,int param_3,byte *param_4,undefined4 *param_5)

{
  byte bVar1;
  short sVar2;
  uint uVar3;
  short *psVar4;
  int iVar5;
  byte *pbVar6;
  byte *pbVar7;
  short *psVar8;
  undefined4 uVar9;
  undefined *puVar10;
  
  puVar10 = &_gp;
  *param_5 = 0;
  param_1->tlsext_ocsp_resplen = 0;
  uVar3 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
  if ((((uVar3 & 0x4000) == 0) && (0x300 < param_1->version)) &&
     (pbVar6 = (byte *)(param_2 + param_3), param_4 != (byte *)0x0)) {
    if (pbVar6 < param_4) {
      pbVar7 = pbVar6 + 1;
      if (param_1->version == 0xfeff) {
        bVar1 = *pbVar6;
        pbVar6 = pbVar7 + bVar1;
        if ((int)param_4 - (int)pbVar7 <= (int)(uint)bVar1) goto LAB_00493fac;
        bVar1 = *pbVar6;
      }
      else {
        bVar1 = *pbVar6;
      }
      pbVar7 = pbVar6 + 2;
      uVar3 = (uint)CONCAT11(bVar1,pbVar6[1]);
      if ((int)uVar3 < (int)param_4 - (int)pbVar7) {
        if ((int)(uint)pbVar7[uVar3] <= (int)param_4 - (int)(pbVar7 + uVar3 + 1)) {
          pbVar6 = pbVar7 + uVar3 + 1 + pbVar7[uVar3];
          if ((2 < (int)param_4 - (int)pbVar6) && (3 < (int)param_4 - (int)(pbVar6 + 2))) {
            psVar8 = (short *)(pbVar6 + 6);
            sVar2 = *(short *)(pbVar6 + 2);
            uVar3 = (uint)*(ushort *)(pbVar6 + 4);
            if ((int)uVar3 <= (int)param_4 - (int)psVar8) {
              do {
                if (sVar2 == 0x23) {
                  if (uVar3 == 0) {
                    param_1->tlsext_ocsp_resplen = 1;
                    return 1;
                  }
                  uVar9 = 2;
                  if (param_1->tls_session_ticket_ext_cb_arg != (void *)0x0) {
                    return 2;
                  }
                  iVar5 = tls_decrypt_ticket(param_1,psVar8,uVar3,param_2,param_3,param_5,puVar10);
                  if (iVar5 == 3) {
                    return 3;
                  }
                  if (iVar5 == 4) {
                    uVar9 = 3;
                  }
                  else if (iVar5 != 2) goto LAB_00493fac;
                  param_1->tlsext_ocsp_resplen = 1;
                  return uVar9;
                }
                psVar4 = (short *)((int)psVar8 + uVar3);
                psVar8 = psVar4 + 2;
                if ((int)param_4 - (int)psVar4 < 4) break;
                sVar2 = *psVar4;
                uVar3 = (uint)(ushort)psVar4[1];
              } while ((int)uVar3 <= (int)param_4 - (int)psVar8);
            }
          }
          goto LAB_00493f20;
        }
      }
    }
LAB_00493fac:
    uVar9 = 0xffffffff;
  }
  else {
LAB_00493f20:
    uVar9 = 0;
  }
  return uVar9;
}

