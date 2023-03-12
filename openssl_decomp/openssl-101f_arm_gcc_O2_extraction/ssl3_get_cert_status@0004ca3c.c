
uint ssl3_get_cert_status(int param_1)

{
  uint uVar1;
  void *pvVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  code *pcVar6;
  uint siz;
  int local_14;
  
  uVar1 = (**(code **)(*(int *)(param_1 + 8) + 0x30))(param_1,0x11f0,0x11f1,0x16,0x4000,&local_14);
  if (local_14 == 0) {
    return uVar1;
  }
  if (uVar1 < 4) {
    iVar3 = 0x85c;
  }
  else {
    pcVar5 = *(char **)(param_1 + 0x40);
    if (*pcVar5 != '\x01') {
      ERR_put_error(0x14,0x121,0x149,"s3_clnt.c",0x863);
      uVar4 = 0x32;
      goto LAB_0004caea;
    }
    siz = (uint)(byte)pcVar5[2] << 8 | (uint)(byte)pcVar5[1] << 0x10 | (uint)(byte)pcVar5[3];
    if (siz + 4 == uVar1) {
      if (*(void **)(param_1 + 0x138) != (void *)0x0) {
        CRYPTO_free(*(void **)(param_1 + 0x138));
      }
      pvVar2 = BUF_memdup(pcVar5 + 4,siz);
      iVar3 = 0x873;
      *(void **)(param_1 + 0x138) = pvVar2;
      if (pvVar2 != (void *)0x0) {
        *(uint *)(param_1 + 0x13c) = siz;
        pcVar6 = *(code **)(*(int *)(param_1 + 0xe4) + 0x13c);
        if (pcVar6 == (code *)0x0) {
          return 1;
        }
        iVar3 = (*pcVar6)(param_1,*(undefined4 *)(*(int *)(param_1 + 0xe4) + 0x140));
        if (iVar3 == 0) {
          ERR_put_error(0x14,0x121,0x148,"s3_clnt.c",0x87e);
          uVar4 = 0x71;
          goto LAB_0004caea;
        }
        if (-1 < iVar3) {
          return 1;
        }
        iVar3 = 0x884;
      }
      ERR_put_error(0x14,0x121,0x41,"s3_clnt.c",iVar3);
      uVar4 = 0x50;
      goto LAB_0004caea;
    }
    iVar3 = 0x86a;
  }
  ERR_put_error(0x14,0x121,0x9f,"s3_clnt.c",iVar3);
  uVar4 = 0x32;
LAB_0004caea:
  ssl3_send_alert(param_1,2,uVar4);
  return 0xffffffff;
}

