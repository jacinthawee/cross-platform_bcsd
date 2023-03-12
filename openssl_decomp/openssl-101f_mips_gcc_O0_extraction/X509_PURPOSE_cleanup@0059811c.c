
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void X509_PURPOSE_cleanup(void)

{
  undefined1 *puVar1;
  
  puVar1 = xstandard;
  (*(code *)PTR_sk_pop_free_006a8158)(xptable,xptable_free);
  do {
    if ((puVar1 != (undefined *)0x0) && ((*(uint *)(puVar1 + 8) & 1) != 0)) {
      if ((*(uint *)(puVar1 + 8) & 2) != 0) {
        (*(code *)PTR_CRYPTO_free_006a7f88)(*(undefined4 *)(puVar1 + 0x10));
        (*(code *)PTR_CRYPTO_free_006a7f88)(*(undefined4 *)(puVar1 + 0x14));
      }
      (*(code *)PTR_CRYPTO_free_006a7f88)(puVar1);
    }
    puVar1 = puVar1 + 0x1c;
  } while (puVar1 != &UNK_006a2f4c);
  xptable = 0;
  return;
}

