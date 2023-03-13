
undefined4 dtls1_send_client_verify(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int in_GS_OFFSET;
  int iVar4;
  uint local_4c;
  uint local_48;
  uchar local_44 [16];
  uchar local_34 [20];
  int local_20;
  
  local_4c = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (*(int *)(param_1 + 0x34) == 0x1190) {
    iVar4 = *(int *)(*(int *)(param_1 + 0x3c) + 4);
    piVar1 = *(int **)(**(int **)(param_1 + 0x98) + 4);
    (**(code **)(*(int *)(*(int *)(param_1 + 8) + 100) + 0x1c))(param_1,0x40,local_34);
    iVar3 = *piVar1;
    if (iVar3 == 6) {
      (**(code **)(*(int *)(*(int *)(param_1 + 8) + 100) + 0x1c))(param_1,4,local_44);
      iVar3 = RSA_sign(0x72,local_44,0x24,(uchar *)(iVar4 + 0xe),&local_4c,(RSA *)piVar1[5]);
      if (0 < iVar3) {
        *(char *)(iVar4 + 0xd) = (char)local_4c;
        *(char *)(iVar4 + 0xc) = (char)(local_4c >> 8);
        local_48 = local_4c;
LAB_080b388a:
        dtls1_set_message_header(param_1,iVar4,0xf,local_48 + 2,0,local_48 + 2);
        *(uint *)(param_1 + 0x44) = local_48 + 0xe;
        *(undefined4 *)(param_1 + 0x48) = 0;
        dtls1_buffer_message(param_1,0);
        *(undefined4 *)(param_1 + 0x34) = 0x1191;
        goto LAB_080b37e7;
      }
      iVar3 = 0x62d;
      iVar4 = 4;
    }
    else if (iVar3 == 0x74) {
      iVar3 = DSA_sign(piVar1[1],local_34,0x14,(uchar *)(iVar4 + 0xe),&local_48,(DSA *)piVar1[5]);
      if (iVar3 != 0) {
LAB_080b3878:
        *(char *)(iVar4 + 0xd) = (char)local_48;
        *(char *)(iVar4 + 0xc) = (char)(local_48 >> 8);
        goto LAB_080b388a;
      }
      iVar3 = 0x63a;
      iVar4 = 10;
    }
    else if (iVar3 == 0x198) {
      iVar3 = ECDSA_sign(piVar1[1],local_34,0x14,(uchar *)(iVar4 + 0xe),&local_48,
                         (EC_KEY *)piVar1[5]);
      if (iVar3 != 0) goto LAB_080b3878;
      iVar3 = 0x647;
      iVar4 = 0x2a;
    }
    else {
      iVar3 = 0x64f;
      iVar4 = 0x44;
    }
    ERR_put_error(0x14,0x107,iVar4,"d1_clnt.c",iVar3);
    uVar2 = 0xffffffff;
  }
  else {
LAB_080b37e7:
    uVar2 = dtls1_do_write(param_1,0x16);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

