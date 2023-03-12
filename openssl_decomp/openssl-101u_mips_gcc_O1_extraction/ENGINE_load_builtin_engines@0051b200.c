
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ENGINE_load_builtin_engines(void)

{
  (*(code *)PTR_OPENSSL_cpuid_setup_006a8820)();
  ENGINE_load_rsax();
  ENGINE_load_rdrand();
  ENGINE_load_dynamic();
  (*(code *)PTR_ENGINE_load_4758cca_006a8830)();
  (*(code *)PTR_ENGINE_load_aep_006a8834)();
  (*(code *)PTR_ENGINE_load_atalla_006a8838)();
  (*(code *)PTR_ENGINE_load_cswift_006a883c)();
  (*(code *)PTR_ENGINE_load_chil_006a8840)();
  (*(code *)PTR_ENGINE_load_nuron_006a8844)();
  (*(code *)PTR_ENGINE_load_sureware_006a8848)();
  (*(code *)PTR_ENGINE_load_ubsec_006a884c)();
  (*(code *)PTR_ENGINE_load_padlock_006a8850)();
  (*(code *)PTR_ENGINE_load_gost_006a8854)();
  ENGINE_register_all_complete();
  return;
}

