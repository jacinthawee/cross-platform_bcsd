
int tls1_process_heartbeat(undefined4 *param_1)

{
  int num;
  char cVar1;
  ushort uVar2;
  char *pcVar3;
  int iVar4;
  undefined *ptr;
  uint uVar5;
  ushort uVar6;
  
  pcVar3 = *(char **)(param_1[0x16] + 0x118);
  uVar2 = *(ushort *)(pcVar3 + 1);
  cVar1 = *pcVar3;
  uVar6 = uVar2 << 8 | uVar2 >> 8;
  uVar5 = (uint)uVar6;
  if ((code *)param_1[0x19] != (code *)0x0) {
    (*(code *)param_1[0x19])
              (0,*param_1,0x18,pcVar3,*(undefined4 *)(param_1[0x16] + 0x110),param_1,param_1[0x1a]);
  }
  if (cVar1 == '\x01') {
    num = uVar5 + 0x13;
    ptr = (undefined *)CRYPTO_malloc(num,"t1_lib.c",0xa14);
    *ptr = 2;
    ptr[2] = (char)(uVar2 >> 8);
    ptr[1] = (char)uVar2;
    memcpy(ptr + 3,pcVar3 + 3,uVar5);
    RAND_pseudo_bytes(ptr + 3 + uVar5,0x10);
    iVar4 = ssl3_write_bytes(param_1,0x18,ptr,num);
    if (-1 < iVar4) {
      if ((code *)param_1[0x19] != (code *)0x0) {
        (*(code *)param_1[0x19])(1,*param_1,0x18,ptr,num,param_1,param_1[0x1a]);
      }
      CRYPTO_free(ptr);
      return 0;
    }
    CRYPTO_free(ptr);
  }
  else {
    iVar4 = 0;
    if (((cVar1 == '\x02') && (uVar6 == 0x12)) &&
       (uVar5 = (uint)(ushort)(*(ushort *)(pcVar3 + 3) << 8 | *(ushort *)(pcVar3 + 3) >> 8),
       uVar5 == param_1[99])) {
      param_1[0x62] = 0;
      param_1[99] = uVar5 + 1;
    }
  }
  return iVar4;
}

