
void EC_POINT_clear_free(EC_POINT *point)

{
  code *pcVar1;
  
  if (point == (EC_POINT *)0x0) {
    return;
  }
  pcVar1 = *(code **)(*(int *)point + 0x30);
  if ((pcVar1 != (code *)0x0) || (pcVar1 = *(code **)(*(int *)point + 0x2c), pcVar1 != (code *)0x0))
  {
    (*pcVar1)();
  }
  (*(code *)PTR_OPENSSL_cleanse_006a8174)(point,0x44);
                    /* WARNING: Could not recover jumptable at 0x005049a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_CRYPTO_free_006a7f88)(point);
  return;
}

