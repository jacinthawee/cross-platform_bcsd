
undefined4 dtls1_send_server_hello(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined *puVar3;
  int iVar4;
  uint uVar5;
  undefined uVar6;
  byte *pbVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  
  if (param_1[0xd] != 0x2130) goto LAB_080b0394;
  iVar11 = *(int *)(param_1[0xf] + 4);
  ssl_fill_hello_random(param_1,1,param_1[0x16] + 0xa0,0x20);
  *(char *)(iVar11 + 0xc) = (char)((uint)*param_1 >> 8);
  *(char *)(iVar11 + 0xd) = (char)*param_1;
  iVar4 = param_1[0x16];
  *(undefined4 *)(iVar11 + 0xe) = *(undefined4 *)(iVar4 + 0xa0);
  *(undefined4 *)(iVar11 + 0x12) = *(undefined4 *)(iVar4 + 0xa4);
  *(undefined4 *)(iVar11 + 0x16) = *(undefined4 *)(iVar4 + 0xa8);
  *(undefined4 *)(iVar11 + 0x1a) = *(undefined4 *)(iVar4 + 0xac);
  *(undefined4 *)(iVar11 + 0x1e) = *(undefined4 *)(iVar4 + 0xb0);
  *(undefined4 *)(iVar11 + 0x22) = *(undefined4 *)(iVar4 + 0xb4);
  *(undefined4 *)(iVar11 + 0x26) = *(undefined4 *)(iVar4 + 0xb8);
  *(undefined4 *)(iVar11 + 0x2a) = *(undefined4 *)(iVar4 + 0xbc);
  if ((*(byte *)(param_1[0x39] + 0x20) & 2) == 0) {
    *(undefined4 *)(param_1[0x30] + 0x44) = 0;
    uVar6 = 0;
    uVar5 = 0;
LAB_080b0440:
    *(undefined *)(iVar11 + 0x2e) = uVar6;
    iVar4 = param_1[0x30];
    if (uVar5 < 4) {
      if ((uVar5 != 0) &&
         (*(undefined *)(iVar11 + 0x2f) = *(undefined *)(iVar4 + 0x48), (uVar5 & 2) != 0)) {
        *(undefined2 *)(iVar11 + 0x2d + uVar5) = *(undefined2 *)(iVar4 + 0x46 + uVar5);
      }
    }
    else {
      uVar10 = iVar11 + 0x33U & 0xfffffffc;
      *(undefined4 *)(iVar11 + 0x2f) = *(undefined4 *)(iVar4 + 0x48);
      *(undefined4 *)(iVar11 + 0x2b + uVar5) = *(undefined4 *)(iVar4 + 0x44 + uVar5);
      iVar2 = (iVar11 + 0x2f) - uVar10;
      uVar8 = iVar2 + uVar5 & 0xfffffffc;
      if (3 < uVar8) {
        uVar9 = 0;
        do {
          *(undefined4 *)(uVar10 + uVar9) = *(undefined4 *)(((iVar4 + 0x48) - iVar2) + uVar9);
          uVar9 = uVar9 + 4;
        } while (uVar9 < uVar8);
      }
    }
    iVar4 = iVar11 + 0x2f + uVar5;
    if (*(int *)(param_1[0x16] + 0x344) == 0) {
      return 0xffffffff;
    }
    iVar2 = ssl3_put_cipher_by_char(*(int *)(param_1[0x16] + 0x344),iVar4);
    puVar3 = (undefined *)(iVar2 + iVar4);
    pbVar7 = *(byte **)(param_1[0x16] + 0x38c);
    if (pbVar7 != (byte *)0x0) {
      pbVar7 = (byte *)(uint)*pbVar7;
    }
    *puVar3 = (char)pbVar7;
    iVar4 = ssl_prepare_serverhello_tlsext(param_1);
    if (iVar4 < 1) {
      iVar11 = 0x40d;
      iVar4 = 0x113;
      goto LAB_080b057f;
    }
    iVar4 = ssl_add_serverhello_tlsext(param_1,puVar3 + 1,iVar11 + 0x4000);
    if (iVar4 != 0) {
      iVar2 = iVar4 - (iVar11 + 0xc);
      dtls1_set_message_header(param_1,iVar11,2,iVar2,0,iVar2);
      param_1[0xd] = 0x2131;
      param_1[0x11] = iVar4 - iVar11;
      param_1[0x12] = 0;
      dtls1_buffer_message(param_1,0);
LAB_080b0394:
      uVar1 = dtls1_do_write(param_1,0x16);
      return uVar1;
    }
    iVar11 = 0x414;
  }
  else {
    uVar5 = *(uint *)(param_1[0x30] + 0x44);
    uVar6 = (undefined)uVar5;
    if (uVar5 < 0x21) goto LAB_080b0440;
    iVar11 = 0x3f4;
  }
  iVar4 = 0x44;
LAB_080b057f:
  ERR_put_error(0x14,0x10a,iVar4,"d1_srvr.c",iVar11);
  return 0xffffffff;
}

