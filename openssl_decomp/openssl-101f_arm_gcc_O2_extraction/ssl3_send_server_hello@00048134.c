
undefined4 ssl3_send_server_hello(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  size_t __n;
  int iVar4;
  byte *pbVar5;
  undefined *puVar6;
  undefined4 uVar7;
  undefined *puVar8;
  
  if (param_1[0xd] == 0x2130) {
    puVar6 = *(undefined **)(param_1[0xf] + 4);
    puVar6[4] = (char)((uint)*param_1 >> 8);
    puVar6[5] = (char)*param_1;
    iVar4 = param_1[0x16];
    uVar7 = *(undefined4 *)(iVar4 + 0xa4);
    uVar1 = *(undefined4 *)(iVar4 + 0xa8);
    uVar3 = *(undefined4 *)(iVar4 + 0xac);
    *(undefined4 *)(puVar6 + 6) = *(undefined4 *)(iVar4 + 0xa0);
    *(undefined4 *)(puVar6 + 10) = uVar7;
    *(undefined4 *)(puVar6 + 0xe) = uVar1;
    *(undefined4 *)(puVar6 + 0x12) = uVar3;
    uVar7 = *(undefined4 *)(iVar4 + 0xb4);
    uVar1 = *(undefined4 *)(iVar4 + 0xb8);
    uVar3 = *(undefined4 *)(iVar4 + 0xbc);
    *(undefined4 *)(puVar6 + 0x16) = *(undefined4 *)(iVar4 + 0xb0);
    *(undefined4 *)(puVar6 + 0x1a) = uVar7;
    *(undefined4 *)(puVar6 + 0x1e) = uVar1;
    *(undefined4 *)(puVar6 + 0x22) = uVar3;
    if ((*(int *)(param_1[0x39] + 0x20) << 0x1e < 0) || (__n = param_1[0x1b], __n != 0)) {
      __n = *(size_t *)(param_1[0x30] + 0x44);
      if (0x20 < (int)__n) {
        iVar4 = 0x5c5;
        goto LAB_00048234;
      }
    }
    else {
      *(undefined4 *)(param_1[0x30] + 0x44) = 0;
    }
    puVar6[0x26] = (char)__n;
    puVar8 = puVar6 + 0x27 + __n;
    memcpy(puVar6 + 0x27,(void *)(param_1[0x30] + 0x48),__n);
    iVar4 = ssl3_put_cipher_by_char(*(undefined4 *)(param_1[0x16] + 0x344),puVar8);
    pbVar5 = *(byte **)(param_1[0x16] + 0x38c);
    if (pbVar5 != (byte *)0x0) {
      pbVar5 = (byte *)(uint)*pbVar5;
    }
    puVar8[iVar4] = (char)pbVar5;
    iVar2 = ssl_prepare_serverhello_tlsext(param_1);
    if (iVar2 < 1) {
      ERR_put_error(0x14,0xf2,0x113,"s3_srvr.c",0x5dc);
      return 0xffffffff;
    }
    iVar4 = ssl_add_serverhello_tlsext(param_1,puVar8 + iVar4 + 1,puVar6 + 0x4000);
    if (iVar4 == 0) {
      iVar4 = 0x5e1;
LAB_00048234:
      ERR_put_error(0x14,0xf2,0x44,"s3_srvr.c",iVar4);
      return 0xffffffff;
    }
    iVar2 = iVar4 - (int)(puVar6 + 4);
    puVar6[3] = (char)iVar2;
    *puVar6 = 2;
    puVar6[1] = (char)((uint)iVar2 >> 0x10);
    puVar6[2] = (char)((uint)iVar2 >> 8);
    param_1[0x11] = iVar4 - (int)puVar6;
    param_1[0xd] = 0x2131;
    param_1[0x12] = 0;
  }
  uVar1 = ssl3_do_write(param_1,0x16);
  return uVar1;
}

