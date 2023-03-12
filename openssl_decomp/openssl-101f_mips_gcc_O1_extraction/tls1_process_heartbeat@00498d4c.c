
int tls1_process_heartbeat(undefined4 *param_1)

{
  char cVar1;
  ushort uVar2;
  undefined *puVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  int iVar7;
  
  pcVar5 = *(char **)(param_1[0x16] + 0x118);
  uVar2 = *(ushort *)(pcVar5 + 1);
  cVar1 = *pcVar5;
  uVar6 = (uint)uVar2;
  if ((code *)param_1[0x19] != (code *)0x0) {
    (*(code *)param_1[0x19])
              (0,*param_1,0x18,pcVar5,*(undefined4 *)(param_1[0x16] + 0x110),param_1,param_1[0x1a]);
  }
  if (cVar1 == '\x01') {
    iVar7 = uVar6 + 0x13;
    puVar3 = (undefined *)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar7,"t1_lib.c",0xa14);
    puVar3[2] = (char)uVar2;
    *puVar3 = 2;
    puVar3[1] = (char)(uVar2 >> 8);
    iVar4 = (*(code *)PTR_memcpy_006aabf4)(puVar3 + 3,pcVar5 + 3,uVar6);
    (*(code *)PTR_RAND_pseudo_bytes_006a8664)(iVar4 + uVar6,0x10);
    iVar4 = ssl3_write_bytes(param_1,0x18,puVar3,iVar7);
    if (-1 < iVar4) {
      if ((code *)param_1[0x19] != (code *)0x0) {
        (*(code *)param_1[0x19])(1,*param_1,0x18,puVar3,iVar7,param_1,param_1[0x1a]);
      }
      (*(code *)PTR_CRYPTO_free_006a7f88)(puVar3);
      return 0;
    }
    (*(code *)PTR_CRYPTO_free_006a7f88)(puVar3);
    return iVar4;
  }
  if (cVar1 == '\x02') {
    if (uVar6 != 0x12) {
      return 0;
    }
    uVar2 = *(ushort *)(pcVar5 + 3);
    if ((uint)uVar2 == param_1[99]) {
      param_1[0x62] = 0;
      param_1[99] = uVar2 + 1;
      return 0;
    }
  }
  return 0;
}

