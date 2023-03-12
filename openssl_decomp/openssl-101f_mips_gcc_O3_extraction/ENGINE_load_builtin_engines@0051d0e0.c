
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ENGINE_load_builtin_engines(void)

{
  (*(code *)PTR_OPENSSL_cpuid_setup_006a9940)();
  ENGINE_load_rsax();
  ENGINE_load_rdrand();
  ENGINE_load_dynamic();
  (*(code *)PTR_ENGINE_load_4758cca_006a9950)();
  (*(code *)PTR_ENGINE_load_aep_006a9954)();
  (*(code *)PTR_ENGINE_load_atalla_006a9958)();
  (*(code *)PTR_ENGINE_load_cswift_006a995c)();
  (*(code *)PTR_ENGINE_load_chil_006a9960)();
  (*(code *)PTR_ENGINE_load_nuron_006a9964)();
  (*(code *)PTR_ENGINE_load_sureware_006a9968)();
  (*(code *)PTR_ENGINE_load_ubsec_006a996c)();
  (*(code *)PTR_ENGINE_load_padlock_006a9970)();
  (*(code *)PTR_ENGINE_load_gost_006a9974)();
  ENGINE_register_all_complete();
  return;
}

