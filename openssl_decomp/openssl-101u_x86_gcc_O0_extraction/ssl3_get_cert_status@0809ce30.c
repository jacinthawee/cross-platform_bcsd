
uint ssl3_get_cert_status(int param_1)

{
  code *pcVar1;
  char *pcVar2;
  uint uVar3;
  int iVar4;
  void *pvVar5;
  undefined4 uVar6;
  uint siz;
  int in_GS_OFFSET;
  int line;
  int local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  uVar3 = (**(code **)(*(int *)(param_1 + 8) + 0x30))
                    (param_1,0x11f0,0x11f1,0xffffffff,0x4000,&local_14);
  if (local_14 == 0) goto LAB_0809ceb7;
  if (*(int *)(*(int *)(param_1 + 0x58) + 0x340) == 0x16) {
    if (uVar3 < 4) {
      line = 0x8ee;
      iVar4 = 0x9f;
    }
    else {
      pcVar2 = *(char **)(param_1 + 0x40);
      if (*pcVar2 == '\x01') {
        siz = (uint)(byte)pcVar2[3] | (uint)(byte)pcVar2[2] << 8 | (uint)(byte)pcVar2[1] << 0x10;
        if (uVar3 == siz + 4) {
          pvVar5 = BUF_memdup(pcVar2 + 4,siz);
          *(void **)(param_1 + 0x138) = pvVar5;
          if (pvVar5 != (void *)0x0) {
            *(uint *)(param_1 + 0x13c) = siz;
            goto LAB_0809ce85;
          }
          iVar4 = 0x900;
          goto LAB_0809cfd1;
        }
        line = 0x8fa;
        iVar4 = 0x9f;
      }
      else {
        line = 0x8f4;
        iVar4 = 0x149;
      }
    }
    ERR_put_error(0x14,0x121,iVar4,"s3_clnt.c",line);
    uVar6 = 0x32;
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x354) = 1;
LAB_0809ce85:
    pcVar1 = *(code **)(*(int *)(param_1 + 0xe4) + 0x13c);
    if (pcVar1 == (code *)0x0) {
LAB_0809ceb2:
      uVar3 = 1;
      goto LAB_0809ceb7;
    }
    iVar4 = (*pcVar1)(param_1,*(undefined4 *)(*(int *)(param_1 + 0xe4) + 0x140));
    if (iVar4 == 0) {
      ERR_put_error(0x14,0x121,0x148,"s3_clnt.c",0x90a);
      uVar6 = 0x71;
    }
    else {
      if (-1 < iVar4) goto LAB_0809ceb2;
      iVar4 = 0x90f;
LAB_0809cfd1:
      ERR_put_error(0x14,0x121,0x41,"s3_clnt.c",iVar4);
      uVar6 = 0x50;
    }
  }
  ssl3_send_alert(param_1,2,uVar6);
  *(undefined4 *)(param_1 + 0x34) = 5;
  uVar3 = 0xffffffff;
LAB_0809ceb7:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

