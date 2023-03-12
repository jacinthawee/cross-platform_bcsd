
undefined4
tls1_process_ticket(SSL *param_1,int param_2,int param_3,undefined *param_4,undefined4 *param_5)

{
  undefined *puVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  undefined *puVar5;
  undefined *puVar6;
  
  *param_5 = 0;
  param_1->tlsext_ocsp_resplen = 0;
  uVar3 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
  if ((uVar3 & 0x4000) == 0) {
    if (param_1->version < 0x301) {
      return 0;
    }
    if (param_4 != (undefined *)0x0) {
      puVar6 = (undefined *)(param_2 + param_3);
      if (puVar6 < param_4) {
        if (param_1->version == 0xfeff) {
          if ((int)param_4 - (int)(puVar6 + 1) <= (int)(uint)*(byte *)(param_2 + param_3)) {
            return 0xffffffff;
          }
          puVar6 = puVar6 + 1 + *(byte *)(param_2 + param_3);
        }
        puVar5 = puVar6 + 2;
        uVar3 = (uint)CONCAT11(*puVar6,puVar6[1]);
        if ((int)uVar3 < (int)param_4 - (int)puVar5) {
          if ((int)(uint)(byte)puVar5[uVar3] <= (int)param_4 - (int)(puVar5 + uVar3 + 1)) {
            puVar6 = puVar5 + uVar3 + 1 + (byte)puVar5[uVar3];
            if ((int)param_4 - (int)puVar6 < 3) {
              return 0;
            }
            if ((int)param_4 - (int)(puVar6 + 2) < 4) {
              return 0;
            }
            puVar5 = puVar6 + 6;
            uVar3 = (uint)CONCAT11(puVar6[4],puVar6[5]);
            sVar2 = CONCAT11(puVar6[2],puVar6[3]);
            if ((int)param_4 - (int)puVar5 < (int)uVar3) {
              return 0;
            }
            while (sVar2 != 0x23) {
              puVar6 = puVar5 + uVar3;
              if ((int)param_4 - (int)puVar6 < 4) {
                return 0;
              }
              puVar1 = puVar5 + uVar3;
              puVar5 = puVar6 + 4;
              uVar3 = (uint)CONCAT11(puVar6[2],puVar6[3]);
              sVar2 = CONCAT11(*puVar1,puVar6[1]);
              if ((int)param_4 - (int)puVar5 < (int)uVar3) {
                return 0;
              }
            }
            if (uVar3 == 0) {
              param_1->tlsext_ocsp_resplen = 1;
              return 1;
            }
            if (param_1->tls_session_ticket_ext_cb_arg != (void *)0x0) {
              return 2;
            }
            iVar4 = tls_decrypt_ticket(param_1,puVar5,uVar3,param_2,param_3,param_5);
            if (iVar4 == 3) {
              return 3;
            }
            if (iVar4 != 4) {
              if (iVar4 != 2) {
                return 0xffffffff;
              }
              param_1->tlsext_ocsp_resplen = 1;
              return 2;
            }
            param_1->tlsext_ocsp_resplen = 1;
            return 3;
          }
        }
      }
      return 0xffffffff;
    }
  }
  return 0;
}

