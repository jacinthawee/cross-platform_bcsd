
undefined4 ssl2_new(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 *ptr;
  void *pvVar2;
  uint uVar3;
  undefined4 *puVar4;
  byte bVar5;
  
  bVar5 = 0;
  ptr = (undefined4 *)CRYPTO_malloc(0x120,"s2_lib.c",0x143);
  if (ptr == (undefined4 *)0x0) {
    return 0;
  }
  *ptr = 0;
  ptr[0x47] = 0;
  puVar4 = (undefined4 *)((uint)(ptr + 1) & 0xfffffffc);
  uVar3 = (uint)((int)ptr + (0x120 - (int)puVar4)) >> 2;
  for (; uVar3 != 0; uVar3 = uVar3 - 1) {
    *puVar4 = 0;
    puVar4 = puVar4 + (uint)bVar5 * -2 + 1;
  }
  pvVar2 = CRYPTO_malloc(0x8001,"s2_lib.c",0x14b);
  ptr[0xc] = pvVar2;
  if (pvVar2 == (void *)0x0) {
    if ((void *)ptr[0xd] == (void *)0x0) goto LAB_080973c6;
    CRYPTO_free((void *)ptr[0xd]);
  }
  else {
    pvVar2 = CRYPTO_malloc(0x8002,"s2_lib.c",0x14f);
    ptr[0xd] = pvVar2;
    if (pvVar2 != (void *)0x0) {
      puVar4 = (undefined4 *)((uint)(ptr + 1) & 0xfffffffc);
      param_1[0x15] = ptr;
      uVar1 = ptr[0xc];
      *ptr = 0;
      ptr[0x47] = 0;
      uVar3 = (uint)((int)ptr + (0x120 - (int)puVar4)) >> 2;
      for (; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar4 = 0;
        puVar4 = puVar4 + (uint)bVar5 * -2 + 1;
      }
      ptr[0xd] = pvVar2;
      ptr[1] = 1;
      ptr[0xc] = uVar1;
      param_1[0x13] = uVar1;
      *param_1 = 2;
      param_1[0x14] = 0;
      return 1;
    }
  }
  if ((void *)ptr[0xc] != (void *)0x0) {
    CRYPTO_free((void *)ptr[0xc]);
  }
LAB_080973c6:
  CRYPTO_free(ptr);
  return 0;
}

