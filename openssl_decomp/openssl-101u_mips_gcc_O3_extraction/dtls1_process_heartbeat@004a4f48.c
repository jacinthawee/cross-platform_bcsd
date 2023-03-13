
int dtls1_process_heartbeat(undefined4 *param_1)

{
  ushort uVar1;
  undefined *puVar2;
  int iVar3;
  undefined *ptr;
  char *pcVar4;
  uint uVar5;
  uint num;
  
  iVar3 = param_1[0x16];
  pcVar4 = *(char **)(iVar3 + 0x118);
  if ((code *)param_1[0x19] != (code *)0x0) {
    (*(code *)param_1[0x19])
              (0,*param_1,0x18,pcVar4,*(undefined4 *)(iVar3 + 0x110),param_1,param_1[0x1a]);
    iVar3 = param_1[0x16];
  }
  if (0x3fed < *(uint *)(iVar3 + 0x110) - 0x13) {
    return 0;
  }
  uVar1 = *(ushort *)(pcVar4 + 1);
  uVar5 = (uint)uVar1;
  num = uVar5 + 0x13;
  if (num <= *(uint *)(iVar3 + 0x110)) {
    if (*pcVar4 == '\x01') {
      ptr = (undefined *)CRYPTO_malloc(num,"d1_both.c",0x630);
      puVar2 = PTR_memcpy_006a9aec;
      if (ptr == (undefined *)0x0) {
        return -1;
      }
      ptr[2] = (char)uVar1;
      ptr[1] = (char)(uVar1 >> 8);
      *ptr = 2;
      iVar3 = (*(code *)puVar2)(ptr + 3,pcVar4 + 3,uVar5);
      iVar3 = (*(code *)PTR_RAND_bytes_006a7574)(iVar3 + uVar5,0x10);
      if (0 < iVar3) {
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
      CRYPTO_free(ptr);
      return -1;
    }
    if (*pcVar4 != '\x02') {
      return 0;
    }
    if ((uVar5 == 0x12) && ((uint)*(ushort *)(pcVar4 + 3) == param_1[99])) {
      dtls1_stop_timer(param_1);
      param_1[0x62] = 0;
      param_1[99] = param_1[99] + 1;
      return 0;
    }
  }
  return 0;
}

