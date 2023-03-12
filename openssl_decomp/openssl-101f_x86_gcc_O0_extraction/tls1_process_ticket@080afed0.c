
undefined4
tls1_process_ticket(SSL *param_1,int param_2,int param_3,ushort *param_4,undefined4 *param_5)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  ushort *puVar4;
  int iVar5;
  
  *param_5 = 0;
  param_1->tlsext_ocsp_resplen = 0;
  uVar3 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
  if ((uVar3 & 0x4000) != 0) {
    return 0;
  }
  if ((param_4 == (ushort *)0x0) || (param_1->version < 0x301)) {
    return 0;
  }
  puVar4 = (ushort *)(param_2 + param_3);
  if (((puVar4 < param_4) &&
      (((param_1->version != 0xfeff ||
        (puVar4 = (ushort *)((int)puVar4 + *(byte *)puVar4 + 1), puVar4 < param_4)) &&
       (puVar4 = (ushort *)((int)puVar4 + (ushort)(*puVar4 << 8 | *puVar4 >> 8) + 2),
       puVar4 < param_4)))) &&
     (puVar4 = (ushort *)((int)puVar4 + *(byte *)puVar4 + 1), puVar4 <= param_4)) {
    puVar4 = puVar4 + 1;
    if (param_4 <= puVar4) {
      return 0;
    }
    do {
      if (param_4 < puVar4 + 2) {
        return 0;
      }
      uVar1 = *puVar4;
      uVar2 = puVar4[1] << 8 | puVar4[1] >> 8;
      puVar4 = (ushort *)((int)(puVar4 + 2) + (uint)uVar2);
      if (param_4 < puVar4) {
        return 0;
      }
    } while ((ushort)(uVar1 << 8 | uVar1 >> 8) != 0x23);
    if (uVar2 == 0) {
      param_1->tlsext_ocsp_resplen = 1;
      return 1;
    }
    if (param_1->tls_session_ticket_ext_cb_arg != (void *)0x0) {
      return 2;
    }
    iVar5 = tls_decrypt_ticket(param_2,param_3,param_5);
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
  return 0xffffffff;
}

