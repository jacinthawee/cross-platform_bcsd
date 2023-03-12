
void X509V3_conf_free(CONF_VALUE *val)

{
  if (val != (CONF_VALUE *)0x0) {
    if (val->name != (char *)0x0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)();
    }
    if (val->value != (char *)0x0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)();
    }
    if (val->section != (char *)0x0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)();
    }
                    /* WARNING: Could not recover jumptable at 0x0058bf0c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_CRYPTO_free_006a7f88)(val);
    return;
  }
  return;
}

