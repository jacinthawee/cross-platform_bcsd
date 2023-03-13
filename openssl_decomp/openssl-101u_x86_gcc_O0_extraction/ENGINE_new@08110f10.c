
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ENGINE * ENGINE_new(void)

{
  undefined4 *obj;
  uint uVar1;
  undefined4 *puVar2;
  byte bVar3;
  
  bVar3 = 0;
  obj = (undefined4 *)CRYPTO_malloc(0x70,"eng_lib.c",0x45);
  if (obj == (undefined4 *)0x0) {
    ERR_put_error(0x26,0x7a,0x41,"eng_lib.c",0x47);
    obj = (undefined4 *)0x0;
  }
  else {
    *obj = 0;
    obj[0x1b] = 0;
    puVar2 = (undefined4 *)((uint)(obj + 1) & 0xfffffffc);
    for (uVar1 = (uint)((int)obj + (0x70 - (int)(undefined4 *)((uint)(obj + 1) & 0xfffffffc))) >> 2;
        uVar1 != 0; uVar1 = uVar1 - 1) {
      *puVar2 = 0;
      puVar2 = puVar2 + (uint)bVar3 * -2 + 1;
    }
    obj[0x16] = 1;
    CRYPTO_new_ex_data(9,obj,(CRYPTO_EX_DATA *)(obj + 0x18));
  }
  return (ENGINE *)obj;
}

