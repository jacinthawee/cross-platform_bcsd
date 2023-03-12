
void ec_pre_comp_clear_free(int param_1)

{
  int iVar1;
  EC_POINT *point;
  EC_POINT **ppEVar2;
  
  if ((param_1 != 0) &&
     (iVar1 = (*(code *)PTR_CRYPTO_add_lock_006a805c)
                        (param_1 + 0x18,0xffffffff,0x24,"ec_mult.c",0x9f), iVar1 < 1)) {
    ppEVar2 = *(EC_POINT ***)(param_1 + 0x10);
    if (ppEVar2 != (EC_POINT **)0x0) {
      point = *ppEVar2;
      if (point != (EC_POINT *)0x0) {
        do {
          EC_POINT_clear_free(point);
          (*(code *)PTR_OPENSSL_cleanse_006a7074)(ppEVar2,4);
          point = ppEVar2[1];
          ppEVar2 = ppEVar2 + 1;
        } while (point != (EC_POINT *)0x0);
        ppEVar2 = *(EC_POINT ***)(param_1 + 0x10);
      }
      (*(code *)PTR_CRYPTO_free_006a6e88)(ppEVar2);
    }
    (*(code *)PTR_OPENSSL_cleanse_006a7074)(param_1,0x1c);
                    /* WARNING: Could not recover jumptable at 0x005038c4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_CRYPTO_free_006a6e88)(param_1);
    return;
  }
  return;
}
