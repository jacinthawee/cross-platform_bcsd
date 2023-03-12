
uint ssl3_get_cert_status(int param_1)

{
  uint uVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  code *pcVar5;
  char *pcVar6;
  uint siz;
  int local_14 [2];
  
  uVar1 = (**(code **)(*(int *)(param_1 + 8) + 0x30))
                    (param_1,0x11f0,0x11f1,0xffffffff,0x4000,local_14);
  if (local_14[0] == 0) {
    return uVar1;
  }
  if (*(int *)(*(int *)(param_1 + 0x58) + 0x340) == 0x16) {
    if (uVar1 < 4) {
      iVar2 = 0x8ee;
    }
    else {
      pcVar6 = *(char **)(param_1 + 0x40);
      if (*pcVar6 != '\x01') {
        ERR_put_error(0x14,0x121,0x149,"s3_clnt.c",0x8f4);
        uVar4 = 0x32;
        goto LAB_00049c1e;
      }
      siz = (uint)(byte)pcVar6[2] << 8 | (uint)(byte)pcVar6[1] << 0x10 | (uint)(byte)pcVar6[3];
      if (siz + 4 == uVar1) {
        pvVar3 = BUF_memdup(pcVar6 + 4,siz);
        iVar2 = 0x900;
        *(void **)(param_1 + 0x138) = pvVar3;
        if (pvVar3 != (void *)0x0) {
          *(uint *)(param_1 + 0x13c) = siz;
          goto LAB_00049b9a;
        }
        goto LAB_00049c78;
      }
      iVar2 = 0x8fa;
    }
    ERR_put_error(0x14,0x121,0x9f,"s3_clnt.c",iVar2);
    uVar4 = 0x32;
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x354) = 1;
LAB_00049b9a:
    pcVar5 = *(code **)(*(int *)(param_1 + 0xe4) + 0x13c);
    if (pcVar5 == (code *)0x0) {
      return 1;
    }
    iVar2 = (*pcVar5)(param_1,*(undefined4 *)(*(int *)(param_1 + 0xe4) + 0x140));
    if (iVar2 == 0) {
      ERR_put_error(0x14,0x121,0x148,"s3_clnt.c",0x90a);
      uVar4 = 0x71;
      goto LAB_00049c1e;
    }
    if (-1 < iVar2) {
      return 1;
    }
    iVar2 = 0x90f;
LAB_00049c78:
    ERR_put_error(0x14,0x121,0x41,"s3_clnt.c",iVar2);
    uVar4 = 0x50;
  }
LAB_00049c1e:
  ssl3_send_alert(param_1,2,uVar4);
  *(undefined4 *)(param_1 + 0x34) = 5;
  return 0xffffffff;
}

