
undefined4
tls1_process_ticket(SSL *param_1,int param_2,int param_3,undefined *param_4,undefined4 *param_5)

{
  undefined *puVar1;
  undefined uVar2;
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
      puVar5 = (undefined *)(param_2 + param_3);
      if ((puVar5 < param_4) &&
         ((param_1->version != 0xfeff ||
          (puVar5 = puVar5 + *(byte *)(param_2 + param_3) + 1, puVar5 < param_4)))) {
        puVar6 = puVar5 + CONCAT11(*puVar5,puVar5[1]) + 2;
        if ((puVar6 < param_4) &&
           (puVar6 + (byte)puVar5[CONCAT11(*puVar5,puVar5[1]) + 2] + 1 <= param_4)) {
          puVar5 = puVar6 + (byte)puVar5[CONCAT11(*puVar5,puVar5[1]) + 2] + 1 + 2;
          if (param_4 <= puVar5) {
            return 0;
          }
          do {
            puVar6 = puVar5 + 4;
            if (param_4 < puVar6) {
              return 0;
            }
            uVar2 = *puVar5;
            uVar3 = (uint)CONCAT11(puVar5[2],puVar5[3]);
            puVar1 = puVar5 + 1;
            puVar5 = puVar6 + uVar3;
            if (param_4 < puVar5) {
              return 0;
            }
          } while (CONCAT11(uVar2,*puVar1) != 0x23);
          if (uVar3 == 0) {
            param_1->tlsext_ocsp_resplen = 1;
            return 1;
          }
          if (param_1->tls_session_ticket_ext_cb_arg != (void *)0x0) {
            return 2;
          }
          iVar4 = tls_decrypt_ticket(param_1,puVar6,uVar3,param_2,param_3,param_5);
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
        }
      }
      return 0xffffffff;
    }
  }
  return 0;
}

