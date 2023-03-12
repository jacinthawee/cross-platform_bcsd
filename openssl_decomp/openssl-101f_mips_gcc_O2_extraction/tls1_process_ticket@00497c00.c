
undefined4
tls1_process_ticket(SSL *param_1,int param_2,int param_3,ushort *param_4,undefined4 *param_5)

{
  ushort uVar1;
  uint uVar2;
  ushort *puVar3;
  ushort *puVar4;
  int iVar5;
  undefined4 uVar6;
  undefined *puVar7;
  
  puVar7 = &_gp;
  *param_5 = 0;
  param_1->tlsext_ocsp_resplen = 0;
  uVar2 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
  if ((((uVar2 & 0x4000) == 0) && (0x300 < param_1->version)) &&
     (puVar3 = (ushort *)(param_2 + param_3), param_4 != (ushort *)0x0)) {
    if ((((puVar3 < param_4) &&
         ((param_1->version != 0xfeff ||
          (puVar3 = (ushort *)((int)puVar3 + *(byte *)puVar3 + 1), puVar3 < param_4)))) &&
        (puVar3 = (ushort *)((int)puVar3 + *puVar3 + 2), puVar3 < param_4)) &&
       (puVar3 = (ushort *)((int)puVar3 + *(byte *)puVar3 + 1), puVar4 = puVar3 + 1,
       puVar3 <= param_4)) {
      if (param_4 <= puVar4) goto LAB_00497d24;
      do {
        puVar3 = puVar4 + 2;
        if (param_4 < puVar3) goto LAB_00497d24;
        uVar1 = *puVar4;
        uVar2 = (uint)puVar4[1];
        puVar4 = (ushort *)((int)puVar3 + uVar2);
        if (param_4 < puVar4) goto LAB_00497d24;
      } while (uVar1 != 0x23);
      if (uVar2 == 0) {
        param_1->tlsext_ocsp_resplen = 1;
        return 1;
      }
      if (param_1->tls_session_ticket_ext_cb_arg != (void *)0x0) {
        return 2;
      }
      iVar5 = tls_decrypt_ticket(param_1,puVar3,uVar2,param_2,param_3,param_5,puVar7);
      if (iVar5 == 3) {
        return 3;
      }
      if (iVar5 == 4) {
        param_1->tlsext_ocsp_resplen = 1;
        return 3;
      }
      if (iVar5 == 2) {
        param_1->tlsext_ocsp_resplen = 1;
        return 2;
      }
    }
    uVar6 = 0xffffffff;
  }
  else {
LAB_00497d24:
    uVar6 = 0;
  }
  return uVar6;
}

