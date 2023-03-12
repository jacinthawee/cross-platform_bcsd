
uint ssl3_get_cert_status(int param_1)

{
  char *pcVar1;
  code *pcVar2;
  uint uVar3;
  void *pvVar4;
  int iVar5;
  undefined4 uVar6;
  uint siz;
  int in_GS_OFFSET;
  int line;
  int local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  uVar3 = (**(code **)(*(int *)(param_1 + 8) + 0x30))(param_1,0x11f0,0x11f1,0x16,0x4000,&local_24);
  if (local_24 == 0) goto LAB_080a09f5;
  if (uVar3 < 4) {
    line = 0x85c;
    iVar5 = 0x9f;
LAB_080a0a62:
    ERR_put_error(0x14,0x121,iVar5,"s3_clnt.c",line);
    uVar6 = 0x32;
  }
  else {
    pcVar1 = *(char **)(param_1 + 0x40);
    if (*pcVar1 != '\x01') {
      line = 0x863;
      iVar5 = 0x149;
      goto LAB_080a0a62;
    }
    siz = (uint)(byte)pcVar1[3] | (uint)(byte)pcVar1[2] << 8 | (uint)(byte)pcVar1[1] << 0x10;
    if (uVar3 != siz + 4) {
      line = 0x86a;
      iVar5 = 0x9f;
      goto LAB_080a0a62;
    }
    if (*(void **)(param_1 + 0x138) != (void *)0x0) {
      CRYPTO_free(*(void **)(param_1 + 0x138));
    }
    pvVar4 = BUF_memdup(pcVar1 + 4,siz);
    *(void **)(param_1 + 0x138) = pvVar4;
    if (pvVar4 != (void *)0x0) {
      *(uint *)(param_1 + 0x13c) = siz;
      pcVar2 = *(code **)(*(int *)(param_1 + 0xe4) + 0x13c);
      if (pcVar2 != (code *)0x0) {
        iVar5 = (*pcVar2)(param_1,*(undefined4 *)(*(int *)(param_1 + 0xe4) + 0x140));
        if (iVar5 == 0) {
          ERR_put_error(0x14,0x121,0x148,"s3_clnt.c",0x87e);
          uVar6 = 0x71;
          goto LAB_080a0a38;
        }
        if (iVar5 < 0) {
          iVar5 = 0x884;
          goto LAB_080a0a16;
        }
      }
      uVar3 = 1;
      goto LAB_080a09f5;
    }
    iVar5 = 0x873;
LAB_080a0a16:
    ERR_put_error(0x14,0x121,0x41,"s3_clnt.c",iVar5);
    uVar6 = 0x50;
  }
LAB_080a0a38:
  ssl3_send_alert(param_1,2,uVar6);
  uVar3 = 0xffffffff;
LAB_080a09f5:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

