
void EC_POINT_free(EC_POINT *point)

{
  if (point != (EC_POINT *)0x0) {
    if (*(code **)(*(int *)point + 0x2c) != (code *)0x0) {
      (**(code **)(*(int *)point + 0x2c))();
    }
                    /* WARNING: Could not recover jumptable at 0x00504938. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_CRYPTO_free_006a7f88)(point);
    return;
  }
  return;
}

