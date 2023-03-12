
undefined4 dtls1_send_server_hello(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint __n;
  byte *pbVar6;
  int iVar7;
  undefined4 uVar8;
  
  if (param_1[0xd] == 0x2130) {
    iVar7 = *(int *)(param_1[0xf] + 4);
    ssl_fill_hello_random(param_1,1,param_1[0x16] + 0xa0,0x20);
    *(char *)(iVar7 + 0xc) = (char)((uint)*param_1 >> 8);
    *(char *)(iVar7 + 0xd) = (char)*param_1;
    iVar4 = param_1[0x16];
    uVar5 = *(undefined4 *)(iVar4 + 0xa4);
    uVar8 = *(undefined4 *)(iVar4 + 0xa8);
    uVar1 = *(undefined4 *)(iVar4 + 0xac);
    *(undefined4 *)(iVar7 + 0xe) = *(undefined4 *)(iVar4 + 0xa0);
    *(undefined4 *)(iVar7 + 0x12) = uVar5;
    *(undefined4 *)(iVar7 + 0x16) = uVar8;
    *(undefined4 *)(iVar7 + 0x1a) = uVar1;
    uVar5 = *(undefined4 *)(iVar4 + 0xb4);
    uVar8 = *(undefined4 *)(iVar4 + 0xb8);
    uVar1 = *(undefined4 *)(iVar4 + 0xbc);
    *(undefined4 *)(iVar7 + 0x1e) = *(undefined4 *)(iVar4 + 0xb0);
    *(undefined4 *)(iVar7 + 0x22) = uVar5;
    *(undefined4 *)(iVar7 + 0x26) = uVar8;
    *(undefined4 *)(iVar7 + 0x2a) = uVar1;
    __n = *(uint *)(param_1[0x39] + 0x20) & 2;
    if (__n == 0) {
      *(undefined4 *)(param_1[0x30] + 0x44) = 0;
    }
    else {
      __n = *(uint *)(param_1[0x30] + 0x44);
      if (0x20 < __n) {
        iVar4 = 0x3f4;
        goto LAB_000563d6;
      }
    }
    *(char *)(iVar7 + 0x2e) = (char)__n;
    iVar4 = __n + (int)(void *)(iVar7 + 0x2f);
    memcpy((void *)(iVar7 + 0x2f),(void *)(param_1[0x30] + 0x48),__n);
    if (*(int *)(param_1[0x16] + 0x344) == 0) {
      return 0xffffffff;
    }
    iVar2 = ssl3_put_cipher_by_char(*(int *)(param_1[0x16] + 0x344),iVar4);
    pbVar6 = *(byte **)(param_1[0x16] + 0x38c);
    if (pbVar6 != (byte *)0x0) {
      pbVar6 = (byte *)(uint)*pbVar6;
    }
    *(char *)(iVar4 + iVar2) = (char)pbVar6;
    iVar3 = ssl_prepare_serverhello_tlsext(param_1);
    if (iVar3 < 1) {
      ERR_put_error(0x14,0x10a,0x113,"d1_srvr.c",0x40d);
      return 0xffffffff;
    }
    iVar4 = ssl_add_serverhello_tlsext(param_1,iVar4 + iVar2 + 1,iVar7 + 0x4000);
    if (iVar4 == 0) {
      iVar4 = 0x414;
LAB_000563d6:
      ERR_put_error(0x14,0x10a,0x44,"d1_srvr.c",iVar4);
      return 0xffffffff;
    }
    iVar2 = iVar4 - (iVar7 + 0xc);
    dtls1_set_message_header(param_1,iVar7,2,iVar2,0,iVar2);
    param_1[0x12] = 0;
    param_1[0x11] = iVar4 - iVar7;
    param_1[0xd] = 0x2131;
    dtls1_buffer_message(param_1,0);
  }
  uVar1 = dtls1_do_write(param_1,0x16);
  return uVar1;
}

