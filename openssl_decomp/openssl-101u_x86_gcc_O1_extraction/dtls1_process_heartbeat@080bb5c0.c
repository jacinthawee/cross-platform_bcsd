
int dtls1_process_heartbeat(undefined4 *param_1)

{
  uint num;
  ushort uVar1;
  char *pcVar2;
  undefined *ptr;
  int iVar3;
  uint __n;
  ushort uVar4;
  int local_24;
  
  iVar3 = param_1[0x16];
  pcVar2 = *(char **)(iVar3 + 0x118);
  if ((code *)param_1[0x19] != (code *)0x0) {
    (*(code *)param_1[0x19])
              (0,*param_1,0x18,pcVar2,*(undefined4 *)(iVar3 + 0x110),param_1,param_1[0x1a]);
    iVar3 = param_1[0x16];
  }
  local_24 = 0;
  if (*(uint *)(iVar3 + 0x110) - 0x13 < 0x3fee) {
    uVar1 = *(ushort *)(pcVar2 + 1);
    uVar4 = uVar1 << 8 | uVar1 >> 8;
    __n = (uint)uVar4;
    num = __n + 0x13;
    if (num <= *(uint *)(iVar3 + 0x110)) {
      if (*pcVar2 == '\x01') {
        ptr = (undefined *)CRYPTO_malloc(num,"d1_both.c",0x630);
        if (ptr == (undefined *)0x0) {
          local_24 = -1;
        }
        else {
          *ptr = 2;
          ptr[1] = (char)uVar1;
          ptr[2] = (char)(uVar1 >> 8);
          memcpy(ptr + 3,pcVar2 + 3,__n);
          iVar3 = RAND_bytes(ptr + 3 + __n,0x10);
          if (iVar3 < 1) {
            CRYPTO_free(ptr);
            local_24 = -1;
          }
          else {
            local_24 = dtls1_write_bytes(param_1,0x18,ptr,num);
            if (local_24 < 0) {
              CRYPTO_free(ptr);
            }
            else {
              if ((code *)param_1[0x19] != (code *)0x0) {
                (*(code *)param_1[0x19])(1,*param_1,0x18,ptr,num,param_1,param_1[0x1a]);
              }
              CRYPTO_free(ptr);
              local_24 = 0;
            }
          }
        }
      }
      else if (((*pcVar2 == '\x02') && (uVar4 == 0x12)) &&
              ((uint)(ushort)(*(ushort *)(pcVar2 + 3) << 8 | *(ushort *)(pcVar2 + 3) >> 8) ==
               param_1[99])) {
        local_24 = 0;
        dtls1_stop_timer(param_1);
        param_1[99] = param_1[99] + 1;
        param_1[0x62] = 0;
      }
    }
  }
  return local_24;
}

