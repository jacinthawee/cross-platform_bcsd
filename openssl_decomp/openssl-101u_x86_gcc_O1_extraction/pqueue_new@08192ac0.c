
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

pqueue pqueue_new(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)CRYPTO_malloc(8,"pqueue.c",0x5d);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
    puVar1[1] = 0;
  }
  return (pqueue)puVar1;
}

