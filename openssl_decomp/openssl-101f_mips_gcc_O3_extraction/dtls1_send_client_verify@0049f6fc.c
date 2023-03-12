
undefined4 dtls1_send_client_verify(int param_1)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  int local_50;
  int local_4c;
  undefined auStack_48 [16];
  undefined auStack_38 [20];
  int local_24;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_50 = 0;
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  if (*(int *)(param_1 + 0x34) == 0x1190) {
    iVar6 = *(int *)(*(int *)(param_1 + 0x3c) + 4);
    piVar5 = *(int **)(**(int **)(param_1 + 0x98) + 4);
    (**(code **)(*(int *)(*(int *)(param_1 + 8) + 100) + 0x1c))(param_1,0x40,auStack_38);
    iVar3 = *piVar5;
    if (iVar3 == 6) {
      (**(code **)(*(int *)(*(int *)(param_1 + 8) + 100) + 0x1c))(param_1,4,auStack_48);
      iVar3 = (*(code *)PTR_RSA_sign_006a8b64)(0x72,auStack_48,0x24,iVar6 + 0xe,&local_50,piVar5[5])
      ;
      if (iVar3 < 1) goto LAB_0049f978;
      *(char *)(iVar6 + 0xd) = (char)local_50;
      *(char *)(iVar6 + 0xc) = (char)((uint)local_50 >> 8);
      local_4c = local_50;
    }
    else {
      if (iVar3 == 0x74) {
        iVar3 = (*(code *)PTR_DSA_sign_006a8b7c)
                          (piVar5[1],auStack_38,0x14,iVar6 + 0xe,&local_4c,piVar5[5]);
        if (iVar3 == 0) {
          uVar4 = 10;
          uVar2 = 0x635;
          goto LAB_0049f888;
        }
      }
      else {
        if (iVar3 != 0x198) {
          uVar4 = 0x44;
          uVar2 = 0x64f;
          goto LAB_0049f888;
        }
        iVar3 = (*(code *)PTR_ECDSA_sign_006a8b74)
                          (piVar5[1],auStack_38,0x14,iVar6 + 0xe,&local_4c,piVar5[5]);
        if (iVar3 == 0) {
          uVar4 = 0x2a;
          uVar2 = 0x646;
          goto LAB_0049f888;
        }
      }
      *(char *)(iVar6 + 0xd) = (char)local_4c;
      *(char *)(iVar6 + 0xc) = (char)((uint)local_4c >> 8);
    }
    dtls1_set_message_header(param_1,iVar6,0xf,local_4c + 2,0,local_4c + 2);
    *(undefined4 *)(param_1 + 0x48) = 0;
    *(int *)(param_1 + 0x44) = local_4c + 0xe;
    dtls1_buffer_message(param_1,0);
    *(undefined4 *)(param_1 + 0x34) = 0x1191;
  }
  uVar2 = dtls1_do_write(param_1,0x16);
  while (local_24 != *(int *)puVar1) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_0049f978:
    uVar4 = 4;
    uVar2 = 0x625;
LAB_0049f888:
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x107,uVar4,"d1_clnt.c",uVar2);
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

