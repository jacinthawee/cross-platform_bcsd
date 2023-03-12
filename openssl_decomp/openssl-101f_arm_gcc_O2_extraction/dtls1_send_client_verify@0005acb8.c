
void dtls1_send_client_verify(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  uint local_48;
  uint local_44;
  uchar auStack_40 [16];
  uchar auStack_30 [20];
  int local_1c;
  
  local_48 = 0;
  local_1c = __TMC_END__;
  if (*(int *)(param_1 + 0x34) == 0x1190) {
    iVar3 = *(int *)(*(int *)(param_1 + 0x3c) + 4);
    piVar4 = *(int **)(**(int **)(param_1 + 0x98) + 4);
    (**(code **)(*(int *)(*(int *)(param_1 + 8) + 100) + 0x1c))(param_1,0x40,auStack_30);
    iVar2 = *piVar4;
    if (iVar2 == 6) {
      (**(code **)(*(int *)(*(int *)(param_1 + 8) + 100) + 0x1c))(param_1,4,auStack_40);
      iVar2 = RSA_sign(0x72,auStack_40,0x24,(uchar *)(iVar3 + 0xe),&local_48,(RSA *)piVar4[5]);
      if (iVar2 < 1) {
        ERR_put_error(0x14,0x107,4,"d1_clnt.c",0x625);
        uVar1 = 0xffffffff;
        goto LAB_0005ace2;
      }
      *(char *)(iVar3 + 0xd) = (char)local_48;
      *(char *)(iVar3 + 0xc) = (char)(local_48 >> 8);
      local_44 = local_48;
    }
    else {
      if (iVar2 == 0x74) {
        iVar2 = DSA_sign(piVar4[1],auStack_30,0x14,(uchar *)(iVar3 + 0xe),&local_44,(DSA *)piVar4[5]
                        );
        if (iVar2 == 0) {
          ERR_put_error(0x14,0x107,10,"d1_clnt.c",0x635);
          uVar1 = 0xffffffff;
          goto LAB_0005ace2;
        }
      }
      else {
        if (iVar2 != 0x198) {
          ERR_put_error(0x14,0x107,0x44,"d1_clnt.c",0x64f);
          uVar1 = 0xffffffff;
          goto LAB_0005ace2;
        }
        iVar2 = ECDSA_sign(piVar4[1],auStack_30,0x14,(uchar *)(iVar3 + 0xe),&local_44,
                           (EC_KEY *)piVar4[5]);
        if (iVar2 == 0) {
          ERR_put_error(0x14,0x107,0x2a,"d1_clnt.c",0x646);
          uVar1 = 0xffffffff;
          goto LAB_0005ace2;
        }
      }
      *(char *)(iVar3 + 0xd) = (char)local_44;
      *(char *)(iVar3 + 0xc) = (char)(local_44 >> 8);
    }
    dtls1_set_message_header(param_1,iVar3,0xf,local_44 + 2,0,local_44 + 2);
    *(undefined4 *)(param_1 + 0x48) = 0;
    *(uint *)(param_1 + 0x44) = local_44 + 0xe;
    dtls1_buffer_message(param_1,0);
    *(undefined4 *)(param_1 + 0x34) = 0x1191;
  }
  uVar1 = dtls1_do_write(param_1,0x16);
LAB_0005ace2:
  if (local_1c == __TMC_END__) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar1);
}

