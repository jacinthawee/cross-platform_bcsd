
undefined4
tls1_process_ticket(SSL *param_1,int param_2,int param_3,ushort *param_4,undefined4 *param_5)

{
  ushort uVar1;
  uint uVar2;
  ushort *puVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  byte *pbVar7;
  ushort *puVar8;
  ushort uVar9;
  
  *param_5 = 0;
  param_1->tlsext_ocsp_resplen = 0;
  uVar2 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
  if ((uVar2 & 0x4000) != 0) {
    return 0;
  }
  if ((param_4 == (ushort *)0x0) || (param_1->version < 0x301)) {
LAB_080ac9e6:
    uVar5 = 0;
  }
  else {
    puVar3 = (ushort *)(param_2 + param_3);
    if (puVar3 < param_4) {
      if (param_1->version == 0xfeff) {
        if ((int)param_4 - (int)(byte *)((int)puVar3 + 1) <= (int)(uint)*(byte *)puVar3)
        goto LAB_080aca58;
        puVar3 = (ushort *)((byte *)((int)puVar3 + 1) + *(byte *)puVar3);
      }
      uVar2 = (uint)(ushort)(*puVar3 << 8 | *puVar3 >> 8);
      if ((int)uVar2 < (int)param_4 - (int)(puVar3 + 1)) {
        uVar6 = (uint)*(byte *)((int)puVar3 + uVar2 + 2);
        pbVar7 = (byte *)((int)puVar3 + uVar2 + 3);
        if ((int)uVar6 <= (int)param_4 - (int)pbVar7) {
          pbVar7 = pbVar7 + uVar6;
          if ((int)param_4 - (int)pbVar7 < 3) {
            return 0;
          }
          if ((int)param_4 - (int)(pbVar7 + 2) < 4) {
            return 0;
          }
          puVar3 = (ushort *)(pbVar7 + 6);
          uVar1 = *(ushort *)(pbVar7 + 2) << 8 | *(ushort *)(pbVar7 + 2) >> 8;
          uVar9 = *(ushort *)(pbVar7 + 4) << 8 | *(ushort *)(pbVar7 + 4) >> 8;
          uVar2 = (uint)uVar9;
          if ((int)param_4 - (int)puVar3 < (int)uVar2) {
            return 0;
          }
          do {
            if (uVar1 == 0x23) {
              if (uVar9 == 0) {
                param_1->tlsext_ocsp_resplen = 1;
                return 1;
              }
              if (param_1->tls_session_ticket_ext_cb_arg != (void *)0x0) {
                return 2;
              }
              iVar4 = tls_decrypt_ticket(param_2,param_3,param_5);
              if (iVar4 == 3) {
                return 3;
              }
              if (iVar4 == 4) {
                param_1->tlsext_ocsp_resplen = 1;
                return 3;
              }
              if (iVar4 == 2) {
                param_1->tlsext_ocsp_resplen = 1;
                return 2;
              }
              goto LAB_080aca58;
            }
            puVar8 = (ushort *)((int)puVar3 + uVar2);
            if ((int)param_4 - (int)puVar8 < 4) break;
            puVar3 = puVar8 + 2;
            uVar9 = puVar8[1] << 8 | puVar8[1] >> 8;
            uVar1 = *puVar8 << 8 | *puVar8 >> 8;
            uVar2 = (uint)uVar9;
          } while ((int)uVar2 <= (int)param_4 - (int)puVar3);
          goto LAB_080ac9e6;
        }
      }
    }
LAB_080aca58:
    uVar5 = 0xffffffff;
  }
  return uVar5;
}

