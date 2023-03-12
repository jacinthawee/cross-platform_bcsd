
int tls1_process_heartbeat(undefined4 *param_1)

{
  char cVar1;
  char cVar2;
  char cVar3;
  undefined *ptr;
  void *pvVar4;
  int iVar5;
  char *pcVar6;
  uint __n;
  int num;
  
  pcVar6 = *(char **)(param_1[0x16] + 0x118);
  cVar3 = pcVar6[1];
  cVar1 = pcVar6[2];
  cVar2 = *pcVar6;
  __n = (uint)CONCAT11(cVar3,cVar1);
  if ((code *)param_1[0x19] != (code *)0x0) {
    (*(code *)param_1[0x19])
              (0,*param_1,0x18,pcVar6,*(undefined4 *)(param_1[0x16] + 0x110),param_1,param_1[0x1a]);
  }
  if (cVar2 == '\x01') {
    num = __n + 0x13;
    ptr = (undefined *)CRYPTO_malloc(num,"t1_lib.c",0xa14);
    ptr[2] = cVar1;
    ptr[1] = cVar3;
    *ptr = 2;
    pvVar4 = memcpy(ptr + 3,pcVar6 + 3,__n);
    RAND_pseudo_bytes((uchar *)((int)pvVar4 + __n),0x10);
    iVar5 = ssl3_write_bytes(param_1,0x18,ptr,num);
    if (iVar5 < 0) {
      CRYPTO_free(ptr);
      return iVar5;
    }
    if ((code *)param_1[0x19] != (code *)0x0) {
      (*(code *)param_1[0x19])(1,*param_1,0x18,ptr,num,param_1,param_1[0x1a]);
    }
    CRYPTO_free(ptr);
  }
  else if (cVar2 == '\x02') {
    if (__n == 0x12) {
      if (param_1[99] != (uint)CONCAT11(pcVar6[3],pcVar6[4])) {
        return 0;
      }
      param_1[0x62] = 0;
      param_1[99] = param_1[99] + 1;
      return 0;
    }
  }
  return 0;
}

