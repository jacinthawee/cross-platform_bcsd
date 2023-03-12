
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void OPENSSL_load_builtin_modules(void)

{
  (*(code *)PTR_ASN1_add_oid_module_006aa210)();
  (*(code *)PTR_ENGINE_add_conf_module_006aa214)();
                    /* WARNING: Could not recover jumptable at 0x005a11ec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_EVP_add_alg_module_006aa218)();
  return;
}

