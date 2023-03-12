
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void X509_PURPOSE_cleanup(void)

{
  undefined1 *puVar1;
  
  puVar1 = xstandard;
  (*(code *)PTR_sk_pop_free_006a7058)(xptable,xptable_free);
  do {
    if ((puVar1 != (undefined *)0x0) && ((*(uint *)(puVar1 + 8) & 1) != 0)) {
      if ((*(uint *)(puVar1 + 8) & 2) != 0) {
        (*(code *)PTR_CRYPTO_free_006a6e88)(*(undefined4 *)(puVar1 + 0x10));
        (*(code *)PTR_CRYPTO_free_006a6e88)(*(undefined4 *)(puVar1 + 0x14));
      }
      (*(code *)PTR_CRYPTO_free_006a6e88)(puVar1);
    }
    puVar1 = puVar1 + 0x1c;
  } while (puVar1 != &UNK_006a1dec);
  xptable = 0;
  return;
}

