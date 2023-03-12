
undefined4 dtls1_send_server_hello(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint __n;
  byte *pbVar5;
  int iVar6;
  undefined4 uVar7;
  
  if (param_1[0xd] == 0x2130) {
    iVar6 = *(int *)(param_1[0xf] + 4);
    ssl_fill_hello_random(param_1,1,param_1[0x16] + 0xa0,0x20);
    *(char *)(iVar6 + 0xc) = (char)((uint)*param_1 >> 8);
    *(char *)(iVar6 + 0xd) = (char)*param_1;
    iVar3 = param_1[0x16];
    uVar4 = *(undefined4 *)(iVar3 + 0xa4);
    uVar7 = *(undefined4 *)(iVar3 + 0xa8);
    uVar1 = *(undefined4 *)(iVar3 + 0xac);
    *(undefined4 *)(iVar6 + 0xe) = *(undefined4 *)(iVar3 + 0xa0);
    *(undefined4 *)(iVar6 + 0x12) = uVar4;
    *(undefined4 *)(iVar6 + 0x16) = uVar7;
    *(undefined4 *)(iVar6 + 0x1a) = uVar1;
    uVar4 = *(undefined4 *)(iVar3 + 0xb4);
    uVar7 = *(undefined4 *)(iVar3 + 0xb8);
    uVar1 = *(undefined4 *)(iVar3 + 0xbc);
    *(undefined4 *)(iVar6 + 0x1e) = *(undefined4 *)(iVar3 + 0xb0);
    *(undefined4 *)(iVar6 + 0x22) = uVar4;
    *(undefined4 *)(iVar6 + 0x26) = uVar7;
    *(undefined4 *)(iVar6 + 0x2a) = uVar1;
    __n = *(uint *)(param_1[0x39] + 0x20) & 2;
    if (__n == 0) {
      *(undefined4 *)(param_1[0x30] + 0x44) = 0;
    }
    else {
      __n = *(uint *)(param_1[0x30] + 0x44);
      if (0x20 < __n) {
        iVar3 = 0x3bf;
        goto LAB_00058bdc;
      }
    }
    *(char *)(iVar6 + 0x2e) = (char)__n;
    iVar3 = __n + (int)(void *)(iVar6 + 0x2f);
    memcpy((void *)(iVar6 + 0x2f),(void *)(param_1[0x30] + 0x48),__n);
    if (*(int *)(param_1[0x16] + 0x344) == 0) {
      return 0xffffffff;
    }
    iVar2 = ssl3_put_cipher_by_char(*(int *)(param_1[0x16] + 0x344),iVar3);
    pbVar5 = *(byte **)(param_1[0x16] + 0x38c);
    if (pbVar5 != (byte *)0x0) {
      pbVar5 = (byte *)(uint)*pbVar5;
    }
    *(char *)(iVar3 + iVar2) = (char)pbVar5;
    iVar3 = ssl_add_serverhello_tlsext(param_1,iVar3 + iVar2 + 1,iVar6 + 0x4000);
    if (iVar3 == 0) {
      iVar3 = 0x3d9;
LAB_00058bdc:
      ERR_put_error(0x14,0x10a,0x44,"d1_srvr.c",iVar3);
      return 0xffffffff;
    }
    iVar2 = iVar3 - (iVar6 + 0xc);
    dtls1_set_message_header(param_1,iVar6,2,iVar2,0,iVar2);
    param_1[0x12] = 0;
    param_1[0x11] = iVar3 - iVar6;
    param_1[0xd] = 0x2131;
    dtls1_buffer_message(param_1,0);
  }
  uVar1 = dtls1_do_write(param_1,0x16);
  return uVar1;
}

