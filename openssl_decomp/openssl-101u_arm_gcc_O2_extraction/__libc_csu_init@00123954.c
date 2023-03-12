
void __libc_csu_init(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  int iVar2;
  code **ppcVar3;
  int iVar4;
  
  puVar1 = PTR_ssl_set_cert_0012398c;
  iVar4 = DAT_00123988 + 0x123966;
  _init();
  iVar4 = iVar4 - (int)(puVar1 + 0x12396c) >> 2;
  if (iVar4 != 0) {
    iVar2 = 0;
    ppcVar3 = (code **)(puVar1 + 0x12396c);
    do {
      iVar2 = iVar2 + 1;
      (**ppcVar3)(param_1,param_2,param_3,*ppcVar3,param_4);
      ppcVar3 = ppcVar3 + 1;
    } while (iVar2 != iVar4);
  }
  return;
}

