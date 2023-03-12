
int tls1_process_heartbeat(undefined4 *param_1)

{
  ushort uVar1;
  undefined *puVar2;
  int iVar3;
  undefined *puVar4;
  char *pcVar5;
  uint uVar6;
  uint uVar7;
  
  iVar3 = param_1[0x16];
  pcVar5 = *(char **)(iVar3 + 0x118);
  if ((code *)param_1[0x19] != (code *)0x0) {
    (*(code *)param_1[0x19])
              (0,*param_1,0x18,pcVar5,*(undefined4 *)(iVar3 + 0x110),param_1,param_1[0x1a]);
    iVar3 = param_1[0x16];
  }
  if (0x12 < *(uint *)(iVar3 + 0x110)) {
    uVar1 = *(ushort *)(pcVar5 + 1);
    uVar6 = (uint)uVar1;
    uVar7 = uVar6 + 0x13;
    if (uVar7 <= *(uint *)(iVar3 + 0x110)) {
      if (*pcVar5 == '\x01') {
        puVar4 = (undefined *)(*(code *)PTR_CRYPTO_malloc_006a7008)(uVar7,"t1_lib.c",0xa2a);
        puVar2 = PTR_memcpy_006a9aec;
        if (puVar4 == (undefined *)0x0) {
          return -1;
        }
        puVar4[2] = (char)uVar1;
        puVar4[1] = (char)(uVar1 >> 8);
        *puVar4 = 2;
        iVar3 = (*(code *)puVar2)(puVar4 + 3,pcVar5 + 3,uVar6);
        iVar3 = (*(code *)PTR_RAND_bytes_006a7574)(iVar3 + uVar6,0x10);
        if (0 < iVar3) {
          iVar3 = ssl3_write_bytes(param_1,0x18,puVar4,uVar7);
          if (-1 < iVar3) {
            if ((code *)param_1[0x19] != (code *)0x0) {
              (*(code *)param_1[0x19])(1,*param_1,0x18,puVar4,uVar7,param_1,param_1[0x1a]);
            }
            (*(code *)PTR_CRYPTO_free_006a6e88)(puVar4);
            return 0;
          }
          (*(code *)PTR_CRYPTO_free_006a6e88)(puVar4);
          return iVar3;
        }
        (*(code *)PTR_CRYPTO_free_006a6e88)(puVar4);
        return -1;
      }
      if (*pcVar5 == '\x02') {
        if (uVar6 != 0x12) {
          return 0;
        }
        uVar1 = *(ushort *)(pcVar5 + 3);
        if ((uint)uVar1 == param_1[99]) {
          param_1[0x62] = 0;
          param_1[99] = uVar1 + 1;
          return 0;
        }
      }
    }
  }
  return 0;
}

