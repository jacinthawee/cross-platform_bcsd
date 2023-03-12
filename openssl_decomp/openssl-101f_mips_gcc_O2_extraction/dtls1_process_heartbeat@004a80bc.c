
int dtls1_process_heartbeat(undefined4 *param_1)

{
  char cVar1;
  ushort uVar2;
  undefined *ptr;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  int num;
  
  pcVar4 = *(char **)(param_1[0x16] + 0x118);
  uVar2 = *(ushort *)(pcVar4 + 1);
  cVar1 = *pcVar4;
  uVar5 = (uint)uVar2;
  if ((code *)param_1[0x19] != (code *)0x0) {
    (*(code *)param_1[0x19])
              (0,*param_1,0x18,pcVar4,*(undefined4 *)(param_1[0x16] + 0x110),param_1,param_1[0x1a]);
  }
  if (cVar1 == '\x01') {
    num = uVar5 + 0x13;
    ptr = (undefined *)CRYPTO_malloc(num,"d1_both.c",0x5c9);
    ptr[2] = (char)uVar2;
    *ptr = 2;
    ptr[1] = (char)(uVar2 >> 8);
    iVar3 = (*(code *)PTR_memcpy_006aabf4)(ptr + 3,pcVar4 + 3,uVar5);
    (*(code *)PTR_RAND_pseudo_bytes_006a8664)(iVar3 + uVar5,0x10);
    iVar3 = dtls1_write_bytes(param_1,0x18,ptr,num);
    if (-1 < iVar3) {
      if ((code *)param_1[0x19] != (code *)0x0) {
        (*(code *)param_1[0x19])(1,*param_1,0x18,ptr,num,param_1,param_1[0x1a]);
      }
      CRYPTO_free(ptr);
      return 0;
    }
    CRYPTO_free(ptr);
    return iVar3;
  }
  if (cVar1 == '\x02') {
    if (uVar5 != 0x12) {
      return 0;
    }
    if ((uint)*(ushort *)(pcVar4 + 3) == param_1[99]) {
      dtls1_stop_timer(param_1);
      param_1[0x62] = 0;
      param_1[99] = param_1[99] + 1;
      return 0;
    }
  }
  return 0;
}

