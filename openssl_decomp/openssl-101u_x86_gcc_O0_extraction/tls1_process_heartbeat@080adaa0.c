
int tls1_process_heartbeat(undefined4 *param_1)

{
  ushort uVar1;
  char *pcVar2;
  int iVar3;
  undefined *ptr;
  int iVar4;
  uint uVar5;
  uint __n;
  ushort uVar6;
  
  iVar4 = param_1[0x16];
  pcVar2 = *(char **)(iVar4 + 0x118);
  if ((code *)param_1[0x19] != (code *)0x0) {
    (*(code *)param_1[0x19])
              (0,*param_1,0x18,pcVar2,*(undefined4 *)(iVar4 + 0x110),param_1,param_1[0x1a]);
    iVar4 = param_1[0x16];
  }
  iVar3 = 0;
  if (0x12 < *(uint *)(iVar4 + 0x110)) {
    uVar1 = *(ushort *)(pcVar2 + 1);
    uVar6 = uVar1 << 8 | uVar1 >> 8;
    __n = (uint)uVar6;
    uVar5 = __n + 0x13;
    if (uVar5 <= *(uint *)(iVar4 + 0x110)) {
      if (*pcVar2 == '\x01') {
        ptr = (undefined *)CRYPTO_malloc(uVar5,"t1_lib.c",0xa2a);
        if (ptr == (undefined *)0x0) {
          iVar3 = -1;
        }
        else {
          *ptr = 2;
          ptr[1] = (char)uVar1;
          ptr[2] = (char)(uVar1 >> 8);
          memcpy(ptr + 3,pcVar2 + 3,__n);
          iVar4 = RAND_bytes(ptr + 3 + __n,0x10);
          if (iVar4 < 1) {
            CRYPTO_free(ptr);
            iVar3 = -1;
          }
          else {
            iVar3 = ssl3_write_bytes(param_1,0x18,ptr,uVar5);
            if (iVar3 < 0) {
              CRYPTO_free(ptr);
            }
            else {
              if ((code *)param_1[0x19] != (code *)0x0) {
                (*(code *)param_1[0x19])(1,*param_1,0x18,ptr,uVar5,param_1,param_1[0x1a]);
              }
              CRYPTO_free(ptr);
              iVar3 = 0;
            }
          }
        }
      }
      else if (((*pcVar2 == '\x02') && (uVar6 == 0x12)) &&
              (uVar5 = (uint)(ushort)(*(ushort *)(pcVar2 + 3) << 8 | *(ushort *)(pcVar2 + 3) >> 8),
              uVar5 == param_1[99])) {
        param_1[0x62] = 0;
        param_1[99] = uVar5 + 1;
      }
    }
  }
  return iVar3;
}

