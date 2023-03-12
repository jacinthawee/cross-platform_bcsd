
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void X509_TRUST_cleanup(void)

{
  undefined1 *puVar1;
  
  puVar1 = trstandard;
  do {
    if (((undefined **)puVar1 != (undefined **)0x0) &&
       (((uint)*(undefined **)((int)puVar1 + 4) & 1) != 0)) {
      if (((uint)*(undefined **)((int)puVar1 + 4) & 2) != 0) {
        (*(code *)PTR_CRYPTO_free_006a7f88)(*(undefined **)((int)puVar1 + 0xc));
      }
      (*(code *)PTR_CRYPTO_free_006a7f88)(puVar1);
    }
    puVar1 = (undefined1 *)((int)puVar1 + 0x18);
  } while ((undefined **)puVar1 != &default_trust);
  (*(code *)PTR_sk_pop_free_006a8158)(trtable,trtable_free);
  trtable = 0;
  return;
}

