
int dtls1_process_heartbeat(undefined4 *param_1)

{
  int num;
  char cVar1;
  ushort uVar2;
  char *pcVar3;
  undefined *ptr;
  uint __n;
  ushort uVar4;
  int local_24;
  
  pcVar3 = *(char **)(param_1[0x16] + 0x118);
  uVar2 = *(ushort *)(pcVar3 + 1);
  cVar1 = *pcVar3;
  uVar4 = uVar2 << 8 | uVar2 >> 8;
  __n = (uint)uVar4;
  if ((code *)param_1[0x19] != (code *)0x0) {
    (*(code *)param_1[0x19])
              (0,*param_1,0x18,pcVar3,*(undefined4 *)(param_1[0x16] + 0x110),param_1,param_1[0x1a]);
  }
  if (cVar1 == '\x01') {
    num = __n + 0x13;
    ptr = (undefined *)CRYPTO_malloc(num,"d1_both.c",0x5c9);
    *ptr = 2;
    ptr[2] = (char)(uVar2 >> 8);
    ptr[1] = (char)uVar2;
    memcpy(ptr + 3,pcVar3 + 3,__n);
    RAND_pseudo_bytes(ptr + 3 + __n,0x10);
    local_24 = dtls1_write_bytes(param_1,0x18,ptr,num);
    if (-1 < local_24) {
      if ((code *)param_1[0x19] != (code *)0x0) {
        (*(code *)param_1[0x19])(1,*param_1,0x18,ptr,num,param_1,param_1[0x1a]);
      }
      CRYPTO_free(ptr);
      return 0;
    }
    CRYPTO_free(ptr);
  }
  else {
    local_24 = 0;
    if (((cVar1 == '\x02') && (uVar4 == 0x12)) &&
       ((uint)(ushort)(*(ushort *)(pcVar3 + 3) << 8 | *(ushort *)(pcVar3 + 3) >> 8) == param_1[99]))
    {
      local_24 = 0;
      dtls1_stop_timer(param_1);
      param_1[99] = param_1[99] + 1;
      param_1[0x62] = 0;
    }
  }
  return local_24;
}

