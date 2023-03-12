
int tls1_process_heartbeat(undefined4 *param_1)

{
  char cVar1;
  char cVar2;
  undefined *ptr;
  void *pvVar3;
  int iVar4;
  char *pcVar5;
  uint __n;
  uint num;
  
  iVar4 = param_1[0x16];
  pcVar5 = *(char **)(iVar4 + 0x118);
  if ((code *)param_1[0x19] != (code *)0x0) {
    (*(code *)param_1[0x19])
              (0,*param_1,0x18,pcVar5,*(undefined4 *)(iVar4 + 0x110),param_1,param_1[0x1a]);
    iVar4 = param_1[0x16];
  }
  if (0x12 < *(uint *)(iVar4 + 0x110)) {
    cVar1 = pcVar5[1];
    cVar2 = pcVar5[2];
    __n = (uint)CONCAT11(cVar1,cVar2);
    num = __n + 0x13;
    if (num <= *(uint *)(iVar4 + 0x110)) {
      if (*pcVar5 == '\x01') {
        ptr = (undefined *)CRYPTO_malloc(num,"t1_lib.c",0xa2a);
        if (ptr == (undefined *)0x0) {
          return -1;
        }
        ptr[2] = cVar2;
        *ptr = 2;
        ptr[1] = cVar1;
        pvVar3 = memcpy(ptr + 3,pcVar5 + 3,__n);
        iVar4 = RAND_bytes((uchar *)((int)pvVar3 + __n),0x10);
        if (iVar4 < 1) {
          CRYPTO_free(ptr);
          return -1;
        }
        iVar4 = ssl3_write_bytes(param_1,0x18,ptr,num);
        if (iVar4 < 0) {
          CRYPTO_free(ptr);
          return iVar4;
        }
        if ((code *)param_1[0x19] != (code *)0x0) {
          (*(code *)param_1[0x19])(1,*param_1,0x18,ptr,num,param_1,param_1[0x1a]);
        }
        CRYPTO_free(ptr);
      }
      else if (*pcVar5 == '\x02') {
        if (__n == 0x12) {
          if (param_1[99] != (uint)CONCAT11(pcVar5[3],pcVar5[4])) {
            return 0;
          }
          param_1[0x62] = 0;
          param_1[99] = param_1[99] + 1;
          return 0;
        }
      }
    }
  }
  return 0;
}

